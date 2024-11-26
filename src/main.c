#define _POSIX_C_SOURCE 199309L
#include <drawlib.h>
#include <helperlib.h>
#include <errno.h>
#include <math.h>
#include <ncurses.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

const float FRICTION = 0.92;
const int BASE_PARTICLE_COUNT = 1000000;
const int THREAD_COUNT = 4;

int msleep(long msec) {
  struct timespec ts;
  int res;

  if (msec < 0) {
    errno = EINVAL;
    return -1;
  }

  ts.tv_sec = msec / 1000;
  ts.tv_nsec = (msec % 1000) * 1000000;

  do {
    res = nanosleep(&ts, &ts);
  } while (res && errno == EINTR);

  return res;
}

typedef struct particle particle;
struct particle {
  float x;
  float y;
  float vel_x;
  float vel_y;
  float acc_x;
  float acc_y;
  float lifespan;
};

typedef struct obstacle {
  float x;
  float y;
  float width;
  float height;
} obstacle;

typedef struct worldCtx worldCtx;
struct worldCtx {
  int frame_count;
  int screen_width;
  int screen_height;
  int particle_count;
  int obstacle_count;
  int mouse_x;
  int mouse_y;
  dl_screen* screen;
};

void particle_update(particle *this, double delta) {
  this->vel_x += this->acc_x;
  this->vel_y += this->acc_y;

  this->acc_x = 0;
  this->acc_y = 0;

  this->x += this->vel_x * delta;
  this->y += this->vel_y * delta;

  this->vel_y *= FRICTION;
  this->vel_x *= FRICTION;
}

void particle_draw(dl_screen* screen,particle *this) {
  dl_draw_pixel(screen,floor(this->x), floor(this->y),60 / (fabsf(this->vel_x) + fabsf(this->vel_y)));
}

void particle_apply_force(particle *this, float x, float y) {
  this->acc_x += x;
  this->acc_y += y;
}
particle particle_new(worldCtx *world_ctx) {
  int side = (fast_rand() % 4);
  particle new_particle = {
    .acc_y = 0,
    .acc_x = 0,
    .vel_x = 0,
    .vel_y = 0,
    .lifespan = (fast_rand() % 100) + 100,
  };
  switch (side) {
    case 0:
      new_particle.x = (fast_rand() % world_ctx->screen_width);
      new_particle.y = 0;
      break;
    case 1:
      new_particle.x = 0;
      new_particle.y = (fast_rand() % world_ctx->screen_height);
      break;
    case 2:
      new_particle.x = (fast_rand() % world_ctx->screen_width);
      new_particle.y = world_ctx->screen_height;
      break;
    case 3:
      new_particle.x = world_ctx->screen_width;
      new_particle.y = (fast_rand() % world_ctx->screen_height);
      break;
  }
  return new_particle;
}

void init_particles(particle *particles, worldCtx *world_ctx) {

  for (int i = 0; i < world_ctx->particle_count; i++) {

    int randx = (fast_rand() % world_ctx->screen_width);
    int randy = (fast_rand() % world_ctx->screen_height);

    particles[i] = particle_new(world_ctx);
  }
}

void update(float delta, particle *particles, worldCtx *world_ctx) {
  float target_x = world_ctx->mouse_x;
  float target_y = world_ctx->mouse_y;
  for (int i = 0; i < world_ctx->particle_count; i++) {
    float dist_x = target_x - particles[i].x;
    float dist_y = target_y - particles[i].y;

    particle_apply_force(&particles[i],
                         dist_x * 0.001 * (particles[i].lifespan / 150),
                         dist_y * 0.001 * (particles[i].lifespan / 150));
    // Gravity
    // particle_apply_force(&particles[i], 0, 0.02);

    particle_update(&particles[i], delta);
    particles[i].lifespan -= 1;

    if (particles[i].lifespan < 0) {
      particles[i] = particle_new(world_ctx);
    }
  }
}

void draw(particle *particles, worldCtx *world_ctx) {
  for (int i = 0; i < world_ctx->particle_count; i++) {
    particle_draw(world_ctx->screen,&particles[i]);
  }
  dl_draw_pixel(world_ctx->screen,world_ctx->mouse_x, world_ctx->mouse_y, 40);
}
typedef struct argsForKeyListener argsForKeyListener;
struct argsForKeyListener {
  worldCtx *world_ctx;
  WINDOW *window;
};

void *listen_for_keys(void *args) {

  argsForKeyListener *_args = (argsForKeyListener *)args;

  while (1) {
    MEVENT event;

    int ch = wgetch(_args->window);
    if (ch == KEY_MOUSE) {
      if (getmouse(&event) == OK) {
        _args->world_ctx->mouse_x = event.x;
        _args->world_ctx->mouse_y = event.y;
      }
    }
  }
}
typedef struct argsForDrawLoop {
  dl_screen *screen;
  particle* particles;
  worldCtx* world_ctx;
}argsForDrawLoop;
void* draw_loop(void *args){
  argsForDrawLoop *_args = (argsForDrawLoop* )args;
  while (1) {
    draw(_args->particles,_args->world_ctx);
    dl_swap_buffers(_args->screen);
    dl_draw_screen(_args->screen);
  }
}
typedef struct statusWindowEntry {
  const char *name;
  float value;
} statusWindowEntry;

void draw_status_window(statusWindowEntry *statuses, int count) {
  for (int i = 0; i < count; i++) {
    int status_name_len = strlen(statuses[i].name);
    char status_entry_buffer[status_name_len + 50];

    sprintf(status_entry_buffer, "%s: %lf\n", statuses[i].name,
            statuses[i].value);
    move(1 + i, 1);
    printw("%s", status_entry_buffer);
  }
}

int main(int argc, char *argv[]) {
  // dl_ellipse **circles = (dl_ellipse **)calloc(20, sizeof(dl_ellipse *));


  srand(time(NULL));
  fast_srand(time(NULL));

  // for (int i = 0; i < 100; i++) {
  //   circles[i] = dl_new_ellipse((dl_ellipse){
  //       .position = {.x = rand() % 40, .y = rand() % 40},
  //       .pixel = 'x',
  //       .resolution = 10,
  //       .width = 10,
  //       .height = 10,
  //   });
  // }
  particle *particles =
      (particle *)malloc(sizeof(particle) * BASE_PARTICLE_COUNT);
  const int OBSTACLE_COUNT = 20;
  // obstacle *obstacles = (obstacle *)malloc(sizeof(obstacle) * OBSTACLE_COUNT);

  WINDOW *window = initscr();

  start_color();
  init_color(COLOR_RED, 800, 400, 0);
  init_color(COLOR_YELLOW, 800, 400, 0);
  init_color(COLOR_BLUE, 1000, 600, 0);

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  keypad(stdscr, TRUE);

  mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

  worldCtx world_ctx = {.particle_count = BASE_PARTICLE_COUNT};

  world_ctx.screen_width = getmaxx(window);
  world_ctx.screen_height = getmaxy(window);

  dl_screen* screen = dl_new_screen((dl_screen){
      .width= world_ctx.screen_width,
      .height= world_ctx.screen_height
      });

  world_ctx.screen = screen;
  // init_particles(particles, &world_ctx);
  int frame_count = 0;

  // running keylistener thread
  pthread_t thread_id;
  // I hate this
  argsForKeyListener args_for_key_listener = {.window = window,
                                              .world_ctx = &world_ctx};
  pthread_create(&thread_id, NULL, listen_for_keys,
                 (void *)&args_for_key_listener); // kms
  
  argsForDrawLoop args_for_draw_loop = {.screen = screen};
  pthread_create(&thread_id, NULL, draw_loop,
                 (void *)&args_for_draw_loop); // kms

  struct timeval pre_frame_time, post_frame_time;
  const float SIXTY_FPS_US = (1.0 / 60.0) * 1000.0 * 1000.0;
  while (1) {

    gettimeofday(&pre_frame_time, NULL);
    world_ctx.screen_width = getmaxx(window);
    world_ctx.screen_height = getmaxy(window);

    frame_count++;
    dl_clear_screen(screen);
    clear();
    move(1, 1);
    update(1,particles,&world_ctx);
    // draw(particles, &world_ctx);
    // if(frame_count % 4 == 0){
    //   dl_swap_buffers(screen);
    // }
    gettimeofday(&post_frame_time, NULL);
    float frame_time =
        (float)((pre_frame_time.tv_sec - post_frame_time.tv_sec) * 1000000 +
                 post_frame_time.tv_usec - pre_frame_time.tv_usec);
    if (frame_time > 0) {
      msleep((SIXTY_FPS_US - frame_time) / 1000);
    }

    statusWindowEntry status_window_entries[] = {
        (statusWindowEntry){.name = "frame time", .value = frame_time},
        (statusWindowEntry){.name = "mouse x", .value = world_ctx.mouse_x},
        (statusWindowEntry){.name = "mouse y", .value = world_ctx.mouse_y},
        (statusWindowEntry){.name = "screen width",
                            .value = world_ctx.screen_width},
        (statusWindowEntry){.name = "screen height",
                            .value = world_ctx.screen_height},
        (statusWindowEntry){.name = "target frame time", .value = SIXTY_FPS_US},
        (statusWindowEntry){.name = "frame diff(us)",
                            .value = (SIXTY_FPS_US - frame_time)},
        (statusWindowEntry){.name = "particle count",
                            .value = world_ctx.particle_count},
    };

    world_ctx.frame_count = frame_count;
    // for (int i = 0;i<10;i++) {
    //   dl_draw_pixel(screen,1+i,12,frame_count % 60);
    // }
    dl_draw_screen(screen);
    // for (int i = 0;i<100;i++) {
    //   dl_draw_ellipse(screen,circles[i]);
    // }
    refresh();
  }

  return 0;
}
