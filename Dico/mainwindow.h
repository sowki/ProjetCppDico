#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QString"
#include "mot.h"
#include "GestionnaireSauvegardeSQLite.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void lancerTest();
    void rechercheSaisie();
    
private:
    Ui::MainWindow *ui;
    GestionnaireSauvegardeSQLite *monSQL;
};

#endif // MAINWINDOW_H
