#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QLineEdit>
#include <QMainWindow>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QRect>
#include <QScrollBar>
#include <QSize>
#include <QStyleFactory>
#include <QTimer>

#include "../QtGifImage/src/gifimage/qgifimage.h"

#define MAX_VALUE_TRANSLATION 50
#define MIN_VALUE_TRANSLATION -50

#define MAX_VALUE_ROTATION 360
#define MIN_VALUE_ROTATION 0

#define MAX_VALUE_SCALING 10
#define MIN_VALUE_SCALING -10

#define HEIGHT 480
#define WIDTH 640

#define COUNT_IMAGE 50
extern "C" {
#include "./backend/parcer.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  enum Error {
    OK = 0,
    NO_FILE_ERROR = 1,
    FORMAT_ERROR = 2,
    OVERSIZED_ERROR = 3
  };
  Q_ENUM(Error);

 private slots:
  /*Open and close file*/
  void on_openBtn_clicked();
  void on_clearBtn_clicked();
  /*Translation*/
  void on_translationX_valueChanged(int value);
  void on_translationY_valueChanged(int value);
  void on_translationZ_valueChanged(int value);
  void on_lineTranslationX_editingFinished();
  void on_lineTranslationY_editingFinished();
  void on_lineTranslationZ_editingFinished();
  /*Rotation*/
  void on_rotationX_valueChanged(int value);
  void on_rotationY_valueChanged(int value);
  void on_rotationZ_valueChanged(int value);
  void on_lineRotationX_editingFinished();
  void on_lineRotationY_editingFinished();
  void on_lineRotationZ_editingFinished();
  /*Scaling*/
  void on_scaling_valueChanged(int value);
  void on_lineScaling_editingFinished();
  /*Settings: color*/
  void on_bgColorBtn_clicked();
  void on_vertexColorBtn_clicked();
  void on_edgeColorBtn_clicked();
  /*Settings: projection, vertex and line size*/
  void on_displayBox_currentIndexChanged(int index);
  void on_lineBox_currentIndexChanged(int index);
  void on_projectionBox_currentIndexChanged(int index);
  void on_edgeSizeBox_valueChanged(double arg1);
  void on_vertexSizeBox_valueChanged(double arg1);
  /*Record*/
  void on_saveBtn_clicked();
  void on_gifBtn_clicked();
  void makeGif();
  /*Reset*/
  void on_resetButton_clicked();

 private:
  Ui::MainWindow *ui;
  bool reset = 0;
  QString file;

  QGifImage *gif;
  QImage *image;
  QTimer *timer;
  int count_image = 0;

  void defaultSettings();  // Default settings for scrolls (translation,
                           // rotation and scaling)
  void DefaultSettings_Affine(QLineEdit *line, QScrollBar *scroll,
                              int max_value, int min_value);
  void setControls();  // Invert wheel mouse
  void setTheme();
  void setLineTranslation(
      int *value,
      QScrollBar *scroll);  // checking entered value translation
  void setLineRotation(int *value, QScrollBar *scroll);
  void RotationSettings();
  void setLineScaling(int *value,
                      QScrollBar *scroll);  // checking entered value scaling
  void clearWidget();
  void save_settings();
  void load_settings();
  void changeBtnColor(QPushButton *btn, QColor color);
  void default_ui_settings();
};
#endif  // MAINWINDOW_H
