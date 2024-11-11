#include <drawlib.h>
#include <ncurses.h>
#include <math.h>
#include <stdlib.h>

void dl_draw_pixel(int x, int y, const char pixel) {
  if(y <= 0)return;
  if(x <= 0)return;
  move(y, x);
  addch(pixel);
}

// Bresenham's line drawing algo
void dl_draw_line(vectori point_a, vectori point_b, const char pixel) {
  int dx = abs(point_b.x - point_a.x);
  int dy = abs(point_b.y - point_a.y);
  int sx = (point_a.x < point_b.x) ? 1 : -1;
  int sy = (point_a.y < point_b.y) ? 1 : -1;
  int err = dx - dy;

  while (1) {
    dl_draw_pixel(point_a.x, point_a.y, pixel); // Plot the current point

    if (point_a.x == point_b.x && point_a.y == point_b.y)
      break; // Stop if we've reached the endpoint

    int e2 = 2 * err;
    if (e2 > -dy) {
      err -= dy;
      point_a.x += sx;
    }
    if (e2 < dx) {
      err += dx;
      point_a.y += sy;
    }
  }
}

void dl_draw_ngon(vectori *points, int point_count, const char pixel) {
  for (int i = 0; i < point_count; i++) {
    // draw_pixel(points[i].x,points[i].y,pixel);
    if (i > 0) {
      dl_draw_line(points[i], points[i - 1], pixel);
    }
    // // complete the shape
    if (i == point_count - 1) {
      dl_draw_line(points[i], points[0], pixel);
    }
  }
}

void dl_print_vector_array(vectori *points, int point_count) {
  for (int i = 0; i < point_count; i++) {
    printf("{x = %i, y = %i}\n", points[i].x, points[i].y);
  }
}

vectori* dl_translate_points(vectori *points, int point_count,
                             vectori new_pos) {
  vectori* new_points = (vectori*)malloc(point_count * sizeof(vectori));
  for (int i = 0; i < point_count; i++) {
    new_points[i].x = points[i].x + new_pos.x;
    new_points[i].y = points[i].y + new_pos.y;
  }

  return new_points;
}

vectori vectori_add(vectori a, vectori b){
  return (vectori){
    .x = a.x + b.x,
    .y = a.y + b.y,
  };
}
vectori vectori_sub(vectori a, vectori b){
  return (vectori){
    .x = a.x - b.x,
    .y = a.y - b.y,
  };
}
vectori vectori_mult(vectori a, vectori b){
  return (vectori){
    .x = a.x * b.x,
    .y = a.y * b.y,
  };
}
vectori vectori_div(vectori a, vectori b){
  return (vectori){
    .x = a.x / b.x,
    .y = a.y / b.y,
  };
}





