#include <string>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "call_model.h"
#include "dot_and_vector.h"
#include "errors.h"
#include "mainwindow.h"

#define MAXSIZE 1000000000

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), 
                                          ui(new Ui::MainWindow) {
    params_t params = {.action = MODEL_LOAD, .filename = "cube.txt"};
    int ret = call_model(&params);
    std::cout << ret << '\n';
    if (ret == ERR_MEM_ALLOC) {
        std::cout << "Memory alloc error\n";
        throw "Memory alloc error";
    }
    else if (ret == ERR_FILE_OPEN) {
        std::cout << "File open error\n";
        throw "File open error";
    }
    else if (ret == ERR_FILE_READ) {
        std::cout << "File read error\n";
        throw "File read error";
    }
    else if (ret != ERR_OK) {
        std::cout << "Another error\n";
        throw "Another error"; 
    }
    this->ui->setupUi(this);
    this->repaint();
}

MainWindow::~MainWindow(void) {
    delete this->ui;
    params_t params = {.action = MODEL_DESTROY};
    call_model(&params);
}

void MainWindow::paintEvent(QPaintEvent *pEvent) {
    QPainter p(this);
    int canvasWidth = this->width() - 200;
    int canvasHeight = this->height();
    int canvasX = 200;
    int canvasY = 0;
    p.fillRect(canvasX, canvasY, canvasWidth, canvasHeight, Qt::white);
    p.setPen(QPen(Qt::black, 4));
    scene_t scene = {&p, {canvasX + canvasWidth / 2, canvasY + canvasHeight / 2}, 1};
    params_t params = {.action = MODEL_DRAW, .scene = &scene};
    call_model(&params);
    p.fillRect(0, 0, canvasX, this->height(), Qt::black);
}

void MainWindow::on_shiftButton_clicked(void) {
    vector_t shift;
    int ret = this->getVector(shift.x, shift.y, shift.z);
    if (ret == 0) {
        params_t params = {.action = MODEL_MOVE, .offset = &shift};
        call_model(&params);
        this->repaint();
    }
    else 
        QMessageBox::critical(this, "Ошибка", "Неверный формат входных данных.");
}

void MainWindow::on_scaleButton_clicked(void) {
    double k;
    int ret = this->getK(k);
    if (ret == 0) {
        scaling_params_t scaling_params = {k, k, k};
        params_t params = {.action = MODEL_SCALING, .scaling_params = &scaling_params};
        return_code_t rc = call_model(&params);
        if (rc != ERR_OK)
            QMessageBox::critical(this, "Ошибка", "Коэффициент очень маленький или отрицательный."); 
        else 
            this->repaint();
    }
    else 
        QMessageBox::critical(this, "Ошибка", "Неверный формат входных данных.");
}

void MainWindow::on_rotateButton_clicked(void) {
    int x, y, z;
    int ret = this->getAngles(x, y, z);
    if (ret == 0) {
        rotate_params_t rotate_params = {(double)x, (double)y, (double)z};
        params_t params = {.action = MODEL_ROTATE, .rotate_params = &rotate_params};
        call_model(&params);
        this->repaint();
    }
    else 
        QMessageBox::critical(this, "Ошибка", "Неверный формат входных данных.");
}

void MainWindow::on_saveButton_clicked(void) {
    params_t params = {.action = MODEL_SAVE, .filename = "cube.txt"};
    call_model(&params);
}

int MainWindow::getVector(double &x, double &y, double &z) {
    int rc = 0;
    QString sx = this->ui->lineEditX->text();
    QString sy = this->ui->lineEditY->text();
    QString sz = this->ui->lineEditZ->text();
    double xt = 0;
    double yt = 0;
    double zt = 0;
    bool okX = false;
    bool okY = false;
    bool okZ = false;
    xt = sx.toDouble(&okX);
    yt = sy.toDouble(&okY);
    zt = sz.toDouble(&okZ);
    if (!okX || !okY || !okZ) 
        rc = -1;
    else {
        x = xt;
        y = yt;
        z = zt;
    }
    return rc;
}

int MainWindow::getK(double &k) {
    int rc = ERR_OK;
    QString sk = this->ui->lineEditk->text();
    double kt = 0;
    bool okK = false;
    kt = sk.toDouble(&okK);
    if (!okK) 
        rc = -1;
    else
        k = kt;
    return rc;
}

int MainWindow::getAngles(int &x, int &y, int &z) {
    int rc = ERR_OK;
    QString sx = this->ui->lineEditOX->text();
    QString sy = this->ui->lineEditOY->text();
    QString sz = this->ui->lineEditOZ->text();
    int xt = 0;
    int yt = 0;
    int zt = 0;
    bool okX = false;
    bool okY = false;
    bool okZ = false;
    xt = sx.toInt(&okX);
    yt = sy.toInt(&okY);
    zt = sz.toInt(&okZ);
    if (!okX || !okY || !okZ) 
        rc = -1;
    else {
        x = xt;
        y = yt;
        z = zt;
    }
    return rc;
}
