/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "eventlabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenFile;
    QAction *actionOpenDir;
    QAction *actionSave;
    QAction *actionOutput_YOLO_Pics;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_Annotation;
    QGridLayout *gridLayout_4;
    QTabWidget *Annotation_tabWidget;
    QWidget *sonar_anno;
    QGridLayout *gridLayout;
    QListWidget *sonar_listWidget;
    QWidget *yolo_anno;
    QGridLayout *gridLayout_2;
    QListWidget *yolo_listWidget;
    QVBoxLayout *verticalLayout_5;
    EventLabel *label_image;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_Start;
    QPushButton *btn_Stop;
    QPushButton *btn_Pause;
    QPushButton *btn_Run;
    QPushButton *btn_SpeedUp;
    QPushButton *btn_SpeedDown;
    QLabel *label;
    QSlider *speedSlider;
    QGroupBox *groupBox_Label;
    QVBoxLayout *verticalLayout_2;
    QListWidget *Label_listWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_AddLabel;
    QLineEdit *lineEdit_newLabel;
    QGroupBox *groupBox_file;
    QGridLayout *gridLayout_3;
    QListWidget *Files_listWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/resource/pcl.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpenFile = new QAction(MainWindow);
        actionOpenFile->setObjectName(QStringLiteral("actionOpenFile"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/resource/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenFile->setIcon(icon1);
        actionOpenDir = new QAction(MainWindow);
        actionOpenDir->setObjectName(QStringLiteral("actionOpenDir"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/resource/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenDir->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/resource/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionOutput_YOLO_Pics = new QAction(MainWindow);
        actionOutput_YOLO_Pics->setObjectName(QStringLiteral("actionOutput_YOLO_Pics"));
        actionOutput_YOLO_Pics->setCheckable(false);
        actionOutput_YOLO_Pics->setEnabled(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Images/resource/red-circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOutput_YOLO_Pics->setIcon(icon4);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Images/resource/close-window.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_Annotation = new QGroupBox(centralWidget);
        groupBox_Annotation->setObjectName(QStringLiteral("groupBox_Annotation"));
        groupBox_Annotation->setMinimumSize(QSize(309, 287));
        gridLayout_4 = new QGridLayout(groupBox_Annotation);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        Annotation_tabWidget = new QTabWidget(groupBox_Annotation);
        Annotation_tabWidget->setObjectName(QStringLiteral("Annotation_tabWidget"));
        sizePolicy.setHeightForWidth(Annotation_tabWidget->sizePolicy().hasHeightForWidth());
        Annotation_tabWidget->setSizePolicy(sizePolicy);
        Annotation_tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        sonar_anno = new QWidget();
        sonar_anno->setObjectName(QStringLiteral("sonar_anno"));
        gridLayout = new QGridLayout(sonar_anno);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        sonar_listWidget = new QListWidget(sonar_anno);
        sonar_listWidget->setObjectName(QStringLiteral("sonar_listWidget"));
        sonar_listWidget->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(sonar_listWidget, 0, 0, 1, 1);

        Annotation_tabWidget->addTab(sonar_anno, QString());
        yolo_anno = new QWidget();
        yolo_anno->setObjectName(QStringLiteral("yolo_anno"));
        gridLayout_2 = new QGridLayout(yolo_anno);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        yolo_listWidget = new QListWidget(yolo_anno);
        yolo_listWidget->setObjectName(QStringLiteral("yolo_listWidget"));
        yolo_listWidget->setFrameShape(QFrame::NoFrame);

        gridLayout_2->addWidget(yolo_listWidget, 0, 0, 1, 1);

        Annotation_tabWidget->addTab(yolo_anno, QString());

        gridLayout_4->addWidget(Annotation_tabWidget, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_Annotation, 0, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_image = new EventLabel(centralWidget);
        label_image->setObjectName(QStringLiteral("label_image"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_image->sizePolicy().hasHeightForWidth());
        label_image->setSizePolicy(sizePolicy1);
        label_image->setMaximumSize(QSize(800, 800));
        label_image->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        label_image->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_image);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_Start = new QPushButton(centralWidget);
        btn_Start->setObjectName(QStringLiteral("btn_Start"));

        horizontalLayout->addWidget(btn_Start);

        btn_Stop = new QPushButton(centralWidget);
        btn_Stop->setObjectName(QStringLiteral("btn_Stop"));
        btn_Stop->setEnabled(false);

        horizontalLayout->addWidget(btn_Stop);

        btn_Pause = new QPushButton(centralWidget);
        btn_Pause->setObjectName(QStringLiteral("btn_Pause"));
        btn_Pause->setEnabled(false);

        horizontalLayout->addWidget(btn_Pause);

        btn_Run = new QPushButton(centralWidget);
        btn_Run->setObjectName(QStringLiteral("btn_Run"));
        btn_Run->setEnabled(false);

        horizontalLayout->addWidget(btn_Run);

        btn_SpeedUp = new QPushButton(centralWidget);
        btn_SpeedUp->setObjectName(QStringLiteral("btn_SpeedUp"));
        btn_SpeedUp->setEnabled(false);

        horizontalLayout->addWidget(btn_SpeedUp);

        btn_SpeedDown = new QPushButton(centralWidget);
        btn_SpeedDown->setObjectName(QStringLiteral("btn_SpeedDown"));
        btn_SpeedDown->setEnabled(false);

        horizontalLayout->addWidget(btn_SpeedDown);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        speedSlider = new QSlider(centralWidget);
        speedSlider->setObjectName(QStringLiteral("speedSlider"));
        speedSlider->setEnabled(false);
        speedSlider->setMaximumSize(QSize(300, 16777215));
        speedSlider->setMinimum(2500);
        speedSlider->setMaximum(200000);
        speedSlider->setSingleStep(1000);
        speedSlider->setValue(40000);
        speedSlider->setSliderPosition(40000);
        speedSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(speedSlider);


        verticalLayout_5->addLayout(horizontalLayout);


        gridLayout_5->addLayout(verticalLayout_5, 0, 0, 3, 1);

        groupBox_Label = new QGroupBox(centralWidget);
        groupBox_Label->setObjectName(QStringLiteral("groupBox_Label"));
        groupBox_Label->setMinimumSize(QSize(309, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox_Label);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Label_listWidget = new QListWidget(groupBox_Label);
        Label_listWidget->setObjectName(QStringLiteral("Label_listWidget"));
        Label_listWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(Label_listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_AddLabel = new QPushButton(groupBox_Label);
        btn_AddLabel->setObjectName(QStringLiteral("btn_AddLabel"));

        horizontalLayout_2->addWidget(btn_AddLabel);

        lineEdit_newLabel = new QLineEdit(groupBox_Label);
        lineEdit_newLabel->setObjectName(QStringLiteral("lineEdit_newLabel"));

        horizontalLayout_2->addWidget(lineEdit_newLabel);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout_5->addWidget(groupBox_Label, 1, 1, 1, 1);

        groupBox_file = new QGroupBox(centralWidget);
        groupBox_file->setObjectName(QStringLiteral("groupBox_file"));
        gridLayout_3 = new QGridLayout(groupBox_file);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        Files_listWidget = new QListWidget(groupBox_file);
        Files_listWidget->setObjectName(QStringLiteral("Files_listWidget"));

        gridLayout_3->addWidget(Files_listWidget, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_file, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpenFile);
        menuFile->addAction(actionOpenDir);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuTools->addAction(actionOutput_YOLO_Pics);
        mainToolBar->addAction(actionOpenFile);
        mainToolBar->addAction(actionOpenDir);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionExit);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionOutput_YOLO_Pics);

        retranslateUi(MainWindow);

        Annotation_tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OpenSLT", Q_NULLPTR));
        actionOpenFile->setText(QApplication::translate("MainWindow", "Open File", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpenFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpenDir->setText(QApplication::translate("MainWindow", "Open Dir", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpenDir->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionOutput_YOLO_Pics->setText(QApplication::translate("MainWindow", "Output YOLO Pics", Q_NULLPTR));
        actionOutput_YOLO_Pics->setIconText(QApplication::translate("MainWindow", "red", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        groupBox_Annotation->setTitle(QApplication::translate("MainWindow", "Annotation", Q_NULLPTR));
        Annotation_tabWidget->setTabText(Annotation_tabWidget->indexOf(sonar_anno), QApplication::translate("MainWindow", "sonar", Q_NULLPTR));
        Annotation_tabWidget->setTabText(Annotation_tabWidget->indexOf(yolo_anno), QApplication::translate("MainWindow", "YOLO", Q_NULLPTR));
        label_image->setText(QString());
        btn_Start->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        btn_Stop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        btn_Pause->setText(QApplication::translate("MainWindow", "Pause", Q_NULLPTR));
        btn_Run->setText(QApplication::translate("MainWindow", "Run", Q_NULLPTR));
        btn_SpeedUp->setText(QApplication::translate("MainWindow", "Speed Up", Q_NULLPTR));
        btn_SpeedDown->setText(QApplication::translate("MainWindow", "Speed Down", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Speed", Q_NULLPTR));
        groupBox_Label->setTitle(QApplication::translate("MainWindow", "Label Info", Q_NULLPTR));
        btn_AddLabel->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        groupBox_file->setTitle(QApplication::translate("MainWindow", "File Info", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
