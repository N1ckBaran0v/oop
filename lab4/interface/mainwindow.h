#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include <QGridLayout>
#include <memory>

#include "ui_mainwindow.h"
#include "../lift/lift.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(void);

private:
    Ui::MainWindow *ui;
    std::unique_ptr<QGridLayout> _layout;
    std::unique_ptr<Lift> _lift;
};

#endif //__MAINWINDOW_H__