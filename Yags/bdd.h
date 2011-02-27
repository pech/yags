#ifndef BDD_H
#define BDD_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QMessageBox>
#include <QDebug>


class BDD {
public:
    BDD();
    ~BDD();
    void Connexion ();

    QSqlDatabase db;
};


#endif // BDD_H
