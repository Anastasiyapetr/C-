#ifndef SRC_MODEL_H
#define SRC_MODEL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_obj {
  unsigned int vertex_n;       // количество вершин
  unsigned int vertex_amount;  // количество значений вершин
  double *vertex_value;
  unsigned int face_n;
  int face_amount;
  unsigned int *face_value;
  float min_values[3];
  float max_values[3];
} obj_t;

void Init(obj_t *obj);
void Destroy(obj_t *obj);

#endif  // SRC_MODEL_H
