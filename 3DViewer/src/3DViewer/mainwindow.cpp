#include "mainwindow.h"

#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setFixedSize(this->geometry().width(), this->geometry().height());
  defaultSettings();
  setControls();
  setTheme();
  if (QFile::exists("./settings.ini"))
    load_settings();
  else
    default_ui_settings();
  timer = new QTimer;
  image = new QImage[50];
  connect(timer, SIGNAL(timeout()), this, SLOT(makeGif()));
}

void MainWindow::default_ui_settings() {
  changeBtnColor(ui->bgColorBtn, QColor(0, 0, 0, 1));
  changeBtnColor(ui->edgeColorBtn, QColor(255, 255, 255));
  changeBtnColor(ui->vertexColorBtn, QColor(255, 255, 255));
}

void MainWindow::defaultSettings() {
  /*Scroll translation settings*/
  DefaultSettings_Affine(ui->lineTranslationX, ui->translationX,
                         MAX_VALUE_TRANSLATION, MIN_VALUE_TRANSLATION);
  DefaultSettings_Affine(ui->lineTranslationY, ui->translationY,
                         MAX_VALUE_TRANSLATION, MIN_VALUE_TRANSLATION);
  DefaultSettings_Affine(ui->lineTranslationZ, ui->translationZ,
                         MAX_VALUE_TRANSLATION, MIN_VALUE_TRANSLATION);

  /*Scroll rotation settings*/
  DefaultSettings_Affine(ui->lineRotationX, ui->rotationX, MAX_VALUE_ROTATION,
                         MIN_VALUE_ROTATION);
  DefaultSettings_Affine(ui->lineRotationY, ui->rotationY, MAX_VALUE_ROTATION,
                         MIN_VALUE_ROTATION);
  DefaultSettings_Affine(ui->lineRotationZ, ui->rotationZ, MAX_VALUE_ROTATION,
                         MIN_VALUE_ROTATION);

  /*Scalling settings*/
  DefaultSettings_Affine(ui->lineScaling, ui->scaling, MAX_VALUE_SCALING,
                         MIN_VALUE_SCALING);
}

void MainWindow::DefaultSettings_Affine(QLineEdit *line, QScrollBar *scroll,
                                        int max_value, int min_value) {
  line->setText("0");
  scroll->setValue(0);
  scroll->setMinimum(min_value);
  scroll->setMaximum(max_value);
}

void MainWindow::setControls() {
  ui->translationX->setInvertedControls(0);
  ui->translationY->setInvertedControls(0);
  ui->translationZ->setInvertedControls(0);

  ui->rotationX->setInvertedControls(0);
  ui->rotationY->setInvertedControls(0);
  ui->rotationZ->setInvertedControls(0);
}

void MainWindow::setTheme() {
  qApp->setStyle(QStyleFactory::create("Fusion"));
  QPalette p = qApp->palette();
  p.setColor(QPalette::Window, QColor(53, 53, 53));
  p.setColor(QPalette::Button, QColor(53, 53, 53));
  p.setColor(QPalette::Highlight, QColor(142, 45, 197));
  p.setColor(QPalette::ButtonText, QColor(255, 255, 255));
  p.setColor(QPalette::WindowText, QColor(255, 255, 255));
  qApp->setPalette(p);
}

MainWindow::~MainWindow() {
  Destroy(&ui->openGLWidget->obj);
  delete timer;
  delete[] image;
  save_settings();
  delete ui;
}

void MainWindow::changeBtnColor(QPushButton *btn, QColor color) {
  QPalette pal = ui->bgColorBtn->palette();
  pal.setColor(QPalette::Button, color);
  btn->setAutoFillBackground(true);
  btn->setPalette(pal);
  btn->update();
}

void MainWindow::load_settings() {
  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("values");
  ui->openGLWidget->parallel_projection_type =
      settings.value("projectionType").toBool();
  ui->openGLWidget->edgeColorX = settings.value("edgeColorX").toInt();
  ui->openGLWidget->edgeColorY = settings.value("edgeColorY").toInt();
  ui->openGLWidget->edgeColorZ = settings.value("edgeColorZ").toInt();
  ui->openGLWidget->vertexColorX = settings.value("vertexColorX").toInt();
  ui->openGLWidget->vertexColorY = settings.value("vertexColorY").toInt();
  ui->openGLWidget->vertexColorZ = settings.value("vertexColorZ").toInt();
  ui->openGLWidget->bgX = settings.value("bgX").toInt();
  ui->openGLWidget->bgY = settings.value("bgY").toInt();
  ui->openGLWidget->bgZ = settings.value("bgZ").toInt();
  ui->openGLWidget->edgeSize = settings.value("edgeSize").toFloat();
  ui->openGLWidget->solid_edge_type = settings.value("edgeType").toBool();
  ui->openGLWidget->vertexSize = settings.value("vertexSize").toFloat();
  ui->openGLWidget->vertex_type = settings.value("vertexType").toFloat();
  settings.endGroup();
  ui->projectionBox->setCurrentIndex(
      (ui->openGLWidget->parallel_projection_type) ? 0 : 1);
  ui->lineBox->setCurrentIndex((ui->openGLWidget->solid_edge_type) ? 0 : 1);
  ui->displayBox->setCurrentIndex(ui->openGLWidget->vertex_type);
  ui->edgeSizeBox->setValue(ui->openGLWidget->edgeSize);
  ui->vertexSizeBox->setValue(ui->openGLWidget->vertexSize);
  ui->openGLWidget->changeBg();

  changeBtnColor(ui->bgColorBtn,
                 QColor(ui->openGLWidget->bgX, ui->openGLWidget->bgY,
                        ui->openGLWidget->bgZ));
  changeBtnColor(ui->edgeColorBtn, QColor(ui->openGLWidget->edgeColorX,
                                          ui->openGLWidget->edgeColorY,
                                          ui->openGLWidget->edgeColorZ));
  changeBtnColor(ui->vertexColorBtn, QColor(ui->openGLWidget->vertexColorX,
                                            ui->openGLWidget->vertexColorY,
                                            ui->openGLWidget->vertexColorZ));
}

void MainWindow::save_settings() {
  QSettings settings("settings.ini", QSettings::IniFormat);
  settings.beginGroup("values");
  settings.setValue("projectionType",
                    ui->openGLWidget->parallel_projection_type);
  settings.setValue("edgeColorX", ui->openGLWidget->edgeColorX);
  settings.setValue("edgeColorY", ui->openGLWidget->edgeColorY);
  settings.setValue("edgeColorZ", ui->openGLWidget->edgeColorZ);
  settings.setValue("vertexColorX", ui->openGLWidget->vertexColorX);
  settings.setValue("vertexColorY", ui->openGLWidget->vertexColorY);
  settings.setValue("vertexColorZ", ui->openGLWidget->vertexColorZ);
  settings.setValue("bgX", ui->openGLWidget->bgX);
  settings.setValue("bgY", ui->openGLWidget->bgY);
  settings.setValue("bgZ", ui->openGLWidget->bgZ);
  settings.setValue("edgeSize", ui->openGLWidget->edgeSize);
  settings.setValue("edgeType", ui->openGLWidget->solid_edge_type);
  settings.setValue("vertexSize", ui->openGLWidget->vertexSize);
  settings.setValue("vertexType", ui->openGLWidget->vertex_type);
  settings.endGroup();
}

void MainWindow::on_openBtn_clicked() {
  file = QFileDialog::getOpenFileName(this, "Choose a file",
                                      QDir::currentPath(), "*.obj");
  if (!file.isEmpty()) {
    ui->fileText->setText(file);
    obj_t obj;
    int result = TryToInitObj(file.toLocal8Bit().data(), &obj);
    if (result == OK) {
      ui->openGLWidget->obj = obj;
      ui->openGLWidget->repaint();
      qsizetype i = file.lastIndexOf('/') + 1;
      QString name = file.right(file.size() - i);
      ui->infoLabel->setText(
          name + ", vertices: " + QString::number(obj.vertex_n - 1) +
          ", faces: " + QString::number(obj.face_n));
      ui->saveBtn->setEnabled(true);
      ui->gifBtn->setEnabled(true);
    } else {
      QMetaEnum metaEnum = QMetaEnum::fromType<MainWindow::Error>();
      clearWidget();
      ui->infoLabel->setText(metaEnum.valueToKey(result));
    }
  }
}

void MainWindow::clearWidget() {
  if (!ui->fileText->toPlainText().isEmpty()) ui->fileText->setText("");
  if (!ui->infoLabel->text().isEmpty()) ui->infoLabel->setText("");
  Destroy(&ui->openGLWidget->obj);
  ui->openGLWidget->update();
  ui->saveBtn->setEnabled(false);
  ui->gifBtn->setEnabled(false);
  defaultSettings();
}

void MainWindow::on_clearBtn_clicked() { clearWidget(); }

/*signals and functions for translation*/

void MainWindow::on_translationX_valueChanged(int value) {
  ui->openGLWidget->setTranslate(value, IS_X);
  ui->lineTranslationX->setText(QString::number(value));
}

void MainWindow::on_translationY_valueChanged(int value) {
  ui->openGLWidget->setTranslate(value, IS_Y);
  ui->lineTranslationY->setText(QString::number(value));
}

void MainWindow::on_translationZ_valueChanged(int value) {
  ui->openGLWidget->setTranslate(value, IS_Z);
  ui->lineTranslationZ->setText(QString::number(value));
}

void MainWindow::on_lineTranslationX_editingFinished() {
  int value = ui->lineTranslationX->text().toInt();
  setLineTranslation(&value, ui->translationX);
  ui->openGLWidget->setTranslate(value, IS_X);
}

void MainWindow::on_lineTranslationY_editingFinished() {
  int value = ui->lineTranslationY->text().toInt();
  setLineTranslation(&value, ui->translationY);
  ui->openGLWidget->setTranslate(value, IS_Y);
}

void MainWindow::on_lineTranslationZ_editingFinished() {
  int value = ui->lineTranslationZ->text().toInt();
  setLineTranslation(&value, ui->translationZ);
  ui->openGLWidget->setTranslate(value, IS_Z);
}

void MainWindow::setLineTranslation(int *value, QScrollBar *scroll) {
  if (*value < MIN_VALUE_TRANSLATION) {
    *value = MIN_VALUE_TRANSLATION;
  } else if (*value > MAX_VALUE_TRANSLATION) {
    *value = MAX_VALUE_TRANSLATION;
  }
  scroll->setValue(*value);
}

/*signals and functions for rotation*/

void MainWindow::on_rotationX_valueChanged(int value) {
  ui->lineRotationX->setText(QString::number(value));
  RotationSettings();
}

void MainWindow::on_rotationY_valueChanged(int value) {
  ui->lineRotationY->setText(QString::number(value));
  RotationSettings();
}

void MainWindow::on_rotationZ_valueChanged(int value) {
  ui->lineRotationZ->setText(QString::number(value));
  RotationSettings();
}

void MainWindow::on_lineRotationX_editingFinished() {
  int value = ui->lineRotationX->text().toInt();
  setLineRotation(&value, ui->rotationX);
}

void MainWindow::on_lineRotationY_editingFinished() {
  int value = ui->lineRotationY->text().toInt();
  setLineRotation(&value, ui->rotationY);
}

void MainWindow::on_lineRotationZ_editingFinished() {
  int value = ui->lineRotationZ->text().toInt();
  setLineRotation(&value, ui->rotationZ);
}

void MainWindow::setLineRotation(int *value, QScrollBar *scroll) {
  if (*value < MIN_VALUE_ROTATION) {
    *value = MIN_VALUE_ROTATION;
  } else if (*value > MAX_VALUE_ROTATION) {
    *value = MAX_VALUE_ROTATION;
  }
  scroll->setValue(*value);
}

void MainWindow::RotationSettings() {
  int value_x = ui->lineRotationX->text().toInt();
  int value_y = ui->lineRotationY->text().toInt();
  int value_z = ui->lineRotationZ->text().toInt();
  if (!reset) {
    ui->openGLWidget->setRotate(value_x, value_y, value_z);
  }
}

/*signals and functions for scaling*/

void MainWindow::on_scaling_valueChanged(int value) {
  ui->openGLWidget->setScaling(value);
  ui->lineScaling->setText(QString::number(value));
}
void MainWindow::on_lineScaling_editingFinished() {
  int value = ui->lineScaling->text().toInt();
  setLineScaling(&value, ui->scaling);
  ui->openGLWidget->setScaling(value);
}

void MainWindow::setLineScaling(int *value, QScrollBar *scroll) {
  if (*value < MIN_VALUE_SCALING) {
    *value = MIN_VALUE_SCALING;
  } else if (*value > MAX_VALUE_SCALING) {
    *value = MAX_VALUE_SCALING;
  }
  scroll->setValue(*value);
}

/*Signals and functions for settings: color*/

void MainWindow::on_bgColorBtn_clicked() {
  QColor color = QColorDialog::getColor();
  ui->openGLWidget->bgX = color.red();
  ui->openGLWidget->bgY = color.green();
  ui->openGLWidget->bgZ = color.blue();
  ui->openGLWidget->update();
  QPalette pal = ui->bgColorBtn->palette();
  pal.setColor(QPalette::Button, color);
  ui->bgColorBtn->setAutoFillBackground(true);
  ui->bgColorBtn->setPalette(pal);
  ui->bgColorBtn->update();
}

void MainWindow::on_vertexColorBtn_clicked() {
  QColor color = QColorDialog::getColor();
  ui->openGLWidget->vertexColorX = color.red();
  ui->openGLWidget->vertexColorY = color.green();
  ui->openGLWidget->vertexColorZ = color.blue();
  ui->openGLWidget->update();
  QPalette pal = ui->vertexColorBtn->palette();
  pal.setColor(QPalette::Button, color);
  ui->vertexColorBtn->setAutoFillBackground(true);
  ui->vertexColorBtn->setPalette(pal);
  ui->vertexColorBtn->update();
}

void MainWindow::on_edgeColorBtn_clicked() {
  QColor color = QColorDialog::getColor();
  ui->openGLWidget->edgeColorX = color.red();
  ui->openGLWidget->edgeColorY = color.green();
  ui->openGLWidget->edgeColorZ = color.blue();
  ui->openGLWidget->update();
  QPalette pal = ui->edgeColorBtn->palette();
  pal.setColor(QPalette::Button, color);
  ui->edgeColorBtn->setAutoFillBackground(true);
  ui->edgeColorBtn->setPalette(pal);
  ui->edgeColorBtn->update();
}

/*Projection type*/

void MainWindow::on_projectionBox_currentIndexChanged(int index) {
  ui->openGLWidget->parallel_projection_type = (index == 0);
  ui->openGLWidget->repaint();
}

/*Signals and functions for settings: vertex size, type, edge size*/

void MainWindow::on_displayBox_currentIndexChanged(int index) {
  ui->openGLWidget->vertex_type = index;
  ui->openGLWidget->repaint();
}

void MainWindow::on_lineBox_currentIndexChanged(int index) {
  ui->openGLWidget->solid_edge_type = (index == 0);
  ui->openGLWidget->repaint();
}

void MainWindow::on_edgeSizeBox_valueChanged(double arg1) {
  ui->openGLWidget->edgeSize = arg1;
  ui->openGLWidget->repaint();
}

void MainWindow::on_vertexSizeBox_valueChanged(double arg1) {
  ui->openGLWidget->vertexSize = arg1;
  ui->openGLWidget->repaint();
}

/*Recording image*/

void MainWindow::on_saveBtn_clicked() {
  QString path = QFileDialog::getSaveFileName(
      0, "Save an image", QDir::currentPath(), "*.png ;; *.jpg ;; *.bmp");
  if (!path.isEmpty()) {
    ui->openGLWidget->grab().save(path);
  }
}

/*Recording gif*/

void MainWindow::on_gifBtn_clicked() {
  ui->gifBtn->setEnabled(false);
  timer->start(100);
}

void MainWindow::makeGif() {
  if (count_image < 50) {
    image[count_image++] =
        ui->openGLWidget->grab(QRect(QPoint(50, 55), QSize(WIDTH, HEIGHT)))
            .toImage();
  } else {
    gif = new QGifImage();
    for (int i = 0; i < count_image; i++) {
      gif->addFrame(image[i], 0);
    }
    QString path = QFileDialog::getSaveFileName(
        0, "Save GIF", QDir::currentPath(), "GIF (*.gif)");
    if (!path.isEmpty()) {
      gif->save(path);
    }
    timer->stop();
    ui->gifBtn->setEnabled(true);
    delete gif;
    count_image = 0;
  }
}

/*Reset*/

void MainWindow::on_resetButton_clicked() {
  obj_t obj;
  TryToInitObj(file.toLocal8Bit().data(), &obj);
  ui->openGLWidget->obj = obj;
  ui->openGLWidget->resetTransformations();
  reset = 1;
  defaultSettings();
  reset = 0;
}
