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
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include <QAction>


class BDD : public QObject {
    Q_OBJECT

public:
    BDD();
    ~BDD();
    void Connexion ();
    void listerUser ();
    void listerProjet ();
    void AjoutFenetre ();

    QSqlDatabase db;
    QString listeUser;
    QString listeProjet;

public slots:
    void AjoutUser ();

private:
    QLineEdit *ajoutBox;
    QLineEdit *ajoutBoxpass;
    QLineEdit *ajoutBoxaddress;
    //QLineEdit *ajoutBoxisuser;
    QVBoxLayout *layoutfile;
    QDialog *fileFenetre;

};


#endif // BDD_H
