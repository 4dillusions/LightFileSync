/********************************************************************************
** Form generated from reading UI file 'MainView.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainViewClass
{
public:
    QAction *actionSync;
    QAction *actionSettings;
    QAction *actionInfo;
    QAction *actionStop;
    QAction *actionSave;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QTableWidget *FoldersTable;
    QLineEdit *RightFolderText;
    QToolButton *DeleteSyncFoldersButton;
    QTableWidget *SyncTable;
    QLineEdit *LeftFolderText;
    QPushButton *BrowseFolderLeftButton;
    QToolButton *AddSyncFoldersButton;
    QPushButton *BrowseFolderRightButton;
    QProgressBar *Progress;
    QToolBar *mainToolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *AddWorkflowButton;
    QToolButton *DeleteWorkflowButton;
    QLineEdit *WorkflowText;
    QSpacerItem *horizontalSpacer;
    QListWidget *WorkflowItemList;

    void setupUi(QMainWindow *MainViewClass)
    {
        if (MainViewClass->objectName().isEmpty())
            MainViewClass->setObjectName(QStringLiteral("MainViewClass"));
        MainViewClass->resize(1024, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainViewClass->sizePolicy().hasHeightForWidth());
        MainViewClass->setSizePolicy(sizePolicy);
        MainViewClass->setMinimumSize(QSize(1024, 600));
        actionSync = new QAction(MainViewClass);
        actionSync->setObjectName(QStringLiteral("actionSync"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MainView/Resources/sync.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSync->setIcon(icon);
        actionSettings = new QAction(MainViewClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MainView/Resources/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon1);
        actionInfo = new QAction(MainViewClass);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MainView/Resources/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfo->setIcon(icon2);
        actionStop = new QAction(MainViewClass);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionStop->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/MainView/Resources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon3);
        actionSave = new QAction(MainViewClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/MainView/Resources/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        centralWidget = new QWidget(MainViewClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(500, 500));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        FoldersTable = new QTableWidget(groupBox);
        if (FoldersTable->columnCount() < 2)
            FoldersTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        FoldersTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        FoldersTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        FoldersTable->setObjectName(QStringLiteral("FoldersTable"));
        FoldersTable->setMinimumSize(QSize(0, 150));
        FoldersTable->setMaximumSize(QSize(16777215, 150));
        FoldersTable->setEditTriggers(QAbstractItemView::AnyKeyPressed);
        FoldersTable->setDragDropOverwriteMode(false);
        FoldersTable->setAlternatingRowColors(true);
        FoldersTable->setSelectionMode(QAbstractItemView::SingleSelection);
        FoldersTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        FoldersTable->setShowGrid(true);
        FoldersTable->setRowCount(0);
        FoldersTable->horizontalHeader()->setCascadingSectionResizes(false);
        FoldersTable->horizontalHeader()->setStretchLastSection(false);
        FoldersTable->verticalHeader()->setCascadingSectionResizes(false);

        gridLayout_3->addWidget(FoldersTable, 0, 0, 1, 6);

        RightFolderText = new QLineEdit(groupBox);
        RightFolderText->setObjectName(QStringLiteral("RightFolderText"));
        RightFolderText->setReadOnly(true);

        gridLayout_3->addWidget(RightFolderText, 1, 4, 1, 1);

        DeleteSyncFoldersButton = new QToolButton(groupBox);
        DeleteSyncFoldersButton->setObjectName(QStringLiteral("DeleteSyncFoldersButton"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/MainView/Resources/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        DeleteSyncFoldersButton->setIcon(icon5);
        DeleteSyncFoldersButton->setIconSize(QSize(24, 24));
        DeleteSyncFoldersButton->setToolButtonStyle(Qt::ToolButtonFollowStyle);

        gridLayout_3->addWidget(DeleteSyncFoldersButton, 1, 1, 1, 1);

        SyncTable = new QTableWidget(groupBox);
        if (SyncTable->columnCount() < 7)
            SyncTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        SyncTable->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        SyncTable->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        SyncTable->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        SyncTable->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        SyncTable->setHorizontalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        SyncTable->setHorizontalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        SyncTable->setHorizontalHeaderItem(6, __qtablewidgetitem8);
        SyncTable->setObjectName(QStringLiteral("SyncTable"));
        SyncTable->setEditTriggers(QAbstractItemView::AnyKeyPressed);
        SyncTable->setDragDropOverwriteMode(false);
        SyncTable->setAlternatingRowColors(true);
        SyncTable->setSelectionMode(QAbstractItemView::SingleSelection);
        SyncTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        SyncTable->setRowCount(0);

        gridLayout_3->addWidget(SyncTable, 2, 0, 1, 6);

        LeftFolderText = new QLineEdit(groupBox);
        LeftFolderText->setObjectName(QStringLiteral("LeftFolderText"));
        LeftFolderText->setReadOnly(true);

        gridLayout_3->addWidget(LeftFolderText, 1, 2, 1, 1);

        BrowseFolderLeftButton = new QPushButton(groupBox);
        BrowseFolderLeftButton->setObjectName(QStringLiteral("BrowseFolderLeftButton"));

        gridLayout_3->addWidget(BrowseFolderLeftButton, 1, 3, 1, 1);

        AddSyncFoldersButton = new QToolButton(groupBox);
        AddSyncFoldersButton->setObjectName(QStringLiteral("AddSyncFoldersButton"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/MainView/Resources/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddSyncFoldersButton->setIcon(icon6);
        AddSyncFoldersButton->setIconSize(QSize(24, 24));
        AddSyncFoldersButton->setToolButtonStyle(Qt::ToolButtonFollowStyle);

        gridLayout_3->addWidget(AddSyncFoldersButton, 1, 0, 1, 1);

        BrowseFolderRightButton = new QPushButton(groupBox);
        BrowseFolderRightButton->setObjectName(QStringLiteral("BrowseFolderRightButton"));

        gridLayout_3->addWidget(BrowseFolderRightButton, 1, 5, 1, 1);


        horizontalLayout->addWidget(groupBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        Progress = new QProgressBar(centralWidget);
        Progress->setObjectName(QStringLiteral("Progress"));
        Progress->setValue(0);

        gridLayout->addWidget(Progress, 1, 0, 1, 1);

        MainViewClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainViewClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMinimumSize(QSize(0, 0));
        mainToolBar->setIconSize(QSize(34, 34));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        MainViewClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        dockWidget = new QDockWidget(MainViewClass);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMinimumSize(QSize(270, 230));
        dockWidget->setAutoFillBackground(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidgetContents->setLayoutDirection(Qt::LeftToRight);
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        AddWorkflowButton = new QToolButton(dockWidgetContents);
        AddWorkflowButton->setObjectName(QStringLiteral("AddWorkflowButton"));
        AddWorkflowButton->setIcon(icon6);
        AddWorkflowButton->setIconSize(QSize(24, 24));
        AddWorkflowButton->setToolButtonStyle(Qt::ToolButtonFollowStyle);

        horizontalLayout_2->addWidget(AddWorkflowButton);

        DeleteWorkflowButton = new QToolButton(dockWidgetContents);
        DeleteWorkflowButton->setObjectName(QStringLiteral("DeleteWorkflowButton"));
        DeleteWorkflowButton->setIcon(icon5);
        DeleteWorkflowButton->setIconSize(QSize(24, 24));
        DeleteWorkflowButton->setToolButtonStyle(Qt::ToolButtonFollowStyle);

        horizontalLayout_2->addWidget(DeleteWorkflowButton);

        WorkflowText = new QLineEdit(dockWidgetContents);
        WorkflowText->setObjectName(QStringLiteral("WorkflowText"));

        horizontalLayout_2->addWidget(WorkflowText);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        WorkflowItemList = new QListWidget(dockWidgetContents);
        WorkflowItemList->setObjectName(QStringLiteral("WorkflowItemList"));

        gridLayout_2->addWidget(WorkflowItemList, 1, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MainViewClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        mainToolBar->addAction(actionSync);
        mainToolBar->addAction(actionStop);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSettings);
        mainToolBar->addAction(actionInfo);

        retranslateUi(MainViewClass);
        QObject::connect(mainToolBar, SIGNAL(actionTriggered(QAction*)), MainViewClass, SLOT(ToolBarTriggered(QAction*)));
        QObject::connect(WorkflowItemList, SIGNAL(currentRowChanged(int)), MainViewClass, SLOT(WorkflowListChanged(int)));
        QObject::connect(WorkflowItemList, SIGNAL(currentTextChanged(QString)), WorkflowText, SLOT(setText(QString)));
        QObject::connect(AddWorkflowButton, SIGNAL(clicked()), MainViewClass, SLOT(WorkflowListAddClick()));
        QObject::connect(DeleteWorkflowButton, SIGNAL(clicked()), MainViewClass, SLOT(WorkflowListDeleteClick()));
        QObject::connect(AddSyncFoldersButton, SIGNAL(clicked()), MainViewClass, SLOT(FoldersTableAddClick()));
        QObject::connect(DeleteSyncFoldersButton, SIGNAL(clicked()), MainViewClass, SLOT(FoldersTableDeleteClick()));
        QObject::connect(BrowseFolderLeftButton, SIGNAL(clicked()), MainViewClass, SLOT(FoldersTableLeftBrowseClick()));
        QObject::connect(BrowseFolderRightButton, SIGNAL(clicked()), MainViewClass, SLOT(FoldersTableRightBrowseClick()));
        QObject::connect(FoldersTable, SIGNAL(itemSelectionChanged()), MainViewClass, SLOT(FoldersTableItemSelectionChanged()));

        QMetaObject::connectSlotsByName(MainViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainViewClass)
    {
        MainViewClass->setWindowTitle(QApplication::translate("MainViewClass", "LightFileSync", nullptr));
        actionSync->setText(QApplication::translate("MainViewClass", "Sync", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSync->setToolTip(QApplication::translate("MainViewClass", "Sync", nullptr));
#endif // QT_NO_TOOLTIP
        actionSettings->setText(QApplication::translate("MainViewClass", "Settings", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSettings->setToolTip(QApplication::translate("MainViewClass", "Settings", nullptr));
#endif // QT_NO_TOOLTIP
        actionInfo->setText(QApplication::translate("MainViewClass", "Info", nullptr));
#ifndef QT_NO_TOOLTIP
        actionInfo->setToolTip(QApplication::translate("MainViewClass", "Info", nullptr));
#endif // QT_NO_TOOLTIP
        actionStop->setText(QApplication::translate("MainViewClass", "Stop", nullptr));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("MainViewClass", "Stop", nullptr));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("MainViewClass", "Save", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainViewClass", "Save", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem = FoldersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainViewClass", "Left folder", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = FoldersTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainViewClass", "Right folder", nullptr));
#ifndef QT_NO_TOOLTIP
        DeleteSyncFoldersButton->setToolTip(QApplication::translate("MainViewClass", "Delete", nullptr));
#endif // QT_NO_TOOLTIP
        DeleteSyncFoldersButton->setText(QApplication::translate("MainViewClass", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = SyncTable->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainViewClass", "Left file", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = SyncTable->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainViewClass", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = SyncTable->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainViewClass", "Cat.", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = SyncTable->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainViewClass", "Action", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = SyncTable->horizontalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("MainViewClass", "Right file", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = SyncTable->horizontalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("MainViewClass", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = SyncTable->horizontalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("MainViewClass", "Ok", nullptr));
        BrowseFolderLeftButton->setText(QApplication::translate("MainViewClass", "Browse left", nullptr));
#ifndef QT_NO_TOOLTIP
        AddSyncFoldersButton->setToolTip(QApplication::translate("MainViewClass", "Add", nullptr));
#endif // QT_NO_TOOLTIP
        AddSyncFoldersButton->setText(QApplication::translate("MainViewClass", "...", nullptr));
        BrowseFolderRightButton->setText(QApplication::translate("MainViewClass", "Browse right", nullptr));
        dockWidget->setWindowTitle(QApplication::translate("MainViewClass", "Workflows", nullptr));
#ifndef QT_NO_TOOLTIP
        AddWorkflowButton->setToolTip(QApplication::translate("MainViewClass", "Add", nullptr));
#endif // QT_NO_TOOLTIP
        AddWorkflowButton->setText(QApplication::translate("MainViewClass", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        DeleteWorkflowButton->setToolTip(QApplication::translate("MainViewClass", "Delete", nullptr));
#endif // QT_NO_TOOLTIP
        DeleteWorkflowButton->setText(QApplication::translate("MainViewClass", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainViewClass: public Ui_MainViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
