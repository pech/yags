#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Dark);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    setCentralWidget(scrollArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_actionOuvrir_triggered()
{
    QString filter;
    QString selectFilter;
    QList<QByteArray> formats = QImageWriter::supportedImageFormats();
    foreach (QString format, formats) {
        filter += QString("%1 files(*.%2);;").arg(format.toUpper()).arg(format);
    }
    if ( filter.endsWith(";;") ) {
        filter.chop(2);
    }

    QString FileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(), tr("Image Files(*.png *.jpg *.bmp)"));
    if ( !FileName.isEmpty() ) {
        image.load(FileName);
        if ( image.isNull() ) {
            QMessageBox::information(this, tr("Image"), tr("Cannot load %1.").arg(FileName));
            return;
        }

        imageLabel->setPixmap(QPixmap::fromImage(image));
        imageLabel->resize(imageLabel->pixmap()->size());
        scaleFactor = 1.0;
        this->ui->actionEnregistrer_sous->setEnabled(true);
        this->ui->actionEnregisrer->setEnabled(true);
        this->ui->actionZoom_Arri_re->setEnabled(true);
        this->ui->actionZoom_Avant->setEnabled(true);
    }
}

void MainWindow::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value() + ((factor - 1) * scrollBar->pageStep()/2)));
}

void MainWindow::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);
}

void MainWindow::on_actionZoom_Avant_triggered()
{
    scaleImage(1.25);
}

void MainWindow::on_actionZoom_Arri_re_triggered()
{
    scaleImage(0.8);
}

void MainWindow::on_actionEnregistrer_sous_triggered()
{
    QString filter;
    QList<QByteArray> formats = QImageWriter::supportedImageFormats();
    foreach (QString format, formats) {
        filter += QString("%1 files (*.%2);;").arg(format.toUpper()).arg(format);
    }
    if ( filter.endsWith(";;") ){
        filter.chop(2);
    }

    QString selectFilter;
    QString FileNameSave = QFileDialog::getSaveFileName(this, tr("Save"), QString(), tr("Image Files(*.png *.jpg *.bmp)"));
    if ( !FileNameSave.isEmpty() ) {
        QString format = selectFilter.split(" ").at(0);
        QFileInfo fi(FileNameSave);
        if ( !fi.suffix().endsWith(format, Qt::CaseInsensitive) ) {
            FileNameSave.chop(fi.suffix().length());
            FileNameSave += "." + format.toLower();
        }
        if ( !image.save(FileNameSave, format.toAscii().constData()) ) {
            QMessageBox::information(this, "Image Save", QString("Unable to save %1.").arg(FileNameSave));
        }
    }
}

void tri(int *tab) {
    int temp;
    for (int i = 0; i < 9; i++)  /* Tri à bulles */
      {
          for (int j = 0; j < 8; j++)
          {
              if(tab[j] > tab[j+1])
              {
                   temp = tab[j];
                   tab[j] = tab[j+1];
                   tab[j+1] = temp;
             }
          }
      }  /* Fin du Tri à bulles */
}

void MainWindow::on_actionMedian_triggered()
{
    QMessageBox::information(this, tr("Info"), tr("Action Median"));
    QWidget *g_zoneCentral = new QWidget;
    setWindowTitle(tr("Median Filter"));
    g_photo_orig = new QLabel(tr("Photo Origine"));
    g_photo_orig->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    g_photo_orig->setPixmap(QPixmap::fromImage(image));

    g_filter_median = new QLabel(tr("Filtre median"));
    g_filter_median->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    g_filter_median->setPixmap(QPixmap::fromImage(image));


    int tabr[9];
    int tabg[9];
    int tabb[9];

    for (int i = 0; i < 9; i++)
    {
          tabr[i] = 0;
          tabg[i] = 0;
          tabb[i] = 0;
    }

       for(int i =1; i < image.width()-1; ++i) // parcours de l'image sans le contour.
          for(int j =1; j < image.height()-1; ++j) {
           int val = 0;
             for (int k=0;k<3;k++)
             {
                  for (int l=0;l<3;l++)
                 {
                   QRgb c = image.pixel(i+k-1,j+l-1);
                   tabr[val]=qRed(c);
                   tabg[val]=qGreen(c);
                   tabb[val]=qBlue(c);
                   val++;
                 }
              }
             tri(tabr);
             tri(tabg);
             tri(tabb);
             image.setPixel(i,j,qRgb(tabr[4],tabg[4],tabb[4]));
          }

       g_filter_median->setPixmap(QPixmap::fromImage(image));


    g_layout = new QGridLayout(g_zoneCentral);
    g_layout->addWidget(g_photo_orig, 1, 0, 1, 2);
    g_layout->addWidget(g_filter_median, 1, 2, 1, 2);
    setLayout(g_layout);
    setCentralWidget(g_zoneCentral);
}

void MainWindow::on_actionMoyen_triggered()
{
    QMessageBox::information(this, tr("Info"), tr("Action Moyen"));
    QWidget *g_zoneCentral = new QWidget;
    setWindowTitle(tr("Average Filter"));
    g_photo_orig = new QLabel(tr("Photo Origine"));
    g_photo_orig->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    g_photo_orig->setPixmap(QPixmap::fromImage(image));

    g_filter_moyen = new QLabel(tr("Filtre moyen"));
    g_filter_moyen->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    g_filter_moyen->setPixmap(QPixmap::fromImage(image));


    int rmoy,gmoy,bmoy;
       for(int i =1; i < image.width()-1; ++i) // parcours de l'image sans le contour.
          for(int j =1; j < image.height()-1; ++j) {
             rmoy=0;gmoy=0;bmoy=0; // mise à 0 des moyennes.
             for (int k=0;k<3;k++)
                  for (int l=0;l<3;l++)
                 {
                   QRgb c = image.pixel(i+k-1,j+l-1);
                   rmoy+=qRed(c);
                   gmoy+=qGreen(c);
                   bmoy+=qBlue(c);
                 }
             rmoy=rmoy/9;
             gmoy=gmoy/9;
             bmoy=bmoy/9;
             image.setPixel(i,j,qRgb(rmoy,gmoy,bmoy));
          }

       g_filter_moyen->setPixmap(QPixmap::fromImage(image));


    g_layout = new QGridLayout(g_zoneCentral);
    g_layout->addWidget(g_photo_orig, 1, 0, 1, 2);
    g_layout->addWidget(g_filter_moyen, 1, 2, 1, 2);
    setLayout(g_layout);
    setCentralWidget(g_zoneCentral);
}

void MainWindow::on_actionGaussien_triggered()
{
    QMessageBox::information(this, tr("Info"), tr("Action Gaussien"));
    QWidget *g_zoneCentral = new QWidget;
    setWindowTitle(tr("Gaussian Filter"));
    g_photo_orig = new QLabel(tr("Photo Origine"));
    g_photo_orig->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    g_photo_orig->setPixmap(QPixmap::fromImage(image));

    g_filter_gaussien = new QLabel(tr("Filtre gaussien"));
    g_filter_gaussien->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    g_filter_gaussien->setPixmap(QPixmap::fromImage(image));

    QRgb c[9];
    int rgauss;
    int ggauss;
    int bgauss;

       for(int i =1; i < image.width()-1; ++i) // parcours de l'image sans le contour.
          for(int j =1; j < image.height()-1; ++j) {
           int val = 0;
             for (int k=0;k<3;k++)
                  for (int l=0;l<3;l++)
                 {
                   c[val] = image.pixel(i+k-1,j+l-1);
                   val++;
                 }

             rgauss=(qRed(c[0])+2*qRed(c[1])+qRed(c[2])+2*qRed(c[3])+4*qRed(c[4])+2*qRed(c[5])+qRed(c[6])+2*qRed(c[7])+qRed(c[8]))/9;
             ggauss=(qGreen(c[0])+2*qGreen(c[1])+qGreen(c[2])+2*qGreen(c[3])+4*qGreen(c[4])+2*qGreen(c[5])+qGreen(c[6])+2*qGreen(c[7])+qGreen(c[8]))/9;
             bgauss=(qBlue(c[0])+2*qBlue(c[1])+qBlue(c[2])+2*qBlue(c[3])+4*qBlue(c[4])+2*qBlue(c[5])+qBlue(c[6])+2*qBlue(c[7])+qBlue(c[8]))/9;

             image.setPixel(i,j,qRgb(rgauss,ggauss,bgauss));
          }

       g_filter_gaussien->setPixmap(QPixmap::fromImage(image));


    g_layout = new QGridLayout(g_zoneCentral);
    g_layout->addWidget(g_photo_orig, 1, 0, 1, 2);
    g_layout->addWidget(g_filter_gaussien, 1, 2, 1, 2);
    setLayout(g_layout);
    setCentralWidget(g_zoneCentral);
}

void MainWindow::on_actionA_propos_triggered()
{
    QMessageBox::information(this, tr("A propos..."), tr("<H2>Yags V1.0</H2>"
                                                         "<p>Copyright &copy; 2011</p>"
                                                         "<p> Promo-2012 <br> Enjoy !!!</p>"));
}


void MainWindow::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0)
        scaleImage(1.25);
    else
        scaleImage(0.8);
}

