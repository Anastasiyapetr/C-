#include "transformations.h"

void translation_matrix(obj_t *current_matrix, double xMov, double yMov,
                        double zMov) {
  int count_matrix = current_matrix->vertex_n;
  double **current_point_matrix = create_matrix(NUM_COORD, count_matrix);
  double **transformation_matrix = create_matrix(NUM_COORD, NUM_COORD);
  double **output_matrix = create_matrix(NUM_COORD, count_matrix);

  set_unit_matrix(current_point_matrix, NUM_COORD, count_matrix,
                  current_matrix);
  create_transformation_matrix(transformation_matrix, xMov, yMov, zMov);
  mult_matrix(output_matrix, transformation_matrix, current_point_matrix,
              count_matrix);
  fill_matrix(current_matrix, output_matrix, count_matrix);
  remove_matrix(current_point_matrix, NUM_COORD);
  remove_matrix(transformation_matrix, NUM_COORD);
  remove_matrix(output_matrix, NUM_COORD);
}

void scale_matrix(obj_t *current_matrix, double scale_step) {
  int count_matrix = current_matrix->vertex_n;
  double **current_point_matrix = create_matrix(NUM_COORD, count_matrix);

  double **scale_matrix = create_matrix(NUM_COORD, NUM_COORD);
  double **output_matrix = create_matrix(NUM_COORD, count_matrix);

  set_unit_matrix(current_point_matrix, NUM_COORD, count_matrix,
                  current_matrix);
  create_scale_matrix(scale_matrix, scale_step);
  mult_matrix(output_matrix, scale_matrix, current_point_matrix, count_matrix);
  fill_matrix(current_matrix, output_matrix, count_matrix);

  remove_matrix(current_point_matrix, NUM_COORD);
  remove_matrix(scale_matrix, NUM_COORD);
  remove_matrix(output_matrix, NUM_COORD);
}

void rotate_matrix_x(obj_t *current_matrix, long double angle) {
  angle = degrees_to_radians(angle);
  for (unsigned i = 3; i < current_matrix->vertex_amount; i += 3) {
    double y = current_matrix->vertex_value[i + 1];
    double z = current_matrix->vertex_value[i + 2];
    current_matrix->vertex_value[i + 1] = y * cosl(angle) + z * sinl(angle);
    current_matrix->vertex_value[i + 2] = -y * sinl(angle) + z * cosl(angle);
  }
}

void rotate_matrix_y(obj_t *current_matrix, long double angle) {
  angle = degrees_to_radians(angle);
  for (unsigned i = 3; i < current_matrix->vertex_amount; i += 3) {
    double x = current_matrix->vertex_value[i];
    double z = current_matrix->vertex_value[i + 2];
    current_matrix->vertex_value[i] = x * cosl(angle) + z * sinl(angle);
    current_matrix->vertex_value[i + 2] = -x * sinl(angle) + z * cosl(angle);
  }
}

void rotate_matrix_z(obj_t *current_matrix, long double angle) {
  angle = degrees_to_radians(angle);
  for (unsigned i = 3; i < current_matrix->vertex_amount; i += 3) {
    double x = current_matrix->vertex_value[i];
    double y = current_matrix->vertex_value[i + 1];
    current_matrix->vertex_value[i] = x * cosl(angle) - y * sinl(angle);
    current_matrix->vertex_value[i + 1] = x * sinl(angle) + y * cosl(angle);
  }
}

double **create_matrix(int rows, int columns) {
  double **matrix = calloc(rows, sizeof(double *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = calloc(columns, sizeof(double));
  }
  return matrix;
}

void remove_matrix(double **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
  // matrix = NULL;
}

void set_unit_matrix(double **matrix, int rows, int columns,
                     obj_t *current_matrix) {
  int index_current_matrix = 0;
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      if (j == rows - 1) {
        matrix[j][i] = 1;
      } else {
        matrix[j][i] = current_matrix->vertex_value[index_current_matrix++];
      }
    }
  }
}

void create_transformation_matrix(double **transformation_matrix, double xMov,
                                  double yMov, double zMov) {
  for (int i = 0; i < NUM_COORD; i++) {
    for (int j = 0; j < NUM_COORD; j++) {
      if (i == j) {
        transformation_matrix[i][j] = 1;
      }
    }
  }
  transformation_matrix[0][3] = xMov;
  transformation_matrix[1][3] = yMov;
  transformation_matrix[2][3] = zMov;
}

void create_scale_matrix(double **scale_matrix, double scale_step) {
  scale_matrix[0][0] = scale_matrix[1][1] = scale_matrix[2][2] = scale_step;
  scale_matrix[3][3] = 1;
}

void fill_matrix(obj_t *current_matrix, double **output_matrix,
                 int count_matrix) {
  int index_current_matrix = 0;
  for (int i = 0; i < count_matrix; i++) {
    for (int j = 0; j < NUM_COORD; j++) {
      if (j == NUM_COORD - 1) {
        ;
      } else {
        current_matrix->vertex_value[index_current_matrix++] =
            output_matrix[j][i];
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    current_matrix->vertex_value[i] = 0;
  }
}

void mult_matrix(double **result, double **transformation_matrix,
                 double **current_point_matrix, int count_matrix) {
  double sum = 0;
  for (int i = 0; i < NUM_COORD; i++) {
    for (int j = 0; j < count_matrix; j++) {
      for (int k = 0; k < NUM_COORD; k++) {
        sum += transformation_matrix[i][k] * current_point_matrix[k][j];
      }
      result[i][j] = sum;
      sum = 0;
    }
  }
}

long double degrees_to_radians(long double angle) { return V_PI / 180 * angle; }
