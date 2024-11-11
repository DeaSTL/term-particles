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
} dl_screen;

// screen
dl_screen *dl_new_screen(dl_screen screen);
void dl_resize_screen(dl_screen *screen, int width, int height);
void dl_draw_screen(dl_screen *screen);

// ellipse
dl_ellipse *dl_new_ellipse(dl_ellipse new_ellipse);
// If you update the size of the ellipse then you have to run this function
void dl_update_ellipse(dl_ellipse *ellipse);
void dl_draw_ellipse(dl_ellipse *ellipse);

// primatives
void dl_draw_pixel(dl_screen* screen, int x, int y, short value);
void dl_draw_line(dl_screen* screen,vectori point_a, vectori point_b,short pixel);
void dl_draw_ngon(dl_screen* screen,vectori *points, int point_count, short pixel);
void dl_print_vectori_array(vectori *points, int point_count);
vectori *dl_translate_points(vectori *points, int point_count, vectori new_pos);

// rectangle
dl_rect *dl_new_rect(dl_rect new_rect);
// If you update the size of the rectangle then you have to run this function
void dl_update_rect(dl_rect *rect);
void dl_draw_rect(dl_rect *rect);

// vectori methods
vectori vectori_add(vectori a, vectori b);
vectori vectori_sub(vectori a, vectori b);
vectori vectori_mult(vectori a, vectori b);
vectori vectori_div(vectori a, vectori b);

#endif
