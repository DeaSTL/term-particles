#include <drawlib.h>
#include <math.h>
#include <ncurses.h>
#include <stdlib.h>


dl_screen *dl_new_screen(dl_screen screen) {
  dl_screen *new_screen = (dl_screen *)calloc(1, sizeof(dl_screen));

  new_screen->width = screen.width;
  new_screen->height = screen.height;

  new_screen->screen_buffer =
      (short *)calloc(new_screen->width * new_screen->height, sizeof(short));

  new_screen->draw_buffer =
      (short *)calloc(new_screen->width * new_screen->height, sizeof(short));

  return new_screen;
}

void dl_resize_screen(dl_screen *screen, int new_width, int new_height) {

  short *old_buffer = screen->screen_buffer;

  short *new_buffer = (short *)calloc(new_width * new_height, sizeof(short));

  for (int x = 0; x < screen->width; x++) {
    for (int y = 0; y < screen->height; y++) {

      short value =
          old_buffer[get_screen_index(x, y, screen->width, screen->height)];

      if (x < new_width && y < new_height) {
        new_buffer[get_screen_index(x, y, new_width, new_height)] = value;
      }
    }
  }
  // get rid of the old buffer
  free(screen->screen_buffer);


  screen->screen_buffer = new_buffer;
  screen->width = new_width;
  screen->height = new_height;
}

void dl_swap_buffers(dl_screen *screen){
  screen->draw_buffer_lock = 1;
  short *old_screen_buffer = screen->screen_buffer;

  screen->screen_buffer = screen->draw_buffer;

  screen->draw_buffer = old_screen_buffer;

  screen->draw_buffer_lock = 0;

}
void dl_clear_screen(dl_screen *screen){
  for (size_t i = 0; i < screen->width * screen->height; i++) {
    dl_write_draw_buffer(screen,i,0);
  }
}
void dl_draw_screen(dl_screen *screen) {
   
  for (int x = 0; x < screen->width; x++) {
    for (int y = 0; y < screen->height; y++) {
      while(screen->draw_buffer_lock){}
      short value =
          screen->screen_buffer[get_screen_index(x, y, screen->width, screen->height)];

      if(value >= 0 && value < ascii_density_map_count){
        move(y,x);
        addch(ascii_density_map[value]);
      }
    }
  }

}
