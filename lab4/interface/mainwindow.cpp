#include "mainwindow.h"

#define FLOORS 9

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), 
                                          ui(new Ui::MainWindow) {
    ui->setupUi(this);
    _lift = std::make_unique<Lift>(FLOORS);
    setFixedSize(500, FLOORS * 40);
    _layout = std::make_unique<QGridLayout>();
    ui->centralwidget->setLayout(_layout.get());
    _layout->addWidget((_lift->getController()).get());
}

MainWindow::~MainWindow(void) {
    delete this->ui;
}
