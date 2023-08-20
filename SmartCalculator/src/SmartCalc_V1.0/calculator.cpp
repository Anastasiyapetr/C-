#include "calculator.h"

#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Calculator) {
  ui->setupUi(this);
  DefaultSettings();
  connect(ui->digits, &QButtonGroup::buttonClicked, this,
          &::Calculator::digit_numbers);
  connect(ui->arithmetic, &QButtonGroup::buttonClicked, this,
          &::Calculator::arithmetic);
  connect(ui->functions, &QButtonGroup::buttonClicked, this,
          &::Calculator::functions);
  connect(ui->pushButton_C, &QPushButton::clicked, this, &Calculator::clear);
  connect(ui->pushButton_AC, &QPushButton::clicked, this, &Calculator::clean);
  connect(ui->pushButton_dot, &QPushButton::clicked, this, &Calculator::dot);
  connect(ui->pushButton_negate, &QPushButton::clicked, this,
          &Calculator::negate);

  connect(ui->pushButton_bracket_1, &QPushButton::clicked, this,
          &Calculator::bracket);
  connect(ui->pushButton_bracket_2, &QPushButton::clicked, this,
          &Calculator::backbracket);
  connect(ui->pushButton_eq, &QPushButton::clicked, this, &Calculator::equal);
  connect(ui->pushButton_x, &QPushButton::clicked, this, &Calculator::iks);
  connect(ui->pushButton_graph, &QPushButton::clicked, this,
          &Calculator::graph);

  /*credit calculator*/
  connect(ui->pushButton_calculate, &QPushButton::clicked, this,
          &Calculator::credit_calc);
}

void Calculator::DefaultSettings() {
  string = "0";
  x = "0";
  term = "0";
  amount = "0";
  rate = "0";
  ui->lineEdit->setText(string);
  ui->lineEdit_2->setText(x);
  ui->lineEdit_xmax->setText(x_max);
  ui->lineEdit_xmin->setText(x_min);
  ui->stackedWidget->setCurrentIndex(0);
  ui->lineEdit_term->setText(term);
  ui->lineEdit_amount->setText(amount);
  ui->lineEdit_rate->setText(rate);
};

Calculator::~Calculator() { delete ui; }

bool Calculator::CheckLen() { return string.size() < MAX_LEN; }

void Calculator::digit_numbers(QAbstractButton *btn) {
  if (x != "Invalid value x" && CheckLen()) {
    if ((string.isEmpty() && btn->text() != "0") || (!string.isEmpty())) {
      QString digit = btn->text();
      if (string.size() == 1 && string[0] == QChar('0')) {
        string.clear();
      }
      if ((string.size() != 0) && (string[string.size() - 1] == QChar('x') ||
                                   string[string.size() - 1] == QChar(')'))) {
        string.append(ui->pushButton_mult->text());
      }
      string.append(digit);
      ui->lineEdit->setText(string);
    }
  }
}

void Calculator::arithmetic(QAbstractButton *btn) {
  if (x != "Invalid value x" && CheckLen()) {
    if (((string[string.size() - 1] != QChar('(')) ||
         (string[string.size() - 1] == QChar('(') && (btn->text() == "-"))) &&
        (string[string.size() - 1] != QChar('.'))) {
      QString digit = btn->text();
      string.append(digit);
      int index = string.size() - 1;
      if ((index - 1 == index_arith) ||
          (index - 3 == index_arith && string[index] == QChar('d'))) {
        if (string[index_arith] == QChar('d')) {
          string.remove(index_arith - 2, 3);
        } else {
          string.remove(index_arith, 1);
        }
      }
      index_arith = string.size() - 1;
      ui->lineEdit->setText(string);
    }
  }
}

void Calculator::dot() {
  if (x != "Invalid value x" && CheckLen()) {
    int flag = 1;
    if (string.contains(".", Qt::CaseInsensitive)) {
      for (int i = index_dot; i < string.size(); i++) {
        if (string.at(i) < QChar('0') || string.at(i) > QChar('9')) flag = 0;
      }
    } else {
      flag = 0;
    }
    if (!flag) {
      QString digit;
      digit.resize(2);
      if ((string.isEmpty()) || (string.at(string.size() - 1) < QChar('0') ||
                                 string.at(string.size() - 1) > QChar('9'))) {
        digit[0] = QChar('0');
        digit[1] = QChar('.');
      } else {
        digit.resize(1);
        digit[0] = QChar('.');
      }
      string += digit;
      ui->lineEdit->setText(string);
      index_dot = string.size();
    }
  }
}

void Calculator::clear() {
  if (x != "Invalid value x") {
    string.clear();
    string.append("0");
    ui->lineEdit->setText(string);
  }
}

void Calculator::clean() {
  if (x != "Invalid value x") {
    int index = string.size() - 1;
    if (string.size() != 0) {
      if (string[index] == QChar('d')) {
        string.remove(index - 2, 3);
      } else if (string[index] == QChar('n') || string[index] == QChar('s') ||
                 string[index] == QChar('g') || string[index] == QChar('t')) {
        string.remove(index_func - len_func, len_func);
      } else {
        string.remove(index, 1);
      }
      if (string.size() == 0) {
        string.append("0");
      }
      ui->lineEdit->setText(string);
    }
  }
}

void Calculator::negate() {
  if (x != "Invalid value x" && CheckLen()) {
    int flag = 0;
    if ((string.size() != 0) ||
        (string.size() == 1 && string[0] != QChar('0'))) {
      for (int i = string.size() - 1; i >= 0 && !flag; i--) {
        if ((string[i] < QChar('0') || string[i] > QChar('9')) &&
            (string[i] != QChar('-')) && (string[i] != QChar('.')) &&
            (string[i] != QChar('('))) {
          string.insert(i + 1, "-");
          if (i == index_arith) {
            string.insert(i + 1, '(');
          }
          if (string[string.size() - 1] >= QChar('0') &&
              string[string.size() - 1] <= QChar('9')) {
            string.append(")");
          }
          flag = 1;
        } else if (string[i] == QChar('-') && i != 0) {
          if (string[i - 1] >= QChar('0') && string[i - 1] <= QChar('9')) {
            string.replace(i, 1, '+');
          }
          flag = 1;
        } else if (i == 0 &&
                   (string[i] >= QChar('0') && string[i] <= QChar('9'))) {
          string.prepend("-");
          flag = 1;
        } else if ((i == 0) && (string[i] == QChar('-'))) {
          string.remove(0, 1);
          flag = 1;
        }
      }
      ui->lineEdit->setText(string);
    }
  }
}

void Calculator::bracket() {
  if (x != "Invalid value x" && CheckLen()) {
    if (string.size() == 1 && string[0] == QChar('0')) {
      string.clear();

    } else if ((string[string.size() - 1] >= QChar('0') &&
                string[string.size() - 1] <= QChar('9')) ||
               (string[string.size() - 1] == QChar(')'))) {
      string.append(ui->pushButton_mult->text());
    }
    if ((string.size() == 0) ||
        (string.size() > 0 && string[string.size() - 1] != QChar('.'))) {
      QString digit = ui->pushButton_bracket_1->text();
      string.append(digit);
      ui->lineEdit->setText(string);
    }
  }
}

void Calculator::backbracket() {
  if (x != "Invalid value x" && CheckLen()) {
    int flag = 0;
    for (int i = string.size() - 1; i >= 0; i--) {
      if (string[i] == QChar('(')) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      QString digit = ui->pushButton_bracket_2->text();
      string.append(digit);
      if (string[string.size() - 1] == QChar(')') &&
          string[string.size() - 2] == QChar('(')) {
        string.insert(string.size() - 1, "0");
      }
      ui->lineEdit->setText(string);
    }
  }
}

void Calculator::functions(QAbstractButton *btn) {
  if (x != "Invalid value x" && CheckLen()) {
    if (string.size() == 1 && string[0] == QChar('0')) {
      string.clear();
    }

    if ((string.size() == 0) ||
        (string.size() > 0 && string[string.size() - 1] != QChar('.'))) {
      QString digit = btn->text();
      len_func = digit.size();
      if ((string.size() > 0) && ((string[string.size() - 1] == QChar(')')) ||
                                  (string[string.size() - 1] >= QChar('0') &&
                                   string[string.size() - 1] <= QChar('9')))) {
        digit.prepend(ui->pushButton_mult->text());
      }
      digit.append("(");
      string.append(digit);
      index_func = string.size() - 1;
      ui->lineEdit->setText(string);
    }
  }
}

void Calculator::equal() {
  if (x != "Invalid value x" && string.size() != 0) {
    std::string test = string.toUtf8().constData();
    const char *str = test.c_str();
    char *string_final = (char *)str;
    long double result = 0;
    int res = smartCalculator(string_final, &result, 1, arg);
    if (res != 0) {
      ui->lineEdit->setText("invalid error");
      string.clear();
    } else {
      QString answer = QString::number(result, 'g', 7);
      ui->lineEdit->setText(answer);
      string.clear();
      string += answer;
      index_arith = -100, index_func = -100, index_dot = 0;
    }
  }
}

void Calculator::iks() {
  if (x != "Invalid value x" && CheckLen()) {
    QString digit = ui->pushButton_x->text();
    if (string.size() == 1 && string[0] == QChar('0')) {
      string.clear();
    }
    if (string.size() != 0) {
      if ((string[string.size() - 1] == QChar(')')) ||
          (string[string.size() - 1] >= QChar('0') &&
           string[string.size() - 1] <= QChar('9'))) {
        string.append(ui->pushButton_mult->text());
      }
      if (string[string.size() - 1] != QChar('.') &&
          string[string.size() - 1] != 'x') {
        string += digit;
      }
    } else {
      string += digit;
    }
    ui->lineEdit->setText(string);
  }
}

void Calculator::on_lineEdit_2_textChanged(const QString &arg1) {
  x.clear();
  int flag = 0, dot = 0, minus = 0;
  for (int i = 0; i < arg1.size(); i++) {
    if ((arg1[i] < QChar('0') || arg1[i] > QChar('9')) &&
        (arg1[i] != QChar('.')) && (arg1[i] != QChar('-'))) {
      x = "Invalid value x";
      flag = 1;
      ui->lineEdit->setText(x);
      break;
    }
    if (arg1[i] == QChar('.')) {
      dot++;
    } else if (arg1[i] == QChar('-')) {
      minus++;
    }
    if ((dot > 1 || minus > 1) && (!flag)) {
      x = "Invalid value x";
      flag = 1;
      ui->lineEdit->setText(x);
      break;
    }
  }
  if (!flag) {
    x = arg1;
    arg = arg1.toDouble();
    ui->lineEdit->setText(string);
  }
}

void Calculator::on_lineEdit_2_selectionChanged() {
  ui->lineEdit_2->setText("");
}

void Calculator::graph() {
  if (x != "Invalid value x" && xmax >= xmin &&
      ui->lineEdit->text() != "invalid error") {
    double step = 0.1;
    int flag = 0;
    ui->graph->setInteraction(QCP::iRangeZoom, true);
    ui->graph->setInteraction(QCP::iRangeDrag, true);
    ui->graph->yAxis->setRange(xmax, xmin);
    ui->graph->xAxis->setRange(xmax, xmin);

    std::string test = string.toUtf8().constData();
    const char *str = test.c_str();
    char *string_final = (char *)str;

    for (double dot = xmin; dot <= xmax; dot += step) {
      long double result = 0;

      int res = smartCalculator(string_final, &result, 1, dot);
      if (res == OK && !flag) {
        y1.push_back(result);
        x1.push_back(dot);
      } else if (res == FAIL || res == CALC_ERR) {
        flag = 1;
        continue;
      } else if (flag) {
        y2.push_back(result);
        x2.push_back(dot);
      }
    }
    ui->graph->addGraph();
    ui->graph->graph(0)->setData(x1, y1);
    ui->graph->addGraph();
    ui->graph->graph(1)->setData(x2, y2);

    ui->graph->replot();
    x1.clear();
    y1.clear();
    x2.clear();
    y2.clear();
  } else if (xmax < xmin) {
    ui->lineEdit->setText("Incorrect range of x");
    ui->graph->clearGraphs();
  }
}

void Calculator::credit() { ui->stackedWidget->setCurrentWidget(ui->page_2); }

void Calculator::calc() { ui->stackedWidget->setCurrentWidget(ui->page); }

void Calculator::on_lineEdit_xmax_textChanged(const QString &arg1) {
  x_max.clear();
  int flag = 0, dot = 0, minus = 0;
  for (int i = 0; i < arg1.size(); i++) {
    if ((arg1[i] < QChar('0') || arg1[i] > QChar('9')) &&
        (arg1[i] != QChar('.')) && (arg1[i] != QChar('-'))) {
      x_max = "Invalid value Xmax";
      flag = 1;
      ui->lineEdit->setText(x_max);
      break;
    }
    if (arg1[i] == QChar('.')) {
      dot++;
    } else if (arg1[i] == QChar('-')) {
      minus++;
    }
    if (dot > 1 && !flag) {
      x_max = "Invalid value Xmax";
      flag = 1;
      ui->lineEdit->setText(x_max);
      break;
    }
  }
  if (!flag) {
    x_max = arg1;
    xmax = x_max.toDouble();
    if (xmax > 1000000 || xmax < -1000000) {
      x_max = "Invalid value Xmax";
      ui->lineEdit->setText(x_max);
      xmax = 100;
      ui->lineEdit_xmax->setText(x_max);
    } else {
      ui->lineEdit->setText(string);
      ui->lineEdit_xmax->setText(x_max);
    }
  }
}

void Calculator::on_lineEdit_xmin_textChanged(const QString &arg1) {
  x_min.clear();
  int flag = 0, dot = 0, minus = 0;
  for (int i = 0; i < arg1.size(); i++) {
    if ((arg1[i] < QChar('0') || arg1[i] > QChar('9')) &&
        (arg1[i] != QChar('.')) && (arg1[i] != QChar('-'))) {
      x_min = "Invalid value Xmax";
      flag = 1;
      ui->lineEdit->setText(x_min);
      break;
    }
    if (arg1[i] == QChar('.')) {
      dot++;
    } else if (arg1[i] == QChar('-')) {
      minus++;
    }
    if (dot > 1 && !flag) {
      x_max = "Invalid value Xmin";
      flag = 1;
      ui->lineEdit->setText(x_min);
      break;
    }
  }
  if (!flag) {
    x_min = arg1;
    xmin = x_min.toDouble();
    if (xmin > 1000000 || xmin < -1000000) {
      x_min = "Invalid value Xmin";
      ui->lineEdit->setText(x_min);
      xmin = 100;
      ui->lineEdit_xmin->setText(x_min);
    } else {
      ui->lineEdit->setText(string);
      ui->lineEdit_xmin->setText(x_min);
    }
  }
}

////////////////////////////////credit
/// calculator/////////////////////////////////

void Calculator::on_lineEdit_amount_textChanged(const QString &arg1) {
  int flag = 0, dot = 0;
  sum = 0;
  amount.clear();
  QString tmp = arg1;
  for (int i = 0; i < tmp.size(); i++) {
    if (tmp[i] == ' ') {
      continue;
    } else if ((tmp[i] < QChar('0') || tmp[i] > QChar('9')) &&
               (tmp[i] != QChar('.'))) {
      amount = "Invalid value amount";
      ui->lineEdit_amount->setText(amount);
      flag = 1;
      break;
    } else if (tmp[i] == QChar('.')) {
      dot++;
    }
    if (tmp.size() % 3 == 1) {
      tmp.insert(arg1.size() - 3, " ");
    }
  }
  if (dot > 1) {
    amount = "Invalid value amount";
    ui->lineEdit_amount->setText(amount);
    flag = 1;
  }
  if (!flag) {
    amount = arg1;
    sum = arg1.toDouble();
  }
}

void Calculator::on_lineEdit_term_textChanged(const QString &arg1) {
  int flag = 0, flag_tmp = 0;
  term.clear();
  years = 0;
  if (arg1.size() != 0) {
    for (int i = 0; i < arg1.size(); i++) {
      if ((arg1[i] < QChar('0') || arg1[i] > QChar('9'))) {
        term = "Invalid value term";
        ui->lineEdit_term->setText(term);
        flag = 1;
        break;
      }
    }
    if (!flag) {
      years = arg1.toInt();
      if (ui->comboBox_term->currentText() == "years") {
        if (years > 50 || years < 0) {
          flag_tmp = 1;
          ui->textEdit_result->setText("Maximum term - 50 years\n");
        }

      } else if (ui->comboBox_term->currentText() == "month") {
        if (years > 600 || years < 0) {
          flag_tmp = 1;
          ui->textEdit_result->setText("Maximum term - 600 month\n");
        }
      }
      if (flag_tmp) {
        term = "0";
        ui->lineEdit_term->setText(term);
        years = 0;
      }
    }
  }
}

void Calculator::on_lineEdit_rate_textChanged(const QString &arg1) {
  int flag = 0, dot = 0;
  rate.clear();
  proc = 0;
  for (int i = 0; i < arg1.size(); i++) {
    if ((arg1[i] < QChar('0') || arg1[i] > QChar('9')) &&
        (arg1[i] != QChar('.'))) {
      rate = "Invalid value rate";
      ui->lineEdit_rate->setText(rate);
      flag = 1;
      break;
    } else if (arg1[i] == QChar('.')) {
      dot++;
    }
  }
  if (dot > 1) {
    rate = "Invalid value rate";
    ui->lineEdit_rate->setText(rate);
    flag = 1;
  }
  if (!flag) {
    rate = arg1;
    proc = arg1.toDouble();
  }
}

void Calculator::create_rezult() {
  rezult.resize(18000);
  rezult.replace(0, 18000, "\0");
  QString tmp = "№ month\t Amount\t Main debt\t Percentage\t Loan balance\n";
  rezult.append(tmp);
}

void Calculator::finished_rezult(double sum, double total_md, double total_pd) {
  rezult.append("\nTOTAL\t");

  rezult.append(QString::number(total_md + total_pd, 'f', 2));
  rezult.append("\t ");

  rezult.append(QString::number(total_md, 'f', 2));
  rezult.append("\t ");

  rezult.append(QString::number(total_pd, 'f', 2));
  rezult.append("\nOverpaument: ");
  rezult.append(QString::number(total_pd + total_md - sum, 'f', 2));
}

void Calculator::credit_calc() {
  create_rezult();
  double month_payment = 0;
  sum = ui->lineEdit_amount->text().toDouble();
  double copy_sum = sum;
  QString tmp_string;
  years = ui->lineEdit_term->text().toInt();
  if (ui->comboBox_term->currentText() == "years") {
    years *= 12;
  }
  if (proc != 0 && years != 0 && sum != 0) {
    if (ui->radioButton_ann->isChecked()) {
      month_payment = Calc_month_payment(sum, proc, years);
    }
    for (int i = 0; i < years; i++) {
      double md = 0, pd = 0;
      tmp_string = QString::number(i + 1);
      tmp_string.append("\t ");

      if (ui->radioButton_ann->isChecked()) {
        Calc_ann_type(&md, &pd, proc, sum, month_payment);
      } else {
        md = copy_sum / years;
        Calc_diff_type(&pd, proc, sum);
      }

      tmp_string.append(QString::number(md + pd));
      tmp_string.append("\t ");

      tmp_string.append(QString::number(md));
      tmp_string.append("\t ");

      tmp_string.append(QString::number(pd));
      tmp_string.append("\t ");

      total_md += md;
      total_pd += pd;

      sum -= md;
      if (sum <= 0.1) {
        sum = 0;
      }
      tmp_string.append(QString::number(sum));
      tmp_string.append("\n");
      rezult.append(tmp_string);
      tmp_string.clear();
    }
    finished_rezult(copy_sum, total_md, total_pd);
    ui->textEdit_result->setText(rezult);
    rezult.clear();
    total_md = 0, total_pd = 0, overpayment = 0;
  } else {
    QMessageBox::about(this, "Error", "Invalid value");
  }
}

void Calculator::on_lineEdit_amount_selectionChanged() {
  ui->lineEdit_amount->setText("");
}

void Calculator::on_lineEdit_rate_selectionChanged() {
  ui->lineEdit_rate->setText("");
}

void Calculator::on_lineEdit_term_selectionChanged() {
  ui->lineEdit_term->setText("");
}

void Calculator::on_comboBox_menu2_activated(int index) {
  if (index == 1) {
    calc();
  }
}

void Calculator::on_comboBox_menu_activated(int index) {
  if (index == 1) {
    credit();
  }
}
