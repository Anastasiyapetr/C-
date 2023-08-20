#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QAbstractButton>
#include <QMainWindow>
#include <QMessageBox>
#include <QStackedWidget>
#include <QtDebug>
#include <QtGui>
#include <QtWidgets>
#include <cstring>

#define MAX_LEN 255

extern "C" {
#include "../backend/credit_calculator.h"
#include "../backend/smartCalc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow {
  Q_OBJECT

 public:
  Calculator(QWidget *parent = nullptr);
  ~Calculator();
  void DefaultSettings();
  bool CheckLen();

 public slots:
  void digit_numbers(QAbstractButton *btn);
  void arithmetic(QAbstractButton *btn);
  void functions(QAbstractButton *btn);
  void clear();
  void clean();
  void dot();
  void negate();
  void bracket();
  void backbracket();
  void equal();
  void iks();
  void credit();
  void calc();
  void graph();
  void on_lineEdit_2_selectionChanged();
  void on_lineEdit_2_textChanged(const QString &arg1);
  void on_lineEdit_xmax_textChanged(const QString &arg1);
  void on_lineEdit_xmin_textChanged(const QString &arg1);

  /*credit calculator*/

  void on_lineEdit_amount_textChanged(const QString &arg1);
  void on_lineEdit_term_textChanged(const QString &arg1);
  void on_lineEdit_rate_textChanged(const QString &arg1);
  void create_rezult();
  void credit_calc();
  void finished_rezult(double sum, double total_md, double total_pd);
  void on_lineEdit_amount_selectionChanged();
  void on_lineEdit_term_selectionChanged();
  void on_lineEdit_rate_selectionChanged();
  void on_comboBox_menu2_activated(int index);
  void on_comboBox_menu_activated(int index);

 private:
  QString string;
  int index_dot = 0;
  int index_arith = -100;
  int index_func = -100;
  int len_func = 0;
  QString x;
  double arg = 0.0;
  int use_x = 0;
  QVector<double> x1, y1, x2, y2;
  double xmax = 100, xmin = -100;

  QString x_max = "100", x_min = "-100";

  /*credit calculator*/

  QString amount, rate, term;
  double sum = 0, proc = 0;
  int years = 0, type_term = -1;
  double total_md = 0, total_pd = 0, overpayment = 0;
  int type = 0;  // 1 - annyity, 2 - diff;
  QString rezult;

  Ui::Calculator *ui;
};
#endif  // CALCULATOR_H
