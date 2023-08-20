#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget{parent} { Init(&obj); }

void GLWidget::initializeGL() { glEnable(GL_DEPTH_TEST); }

void GLWidget::changeBg() {
  QColor color = QColor(bgX, bgY, bgZ);
  bgColor =
      QVector4D(color.redF(), color.greenF(), color.blueF(), color.alphaF());
  glClearColor(bgColor.x(), bgColor.y(), bgColor.z(), bgColor.w());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLWidget::paintGL() {
  if (obj.vertex_n > 1) {
    // glClearColor(bgColor.x(), bgColor.y(), bgColor.z(), bgColor.w());
    changeBg();
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    setProjection();

    glPointSize(vertexSize);
    glVertexPointer(3, GL_DOUBLE, 0, obj.vertex_value);
    glEnableClientState(GL_VERTEX_ARRAY);
    glPointSize(vertexSize);
    glColor3ub(vertexColorX, vertexColorY, vertexColorZ);

    if (vertex_type == 1) {
      glEnable(GL_POINT_SMOOTH);
      glDrawArrays(GL_POINTS, 1, obj.vertex_n - 1);
      glDisable(GL_POINT_SMOOTH);
    } else if (vertex_type == 2) {
      glDrawArrays(GL_POINTS, 1, obj.vertex_n - 1);
    }

    glLineWidth(edgeSize);
    if (!solid_edge_type) {
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(5, 0x3333);
    }
    glColor3ub(edgeColorX, edgeColorY, edgeColorZ);
    glDrawElements(GL_LINES, obj.face_amount, GL_UNSIGNED_INT, obj.face_value);
    glPopMatrix();
    if (!solid_edge_type) {
      glDisable(GL_LINE_STIPPLE);
    }
  }
}

void GLWidget::setProjection() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  if (!parallel_projection_type) {
    glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);
    glTranslated(0, 0, -2);
  } else {
    GLfloat ratio = (GLfloat)600 / (GLfloat)600;
    glOrtho(-2.0 / ratio, 2.0 / ratio, -2.0, 2.0, -50.0, 50.0);
  }
}

void GLWidget::setTranslate(double value, int vector) {
  if (obj.vertex_n > 1) {
    if (vector == IS_X) {
      xMov = value * single_step;
    } else if (vector == IS_Y) {
      yMov = value * single_step;
    } else if (vector == IS_Z) {
      zMov = value * single_step;
    }
    if (obj.vertex_n > 1) {
      translation_matrix(&obj, xMov - xPrev, yMov - yPrev, zMov - zPrev);
    }
    xPrev = xMov, yPrev = yMov, zPrev = zMov;
    update();
  }
}

void GLWidget::setRotate(int value_x, int value_y, int value_z) {
  if (obj.vertex_n > 1) {
    if (value_x != xAngle) {
      rotate_matrix_x(&obj, value_x - xAngle);
      xAngle = value_x;
    }
    if (value_y != yAngle) {
      rotate_matrix_y(&obj, value_y - yAngle);
      yAngle = value_y;
    }
    if (value_z != zAngle) {
      rotate_matrix_z(&obj, value_z - zAngle);
      zAngle = value_z;
    }
    update();
  }
}

void GLWidget::setScaling(int value) {
  if (obj.vertex_n > 1 && value != count_scale) {
    int count_step = 0;
    double scale_step = 0;
    if (value < count_scale) {
      count_step = count_scale - value;
      scale_step = 1 / 1.1;
    } else {
      count_step = value - count_scale;
      scale_step = 1.1;
    }
    count_scale = value;
    for (; count_step != 0; count_step--) {
      scale_matrix(&obj, scale_step);
    }
    update();
  }
}

void GLWidget::resetTransformations() {
  count_scale = 0;
  angle = 0;
  xAngle = 0, yAngle = 0, zAngle = 0;
  xMov = 0, yMov = 0, zMov = 0;
  xPrev = 0, yPrev = 0, zPrev = 0;
  update();
}
