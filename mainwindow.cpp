#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Circle.h"
#include <sstream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    deleteList(head);
    delete head;
}



void MainWindow::printList(){
    stringstream stream;
    Circle *adress = head;
    while (adress != NULL){
        stream << "(" << adress->x << "," << adress->y << "," << adress->radius << ")" ;
        adress = adress->next;
    }
    string text = stream.str();
    QString text_qt = text.c_str();
    ui->pteList->clear();
    ui->pteList->appendPlainText(text_qt);
}

void MainWindow::on_pbAddAtTheFront_clicked()
{
    double x = ui->leX->text().toDouble();
    double y = ui->leY->text().toDouble();
    double radius = ui->leRadius->text().toDouble();

        addCircleAtTheFront(&head,x, y, radius);
        printList();
        ui->leX->clear();
        ui->leY->clear();
        ui->leRadius->clear();
}


void MainWindow::on_pbAddAtTheEnd_clicked()
{
    double x = ui->leX->text().toDouble();
    double y = ui->leY->text().toDouble();
    double radius = ui->leRadius->text().toDouble();

        addCircleAtTheEnd(&head,x, y, radius);
        printList();
        ui->leX->clear();
        ui->leY->clear();
        ui->leRadius->clear();
}

void MainWindow::on_pbDelete_clicked()
{
        deleteList(head);
        ui->leX->clear();
        ui->leY->clear();
        ui->leRadius->clear();
        head=NULL;
        printList();
}

void MainWindow::on_pbClear_clicked()
{
    ui->leX->clear();
    ui->leY->clear();
    ui->leRadius->clear();
    ui->pteList->clear();
}

void MainWindow::on_searchBy_clicked()
{
    Circle* i;
    stringstream stream;
    double begin = ui->leFrom->text().toDouble();
    double end = ui->leTo->text().toDouble();
    for (i = head; i != NULL; i = i->next) {
        if (i->radius >= begin && i->radius<= end) {
            stream << "(" << i->x << "," << i->y << ")";
        }
    }
    string text = stream.str();
    QString text_qt = text.c_str();
    ui->pteList->clear();
    ui->pteList->appendPlainText(text_qt);
}

void MainWindow::on_SortByOrigin_clicked()
{
    sortByOrigin(head);
    printList();
}

void MainWindow::on_pbSave_clicked()
{
    QFile file_w("list_out.txt");
    if (!file_w.open(QFile::WriteOnly | QFile::Text)){
         QMessageBox::warning(this, "UWAGA:", "Blad pliku");
    }
    QTextStream out(&file_w);
    //QString text = ui->pteList->toPlainText();
    //out << text;

    while (head != NULL) {
        out  << head->x << "\n" << head->y << "\n" << head->radius << "\n";
        head = head->next;
    }

    file_w.flush();
    file_w.close();
}

void MainWindow::on_pbRead_clicked()
{
    QFile file_w("list_out.txt");
    if (!file_w.open(QFile::ReadOnly | QFile::Text)){
         QMessageBox::warning(this, "UWAGA:", "Blad pliku");
    }
    QTextStream in(&file_w);
    deleteList(head);
    head = NULL;

    while (!in.atEnd()) {
        Circle* newCircle = new Circle();
        in  >> newCircle->x;
        in  >> newCircle->y;
        in  >> newCircle->radius;
        if (head == NULL) {
            head = newCircle;
            head->next = NULL;
        }else {
            Circle* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newCircle;
            ptr->next->next = NULL;
        }
    }

    //QString text = in.readAll();
    //ui->pteList->setPlainText(text);
    file_w.close();
}

void MainWindow::on_pbShow_clicked()
{
    printList();
}


void MainWindow::on_pbClose_clicked()
{
    close();
}


void MainWindow::on_actionZamknij_triggered()
{
    close();
}

