#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QScrollArea>
#include <QWidget>
#include <QtGui>

#include "QtCore/qdatetime.h"
#include "mainwindow.h"

#define IS_X 1
#define IS_Y 2
#define IS_Z 3

#ifdef __cplusplus
extern "C" {
#endif
#include "./backend/transformations.h"
#ifdef __cplusplus
}
#endif

class GLWidget : public QOpenGLWidget {
  Q_OBJECT
 public:
  GLWidget(QWidget *parent = nullptr);

  QVector4D bgColor = QVector4D(0.0, 0.0, 0.0, 1.0);
  int bgX = 0, bgY = 0, bgZ = 0;
  int vertexColorX = 255, vertexColorY = 255, vertexColorZ = 255;
  int edgeColorX = 255, edgeColorY = 255, edgeColorZ = 255;
  int vertex_type = 0;
  bool parallel_projection_type = true, solid_edge_type = true;
  float vertexSize = 1, edgeSize = 1;
  obj_t obj;
  bool bg_changed = false;

  void setTranslate(double value, int vector);
  void setRotate(int value_x, int value_y, int value_z);
  void setScaling(int value);
  void changeBg();
  void resetTransformations();

 protected:
  void initializeGL() override;
  void paintGL() override;

 private:
  int count_scale = 0;
  double single_step = 1.0 / 25;

  long double angle = 0;
  long double xAngle = 0, yAngle = 0, zAngle = 0;

  double xMov = 0, yMov = 0, zMov = 0;
  double xPrev = 0, yPrev = 0, zPrev = 0;
  void setProjection();
};

#endif  // GLWIDGET_H
