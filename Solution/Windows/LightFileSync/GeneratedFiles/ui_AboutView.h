/********************************************************************************
** Form generated from reading UI file 'AboutView.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTVIEW_H
#define UI_ABOUTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutView
{
public:
    QPushButton *OkButton;
    QGroupBox *groupBox;
    QLabel *Copyright;
    QLabel *WrittenIn;
    QLabel *Logo;
    QLabel *QtLogo;
    QLabel *GithubLogo;

    void setupUi(QDialog *AboutView)
    {
        if (AboutView->objectName().isEmpty())
            AboutView->setObjectName(QStringLiteral("AboutView"));
        AboutView->resize(400, 300);
        AboutView->setMinimumSize(QSize(400, 300));
        AboutView->setMaximumSize(QSize(400, 300));
        AboutView->setModal(true);
        OkButton = new QPushButton(AboutView);
        OkButton->setObjectName(QStringLiteral("OkButton"));
        OkButton->setGeometry(QRect(310, 260, 75, 23));
        groupBox = new QGroupBox(AboutView);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 240, 371, 1));
        Copyright = new QLabel(AboutView);
        Copyright->setObjectName(QStringLiteral("Copyright"));
        Copyright->setGeometry(QRect(120, 120, 141, 21));
        WrittenIn = new QLabel(AboutView);
        WrittenIn->setObjectName(QStringLiteral("WrittenIn"));
        WrittenIn->setGeometry(QRect(110, 140, 171, 16));
        Logo = new QLabel(AboutView);
        Logo->setObjectName(QStringLiteral("Logo"));
        Logo->setGeometry(QRect(140, 20, 100, 100));
        Logo->setPixmap(QPixmap(QString::fromUtf8("Resources/syncMedium.png")));
        QtLogo = new QLabel(AboutView);
        QtLogo->setObjectName(QStringLiteral("QtLogo"));
        QtLogo->setGeometry(QRect(120, 160, 64, 54));
        QtLogo->setPixmap(QPixmap(QString::fromUtf8("Resources/qt.png")));
        GithubLogo = new QLabel(AboutView);
        GithubLogo->setObjectName(QStringLiteral("GithubLogo"));
        GithubLogo->setGeometry(QRect(200, 160, 54, 54));
        GithubLogo->setPixmap(QPixmap(QString::fromUtf8("Resources/github.png")));

        retranslateUi(AboutView);
        QObject::connect(OkButton, SIGNAL(clicked()), AboutView, SLOT(close()));

        QMetaObject::connectSlotsByName(AboutView);
    } // setupUi

    void retranslateUi(QDialog *AboutView)
    {
        AboutView->setWindowTitle(QApplication::translate("AboutView", "About", nullptr));
        OkButton->setText(QApplication::translate("AboutView", "Ok", nullptr));
        groupBox->setTitle(QString());
        Copyright->setText(QApplication::translate("AboutView", "\302\251 4D Illusions - Robert Oze", nullptr));
        WrittenIn->setText(QApplication::translate("AboutView", "Source code written in C++ using:", nullptr));
        Logo->setText(QString());
        QtLogo->setText(QString());
        GithubLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutView: public Ui_AboutView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTVIEW_H
