#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Circle.h"
#include <sstream>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbAddAtTheFront_clicked();

    void on_pbAddAtTheEnd_clicked();

    void on_pbDelete_clicked();

    void on_pbClear_clicked();

    void on_searchBy_clicked();

    void on_SortByOrigin_clicked();

    void on_pbSave_clicked();

    void on_pbRead_clicked();

    void on_pbShow_clicked();

    void on_pbClose_clicked();

    void on_actionZamknij_triggered();

private:
    Ui::MainWindow *ui;
    Circle* head = NULL;
    void printList();

};
#endif // MAINWINDOW_H
