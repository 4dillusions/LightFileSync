/********************************************************************************
** Form generated from reading UI file 'SettingsView.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSVIEW_H
#define UI_SETTINGSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SettingsView
{
public:
    QGroupBox *groupBox;
    QPushButton *OkButton;
    QLabel *label;
    QComboBox *LeftOnlyCbox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *LeftNewCbox;
    QComboBox *RightNewCbox;
    QComboBox *RightOnlyCbox;
    QLabel *CategoryLabel;
    QLabel *ActionLabel;
    QLabel *LeftOnlyLabel;
    QLabel *LeftNewLabel;
    QLabel *RightNewLabel;
    QLabel *RightOnlyLabel;

    void setupUi(QDialog *SettingsView)
    {
        if (SettingsView->objectName().isEmpty())
            SettingsView->setObjectName(QStringLiteral("SettingsView"));
        SettingsView->resize(470, 230);
        SettingsView->setMinimumSize(QSize(470, 230));
        SettingsView->setMaximumSize(QSize(470, 230));
        SettingsView->setModal(true);
        groupBox = new QGroupBox(SettingsView);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 170, 440, 1));
        OkButton = new QPushButton(SettingsView);
        OkButton->setObjectName(QStringLiteral("OkButton"));
        OkButton->setGeometry(QRect(380, 190, 75, 23));
        label = new QLabel(SettingsView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 80, 40));
        label->setPixmap(QPixmap(QString::fromUtf8("Resources/LeftOnly.png")));
        LeftOnlyCbox = new QComboBox(SettingsView);
        LeftOnlyCbox->addItem(QString());
        LeftOnlyCbox->addItem(QString());
        LeftOnlyCbox->addItem(QString());
        LeftOnlyCbox->addItem(QString());
        LeftOnlyCbox->addItem(QString());
        LeftOnlyCbox->addItem(QString());
        LeftOnlyCbox->addItem(QString());
        LeftOnlyCbox->setObjectName(QStringLiteral("LeftOnlyCbox"));
        LeftOnlyCbox->setGeometry(QRect(20, 80, 100, 22));
        label_2 = new QLabel(SettingsView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 30, 80, 40));
        label_2->setPixmap(QPixmap(QString::fromUtf8("Resources/LeftNew.png")));
        label_3 = new QLabel(SettingsView);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 30, 80, 40));
        label_3->setPixmap(QPixmap(QString::fromUtf8("Resources/RightNew.png")));
        label_4 = new QLabel(SettingsView);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(360, 30, 80, 40));
        label_4->setPixmap(QPixmap(QString::fromUtf8("Resources/RightOnly.png")));
        LeftNewCbox = new QComboBox(SettingsView);
        LeftNewCbox->addItem(QString());
        LeftNewCbox->addItem(QString());
        LeftNewCbox->addItem(QString());
        LeftNewCbox->addItem(QString());
        LeftNewCbox->addItem(QString());
        LeftNewCbox->addItem(QString());
        LeftNewCbox->addItem(QString());
        LeftNewCbox->setObjectName(QStringLiteral("LeftNewCbox"));
        LeftNewCbox->setGeometry(QRect(130, 80, 100, 22));
        RightNewCbox = new QComboBox(SettingsView);
        RightNewCbox->addItem(QString());
        RightNewCbox->addItem(QString());
        RightNewCbox->addItem(QString());
        RightNewCbox->addItem(QString());
        RightNewCbox->addItem(QString());
        RightNewCbox->addItem(QString());
        RightNewCbox->addItem(QString());
        RightNewCbox->setObjectName(QStringLiteral("RightNewCbox"));
        RightNewCbox->setGeometry(QRect(240, 80, 100, 22));
        RightOnlyCbox = new QComboBox(SettingsView);
        RightOnlyCbox->addItem(QString());
        RightOnlyCbox->addItem(QString());
        RightOnlyCbox->addItem(QString());
        RightOnlyCbox->addItem(QString());
        RightOnlyCbox->addItem(QString());
        RightOnlyCbox->addItem(QString());
        RightOnlyCbox->addItem(QString());
        RightOnlyCbox->setObjectName(QStringLiteral("RightOnlyCbox"));
        RightOnlyCbox->setGeometry(QRect(350, 80, 100, 22));
        CategoryLabel = new QLabel(SettingsView);
        CategoryLabel->setObjectName(QStringLiteral("CategoryLabel"));
        CategoryLabel->setGeometry(QRect(210, 10, 51, 20));
        ActionLabel = new QLabel(SettingsView);
        ActionLabel->setObjectName(QStringLiteral("ActionLabel"));
        ActionLabel->setGeometry(QRect(220, 140, 31, 20));
        LeftOnlyLabel = new QLabel(SettingsView);
        LeftOnlyLabel->setObjectName(QStringLiteral("LeftOnlyLabel"));
        LeftOnlyLabel->setGeometry(QRect(45, 110, 48, 24));
        LeftNewLabel = new QLabel(SettingsView);
        LeftNewLabel->setObjectName(QStringLiteral("LeftNewLabel"));
        LeftNewLabel->setGeometry(QRect(155, 110, 48, 24));
        RightNewLabel = new QLabel(SettingsView);
        RightNewLabel->setObjectName(QStringLiteral("RightNewLabel"));
        RightNewLabel->setGeometry(QRect(265, 110, 48, 24));
        RightOnlyLabel = new QLabel(SettingsView);
        RightOnlyLabel->setObjectName(QStringLiteral("RightOnlyLabel"));
        RightOnlyLabel->setGeometry(QRect(375, 110, 48, 24));

        retranslateUi(SettingsView);
        QObject::connect(LeftOnlyCbox, SIGNAL(currentIndexChanged(int)), SettingsView, SLOT(LeftOnlyCboxIndexChanged(int)));
        QObject::connect(LeftNewCbox, SIGNAL(currentIndexChanged(int)), SettingsView, SLOT(LeftNewCboxIndexChanged(int)));
        QObject::connect(RightNewCbox, SIGNAL(currentIndexChanged(int)), SettingsView, SLOT(RightNewCboxIndexChanged(int)));
        QObject::connect(RightOnlyCbox, SIGNAL(currentIndexChanged(int)), SettingsView, SLOT(RightOnlyCboxIndexChanged(int)));
        QObject::connect(OkButton, SIGNAL(clicked()), SettingsView, SLOT(OkClicked()));

        QMetaObject::connectSlotsByName(SettingsView);
    } // setupUi

    void retranslateUi(QDialog *SettingsView)
    {
        SettingsView->setWindowTitle(QApplication::translate("SettingsView", "Settings", nullptr));
        groupBox->setTitle(QString());
        OkButton->setText(QApplication::translate("SettingsView", "Ok", nullptr));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("SettingsView", "Left only", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QString());
        LeftOnlyCbox->setItemText(0, QApplication::translate("SettingsView", "Nothing", nullptr));
        LeftOnlyCbox->setItemText(1, QApplication::translate("SettingsView", "CopyLeft", nullptr));
        LeftOnlyCbox->setItemText(2, QApplication::translate("SettingsView", "CopyRight", nullptr));
        LeftOnlyCbox->setItemText(3, QApplication::translate("SettingsView", "OverrideLeft", nullptr));
        LeftOnlyCbox->setItemText(4, QApplication::translate("SettingsView", "OverrideRight", nullptr));
        LeftOnlyCbox->setItemText(5, QApplication::translate("SettingsView", "DeleteLeft", nullptr));
        LeftOnlyCbox->setItemText(6, QApplication::translate("SettingsView", "DeleteRight", nullptr));

#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("SettingsView", "Left new", nullptr));
#endif // QT_NO_TOOLTIP
        label_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("SettingsView", "Right new", nullptr));
#endif // QT_NO_TOOLTIP
        label_3->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("SettingsView", "Right only", nullptr));
#endif // QT_NO_TOOLTIP
        label_4->setText(QString());
        LeftNewCbox->setItemText(0, QApplication::translate("SettingsView", "Nothing", nullptr));
        LeftNewCbox->setItemText(1, QApplication::translate("SettingsView", "CopyLeft", nullptr));
        LeftNewCbox->setItemText(2, QApplication::translate("SettingsView", "CopyRight", nullptr));
        LeftNewCbox->setItemText(3, QApplication::translate("SettingsView", "OverrideLeft", nullptr));
        LeftNewCbox->setItemText(4, QApplication::translate("SettingsView", "OverrideRight", nullptr));
        LeftNewCbox->setItemText(5, QApplication::translate("SettingsView", "DeleteLeft", nullptr));
        LeftNewCbox->setItemText(6, QApplication::translate("SettingsView", "DeleteRight", nullptr));

        RightNewCbox->setItemText(0, QApplication::translate("SettingsView", "Nothing", nullptr));
        RightNewCbox->setItemText(1, QApplication::translate("SettingsView", "CopyLeft", nullptr));
        RightNewCbox->setItemText(2, QApplication::translate("SettingsView", "CopyRight", nullptr));
        RightNewCbox->setItemText(3, QApplication::translate("SettingsView", "OverrideLeft", nullptr));
        RightNewCbox->setItemText(4, QApplication::translate("SettingsView", "OverrideRight", nullptr));
        RightNewCbox->setItemText(5, QApplication::translate("SettingsView", "DeleteLeft", nullptr));
        RightNewCbox->setItemText(6, QApplication::translate("SettingsView", "DeleteRight", nullptr));

        RightOnlyCbox->setItemText(0, QApplication::translate("SettingsView", "Nothing", nullptr));
        RightOnlyCbox->setItemText(1, QApplication::translate("SettingsView", "CopyLeft", nullptr));
        RightOnlyCbox->setItemText(2, QApplication::translate("SettingsView", "CopyRight", nullptr));
        RightOnlyCbox->setItemText(3, QApplication::translate("SettingsView", "OverrideLeft", nullptr));
        RightOnlyCbox->setItemText(4, QApplication::translate("SettingsView", "OverrideRight", nullptr));
        RightOnlyCbox->setItemText(5, QApplication::translate("SettingsView", "DeleteLeft", nullptr));
        RightOnlyCbox->setItemText(6, QApplication::translate("SettingsView", "DeleteRight", nullptr));

        CategoryLabel->setText(QApplication::translate("SettingsView", "Category", nullptr));
        ActionLabel->setText(QApplication::translate("SettingsView", "Action", nullptr));
        LeftOnlyLabel->setText(QString());
        LeftNewLabel->setText(QString());
        RightNewLabel->setText(QString());
        RightOnlyLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SettingsView: public Ui_SettingsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSVIEW_H
