#include <QMessageBox>
#include <QPainter>
#include <iostream>

#include "./ui_mainwindow.h"
#include "Command/AddObjectCommand.h"
#include "Command/AddToCompositeCommand.h"
#include "Command/ClearSceneCommand.h"
#include "Command/QtDrawSceneCommand.h"
#include "Command/RemoveFromCompositeCommand.h"
#include "Command/RemoveObjectCommand.h"
#include "Command/MoveCommand.h"
#include "Command/RotateCommand.h"
#include "Command/ScaleCommand.h"
#include "Facade/Facade.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QString style("color: white; background-color: black");
    QString zero("0");
    QString one("1");
    ui->addLabel->setStyleSheet(style);
    ui->addComboBox->setStyleSheet(style);
    ui->addButton->setStyleSheet(style);
    ui->operationLabel->setStyleSheet(style);
    ui->selectLabel->setStyleSheet(style);
    ui->operationComboBox->setStyleSheet(style);
    ui->moveLabel->setStyleSheet(style);
    ui->rotateLabel->setStyleSheet(style);
    ui->scaleLabel->setStyleSheet(style);
    ui->dXLabel->setStyleSheet(style);
    ui->oXLabel->setStyleSheet(style);
    ui->cXLabel->setStyleSheet(style);
    ui->dYLabel->setStyleSheet(style);
    ui->oYLabel->setStyleSheet(style);
    ui->cYLabel->setStyleSheet(style);
    ui->dZLabel->setStyleSheet(style);
    ui->oZLabel->setStyleSheet(style);
    ui->cZLabel->setStyleSheet(style);
    ui->dXLineEdit->setText(zero);
    ui->oXLineEdit->setText(zero);
    ui->cXLineEdit->setText(one);
    ui->dYLineEdit->setText(zero);
    ui->oYLineEdit->setText(zero);
    ui->cYLineEdit->setText(one);
    ui->dZLineEdit->setText(zero);
    ui->oZLineEdit->setText(zero);
    ui->cZLineEdit->setText(one);
    ui->moveButton->setStyleSheet(style);
    ui->rotateButton->setStyleSheet(style);
    ui->scaleButton->setStyleSheet(style);
    ui->removeButton->setStyleSheet(style);
    ui->clearButton->setStyleSheet(style);
    ui->compositeLabel->setStyleSheet(style);
    ui->compositeComboBox->setStyleSheet(style);
    ui->objectComboBox->setStyleSheet(style);
    ui->addToCompositeButton->setStyleSheet(style);
    ui->removeFromCompositeButton->setStyleSheet(style);
    ui->cameraLabel->setStyleSheet(style);
    ui->selectCameraComboBox->setStyleSheet(style);
    ui->selectCameraButton->setStyleSheet(style);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::paintEvent(QPaintEvent *pEvent) {
    QPainter p(this);
    auto canvasWidth = this->width() - 300;
    auto canvasHeight = this->height();
    auto canvasX = 300;
    auto canvasY = 0;
    p.fillRect(canvasX, canvasY, canvasWidth, canvasHeight, QBrush(Qt::white));
    p.setPen(QPen(Qt::red));
    if (curr_camera != "") {
        Facade::execute(std::make_shared<QtDrawSceneCommand>(
            curr_camera, p, canvasX + canvasWidth / 2, canvasY + canvasHeight / 2));
    }
    p.fillRect(0, 0, canvasX, canvasHeight, QBrush(Qt::black));
}

void MainWindow::on_addButton_clicked(void) {
    std::string name;
    switch (ui->addComboBox->currentIndex()) {
    case 0:
        QMessageBox::critical(this, "Ошибка", "Не выбран компонент");
        break;
    case 1:
        name = "Camera " + std::to_string(++camera);
        Facade::execute(std::make_shared<AddObjectCommand>("Camera", name));
        ui->objectComboBox->addItem(name.c_str());
        ui->operationComboBox->addItem(name.c_str());
        ui->selectCameraComboBox->addItem(name.c_str());
        break;
    case 2:
        name = "Cube " + std::to_string(++cube);
        Facade::execute(std::make_shared<AddObjectCommand>("Cube", name));
        ui->objectComboBox->addItem(name.c_str());
        ui->operationComboBox->addItem(name.c_str());
        break;
    case 3:
        name = "Pyramide " + std::to_string(++pyramide);
        Facade::execute(std::make_shared<AddObjectCommand>("Pyramide", name));
        ui->objectComboBox->addItem(name.c_str());
        ui->operationComboBox->addItem(name.c_str());
        break;
    default:
        name = "Composite " + std::to_string(++composite);
        Facade::execute(std::make_shared<AddObjectCommand>("Composite", name));
        ui->compositeComboBox->addItem(name.c_str());
        ui->operationComboBox->addItem(name.c_str());
        break;
    }
    repaint();
}

void MainWindow::on_moveButton_clicked(void) {
    auto index = ui->operationComboBox->currentIndex();
    if (index == 0) {
        QMessageBox::critical(this, "Ошибка", "Не выбран компонент");
        return;
    }
    auto fx = false, fy = false, fz = false;
    auto sx = ui->dXLineEdit->text();
    auto sy = ui->dYLineEdit->text();
    auto sz = ui->dZLineEdit->text();
    auto x = sx.toDouble(&fx);
    auto y = sy.toDouble(&fy);
    auto z = sz.toDouble(&fz);
    if (!(fx && fy && fz)) {
        QMessageBox::critical(this, "Ошибка", "Значения полей не являются числами с плавающей точкой");
    } else {
        auto text = ui->operationComboBox->currentText();
        Facade::execute(std::make_shared<MoveCommand>(text.toStdString(), x, y, z));
    }
    repaint();
}

void MainWindow::on_rotateButton_clicked(void) {
    auto index = ui->operationComboBox->currentIndex();
    if (index == 0) {
        QMessageBox::critical(this, "Ошибка", "Не выбран компонент");
        return;
    }
    auto fx = false, fy = false, fz = false;
    auto sx = ui->oXLineEdit->text();
    auto sy = ui->oYLineEdit->text();
    auto sz = ui->oZLineEdit->text();
    auto x = sx.toDouble(&fx);
    auto y = sy.toDouble(&fy);
    auto z = sz.toDouble(&fz);
    if (!(fx && fy && fz)) {
        QMessageBox::critical(this, "Ошибка", "Значения полей не являются числами с плавающей точкой");
    } else {
        auto text = ui->operationComboBox->currentText();
        Facade::execute(std::make_shared<RotateCommand>(text.toStdString(), x, y, z));
    }
    repaint();
}

void MainWindow::on_scaleButton_clicked(void) {
    auto index = ui->operationComboBox->currentIndex();
    if (index == 0) {
        QMessageBox::critical(this, "Ошибка", "Не выбран компонент");
        return;
    }
    auto fx = false, fy = false, fz = false;
    auto sx = ui->cXLineEdit->text();
    auto sy = ui->cYLineEdit->text();
    auto sz = ui->cZLineEdit->text();
    auto x = sx.toDouble(&fx);
    auto y = sy.toDouble(&fy);
    auto z = sz.toDouble(&fz);
    if (!(fx && fy && fz)) {
        QMessageBox::critical(this, "Ошибка", "Значения полей не являются числами с плавающей точкой");
    } else {
        auto text = ui->operationComboBox->currentText();
        Facade::execute(std::make_shared<ScaleCommand>(text.toStdString(), x, y, z));
    }
    repaint();
}

void MainWindow::on_removeButton_clicked(void) {
    auto index = ui->operationComboBox->currentIndex();
    if (index == 0) {
        QMessageBox::critical(this, "Ошибка", "Не выбран компонент");
        return;
    }
    auto text = ui->operationComboBox->currentText();
    ui->operationComboBox->removeItem(index);
    index = ui->compositeComboBox->findText(text);
    if (index > -1) {
        ui->compositeComboBox->removeItem(index);
    }
    index = ui->objectComboBox->findText(text);
    if (index > -1) {
        ui->objectComboBox->removeItem(index);
    }
    index = ui->selectCameraComboBox->findText(text);
    if (index > -1) {
        ui->selectCameraComboBox->removeItem(index);
    }
    Facade::execute(std::make_shared<RemoveObjectCommand>(text.toStdString()));
    on_selectCameraButton_clicked();
}

void MainWindow::on_clearButton_clicked(void) {
    auto cnt = ui->operationComboBox->count();
    while (cnt > 1) {
        ui->operationComboBox->removeItem(--cnt);
    }
    cnt = ui->compositeComboBox->count();
    while (cnt > 1) {
        ui->compositeComboBox->removeItem(--cnt);
    }
    cnt = ui->objectComboBox->count();
    while (cnt > 1) {
        ui->objectComboBox->removeItem(--cnt);
    }
    cnt = ui->selectCameraComboBox->count();
    while (cnt > 1) {
        ui->selectCameraComboBox->removeItem(--cnt);
    }
    Facade::execute(std::make_shared<ClearSceneCommand>());
    on_selectCameraButton_clicked();
}

void MainWindow::on_addToCompositeButton_clicked(void) {
    auto ind1 = ui->compositeComboBox->currentIndex();
    auto ind2 = ui->objectComboBox->currentIndex();
    if (ind1 == 0 || ind2 == 0) {
        QMessageBox::critical(this, "Ошибка", "Не выбран компонент");
        return;
    }
    auto cmp = ui->compositeComboBox->currentText();
    auto obj = ui->objectComboBox->currentText();
    Facade::execute(std::make_shared<AddToCompositeCommand>(cmp.toStdString(),
                                                            obj.toStdString()));
}

void MainWindow::on_removeFromCompositeButton_clicked(void) {
    auto ind1 = ui->compositeComboBox->currentIndex();
    auto ind2 = ui->objectComboBox->currentIndex();
    if (ind1 == 0 || ind2 == 0) {
        QMessageBox::critical(this, "Ошибка", "Не выбран компонент");
        return;
    }
    auto cmp = ui->compositeComboBox->currentText();
    auto obj = ui->objectComboBox->currentText();
    Facade::execute(std::make_shared<RemoveFromCompositeCommand>(
        cmp.toStdString(), obj.toStdString()));
}

void MainWindow::on_selectCameraButton_clicked(void) {
    if (ui->selectCameraComboBox->currentIndex() != 0) {
        curr_camera = ui->selectCameraComboBox->currentText().toStdString();
    } else {
        curr_camera = "";
    }
    repaint();
}

void MainWindow::on_programAction_triggered(void) {
    QMessageBox::about(this, "О программе", "3d-viewer каркасных моделей.");
}

void MainWindow::on_authorAction_triggered(void) {
    QMessageBox::about(this, "Об авторе", "Автор: Баранов Николай Алексеевич.");
}

void MainWindow::on_exitAction_triggered(void) { this->close(); }
