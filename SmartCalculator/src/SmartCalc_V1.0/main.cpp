#include <QApplication>

#include "calculator.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Calculator w;
  w.setWindowTitle("SmartCalculator");

  w.show();
  return a.exec();
}
