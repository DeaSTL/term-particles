#include <drawlib.h>
#include <helperlib.h>
#include <math.h>
#include <stdlib.h>

dl_ellipse *dl_new_ellipse(dl_ellipse ellipse) {
  dl_ellipse *new_ellipse = (dl_ellipse *)calloc(1, sizeof(dl_ellipse));

  new_ellipse->point_count = ellipse.resolution;
  new_ellipse->width = ellipse.width;
  new_ellipse->height = ellipse.height;
  new_ellipse->resolution = ellipse.resolution;
  new_ellipse->position = ellipse.position;
  new_ellipse->points =
      (vectori *)calloc(new_ellipse->point_count, sizeof(vectori));
  new_ellipse->pixel = ellipse.pixel;
  dl_update_ellipse(new_ellipse);
  return new_ellipse;
}

void dl_update_ellipse(dl_ellipse *ellipse) {

  double point_angle = (2.0 * M_PI) / (double)ellipse->point_count;

  for (int i = 0; i < ellipse->point_count; i++) {
    ellipse->points[i] = (vectori){
        .x = (int)round(cos(point_angle * (double)i) * (ellipse->width / 2)),
        .y = (int)round(sin(point_angle * (double)i) * (ellipse->height / 2))};
  }
}

void dl_draw_ellipse(dl_ellipse *ellipse) {
  vectori *translated_points = dl_translate_points(
      ellipse->points, ellipse->point_count,
      vectori_add(ellipse->position, (vectori){
                                         .x = ellipse->width / 2,
                                         .y = ellipse->height / 2,
                                     }));
  dl_draw_ngon(translated_points, ellipse->point_count, ellipse->pixel);
  free(translated_points);
}
