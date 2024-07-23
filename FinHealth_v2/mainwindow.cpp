#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dataFile->addItem("Текст файла:");
    qDebug()<<"Start Programm";
}

MainWindow::~MainWindow()
{
    delete ui;
}
// вызов функции:

void MainWindow::on_pushButton_clicked()
{
    QString dataFromLine = ui ->lineInputName->text();
    readFile(dataFromLine);

}



void MainWindow::readFile(QString name_file){
    QString fname = QFileDialog::getOpenFileName(this,"open a file",name_file);
    qDebug()<<"Creating data from file:"<<fname;
    QFile in_data(fname);

    if (in_data.open(QFile::ReadOnly | QFile::Text))
    {
        QString line = "";

        if (fname.contains("csv")){

            qDebug()<<"TESTING LINES: ON";


            QString newLine = "";
            int income = 0;
            int bill = 0;
            int sum_income = 0;
            int sum_bill = 0;
            int profit = 0;
            int S_profit = 0;
            float i = 0.10;
            int n = 3;

            QMessageBox::about(this,fname,"read file is ok");
            //Вывод информации:


            ui->dataFile->clear();
            ui->dataFile->addItem("Text: ");

            while (!in_data.atEnd()){

                line = in_data.readLine();
                income = line.mid(0, line.indexOf(",")).toInt();
                bill = line.mid(line.indexOf(",")+1).toInt();
                newLine = "Income: " + QString::number(income) + "\t" + "Bill: " + QString::number(bill);

                profit += income - bill;
                sum_income += income;
                sum_bill += bill;

                ui->dataFile->addItem(newLine);
            }

            ui->dataFile->addItem("Profit by year: " + QString::number(profit));
            ui->dataFile->addItem("Income by year: " + QString::number(sum_income));
            ui->dataFile->addItem("Bill by year: " + QString::number(sum_bill));

            S_profit = profit * pow(1.0+i, n);
            ui->dataFile->addItem("Deposit: " + QString::number(profit) + " for " + QString::number(n) + " at " + QString::number(i*100) + "%");
            ui->dataFile->addItem("Profit by deposit: " + QString::number(S_profit-profit));

            qDebug()<<"TESTING LINES: OFF";

        }
        else{
            ui->dataFile->clear();
            ui->dataFile->addItem("Текст файла:");
            while (!in_data.atEnd())
            {
                line = in_data.readLine();
                ui->dataFile->addItem(line);
            }

        }

    }
    else
    {
        qDebug()<<"Incorrect file/name...";
    }
    qDebug()<<"Close file...";
    in_data.close();


}





