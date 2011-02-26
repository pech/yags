#include "fenlogin.h"

fenlogin::fenlogin(QWidget *parent, Qt::WFlags f) : QDialog(parent, f)
{
    setupUi(this);

    parentWidget()->hide();
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("datas/u.co");
    db.setUserName("root");
   if( !db.open() )
        QMessageBox::critical(this, tr("fenlogin error"), tr("Connexion to the database fail."));
}

fenlogin::~fenlogin()
{
    delete ui;
}

void fenlogin::on_fenloginButton_clicked()
{
    QString login = loginLineEdit->text();
    QString password = passwordLineEdit->text();

    QSqlQuery selectUser(db);
    selectUser.prepare("SELECT name FROM users WHERE name = 'login' AND password = md5('password');");

    if( !selectUser.exec() )
        QMessageBox::critical(this, tr("Login error"), tr("Your logins are bad, try again."));
}

void fenlogin::closeEvent(QCloseEvent* event)
{
    parentWidget()->close();
}
