#include "parcer.h"

int TryToInitObj(char *filename, obj_t *obj) {
  int result = OK;
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    result = NO_FILE;
  } else {
    Init(obj);
    result = CountVertexAndFace(file, obj);
    if (result == OK) {
      obj->vertex_value = (double *)calloc(obj->vertex_amount, sizeof(double));
      obj->face_value =
          (unsigned int *)calloc(obj->face_amount, sizeof(unsigned int));
      fseek(file, 0, 0);
      FillObjValues(file, obj);
    }
    fclose(file);
  }
  return result;
}
void FindMinMax(float *min, float *max, float value) {
  *min = (*min < value) ? *min : value;
  *max = (*max > value) ? *max : value;
}

void FillObjValues(FILE *file, obj_t *obj) {
  int vi = 0;
  int fi = 0;
  char buffer[10000];
  obj->vertex_value[vi++] = 0.0;
  obj->vertex_value[vi++] = 0.0;
  obj->vertex_value[vi++] = 0.0;
  while ((fscanf(file, "%9999[^\n]", buffer)) != EOF) {
    if (buffer[0] == 'v' && buffer[1] == ' ') {
      double f[3];
      if (sscanf(buffer, "%*c %lf %lf %lf", &(f[0]), &(f[1]), &(f[2])) == 3) {
        obj->vertex_value[vi++] = f[0];
        obj->vertex_value[vi++] = f[1];
        obj->vertex_value[vi++] = f[2];
        for (int i = 0; i < 3; i++)
          FindMinMax(&obj->min_values[i], &obj->max_values[i], f[i]);
      }
    } else if (buffer[0] == 'f' && buffer[1] == ' ') {
      unsigned int count = CountNum(buffer);
      char *str = strtok(buffer, " ");
      unsigned int n = 0;
      int tmp, face_ = 0;
      int step = 0;
      do {
        str = strtok(NULL, " ");
        if (str) {
          n++;
          tmp = atoi(str);
          obj->face_value[fi++] = tmp;
          if (step == 0) {
            face_ = tmp;
          } else {
            obj->face_value[fi++] = tmp;
          }
          step++;
        }
      } while (str != NULL && n < count);
      obj->face_value[fi++] = face_;
    }
    fgetc(file);
    buffer[0] = '\0';
  }
  // for (int i = 0; i < (int)obj->vertex_amount;i++) printf("x%i = %lf\n",
  // i, obj->vertex_value[i]);
  // printf("\n");
  CenterObject(obj);
  ScaleObject(obj, 0.7);
  // for (int i = 0; i < obj->face_amount;i++) printf("%i ",
  // obj->face_value[i]);
  // printf("\n");
  //      for (int i = 0; i < (int)obj->vertex_amount;i++) printf("x%i = %lf\n",
  //      i, obj->vertex_value[i]);
}

void CenterObject(obj_t *obj) {
  int j = 0;
  for (int i = 0; i < (int)obj->vertex_amount; i++) {
    obj->vertex_value[i] -=
        obj->min_values[j] + (obj->max_values[j] - obj->min_values[j]) / 2.0;
    j = (j < 2) ? j + 1 : 0;
  }
}

void ScaleObject(obj_t *obj, float value) {
  int diff[3] = {0, 0, 0};
  float max = obj->max_values[0] - obj->min_values[0];
  for (int i = 0; i < 3; i++) {
    diff[i] = obj->max_values[i] - obj->min_values[i];
    max = (max < diff[i]) ? diff[i] : max;
  }
  float scale = (value - (value * (-1))) / max;
  for (int i = 0; i < (int)obj->vertex_amount; i++)
    obj->vertex_value[i] *= scale;
}

int CountVertexAndFace(FILE *file, obj_t *obj) {
  char buffer[10000];
  obj->vertex_n++;
  obj->vertex_amount += 3;
  int result = OK;
  while ((fscanf(file, "%9999[^\n]", buffer)) != EOF) {
    if (obj->vertex_n - 1 < MAX_VERTEX_COUNT) {
      if (buffer[0] == 'v' && buffer[1] == ' ') {
        int count = CountNum(buffer);
        if (count != 3 && count != 4) {
          result = FORMAT_ERR;
          break;
        }
        obj->vertex_n++;
        obj->vertex_amount += count;
      } else if (buffer[0] == 'f' && buffer[1] == ' ') {
        obj->face_n++;
        obj->face_amount += CountNum(buffer) * 2;
      }
    } else {
      result = OVERSIZED;
      break;
    }
    fgetc(file);
    buffer[0] = '\0';
  }
  return result;
}

int CountNum(char *buffer) {
  int res = 0;
  for (size_t i = 1; i < strlen(buffer) - 1; i++) {
    if (buffer[i] == ' ' && buffer[i + 1] != ' ') res++;
  }
  return res;
}
