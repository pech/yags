#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QLabel>
#include <QMessageBox>
#include <QScrollArea>
#include <QScrollBar>
#include <QImageWriter>
#include <QList>
#include <QWidget>
#include <QGridLayout>
#include <QWheelEvent>
#include <QGraphicsView>
#include <QGraphicsScene>

#include <QEvent>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>

#include <QVBoxLayout>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>




namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool zoom_active;

private:
    Ui::MainWindow *ui;
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    void wheelEvent(QWheelEvent *event);

    double scaleFactor;


    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QImage image;

    QLabel *g_photo_orig;
    QGridLayout *g_layout;
    QLabel *g_filter_median; // pour filtre median
    QLabel *g_filter_moyen;
    QLabel *g_filter_gaussien;

    QGraphicsView *view;
    QGraphicsScene *scene;

    QLineEdit *loginBox;
    QLineEdit *passwordBox;
    QLineEdit *fileBox;


    QPushButton *buttonLogin;
    bool isLog; // est connecté
    bool isAdmin; // est admin
    QDialog *loginFenetre;
    QDialog *loginFenetreResultat;

    QSqlDatabase db;

    QString fileName;
    QString FileName;

    //QPushButton *buttonFile;
    //QDialog *fileFenetre;

    //QFileInfo fi(FileNameSave);

    bool eventFilter(QObject * obj, QEvent * event);
    //bool eventFilter(QObject *obj, QWheelEvent *event);

private slots:
    //void on_actionEnregisrer_triggered();
    void on_actionEnregisrer_triggered();
    void on_actionSe_d_connecter_triggered();
    void on_actionSeconnecter_triggered();
    void on_actionGaussien_triggered();
    void on_actionMoyen_triggered();
    void on_actionA_propos_triggered();
    void on_actionMedian_triggered();
    void on_actionEnregistrer_sous_triggered();
    void on_actionZoom_Arri_re_triggered();
    void on_actionZoom_Avant_triggered();
    void on_actionOuvrir_triggered();
    void on_actionQuitter_triggered();
    void connection();
    void closeLoginFenetre();
};

#endif // MAINWINDOW_H

