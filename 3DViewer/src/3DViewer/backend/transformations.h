#ifndef SRC_TRANSFORMATIONS_H
#define SRC_TRANSFORMATIONS_H

#include <math.h>

#include "parcer.h"

#define NUM_COORD 4  // (x, y, z, 1)
#define V_PI 3.14159265358979323846264338327950288f

void translation_matrix(obj_t *current_matrix, double xMov, double yMov,
                        double zMov);

double **create_matrix(int rows, int columns);
void remove_matrix(double **matrix, int rows);
void set_unit_matrix(double **matrix, int rows, int columns,
                     obj_t *current_matrix);
void create_transformation_matrix(double **transformation_matrix, double xMov,
                                  double yMov, double zMov);
void mult_matrix(double **result, double **transformation_matrix,
                 double **current_point_matrix, int count_matrix);
void fill_matrix(obj_t *current_matrix, double **output_matrix,
                 int count_matrix);
void create_scale_matrix(double **scale_matrix, double scale_step);
void scale_matrix(obj_t *current_matrix, double scale_step);

void rotate_matrix_x(obj_t *current_matrix, long double angle);
void rotate_matrix_y(obj_t *current_matrix, long double angle);
void rotate_matrix_z(obj_t *current_matrix, long double angle);
long double degrees_to_radians(long double angle);
#endif  // SRC_TRANSFORMATIONS_H
