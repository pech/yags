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

    //QSqlQuery query;

    //query.exec("create table projet (id int primary key, "
    //           "adresse varchar(20), typeid int)");


    QSqlQuery query;


    query.exec("create table maps (id INT PRIMARY KEY, nomcarte VARCHAR(20), emplacement VARCHAR(200), typeid int)");

    query.exec("create table admin (id int primary key, "
               "login varchar(20), password varchar(20), address varchar(200), typeid int)");
    query.exec("insert into admin values(1, 'admin', 'admin', "
               "'<qt>Alice@gmail.com', 0)");
    query.exec("insert into admin values(2, 'admin2', 'admin2', "
               "'<qt>Bob@gmail.com', 0)");
    query.exec("insert into admin values(3, 'admin3', 'admin3', "
               "'<qt>The Lighthouse</qt>', 0)");
    query.exec("insert into admin values(4, 'admin4', 'admin4', "
               "'Donald@gmail.com', 0)");
    query.exec("insert into admin values(5, 'admin5', 'admin5', "
               "'<qt>Emma@gmail.com</qt>', 0)");

}

void BDD::listerUser(){
    if (db.open())
    {

        QSqlTableModel modelUser;
        modelUser.setTable("user");
        //modelUser.setFilter("login = '"+loginBox->text()+"' and password = '"+passwordBox->text()+"'");
        modelUser.setEditStrategy(QSqlTableModel::OnManualSubmit);
        modelUser.select();

        int numrow = modelUser.rowCount();

        listeUser = "Liste des Utilisateurs : \n\n";

        for (int i = 0; i < numrow; i++) {
            QSqlRecord record = modelUser.record(i);
            QString login = record.value("login").toString();
            QString adresse = record.value("address").toString();

            listeUser += "Login : " + login + ", Adresse  : " + adresse + "\n ";

        }
    }
}

void BDD::listerProjet(){
    if (db.open())
    {

        QSqlTableModel modelMaps;
        modelMaps.setTable("maps");
        modelMaps.setEditStrategy(QSqlTableModel::OnManualSubmit);
        modelMaps.select();

        int numrow = modelMaps.rowCount();

        listeProjet = "Liste des Cartes : \n\n";

        for (int i = 0; i < numrow; i++) {
            QSqlRecord record = modelMaps.record(i);
            //int id = record.value("id").toInt();
            QString name_carte = record.value("nomcarte").toString();
            QString emplacement = record.value("emplacement").toString();
            //int isUser = record.value("typeid").toInt();



            //QObject::tr("Information récupérée"),"Login : " + login + "\n Adresse  : " + adresse + "\n ";

            listeProjet += "Carte : " + name_carte + ", Chemin  : " + emplacement + "\n ";

        }
        //QMessageBox::information(QWidget::, listeUser);
    }

}

