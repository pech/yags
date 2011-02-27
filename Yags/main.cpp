#include <QtGui/QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>

#include "mainwindow.h"
//#include "loginwindowdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/ICO_Home.gif"));
    splash->show();
    Qt::Alignment toRight = Qt::AlignTop | Qt::AlignTop;
    splash->showMessage(QObject::tr("Seeting up the main windows ..."), toRight, Qt::black);
    MainWindow w;


    for(int i=0;i<90000;i++)
           for(int j=0;j<900;j++);
        splash->showMessage(QObject::tr("Loading modules..."), toRight, Qt::black);
        for(int i=0;i<90000;i++)
           for(int j=0;j<900;j++);
        splash->showMessage(QObject::tr("Etablishing connections..."), toRight, Qt::black);
        for(int i=0;i<90000;i++)
           for(int j=0;j<6000;j++);


    w.setWindowState(w.windowState() ^ Qt::WindowMaximized);
    w.show();

    splash->finish(&w);
        delete splash;

    return a.exec();
}
