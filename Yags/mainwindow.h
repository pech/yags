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

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    double scaleFactor;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QImage image;

    QLabel *g_photo_orig;
    QGridLayout *g_layout;
    QLabel *g_filter_median; // pour filtre median
    QLabel *g_filter_moyen;
    QLabel *g_filter_gaussien;



private slots:
    void on_actionGaussien_triggered();
    void on_actionMoyen_triggered();
    void on_actionA_propos_triggered();
    void on_actionMedian_triggered();
    void on_actionEnregistrer_sous_triggered();
    void on_actionZoom_Arri_re_triggered();
    void on_actionZoom_Avant_triggered();
    void on_actionOuvrir_triggered();
    void on_actionQuitter_triggered();
};

#endif // MAINWINDOW_H
