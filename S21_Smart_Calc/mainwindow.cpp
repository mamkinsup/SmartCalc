#include "mainwindow.h"
#include "ui_mainwindow.h"

extern "C" {
#include "../SmartCalc/my_heder.h"
#include "../SmartCalc/help_functions.c"
#include "../SmartCalc/my_heder.h"
#include "../SmartCalc/parser.c"
#include "../SmartCalc/calculation.c"
#include "../SmartCalc/my_test.c"
#include "../SmartCalc/variable_result.c"
}

QString tmp_string;
int count_checked=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_sqrt_2,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_dif,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_division,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_acos,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_asin,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_atan,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_x,SIGNAL(clicked()),this,SLOT(variable()));
    connect(ui->pushButton_AC,SIGNAL(clicked()),this,SLOT(ac_operations()));
    connect(ui->pushButton_dot,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_ln_left,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_ln_right,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_equals,SIGNAL(clicked()),this,SLOT(equals()));
    connect(ui->pushButton_G,SIGNAL(clicked()),this,SLOT(GRAF()));

    ui->pushButton_x->setCheckable(true);
    ui->pushButton_equals->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    if(ui->result_show->text().length()<256){
    QPushButton *button=(QPushButton*)sender();

    QString new_label;

    new_label= (ui->result_show->text()+button->text());

    ui->result_show->setText(new_label);
    }

}

void MainWindow:: math_operations(){
    if(ui->result_show->text().length()<256){
        QPushButton *button=(QPushButton*)sender();

        QString new_label;

        new_label= (ui->result_show->text()+button->text());

        ui->result_show->setText(new_label);
    }
    }



void MainWindow::equals()
{

       if(ui->pushButton_x->isChecked()){
    tmp_string=ui->result_show->text();
    ui->result_show->setText("enter_the_value: ");
    ui->pushButton_x->setChecked(false);
    count_checked=1;
    }
       else{
           if( count_checked){
        QString variable_string=ui->result_show->text();
        QByteArray ar_variable=variable_string.toUtf8();
        const char* str_variable = ar_variable.data();
        QByteArray ar_string_res=tmp_string.toUtf8();
        const char* string_res = ar_string_res.data();
        int res=check_string_correct(string_res);
        if(!res){
            double result=variable_result(string_res,str_variable);
            QString res_string=QString::number(result,'g',10);
            ui->result_show->setText(res_string);
        }else{
            ui->result_show->setText("incorrect input");
        }
        count_checked= 0;
        }
           else {

               QString new_string=ui->result_show->text();
               QByteArray ar=new_string.toUtf8();
               const char* str1 = ar.data();
               int res=check_string_correct(str1);
               if(!res){
                   double res=my_test(str1);
                   QString res_string=QString::number(res,'g',10);
                   ui->result_show->setText(res_string);
               }else{
                   ui->result_show->setText("incorrect input");
               }
           }
           }
       }

void MainWindow::ac_operations(){
    ui->result_show->clear();
    ui->pushButton_x->setChecked(false);
    count_checked=0;
}



void MainWindow::variable(){
    if(ui->result_show->text().length()<256){
        QPushButton *button=(QPushButton*)sender();
        ui->pushButton_x->setChecked(true);
        QString new_label;

        new_label= (ui->result_show->text()+button->text());

        ui->result_show->setText(new_label);
    }
}

void MainWindow::GRAF(){
    QString check_string=ui->result_show->text();
    QByteArray ar_check=check_string.toUtf8();
    const char* c_check_string=ar_check.data();
    if(!check_string_correct(c_check_string)){
        // printf("HERE");

        if (ui->widget->graph(0)) {
            ui->widget->graph(0)->data()->clear();
        }
        double xBegin, xEnd, h, X;

        double ar_x=ui->lineEdit->text().toDouble();
        double ar_y=ui->lineEdit_2->text().toDouble();
        if(ar_x>10000){
            ar_x=10000;
        }
        if(ar_y>10000){
            ar_y=10000;

        }



        h = 0.1;
        xBegin = -ar_x;
        xEnd = ar_x;
        int N = (int)(xEnd - xBegin)/h;
        QVector<double> x(N), y(N);
        ui->widget->xAxis->setRange(xBegin, xEnd);
        ui->widget->yAxis->setRange(-ar_y,ar_x);


        QString current_string=ui->result_show->text();
        QByteArray ar=current_string.toUtf8();
        const char* current_c_char=ar.data();

        int i=0;

        for (X = xBegin; X < xEnd; X += h) {
            X = round(X * 10000000) / 10000000;
            // x.push_back(X);
            x[i]=X;
            QString variable_x=QString::number(X);
            QByteArray ar_var=variable_x.toUtf8();
            const char* variable_c_char=ar_var.data();
            // y.push_back(variable_result(current_c_char, variable_c_char));
            y[i]=variable_result(current_c_char, variable_c_char);
            i++;
        }


        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x, y);
        ui->widget->replot();

    }
    else {
        ui->result_show->setText("incorrect input");
    }
}


