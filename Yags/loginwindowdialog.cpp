#include "loginwindowdialog.h"
#include "ui_loginwindowdialog.h"
#include "mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>

LoginWindowDialog::LoginWindowDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindowDialog)
{
    ui->setupUi(this);
}

LoginWindowDialog::~LoginWindowDialog()
{
    delete ui;
}

void LoginWindowDialog::on_pushButton_clicked()
{
    MainWindow *w = new MainWindow(this);
    w->setWindowState(w->windowState() ^ Qt::WindowMaximized);
    w->show();
    QString nom = ui->loginLineEdit->text();
    QString pass = ui->loginLineEdit->text();


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
         //return false;
    }


    QSqlQuery query;

    bool verifquery = false;
    query.exec() = "SELECT login, password FROM user WHERE login = :nom";
    verifquery = query.bindValue(":login", login);


    if ( verifquery == true)
    {
        QMessageBox::information(this, tr("login"), nom );
    }

      // On vérifie que l'utilisateur existe bien

  }





}

