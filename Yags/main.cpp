#include <QtGui/QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>

//#include "mainwindow.h"
#include "loginwindowdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //fenlogin fen(&w);
    //FenLoginDialog fen(&w, 0);
    //fen.exec();
    LoginWindowDialog fen(0);

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


            query.exec("create table user (id int primary key, "
                       "login varchar(20), password varchar(20), address varchar(200), typeid int)");
            query.exec("insert into user values(1, 'Alice', 'alice', "
                       "'<qt>Alice@gmail.com', 101)");
            query.exec("insert into user values(2, 'Bob', 'bob', "
                       "'<qt>Bob@gmail.com', 102)");
            query.exec("insert into user values(3, 'Carol', 'carol', "
                       "'<qt>The Lighthouse</qt>', 103)");
            query.exec("insert into user values(4, 'Donald', 'donald', "
                       "'Donald@gmail.com', 101)");
            query.exec("insert into person values(5, 'Emma', 'emma', "
                       "'<qt>Emma@gmail.com</qt>', 103)");


    fen.show();

    //w.show();
    a.connect(&a, SIGNAL( lastWindowClosed() ) , &a, SLOT(quit()));
    return a.exec();
}
