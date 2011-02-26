#ifndef FENLOGIN_H
#define FENLOGIN_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

#include "fenlogin.h"

namespace Ui
{
    class fenlogin;
}

class fenlogin : public QDialog, public Ui::fenlogin
{
    Q_OBJECT

    public:
        fenlogin(QWidget *parent = 0, Qt::WFlags f = 0);
        ~fenlogin();

        void closeEvent(QCloseEvent* event);

    private:
        Ui::fenlogin *ui;
        QSqlDatabase db;

    public slots:
        void on_fenloginButton_clicked();
};


#endif // FENLOGIN_H
