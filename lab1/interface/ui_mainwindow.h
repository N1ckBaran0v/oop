/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEditX;
    QLineEdit *lineEditY;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditZ;
    QPushButton *shiftButton;
    QLineEdit *lineEditk;
    QLabel *label_4;
    QPushButton *scaleButton;
    QPushButton *rotateButton;
    QPushButton *saveButton;
    QLineEdit *lineEditOX;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEditOY;
    QLineEdit *lineEditOZ;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 680);
        MainWindow->setMinimumSize(QSize(1200, 680));
        MainWindow->setMaximumSize(QSize(1200, 680));
        MainWindow->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEditX = new QLineEdit(centralwidget);
        lineEditX->setObjectName(QString::fromUtf8("lineEditX"));
        lineEditX->setGeometry(QRect(0, 20, 171, 30));
        lineEditX->setMinimumSize(QSize(0, 0));
        lineEditY = new QLineEdit(centralwidget);
        lineEditY->setObjectName(QString::fromUtf8("lineEditY"));
        lineEditY->setGeometry(QRect(0, 70, 171, 30));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(0, 0, 171, 16));
        label->setAutoFillBackground(false);
        label->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 50, 171, 16));
        label_2->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 100, 171, 16));
        label_3->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        lineEditZ = new QLineEdit(centralwidget);
        lineEditZ->setObjectName(QString::fromUtf8("lineEditZ"));
        lineEditZ->setGeometry(QRect(0, 120, 171, 30));
        shiftButton = new QPushButton(centralwidget);
        shiftButton->setObjectName(QString::fromUtf8("shiftButton"));
        shiftButton->setGeometry(QRect(0, 150, 171, 41));
        shiftButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        lineEditk = new QLineEdit(centralwidget);
        lineEditk->setObjectName(QString::fromUtf8("lineEditk"));
        lineEditk->setGeometry(QRect(0, 230, 171, 30));
        lineEditk->setMinimumSize(QSize(0, 0));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(true);
        label_4->setGeometry(QRect(0, 210, 171, 16));
        label_4->setAutoFillBackground(false);
        label_4->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        scaleButton = new QPushButton(centralwidget);
        scaleButton->setObjectName(QString::fromUtf8("scaleButton"));
        scaleButton->setGeometry(QRect(0, 260, 171, 61));
        scaleButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        rotateButton = new QPushButton(centralwidget);
        rotateButton->setObjectName(QString::fromUtf8("rotateButton"));
        rotateButton->setGeometry(QRect(0, 560, 171, 41));
        rotateButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(0, 620, 171, 41));
        saveButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        lineEditOX = new QLineEdit(centralwidget);
        lineEditOX->setObjectName(QString::fromUtf8("lineEditOX"));
        lineEditOX->setGeometry(QRect(0, 430, 171, 30));
        lineEditOX->setMinimumSize(QSize(0, 0));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 460, 171, 16));
        label_5->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setEnabled(true);
        label_6->setGeometry(QRect(0, 410, 171, 16));
        label_6->setAutoFillBackground(false);
        label_6->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        lineEditOY = new QLineEdit(centralwidget);
        lineEditOY->setObjectName(QString::fromUtf8("lineEditOY"));
        lineEditOY->setGeometry(QRect(0, 480, 171, 30));
        lineEditOZ = new QLineEdit(centralwidget);
        lineEditOZ->setObjectName(QString::fromUtf8("lineEditOZ"));
        lineEditOZ->setGeometry(QRect(0, 530, 171, 30));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 510, 171, 16));
        label_7->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setEnabled(true);
        label_9->setGeometry(QRect(0, 350, 171, 16));
        label_9->setAutoFillBackground(false);
        label_9->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setEnabled(true);
        label_10->setGeometry(QRect(0, 370, 171, 16));
        label_10->setAutoFillBackground(false);
        label_10->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setEnabled(true);
        label_11->setGeometry(QRect(0, 390, 171, 16));
        label_11->setAutoFillBackground(false);
        label_11->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\203 x:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\203 y:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\203 z:", nullptr));
        shiftButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270 \320\272\321\203\320\261", nullptr));
        lineEditk->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 k:", nullptr));
        scaleButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\274\320\260\321\201\321\210\321\202\320\260\320\261 \320\262 \n"
"k \321\200\320\260\320\267", nullptr));
        rotateButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214 \320\272\321\203\320\261", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\321\203\320\261", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\272\321\200\321\203\320\263 \320\276\321\201\320\270 Oy:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\272\321\200\321\203\320\263 \320\276\321\201\320\270 Ox:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\272\321\200\321\203\320\263 \320\276\321\201\320\270 Oz:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \321\203\320\263\320\273\320\276\320\262 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\276\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\320\276 \320\276\321\201\320\265\320\271.", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "(\320\262 \320\263\321\200\320\260\320\264\321\203\321\201\320\260\321\205)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
