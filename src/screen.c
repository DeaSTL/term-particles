#include <drawlib.h>
#include <math.h>
#include <stdlib.h>
size_t get_screen_index(int x, int y, int width, int height) {
  return x + (y * width);
}

dl_screen *dl_new_screen(dl_screen screen) {
  dl_screen *new_screen = (dl_screen *)calloc(1, sizeof(dl_screen));

  new_screen->width = screen.width;
  new_screen->height = screen.height;

  new_screen->screen_buffer =
      (short *)calloc(new_screen->width * new_screen->height, sizeof(short));
}
void dl_resize_screen(dl_screen *screen, int new_width, int new_height) {

  short *old_buffer = screen->screen_buffer;

  short *new_buffer = (short *)calloc(new_width * new_height, sizeof(short));

  for (int x = 0; x < screen->width; x++) {
    for (int y = 0; y < screen->height; x++) {

      short value = old_buffer[get_screen_index(x,y,screen->width,screen->height)];

      if(x < new_width && y < new_height){
        new_buffer[get_screen_index(x,y,new_width,new_height)] = value;
      }
    }
  }
}
void dl_draw_screen(dl_screen *screen) {}
