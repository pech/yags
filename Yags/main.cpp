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
    //fenlogin fen(&w);
    //FenLoginDialog fen(&w, 0);
    //fen.exec()

    //fenlogin fen;


    w.setWindowState(w.windowState() ^ Qt::WindowMaximized);

    //fen.show();

    w.show();

    return a.exec();
}
