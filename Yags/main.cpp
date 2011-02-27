#include <QtGui/QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>

#include "mainwindow.h"
//#include "loginwindowdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowState(w.windowState() ^ Qt::WindowMaximized);
    w.show();

    return a.exec();
}
