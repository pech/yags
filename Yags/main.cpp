#include <QtGui/QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QMessageBox>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowState(w.windowState() ^ Qt::WindowMaximized);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("monDSN"); // DSN que nous venons de créer.
        //db.setUserName("alain.defrance");
        //db.setPassword("plop");

        if(!db.open())
        {
            //QMessageBox::critical(0, QObject::tr("Database Error"), db.lastError().text());
        }


    w.show();


    return a.exec();
}
