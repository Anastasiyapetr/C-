/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <qcustomplot.h>

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator {
 public:
  QWidget *centralwidget;
  QStackedWidget *stackedWidget;
  QWidget *page;
  QLineEdit *lineEdit;
  QPushButton *pushButton_47;
  QPushButton *pushButton_41;
  QPushButton *pushButton_6;
  QPushButton *pushButton_43;
  QPushButton *pushButton_AC;
  QPushButton *pushButton_46;
  QPushButton *pushButton_C;
  QPushButton *pushButton_bracket_1;
  QPushButton *pushButton_5;
  QPushButton *pushButton_39;
  QPushButton *pushButton_40;
  QPushButton *pushButton_42;
  QPushButton *pushButton_bracket_2;
  QPushButton *pushButton_x;
  QPushButton *pushButton_negate;
  QPushButton *pushButton_28;
  QPushButton *pushButton_mult;
  QPushButton *pushButton_4;
  QPushButton *pushButton_31;
  QPushButton *pushButton_22;
  QPushButton *pushButton_38;
  QPushButton *pushButton_37;
  QPushButton *pushButton_36;
  QPushButton *pushButton_33;
  QPushButton *pushButton_eq;
  QPushButton *pushButton_27;
  QPushButton *pushButton_30;
  QPushButton *pushButton_26;
  QPushButton *pushButton_24;
  QPushButton *pushButton_32;
  QPushButton *pushButton_25;
  QPushButton *pushButton_29;
  QPushButton *pushButton_dot;
  QLineEdit *lineEdit_2;
  QPushButton *pushButton_graph;
  QCustomPlot *graph;
  QLineEdit *lineEdit_xmax;
  QPushButton *pushButton_xmax;
  QLineEdit *lineEdit_xmin;
  QPushButton *pushButton_xmin;
  QComboBox *comboBox_menu;
  QWidget *page_2;
  QLineEdit *lineEdit_rate;
  QLineEdit *lineEdit_amount;
  QComboBox *comboBox_term;
  QPushButton *pushButton_calculate;
  QRadioButton *radioButton_ann;
  QRadioButton *radioButton_diff;
  QTextEdit *textEdit_result;
  QLabel *label;
  QLabel *label_2;
  QLabel *label_3;
  QLabel *label_4;
  QLineEdit *lineEdit_term;
  QComboBox *comboBox_menu2;
  QButtonGroup *digits;
  QButtonGroup *arithmetic;
  QButtonGroup *functions;

  void setupUi(QMainWindow *Calculator) {
    if (Calculator->objectName().isEmpty())
      Calculator->setObjectName(QString::fromUtf8("Calculator"));
    Calculator->resize(967, 380);
    centralwidget = new QWidget(Calculator);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    stackedWidget = new QStackedWidget(centralwidget);
    stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
    stackedWidget->setGeometry(QRect(0, 0, 961, 401));
    page = new QWidget();
    page->setObjectName(QString::fromUtf8("page"));
    lineEdit = new QLineEdit(page);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setGeometry(QRect(3, 3, 438, 61));
    lineEdit->setStyleSheet(
        QString::fromUtf8("QLineEdit {\n"
                          "	background-color: rgb(189, 189, 189);\n"
                          "	font: 18pt \"Serif\";\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    lineEdit->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                           Qt::AlignVCenter);
    pushButton_47 = new QPushButton(page);
    functions = new QButtonGroup(Calculator);
    functions->setObjectName(QString::fromUtf8("functions"));
    functions->addButton(pushButton_47);
    pushButton_47->setObjectName(QString::fromUtf8("pushButton_47"));
    pushButton_47->setGeometry(QRect(3, 316, 60, 60));
    pushButton_47->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_41 = new QPushButton(page);
    functions->addButton(pushButton_41);
    pushButton_41->setObjectName(QString::fromUtf8("pushButton_41"));
    pushButton_41->setGeometry(QRect(129, 192, 60, 60));
    pushButton_41->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_6 = new QPushButton(page);
    functions->addButton(pushButton_6);
    pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
    pushButton_6->setGeometry(QRect(129, 130, 60, 60));
    pushButton_6->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_43 = new QPushButton(page);
    functions->addButton(pushButton_43);
    pushButton_43->setObjectName(QString::fromUtf8("pushButton_43"));
    pushButton_43->setGeometry(QRect(66, 254, 60, 60));
    pushButton_43->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_AC = new QPushButton(page);
    pushButton_AC->setObjectName(QString::fromUtf8("pushButton_AC"));
    pushButton_AC->setGeometry(QRect(66, 67, 123, 60));
    pushButton_AC->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(35, 6, 150);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_46 = new QPushButton(page);
    functions->addButton(pushButton_46);
    pushButton_46->setObjectName(QString::fromUtf8("pushButton_46"));
    pushButton_46->setGeometry(QRect(66, 316, 60, 60));
    pushButton_46->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_C = new QPushButton(page);
    pushButton_C->setObjectName(QString::fromUtf8("pushButton_C"));
    pushButton_C->setGeometry(QRect(3, 67, 60, 60));
    pushButton_C->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(35, 6, 150);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_bracket_1 = new QPushButton(page);
    pushButton_bracket_1->setObjectName(
        QString::fromUtf8("pushButton_bracket_1"));
    pushButton_bracket_1->setGeometry(QRect(3, 130, 60, 60));
    pushButton_bracket_1->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_5 = new QPushButton(page);
    functions->addButton(pushButton_5);
    pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
    pushButton_5->setGeometry(QRect(3, 192, 60, 60));
    pushButton_5->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_39 = new QPushButton(page);
    functions->addButton(pushButton_39);
    pushButton_39->setObjectName(QString::fromUtf8("pushButton_39"));
    pushButton_39->setGeometry(QRect(3, 254, 60, 60));
    pushButton_39->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_40 = new QPushButton(page);
    functions->addButton(pushButton_40);
    pushButton_40->setObjectName(QString::fromUtf8("pushButton_40"));
    pushButton_40->setGeometry(QRect(129, 254, 60, 60));
    pushButton_40->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_42 = new QPushButton(page);
    functions->addButton(pushButton_42);
    pushButton_42->setObjectName(QString::fromUtf8("pushButton_42"));
    pushButton_42->setGeometry(QRect(66, 192, 60, 60));
    pushButton_42->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_bracket_2 = new QPushButton(page);
    pushButton_bracket_2->setObjectName(
        QString::fromUtf8("pushButton_bracket_2"));
    pushButton_bracket_2->setGeometry(QRect(66, 130, 60, 60));
    pushButton_bracket_2->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_x = new QPushButton(page);
    pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
    pushButton_x->setGeometry(QRect(129, 316, 60, 60));
    pushButton_x->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	border-left-width: 1.5px;\n"
                          "border-bottom-width:1.5px;\n"
                          "border-top-width: 1.5px;\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(213, 154, 16);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_negate = new QPushButton(page);
    pushButton_negate->setObjectName(QString::fromUtf8("pushButton_negate"));
    pushButton_negate->setGeometry(QRect(192, 67, 60, 60));
    pushButton_negate->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_28 = new QPushButton(page);
    digits = new QButtonGroup(Calculator);
    digits->setObjectName(QString::fromUtf8("digits"));
    digits->addButton(pushButton_28);
    pushButton_28->setObjectName(QString::fromUtf8("pushButton_28"));
    pushButton_28->setGeometry(QRect(192, 130, 60, 60));
    pushButton_28->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	background-color: rgb(189, 189, 189);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_mult = new QPushButton(page);
    arithmetic = new QButtonGroup(Calculator);
    arithmetic->setObjectName(QString::fromUtf8("arithmetic"));
    arithmetic->addButton(pushButton_mult);
    pushButton_mult->setObjectName(QString::fromUtf8("pushButton_mult"));
    pushButton_mult->setGeometry(QRect(381, 130, 60, 60));
    pushButton_mult->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_4 = new QPushButton(page);
    arithmetic->addButton(pushButton_4);
    pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
    pushButton_4->setGeometry(QRect(318, 67, 60, 60));
    pushButton_4->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_31 = new QPushButton(page);
    digits->addButton(pushButton_31);
    pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));
    pushButton_31->setGeometry(QRect(318, 254, 60, 60));
    pushButton_31->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	background-color: rgb(189, 189, 189);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_22 = new QPushButton(page);
    arithmetic->addButton(pushButton_22);
    pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
    pushButton_22->setGeometry(QRect(381, 254, 60, 60));
    pushButton_22->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_38 = new QPushButton(page);
    arithmetic->addButton(pushButton_38);
    pushButton_38->setObjectName(QString::fromUtf8("pushButton_38"));
    pushButton_38->setGeometry(QRect(381, 192, 60, 60));
    pushButton_38->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_37 = new QPushButton(page);
    digits->addButton(pushButton_37);
    pushButton_37->setObjectName(QString::fromUtf8("pushButton_37"));
    pushButton_37->setGeometry(QRect(255, 130, 60, 60));
    pushButton_37->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	background-color: rgb(189, 189, 189);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_36 = new QPushButton(page);
    digits->addButton(pushButton_36);
    pushButton_36->setObjectName(QString::fromUtf8("pushButton_36"));
    pushButton_36->setGeometry(QRect(318, 192, 60, 60));
    pushButton_36->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	background-color: rgb(189, 189, 189);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_33 = new QPushButton(page);
    digits->addButton(pushButton_33);
    pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));
    pushButton_33->setGeometry(QRect(192, 254, 60, 60));
    pushButton_33->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	background-color: rgb(189, 189, 189);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_eq = new QPushButton(page);
    pushButton_eq->setObjectName(QString::fromUtf8("pushButton_eq"));
    pushButton_eq->setGeometry(QRect(381, 316, 60, 60));
    pushButton_eq->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(35, 6, 150);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_27 = new QPushButton(page);
    arithmetic->addButton(pushButton_27);
    pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));
    pushButton_27->setGeometry(QRect(255, 67, 60, 60));
    pushButton_27->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_30 = new QPushButton(page);
    digits->addButton(pushButton_30);
    pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));
    pushButton_30->setGeometry(QRect(318, 130, 60, 60));
    pushButton_30->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	background-color: rgb(189, 189, 189);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_26 = new QPushButton(page);
    digits->addButton(pushButton_26);
    pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));
    pushButton_26->setGeometry(QRect(255, 316, 60, 60));
    pushButton_26->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	background-color: rgb(189, 189, 189);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_24 = new QPushButton(page);
    digits->addButton(pushButton_24);
    pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));
    pushButton_24->setGeometry(QRect(255, 254, 60, 60));
    pushButton_24->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	background-color: rgb(189, 189, 189);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_32 = new QPushButton(page);
    digits->addButton(pushButton_32);
    pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));
    pushButton_32->setGeometry(QRect(255, 192, 60, 60));
    pushButton_32->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	background-color: rgb(189, 189, 189);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_25 = new QPushButton(page);
    digits->addButton(pushButton_25);
    pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));
    pushButton_25->setGeometry(QRect(192, 192, 60, 60));
    pushButton_25->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	background-color: rgb(189, 189, 189);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_29 = new QPushButton(page);
    arithmetic->addButton(pushButton_29);
    pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));
    pushButton_29->setGeometry(QRect(381, 67, 60, 60));
    pushButton_29->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    pushButton_dot = new QPushButton(page);
    pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
    pushButton_dot->setGeometry(QRect(318, 316, 60, 60));
    pushButton_dot->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(255, 255, 255);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	border-width: 1.5px;\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    lineEdit_2 = new QLineEdit(page);
    lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
    lineEdit_2->setGeometry(QRect(189, 316, 64, 60));
    lineEdit_2->setStyleSheet(
        QString::fromUtf8("QLineEdit {\n"
                          "	\n"
                          "	background-color: rgb(213, 154, 16);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	border-right-width: 1.5px;\n"
                          "border-bottom-width:1.5px;\n"
                          "border-top-width: 1.5px;\n"
                          "\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    lineEdit_2->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                             Qt::AlignVCenter);
    pushButton_graph = new QPushButton(page);
    pushButton_graph->setObjectName(QString::fromUtf8("pushButton_graph"));
    pushButton_graph->setGeometry(QRect(625, 331, 141, 44));
    pushButton_graph->setStyleSheet(QString::fromUtf8(
        "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, "
        "stop:0 rgba(131, 80, 18, 255), stop:1 rgba(255, 255, 255, 255));\n"
        "	font: 14pt \"Serif\";\n"
        "	\n"
        "	font: bold;\n"
        "	\n"
        "color: rgb(255, 255, 255);\n"
        "	border-width: 1.5px;\n"
        "border-color: white;\n"
        "    border-style: solid;"));
    graph = new QCustomPlot(page);
    graph->setObjectName(QString::fromUtf8("graph"));
    graph->setGeometry(QRect(446, 50, 501, 281));
    lineEdit_xmax = new QLineEdit(page);
    lineEdit_xmax->setObjectName(QString::fromUtf8("lineEdit_xmax"));
    lineEdit_xmax->setGeometry(QRect(896, 340, 50, 35));
    lineEdit_xmax->setStyleSheet(
        QString::fromUtf8("QLineEdit {\n"
                          "	\n"
                          "	background-color: rgb(213, 154, 16);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	border-right-width: 1.5px;\n"
                          "border-bottom-width:1.5px;\n"
                          "border-top-width: 1.5px;\n"
                          "\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    lineEdit_xmax->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                                Qt::AlignVCenter);
    pushButton_xmax = new QPushButton(page);
    pushButton_xmax->setObjectName(QString::fromUtf8("pushButton_xmax"));
    pushButton_xmax->setGeometry(QRect(836, 340, 61, 35));
    pushButton_xmax->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	border-left-width: 1.5px;\n"
                          "border-bottom-width:1.5px;\n"
                          "border-top-width: 1.5px;\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(213, 154, 16);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    lineEdit_xmin = new QLineEdit(page);
    lineEdit_xmin->setObjectName(QString::fromUtf8("lineEdit_xmin"));
    lineEdit_xmin->setGeometry(QRect(507, 340, 51, 35));
    lineEdit_xmin->setStyleSheet(
        QString::fromUtf8("QLineEdit {\n"
                          "	\n"
                          "	background-color: rgb(213, 154, 16);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	border-right-width: 1.5px;\n"
                          "border-bottom-width:1.5px;\n"
                          "border-top-width: 1.5px;\n"
                          "\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    lineEdit_xmin->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                                Qt::AlignVCenter);
    pushButton_xmin = new QPushButton(page);
    pushButton_xmin->setObjectName(QString::fromUtf8("pushButton_xmin"));
    pushButton_xmin->setGeometry(QRect(446, 340, 61, 35));
    pushButton_xmin->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	border-left-width: 1.5px;\n"
                          "border-bottom-width:1.5px;\n"
                          "border-top-width: 1.5px;\n"
                          "	\n"
                          "	\n"
                          "	background-color: rgb(213, 154, 16);\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	color: rgb(0, 0, 0);\n"
                          "	\n"
                          "    border-style: solid;\n"
                          "    border-color: black;\n"
                          "}"));
    comboBox_menu = new QComboBox(page);
    QIcon icon;
    icon.addFile(QString::fromUtf8("../icon.png"), QSize(), QIcon::Normal,
                 QIcon::On);
    comboBox_menu->addItem(icon, QString());
    comboBox_menu->addItem(QString());
    comboBox_menu->setObjectName(QString::fromUtf8("comboBox_menu"));
    comboBox_menu->setGeometry(QRect(710, 3, 251, 41));
    comboBox_menu->setStyleSheet(
        QString::fromUtf8("color: rgb(0, 0, 0);\n"
                          "font: 14pt \"Serif\";\n"
                          ""));
    stackedWidget->addWidget(page);
    page_2 = new QWidget();
    page_2->setObjectName(QString::fromUtf8("page_2"));
    page_2->setStyleSheet(QString::fromUtf8("background-color: #22222e;"));
    lineEdit_rate = new QLineEdit(page_2);
    lineEdit_rate->setObjectName(QString::fromUtf8("lineEdit_rate"));
    lineEdit_rate->setGeometry(QRect(230, 140, 200, 31));
    lineEdit_rate->setStyleSheet(
        QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
                          "font: 11pt \"Serif\";"));
    lineEdit_amount = new QLineEdit(page_2);
    lineEdit_amount->setObjectName(QString::fromUtf8("lineEdit_amount"));
    lineEdit_amount->setGeometry(QRect(230, 40, 200, 31));
    lineEdit_amount->setStyleSheet(
        QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
                          "font: 11pt \"Serif\";"));
    comboBox_term = new QComboBox(page_2);
    comboBox_term->addItem(QString());
    comboBox_term->addItem(QString());
    comboBox_term->setObjectName(QString::fromUtf8("comboBox_term"));
    comboBox_term->setGeometry(QRect(360, 90, 71, 31));
    comboBox_term->setStyleSheet(
        QString::fromUtf8("color: rgb(255, 255, 255);"));
    pushButton_calculate = new QPushButton(page_2);
    pushButton_calculate->setObjectName(
        QString::fromUtf8("pushButton_calculate"));
    pushButton_calculate->setGeometry(QRect(10, 310, 421, 44));
    pushButton_calculate->setStyleSheet(
        QString::fromUtf8("\n"
                          "	font: 14pt \"Serif\";\n"
                          "	\n"
                          "	font: bold;\n"
                          "	\n"
                          "color: rgb(255, 255, 255);\n"
                          "	border-width: 1.5px;\n"
                          "border-color: white;\n"
                          "    border-style: solid;"));
    radioButton_ann = new QRadioButton(page_2);
    radioButton_ann->setObjectName(QString::fromUtf8("radioButton_ann"));
    radioButton_ann->setGeometry(QRect(230, 190, 200, 21));
    radioButton_ann->setStyleSheet(
        QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
                          "font: 11pt \"Serif\";"));
    radioButton_ann->setChecked(true);
    radioButton_diff = new QRadioButton(page_2);
    radioButton_diff->setObjectName(QString::fromUtf8("radioButton_diff"));
    radioButton_diff->setGeometry(QRect(230, 220, 200, 21));
    radioButton_diff->setStyleSheet(
        QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
                          "font: 11pt \"Serif\";"));
    textEdit_result = new QTextEdit(page_2);
    textEdit_result->setObjectName(QString::fromUtf8("textEdit_result"));
    textEdit_result->setGeometry(QRect(450, 50, 511, 321));
    textEdit_result->setStyleSheet(
        QString::fromUtf8("color: rgb(255, 255, 255);\n"
                          "font: 9pt \"Serif\";"));
    label = new QLabel(page_2);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(10, 40, 200, 31));
    label->setStyleSheet(
        QString::fromUtf8("background-color: #22222e;\n"
                          "font: 11pt \"Serif\";\n"
                          "color: rgb(255, 255, 255);"));
    label_2 = new QLabel(page_2);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 90, 200, 31));
    label_2->setStyleSheet(
        QString::fromUtf8("background-color: #22222e;\n"
                          "font: 11pt \"Serif\";\n"
                          "color: rgb(255, 255, 255);"));
    label_3 = new QLabel(page_2);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(10, 140, 200, 31));
    label_3->setStyleSheet(
        QString::fromUtf8("background-color: #22222e;\n"
                          "font: 11pt \"Serif\";\n"
                          "color: rgb(255, 255, 255);"));
    label_4 = new QLabel(page_2);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(10, 190, 200, 31));
    label_4->setStyleSheet(
        QString::fromUtf8("background-color: #22222e;\n"
                          "font: 11pt \"Serif\";\n"
                          "color: rgb(255, 255, 255);"));
    lineEdit_term = new QLineEdit(page_2);
    lineEdit_term->setObjectName(QString::fromUtf8("lineEdit_term"));
    lineEdit_term->setGeometry(QRect(230, 90, 121, 31));
    lineEdit_term->setStyleSheet(
        QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
                          "font: 11pt \"Serif\";"));
    comboBox_menu2 = new QComboBox(page_2);
    QIcon icon1;
    icon1.addFile(QString::fromUtf8("../icon2.png"), QSize(), QIcon::Normal,
                  QIcon::On);
    comboBox_menu2->addItem(icon1, QString());
    comboBox_menu2->addItem(QString());
    comboBox_menu2->setObjectName(QString::fromUtf8("comboBox_menu2"));
    comboBox_menu2->setGeometry(QRect(710, 3, 251, 41));
    comboBox_menu2->setStyleSheet(
        QString::fromUtf8("color: rgb(255, 255, 255);\n"
                          "font: 14pt \"Serif\";\n"
                          ""));
    stackedWidget->addWidget(page_2);
    Calculator->setCentralWidget(centralwidget);

    retranslateUi(Calculator);

    stackedWidget->setCurrentIndex(1);

    QMetaObject::connectSlotsByName(Calculator);
  }  // setupUi

  void retranslateUi(QMainWindow *Calculator) {
    Calculator->setWindowTitle(
        QCoreApplication::translate("Calculator", "MainWindow", nullptr));
    lineEdit->setText(QCoreApplication::translate("Calculator", "0", nullptr));
    pushButton_47->setText(
        QCoreApplication::translate("Calculator", "ln", nullptr));
    pushButton_41->setText(
        QCoreApplication::translate("Calculator", "tan", nullptr));
    pushButton_6->setText(
        QCoreApplication::translate("Calculator", "sqrt", nullptr));
    pushButton_43->setText(
        QCoreApplication::translate("Calculator", "asin", nullptr));
    pushButton_AC->setText(
        QCoreApplication::translate("Calculator", "Backspace", nullptr));
    pushButton_46->setText(
        QCoreApplication::translate("Calculator", "log", nullptr));
    pushButton_C->setText(
        QCoreApplication::translate("Calculator", "C", nullptr));
    pushButton_bracket_1->setText(
        QCoreApplication::translate("Calculator", "(", nullptr));
    pushButton_5->setText(
        QCoreApplication::translate("Calculator", "sin", nullptr));
    pushButton_39->setText(
        QCoreApplication::translate("Calculator", "acos", nullptr));
    pushButton_40->setText(
        QCoreApplication::translate("Calculator", "atan", nullptr));
    pushButton_42->setText(
        QCoreApplication::translate("Calculator", "cos", nullptr));
    pushButton_bracket_2->setText(
        QCoreApplication::translate("Calculator", ")", nullptr));
    pushButton_x->setText(
        QCoreApplication::translate("Calculator", "x", nullptr));
    pushButton_negate->setText(
        QCoreApplication::translate("Calculator", "+/-", nullptr));
    pushButton_28->setText(
        QCoreApplication::translate("Calculator", "7", nullptr));
    pushButton_mult->setText(
        QCoreApplication::translate("Calculator", "*", nullptr));
    pushButton_4->setText(
        QCoreApplication::translate("Calculator", "mod", nullptr));
    pushButton_31->setText(
        QCoreApplication::translate("Calculator", "3", nullptr));
    pushButton_22->setText(
        QCoreApplication::translate("Calculator", "+", nullptr));
    pushButton_38->setText(
        QCoreApplication::translate("Calculator", "-", nullptr));
    pushButton_37->setText(
        QCoreApplication::translate("Calculator", "8", nullptr));
    pushButton_36->setText(
        QCoreApplication::translate("Calculator", "6", nullptr));
    pushButton_33->setText(
        QCoreApplication::translate("Calculator", "1", nullptr));
    pushButton_eq->setText(
        QCoreApplication::translate("Calculator", "=", nullptr));
    pushButton_27->setText(
        QCoreApplication::translate("Calculator", "^", nullptr));
    pushButton_30->setText(
        QCoreApplication::translate("Calculator", "9", nullptr));
    pushButton_26->setText(
        QCoreApplication::translate("Calculator", "0", nullptr));
    pushButton_24->setText(
        QCoreApplication::translate("Calculator", "2", nullptr));
    pushButton_32->setText(
        QCoreApplication::translate("Calculator", "5", nullptr));
    pushButton_25->setText(
        QCoreApplication::translate("Calculator", "4", nullptr));
    pushButton_29->setText(
        QCoreApplication::translate("Calculator", "/", nullptr));
    pushButton_dot->setText(
        QCoreApplication::translate("Calculator", ".", nullptr));
    lineEdit_2->setText(QString());
    pushButton_graph->setText(
        QCoreApplication::translate("Calculator", "Plot", nullptr));
    lineEdit_xmax->setText(QString());
    pushButton_xmax->setText(
        QCoreApplication::translate("Calculator", "Xmax", nullptr));
    lineEdit_xmin->setText(QString());
    pushButton_xmin->setText(
        QCoreApplication::translate("Calculator", "Xmin", nullptr));
    comboBox_menu->setItemText(
        0, QCoreApplication::translate("Calculator", "Calculator", nullptr));
    comboBox_menu->setItemText(
        1, QCoreApplication::translate("Calculator", "Credit Calculator",
                                       nullptr));

    comboBox_term->setItemText(
        0, QCoreApplication::translate("Calculator", "years", nullptr));
    comboBox_term->setItemText(
        1, QCoreApplication::translate("Calculator", "month", nullptr));

    pushButton_calculate->setText(
        QCoreApplication::translate("Calculator", "Calculate", nullptr));
    radioButton_ann->setText(
        QCoreApplication::translate("Calculator", "Annuity", nullptr));
    radioButton_diff->setText(
        QCoreApplication::translate("Calculator", "Differentiated", nullptr));
    label->setText(QCoreApplication::translate("Calculator",
                                               "Total credit amount", nullptr));
    label_2->setText(
        QCoreApplication::translate("Calculator", "Term", nullptr));
    label_3->setText(
        QCoreApplication::translate("Calculator", "Insert rate (%)", nullptr));
    label_4->setText(
        QCoreApplication::translate("Calculator", "Type", nullptr));
    comboBox_menu2->setItemText(
        0, QCoreApplication::translate("Calculator", "Credit Calculator",
                                       nullptr));
    comboBox_menu2->setItemText(
        1, QCoreApplication::translate("Calculator", "Calculator", nullptr));

  }  // retranslateUi
};

namespace Ui {
class Calculator : public Ui_Calculator {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_CALCULATOR_H
