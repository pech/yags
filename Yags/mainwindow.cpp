#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlTableModel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zoom_active = false;

    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Dark);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    setCentralWidget(scrollArea);

    //Login
    QLabel *fileBoxTextLogin = new QLabel;
    QString texteLogin = "Login : ";
    fileBoxTextLogin->setText(texteLogin);
    QLabel *fileBoxTextPass = new QLabel;
    QString textePass = "Password : ";
    fileBoxTextPass->setText(textePass);

    loginBox = new QLineEdit;
    passwordBox = new QLineEdit;

    passwordBox->setEchoMode(QLineEdit::Password);
    buttonLogin = new QPushButton("Se connecter");
    isLog = false;
    isAdmin = false;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(fileBoxTextLogin);
    layout->addWidget(loginBox);
    layout->addWidget(fileBoxTextPass);
    layout->addWidget(passwordBox);
    layout->addWidget(buttonLogin);

    loginFenetre = new QDialog(parent);
    loginFenetre->setLayout(layout);
    loginFenetreResultat = new QDialog(parent);

    connect(buttonLogin, SIGNAL(clicked()), this, SLOT(connection()));


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

    FileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(), tr("Image Files(*.png *.jpg *.bmp)"));
    if ( !FileName.isEmpty() ) {
        image.load(FileName);
        if ( image.isNull() ) {
            QMessageBox::information(this, tr("Image"), tr("Cannot load %1.").arg(FileName));
            return;
        }

        zoom_active = true;
        imageLabel->setPixmap(QPixmap::fromImage(image));
        imageLabel->resize(imageLabel->pixmap()->size());
        scaleFactor = 1.0;
        this->ui->actionEnregistrer_sous->setEnabled(true);
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

    fileBox = new QLineEdit;
    fileBox->setText("");

    QLabel *fileBoxText = new QLabel;
    QString texte = "Nom du fichier : ";
    fileBoxText->setText(texte);

    QPushButton *buttonFile = new QPushButton("Enregistrer");

    QVBoxLayout *layoutfile = new QVBoxLayout;
    layoutfile->addWidget(fileBoxText);
    layoutfile->addWidget(fileBox);
    layoutfile->addWidget(buttonFile);

    QDialog *fileFenetre = new QDialog(0);
    fileFenetre->setLayout(layoutfile);

    connect(buttonFile, SIGNAL(clicked()), this, SLOT(on_actionEnregisrer_triggered()));

    fileFenetre->show();
    this->ui->actionEnregisrer->setEnabled(true);

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
    QRgb c;
    int rgauss;
    int ggauss;
    int bgauss;
       for(int i =1; i < image.width()-1; ++i) // parcours de l'image sans le contour.
          for(int j =1; j < image.height()-1; ++j) {
           rgauss=0;ggauss=0;bgauss=0;
             for (int k=0;k<3;k++)
                  for (int l=0;l<3;l++)
                 {
                    c = image.pixel(i+k-1,j+l-1);
                    rgauss+=qRed(c);
                    ggauss+=qGreen(c);
                    bgauss+=qBlue(c);
                 }
             c = image.pixel(i,j);
             rgauss+=qRed(c);
             ggauss+=qGreen(c);
             bgauss+=qBlue(c);
             rgauss/=10;
             ggauss/=10;
             bgauss/=10;
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
    if (zoom_active == true) {

        if(event->delta()>0)
            scaleImage(1.25);
        else
            scaleImage(0.8);
    }
}

bool MainWindow::eventFilter(QObject * obj, QEvent * event)
{
  if (event->type() == QEvent::Wheel) {
      if (zoom_active == true) {
                      scaleImage(1.25);
                  } else {
                       scaleImage(0.8);
                  }
       return true;
  } else {
    return MainWindow::eventFilter(obj, event);
  }
}


void MainWindow::connection()
{
    QHBoxLayout *layout = new QHBoxLayout;
    QLabel *label = new QLabel;
    QPushButton *button = new QPushButton;

    QSqlTableModel model;

    model.setTable("user2");
    model.setFilter("login = '"+loginBox->text()+"' and password = '"+passwordBox->text()+"'");
    model.select();

    int numrow = model.rowCount();

     QMessageBox::information(this, tr("info"), loginBox->text() + " " + passwordBox->text() + " " + QString::number(numrow));

     if (numrow > 0 ) {
        isLog = true;
        //label->setText("Connection reussie");
        layout->addWidget(label);
        layout->addWidget(button);
        //button->setText("Ok");
        connect(button, SIGNAL(clicked()), this, SLOT(closeLoginFenetre()));
        this->ui->actionSe_d_connecter->setEnabled(true);
        this->ui->actionSeconnecter->setEnabled(false);
        //label->setText("");
        //layout->removeWidget(label);
        this->ui->actionOuvrir->setEnabled(true);
    }
    else {

        //label->setText("Echec connection");
        layout->addWidget(label);
        layout->addWidget(button);
        button->setText("Reessayer");
        connect(button, SIGNAL(clicked()), this, SLOT(on_actionSeconnecter_triggered()));
        //layout->removeWidget(label);
    }


    loginFenetre->hide();
    loginFenetreResultat->setLayout(layout);
    loginFenetreResultat->show();
    layout->removeWidget(label);

}

void MainWindow::closeLoginFenetre() {
    loginFenetreResultat->hide();
    loginBox->setText("");
    passwordBox->setText("");
    loginFenetre->hide();

}



void MainWindow::on_actionSeconnecter_triggered()
{
    db = QSqlDatabase::addDatabase("QODBC");

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


    //test query

    //QSqlQuery query;

    //query.exec("create table user (id int primary key, "
    //           "login varchar(20), password varchar(20), address varchar(200), typeid int)");
    //query.exec("insert into user values(1, 'Alice', 'alice', "
    //           "'<qt>Alice@gmail.com', 1)");
    //query.exec("insert into user values(2, 'Bob', 'bob', "
    //           "'<qt>Bob@gmail.com', 1)");
    //query.exec("insert into user values(3, 'Carol', 'carol', "
    //           "'<qt>The Lighthouse</qt>', 1)");
    //query.exec("insert into user values(4, 'Donald', 'donald', "
    //           "'Donald@gmail.com', 1)");
    //query.exec("insert into user values(5, 'Emma', 'emma', "
    //           "'<qt>Emma@gmail.com</qt>', 1)");

    loginFenetreResultat->hide();
    loginBox->setText("");
    passwordBox->setText("");
    loginFenetre->show();

}

void MainWindow::on_actionSe_d_connecter_triggered()
{
    db.close();
    this->ui->actionSe_d_connecter->setEnabled(false);
    this->ui->actionSeconnecter->setEnabled(true);
    this->ui->actionOuvrir->setEnabled(false);
}

void MainWindow::on_actionEnregisrer_triggered()
{
    QString selectFilter;
    QString FileSave;
    //QString FileNameSave = QFileDialog::getSaveFileName(this, tr("Save"), QString(), tr("Image Files(*.png *.jpg *.bmp)"));
    if ( !fileBox->text().isEmpty() ) {
        QString format = selectFilter.split(" ").at(0);
        QFileInfo fi(fileBox->text());
        if ( !fi.suffix().endsWith(format, Qt::CaseInsensitive) ) {
            fileBox->text().chop(fi.suffix().length());
            fileBox->text() += "." + format.toLower();
        }
        if (!(fileBox->text().isNull())) {
            FileSave = "C:/Users/Belle/Documents/Median/"+fileBox->text()+".png";
            QMessageBox::information(this, "Image Save", FileSave);
    }
        else {
            FileSave = "C:/Users/Belle/Documents/Median/"+FileName+".png";
        }

        if ( !image.save(FileSave, format.toAscii().constData()) ) {
            QMessageBox::information(this, "Image Save", QString("Unable to save %1.").arg(FileSave));
        }

    }
}
