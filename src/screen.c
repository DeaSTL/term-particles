#include <drawlib.h>
#include <math.h>
#include <ncurses.h>
#include <stdlib.h>
size_t get_screen_index(int x, int y, int width, int height) {
  return x + (y * width);
}

// number between 0-255 mapped to a number between ascii_pixel_density_count
int interpolate_pixel_density(short value) {
  return ((1.0 / 255.0) * value) * ascii_density_map_count;
}

void dl_draw_pixel(dl_screen *screen, int x, int y, short pixel) {
  if (x >= screen->width - 1 || y >= screen->height - 1)
    return;

  screen->screen_buffer[get_screen_index(x, y, screen->width, screen->height)] =
      interpolate_pixel_density(pixel);
}

dl_screen *dl_new_screen(dl_screen screen) {
  dl_screen *new_screen = (dl_screen *)calloc(1, sizeof(dl_screen));

  new_screen->width = screen.width;
  new_screen->height = screen.height;

  new_screen->screen_buffer =
      (short *)calloc(new_screen->width * new_screen->height, sizeof(short));

  return new_screen;
}

void dl_resize_screen(dl_screen *screen, int new_width, int new_height) {

  short *old_buffer = screen->screen_buffer;

  short *new_buffer = (short *)calloc(new_width * new_height, sizeof(short));

  for (int x = 0; x < screen->width; x++) {
    for (int y = 0; y < screen->height; x++) {

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
void dl_draw_screen(dl_screen *screen) {
  
  for (int x = 0; x < screen->width; x++) {
    for (int y = 0; y < screen->height; x++) {

      short value =
          screen->screen_buffer[get_screen_index(x, y, screen->width, screen->height)];
      move(y,x);
      addch(ascii_density_map[value]);
    }
  }

}
