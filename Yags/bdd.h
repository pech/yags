#ifndef BDD_H
#define BDD_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QMessageBox>
#include <QDebug>

#include <QSqlTableModel>
#include <QSqlRecord>
#include <QMessageBox>


class BDD {
public:
    BDD();
    ~BDD();
    void Connexion ();
    void listerUser ();
    void listerProjet ();

    QSqlDatabase db;
    QString listeUser;
    QString listeProjet;
};


#endif // BDD_H
