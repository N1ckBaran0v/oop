#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

private slots:
    void on_addButton_clicked(void);
    void on_moveButton_clicked(void);
    void on_rotateButton_clicked(void);
    void on_scaleButton_clicked(void);
    void on_removeButton_clicked(void);
    void on_clearButton_clicked(void);
    void on_addToCompositeButton_clicked(void);
    void on_removeFromCompositeButton_clicked(void);
    void on_selectCameraButton_clicked(void);
    void on_programAction_triggered(void);
    void on_authorAction_triggered(void);
    void on_exitAction_triggered(void);

private:
    Ui::MainWindow *ui;
    std::string curr_camera = "";
    int camera = 0;
    int cube = 0;
    int pyramide = 0;
    int composite = 0;
};
#endif // __MAIN_WINDOW_H__
