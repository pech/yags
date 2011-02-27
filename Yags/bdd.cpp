#include "bdd.h"

BDD::BDD() {

}

BDD::~BDD() {

}

void BDD::Connexion ()
{
    db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=C:/Users/Belle/Desktop/pa8/new3/Yags/Yags/bdd_yags.mdb");

    if ( !db.open() ) {
        QMessageBox::critical(0, QObject::tr("Cannot open database"),
             QObject::tr("Unable to establish a database connection.n"
                      "This example needs SQLite support. Please read "
                      "the Qt SQL driver documentation for information how "
                      "to build it.nn"
                      "Click Cancel to exit."), QMessageBox::Cancel,
                      QMessageBox::NoButton);
             qDebug() << db.lastError();
         //return false;
    }


    //test query

    //QSqlQuery query;

    //query.exec("create table user (id int primary key, "
    //           "login varchar(20), password varchar(20), address varchar(200), typeid int)");
    //query.exec("insert into user values(1, 'Alice', 'alice', "
    //           "'<qt>Alice@gmail.com', 1)");
    //query.exec("insert into user values(2, 'Bob', 'bob', "
    //           "'<qt>Bob@gmail.com', 1)");
    //query.exec("insert into user values(3, 'Carol', 'carol', "
    //           "'<qt>The Lighthouse</qt>', 1)");
    //query.exec("insert into user values(4, 'Donald', 'donald', "
    //           "'Donald@gmail.com', 1)");
    //query.exec("insert into user values(5, 'Emma', 'emma', "
    //           "'<qt>Emma@gmail.com</qt>', 1)");


}
