#include "mainwindow.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile StyleSheetFile("/Users/szymi/Projekty_qt/Dynamic_list_gui/Combinear.qss");
    StyleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(StyleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    MainWindow w;
    w.show();
    return a.exec();
}
