#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QMessageBox>
#include <vector>

#include "ui_mainwindow.h"
#include "call_model.h"

enum LastAct{NONE, ADD_DOT, RM_DOT, CLS, SOLVE};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(void);
    void paintEvent(QPaintEvent*);
private slots:
    void on_shiftButton_clicked(void);
    void on_scaleButton_clicked(void);
    void on_rotateButton_clicked(void);
    void on_saveButton_clicked(void);
private:
    Ui::MainWindow *ui;
    int getVector(double&, double&, double&);
    int getK(double&);
    int getAngles(int&, int&, int&);
    //Surface surface;
    //int scale;
    /*bool isSolved;
    LastAct lastAct;
    bool lastFlag;
    std::vector <Dot> lastDots;
    double minX, minY, maxX, maxY;
    int getDot(double&, double&);
    void mousePressEvent(QMouseEvent*);*/
};

#endif //__MAINWINDOW_H__