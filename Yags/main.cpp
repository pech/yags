#include <QtGui/QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>

#include "mainwindow.h"
#include "fenlogin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    fenlogin fen(&w);

    //fenlogin fen;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=C:/Users/Belle/Desktop/pa8/new3/Yags/Yags/bdd_yags.mdb");
    if ( !db.open() ) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
             qApp->tr("Unable to establish a database connection.n"
                      "This example needs SQLite support. Please read "
                      "the Qt SQL driver documentation for information how "
                      "to build it.nn"
                      "Click Cancel to exit."), QMessageBox::Cancel,
                      QMessageBox::NoButton);
             qDebug() << db.lastError();
         return false;
    }

    // test query
    QSqlQuery query;
        query.exec("create table person (id int primary key, "
                   "name varchar(20), address varchar(200), typeid int)");
        query.exec("insert into person values(1, 'Alice', "
                   "'<qt>123 Main Street<br/>Market Town</qt>', 101)");
        query.exec("insert into person values(2, 'Bob', "
                   "'<qt>PO Box 32<br/>Mail Handling Service"
                   "<br/>Service City</qt>', 102)");
        query.exec("insert into person values(3, 'Carol', "
                   "'<qt>The Lighthouse<br/>Remote Island</qt>', 103)");
        query.exec("insert into person values(4, 'Donald', "
                   "'<qt>47338 Park Avenue<br/>Big City</qt>', 101)");
        query.exec("insert into person values(5, 'Emma', "
                   "'<qt>Research Station<br/>Base Camp<br/>"
                   "Big Mountain</qt>', 103)");

    //w.setWindowState(w.windowState() ^ Qt::WindowMaximized);

    fen.show();

    //w.show();
    return a.exec();
}
