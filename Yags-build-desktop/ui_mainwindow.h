/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 27. Feb 23:54:56 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSeconnecter;
    QAction *actionOuvrir;
    QAction *actionEnregisrer;
    QAction *actionEnregistrer_sous;
    QAction *actionQuitter;
    QAction *actionMedian;
    QAction *actionMoyen;
    QAction *actionGaussien;
    QAction *actionZoom_Avant;
    QAction *actionZoom_Arri_re;
    QAction *actionAide;
    QAction *actionA_propos;
    QAction *actionSe_d_connecter;
    QAction *actionListe_User;
    QAction *actionListe_Cartes;
    QAction *actionAjout_User;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuVue;
    QMenu *menuAction;
    QMenu *menuFiltre;
    QMenu *menuOption;
    QMenu *menuAffichage;
    QMenu *menuAide;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(500, 400);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ICO_Home.gif"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::VerticalTabs);
        actionSeconnecter = new QAction(MainWindow);
        actionSeconnecter->setObjectName(QString::fromUtf8("actionSeconnecter"));
        actionSeconnecter->setEnabled(true);
        actionOuvrir = new QAction(MainWindow);
        actionOuvrir->setObjectName(QString::fromUtf8("actionOuvrir"));
        actionOuvrir->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOuvrir->setIcon(icon1);
        actionEnregisrer = new QAction(MainWindow);
        actionEnregisrer->setObjectName(QString::fromUtf8("actionEnregisrer"));
        actionEnregisrer->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnregisrer->setIcon(icon2);
        actionEnregistrer_sous = new QAction(MainWindow);
        actionEnregistrer_sous->setObjectName(QString::fromUtf8("actionEnregistrer_sous"));
        actionEnregistrer_sous->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/save_as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnregistrer_sous->setIcon(icon3);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/quitter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuitter->setIcon(icon4);
        actionMedian = new QAction(MainWindow);
        actionMedian->setObjectName(QString::fromUtf8("actionMedian"));
        actionMoyen = new QAction(MainWindow);
        actionMoyen->setObjectName(QString::fromUtf8("actionMoyen"));
        actionGaussien = new QAction(MainWindow);
        actionGaussien->setObjectName(QString::fromUtf8("actionGaussien"));
        actionZoom_Avant = new QAction(MainWindow);
        actionZoom_Avant->setObjectName(QString::fromUtf8("actionZoom_Avant"));
        actionZoom_Avant->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_Avant->setIcon(icon5);
        actionZoom_Arri_re = new QAction(MainWindow);
        actionZoom_Arri_re->setObjectName(QString::fromUtf8("actionZoom_Arri_re"));
        actionZoom_Arri_re->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_Arri_re->setIcon(icon6);
        actionAide = new QAction(MainWindow);
        actionAide->setObjectName(QString::fromUtf8("actionAide"));
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName(QString::fromUtf8("actionA_propos"));
        actionSe_d_connecter = new QAction(MainWindow);
        actionSe_d_connecter->setObjectName(QString::fromUtf8("actionSe_d_connecter"));
        actionSe_d_connecter->setEnabled(false);
        actionListe_User = new QAction(MainWindow);
        actionListe_User->setObjectName(QString::fromUtf8("actionListe_User"));
        actionListe_User->setEnabled(false);
        actionListe_Cartes = new QAction(MainWindow);
        actionListe_Cartes->setObjectName(QString::fromUtf8("actionListe_Cartes"));
        actionListe_Cartes->setEnabled(false);
        actionAjout_User = new QAction(MainWindow);
        actionAjout_User->setObjectName(QString::fromUtf8("actionAjout_User"));
        actionAjout_User->setEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        menuVue = new QMenu(menuBar);
        menuVue->setObjectName(QString::fromUtf8("menuVue"));
        menuAction = new QMenu(menuBar);
        menuAction->setObjectName(QString::fromUtf8("menuAction"));
        menuFiltre = new QMenu(menuAction);
        menuFiltre->setObjectName(QString::fromUtf8("menuFiltre"));
        menuOption = new QMenu(menuBar);
        menuOption->setObjectName(QString::fromUtf8("menuOption"));
        menuAffichage = new QMenu(menuBar);
        menuAffichage->setObjectName(QString::fromUtf8("menuAffichage"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuVue->menuAction());
        menuBar->addAction(menuAction->menuAction());
        menuBar->addAction(menuOption->menuAction());
        menuBar->addAction(menuAffichage->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionSeconnecter);
        menuFichier->addAction(actionSe_d_connecter);
        menuFichier->addSeparator();
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionEnregisrer);
        menuFichier->addAction(actionEnregistrer_sous);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuAction->addAction(menuFiltre->menuAction());
        menuFiltre->addAction(actionMedian);
        menuFiltre->addAction(actionMoyen);
        menuFiltre->addAction(actionGaussien);
        menuOption->addAction(actionAjout_User);
        menuOption->addSeparator();
        menuOption->addAction(actionListe_User);
        menuOption->addAction(actionListe_Cartes);
        menuAffichage->addAction(actionZoom_Avant);
        menuAffichage->addAction(actionZoom_Arri_re);
        menuAide->addAction(actionAide);
        menuAide->addSeparator();
        menuAide->addSeparator();
        menuAide->addAction(actionA_propos);
        toolBar->addAction(actionQuitter);
        toolBar->addAction(actionOuvrir);
        toolBar->addAction(actionEnregisrer);
        toolBar->addAction(actionEnregistrer_sous);
        toolBar->addSeparator();
        toolBar->addAction(actionZoom_Avant);
        toolBar->addAction(actionZoom_Arri_re);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Yags", 0, QApplication::UnicodeUTF8));
        actionSeconnecter->setText(QApplication::translate("MainWindow", "Se connecter", 0, QApplication::UnicodeUTF8));
        actionOuvrir->setText(QApplication::translate("MainWindow", "&Ouvrir...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionOuvrir->setStatusTip(QApplication::translate("MainWindow", "Open file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionOuvrir->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionEnregisrer->setText(QApplication::translate("MainWindow", "Enregistrer", 0, QApplication::UnicodeUTF8));
        actionEnregistrer_sous->setText(QApplication::translate("MainWindow", "Enregistrer sous...", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "&Quitter", 0, QApplication::UnicodeUTF8));
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionMedian->setText(QApplication::translate("MainWindow", "Median", 0, QApplication::UnicodeUTF8));
        actionMoyen->setText(QApplication::translate("MainWindow", "Moyen", 0, QApplication::UnicodeUTF8));
        actionGaussien->setText(QApplication::translate("MainWindow", "Gaussien", 0, QApplication::UnicodeUTF8));
        actionZoom_Avant->setText(QApplication::translate("MainWindow", "Zoom Avant", 0, QApplication::UnicodeUTF8));
        actionZoom_Avant->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        actionZoom_Arri_re->setText(QApplication::translate("MainWindow", "Zoom Arri\303\250re", 0, QApplication::UnicodeUTF8));
        actionZoom_Arri_re->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        actionAide->setText(QApplication::translate("MainWindow", "Aide", 0, QApplication::UnicodeUTF8));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos...", 0, QApplication::UnicodeUTF8));
        actionSe_d_connecter->setText(QApplication::translate("MainWindow", "Se d\303\251connecter", 0, QApplication::UnicodeUTF8));
        actionListe_User->setText(QApplication::translate("MainWindow", "Liste User", 0, QApplication::UnicodeUTF8));
        actionListe_Cartes->setText(QApplication::translate("MainWindow", "Liste Cartes", 0, QApplication::UnicodeUTF8));
        actionAjout_User->setText(QApplication::translate("MainWindow", "Ajout User", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "&Fichier", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0, QApplication::UnicodeUTF8));
        menuVue->setTitle(QApplication::translate("MainWindow", "Vue", 0, QApplication::UnicodeUTF8));
        menuAction->setTitle(QApplication::translate("MainWindow", "Action", 0, QApplication::UnicodeUTF8));
        menuFiltre->setTitle(QApplication::translate("MainWindow", "Filtre", 0, QApplication::UnicodeUTF8));
        menuOption->setTitle(QApplication::translate("MainWindow", "Option", 0, QApplication::UnicodeUTF8));
        menuAffichage->setTitle(QApplication::translate("MainWindow", "Affichage", 0, QApplication::UnicodeUTF8));
        menuAide->setTitle(QApplication::translate("MainWindow", "&?", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
