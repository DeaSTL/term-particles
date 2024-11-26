#include <stdlib.h>

#ifndef DRAWLIB
#define DRAWLIB
#define ascii_density_map_count 64
extern const char ascii_density_map[];
typedef struct vectord {
  float x;
  float y;
} vectord;
typedef struct vectori {
  int x;
  int y;
} vectori;
typedef struct dl_ellipse {
  char pixel;
  vectori *points;
  int point_count;
  int resolution;
  vectori position;
  float width;
  float height;
} dl_ellipse;

typedef struct dl_rect {
  char pixel;
  vectori *points;
  int point_count;
  vectori position;
  int width;
  int height;
} dl_rect;
typedef struct dl_screen {
  int width;
  int height;
  short *screen_buffer;
  short *draw_buffer;
  int draw_buffer_lock;
} dl_screen;

// screen
dl_screen *dl_new_screen(dl_screen screen);
void dl_resize_screen(dl_screen *screen, int width, int height);
void dl_draw_screen(dl_screen *screen);
void dl_clear_screen(dl_screen *screen);
void dl_swap_buffers(dl_screen *screen);
static inline void dl_write_draw_buffer(dl_screen* screen,int index, short pixel){
  //pauses write while the draw buffer is locked
  while(screen->draw_buffer_lock){}

  screen->draw_buffer[index] = pixel;

}

// ellipse
dl_ellipse *dl_new_ellipse(dl_ellipse new_ellipse);
// If you update the size of the ellipse then you have to run this function
void dl_update_ellipse(dl_ellipse *ellipse);
void dl_draw_ellipse(dl_screen* screen,dl_ellipse *ellipse);

// primatives
// void dl_draw_pixel(dl_screen* screen, int x, int y, short value);
void dl_draw_line(dl_screen* screen,vectori point_a, vectori point_b,short pixel);
void dl_draw_ngon(dl_screen* screen,vectori *points, int point_count, short pixel);
void dl_print_vectori_array(vectori *points, int point_count);
vectori *dl_translate_points(vectori *points, int point_count, vectori new_pos);

// rectangle
dl_rect *dl_new_rect(dl_rect new_rect);
// If you update the size of the rectangle then you have to run this function
void dl_update_rect(dl_rect *rect);
void dl_draw_rect(dl_screen* screen,dl_rect *rect);

// vectori methods
vectori vectori_add(vectori a, vectori b);
vectori vectori_sub(vectori a, vectori b);
vectori vectori_mult(vectori a, vectori b);
vectori vectori_div(vectori a, vectori b);

static inline size_t get_screen_index(int x, int y, int width, int height) {
  return x + (y * width);
}

// number between 0-255 mapped to a number between ascii_pixel_density_count
static inline int interpolate_pixel_density(short value) {
  return ((1.0 / 255.0) * value) * ascii_density_map_count;
}

static inline void dl_draw_pixel(dl_screen *screen, int x, int y, short pixel) {
  if (x >= screen->width - 1 || y >= screen->height - 1)
    return;

  int index = get_screen_index(x, y, screen->width, screen->height);
  int pixel_level = interpolate_pixel_density(pixel);
  if(screen->draw_buffer[index] != pixel_level){
    dl_write_draw_buffer(screen,index,pixel_level);
    // screen->draw_buffer[index] = pixel_level;
  }
  // if(screen->screen_buffer[index] == 0){
  //
  // }
}

#endif
