#include <drawlib.h>
#include <stdlib.h>

void dl_update_rect(dl_rect *rect) {
  vectori points[4] = {
      (vectori){.x = rect->position.x, .y = rect->position.y},
      (vectori){.x = rect->position.x + rect->width, .y = rect->position.y},
      (vectori){.x = rect->position.x + rect->width,
                .y = rect->position.y + rect->height},
      (vectori){.x = rect->position.x, .y = rect->position.y + rect->height}};
}

dl_rect *dl_new_rect(dl_rect rect) {
  dl_rect *new_rect = (dl_rect *)calloc(1, sizeof(dl_rect));
  new_rect->point_count = 4;
  new_rect->width = rect.width;
  new_rect->height = rect.height;
  new_rect->position = rect.position;
  new_rect->pixel = rect.pixel;
  dl_update_rect(new_rect);
  return new_rect;
}

void dl_draw_rect(dl_screen* screen, dl_rect *rect) {
  dl_draw_ngon(screen,rect->points, rect->point_count, rect->pixel);
}
