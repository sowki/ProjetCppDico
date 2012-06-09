#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCompleter>
#include <QtDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->validButton,SIGNAL(clicked()),this, SLOT(lancerTest()));
    connect(ui->rechercheBar,SIGNAL(textEdited(QString)),this, SLOT(rechercheSaisie()));
    monSQL = new GestionnaireSauvegardeSQLite();
    monSQL->initDB();

    QStringList completerList;
    completerList << "Un"<< "Une"<< "Unu" << "Deux" << "Trois" << "Quatre" << "Cinq" << "Six" << "Sept";
    ui->lineEdit->setCompleter(new QCompleter(completerList));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete monSQL;
}

void MainWindow::lancerTest()
{
    QString mot = ui->insertMot->text();
    QString def = "definition";

    qDebug() << "Mot saisi : " + mot;


    //Mot* nouveauMot = new Mot(mot,def,);
    //monSQL->sauvegarderMot(*nouveauMot);
    //monSQL->selectMot(nouveauMot->getNom());
}

void MainWindow::rechercheSaisie()
{
    qDebug() << "recherche lancée...";
    ui->calque->hide();
}
