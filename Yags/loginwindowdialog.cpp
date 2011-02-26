#include "loginwindowdialog.h"
#include "ui_loginwindowdialog.h"
#include "mainwindow.h"

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
}