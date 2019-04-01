#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opencv2/opencv.hpp"
#include <QFileDialog>
#include <QMessageBox>
#include <qDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionfile_triggered();

    void on_findContour_clicked();

    void on_bgprocess_clicked();

private:
    Ui::MainWindow *ui;

    cv::Mat dst;

    cv::Mat src;
};

#endif // MAINWINDOW_H
