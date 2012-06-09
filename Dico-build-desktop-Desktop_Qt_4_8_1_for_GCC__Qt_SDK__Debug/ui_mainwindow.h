/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Jun 6 22:39:11 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *rechercheLayout;
    QLineEdit *rechercheBar;
    QListView *rechercheList;
    QWidget *calque;
    QWidget *gridLayoutWidget;
    QGridLayout *testLayout;
    QLineEdit *insertMot;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *validButton;
    QTextEdit *insertDef;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(603, 435);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(390, 30, 201, 141));
        rechercheLayout = new QVBoxLayout(verticalLayoutWidget);
        rechercheLayout->setSpacing(6);
        rechercheLayout->setContentsMargins(11, 11, 11, 11);
        rechercheLayout->setObjectName(QString::fromUtf8("rechercheLayout"));
        rechercheLayout->setContentsMargins(0, 0, 0, 0);
        rechercheBar = new QLineEdit(verticalLayoutWidget);
        rechercheBar->setObjectName(QString::fromUtf8("rechercheBar"));

        rechercheLayout->addWidget(rechercheBar);

        rechercheList = new QListView(verticalLayoutWidget);
        rechercheList->setObjectName(QString::fromUtf8("rechercheList"));

        rechercheLayout->addWidget(rechercheList);

        calque = new QWidget(centralWidget);
        calque->setObjectName(QString::fromUtf8("calque"));
        calque->setGeometry(QRect(0, 0, 381, 221));
        gridLayoutWidget = new QWidget(calque);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, -20, 450, 209));
        testLayout = new QGridLayout(gridLayoutWidget);
        testLayout->setSpacing(6);
        testLayout->setContentsMargins(11, 11, 11, 11);
        testLayout->setObjectName(QString::fromUtf8("testLayout"));
        testLayout->setContentsMargins(0, 0, 0, 0);
        insertMot = new QLineEdit(gridLayoutWidget);
        insertMot->setObjectName(QString::fromUtf8("insertMot"));

        testLayout->addWidget(insertMot, 2, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        testLayout->addWidget(label, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        testLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        validButton = new QPushButton(gridLayoutWidget);
        validButton->setObjectName(QString::fromUtf8("validButton"));

        testLayout->addWidget(validButton, 4, 1, 1, 1);

        insertDef = new QTextEdit(gridLayoutWidget);
        insertDef->setObjectName(QString::fromUtf8("insertDef"));

        testLayout->addWidget(insertDef, 3, 0, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(410, 230, 113, 22));
        MainWindow->setCentralWidget(centralWidget);
        verticalLayoutWidget->raise();
        calque->raise();
        rechercheList->raise();
        lineEdit->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 603, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        insertMot->setText(QApplication::translate("MainWindow", "Veuillez \303\251crire un mot", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Bienvenue dans le test d'insertion de mots", 0, QApplication::UnicodeUTF8));
        validButton->setText(QApplication::translate("MainWindow", "Ins\303\251rer", 0, QApplication::UnicodeUTF8));
        insertDef->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Veuillez \303\251crire une d\303\251finiton</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
