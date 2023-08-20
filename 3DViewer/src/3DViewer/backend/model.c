#include "model.h"

void Init(obj_t *obj) {
  obj->vertex_amount = 0;
  obj->face_amount = 0;
  obj->vertex_n = 0;
  obj->face_n = 0;
  for (int i = 0; i < 3; i++) {
    obj->min_values[i] = 0;
    obj->max_values[i] = 0;
  }
}

void Destroy(obj_t *obj) {
  if (obj->vertex_n) {
    free(obj->vertex_value);
    obj->vertex_value = NULL;
    obj->vertex_amount = 0;
    obj->vertex_n = 0;
  }
  if (obj->face_n) {
    free(obj->face_value);
    obj->face_value = NULL;
    obj->face_n = 0;
    obj->face_amount = 0;
  }
  for (int i = 0; i < 3; i++) {
    obj->min_values[i] = 0;
    obj->max_values[i] = 0;
  }
}
