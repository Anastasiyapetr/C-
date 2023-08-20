#ifndef SRC_PARCER_H
#define SRC_PARCER_H

#include <string.h>

#include "model.h"

#define MAX_VERTEX_COUNT 1000005

enum ErrorCode { OK = 0, NO_FILE = 1, FORMAT_ERR = 2, OVERSIZED = 3 };

int TryToInitObj(char *filename, obj_t *obj);
int CountVertexAndFace(FILE *file, obj_t *obj);
int CountNum(char *buffer);
void FillObjValues(FILE *file, obj_t *obj);
void FindMinMax(float *min, float *max, float value);
void CenterObject(obj_t *obj);
void ScaleObject(obj_t *obj, float value);

#endif  // SRC_PARCER_H
