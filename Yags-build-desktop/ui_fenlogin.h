/********************************************************************************
** Form generated from reading UI file 'fenlogin.ui'
**
** Created: Sat 26. Feb 14:42:44 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENLOGIN_H
#define UI_FENLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_fenlogin
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *fenlogin)
    {
        if (fenlogin->objectName().isEmpty())
            fenlogin->setObjectName(QString::fromUtf8("fenlogin"));
        fenlogin->resize(406, 304);
        buttonBox = new QDialogButtonBox(fenlogin);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(fenlogin);
        QObject::connect(buttonBox, SIGNAL(accepted()), fenlogin, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), fenlogin, SLOT(reject()));

        QMetaObject::connectSlotsByName(fenlogin);
    } // setupUi

    void retranslateUi(QDialog *fenlogin)
    {
        fenlogin->setWindowTitle(QApplication::translate("fenlogin", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class fenlogin: public Ui_fenlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENLOGIN_H
