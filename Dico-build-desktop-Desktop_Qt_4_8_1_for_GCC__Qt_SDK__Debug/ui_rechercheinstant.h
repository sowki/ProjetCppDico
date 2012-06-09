/********************************************************************************
** Form generated from reading UI file 'rechercheinstant.ui'
**
** Created: Sat Jun 2 18:01:41 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECHERCHEINSTANT_H
#define UI_RECHERCHEINSTANT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RechercheInstant
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *RechercheInstant)
    {
        if (RechercheInstant->objectName().isEmpty())
            RechercheInstant->setObjectName(QString::fromUtf8("RechercheInstant"));
        RechercheInstant->resize(400, 300);
        pushButton = new QPushButton(RechercheInstant);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 190, 114, 32));

        retranslateUi(RechercheInstant);

        QMetaObject::connectSlotsByName(RechercheInstant);
    } // setupUi

    void retranslateUi(QWidget *RechercheInstant)
    {
        RechercheInstant->setWindowTitle(QApplication::translate("RechercheInstant", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("RechercheInstant", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RechercheInstant: public Ui_RechercheInstant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECHERCHEINSTANT_H
