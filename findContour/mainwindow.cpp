#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionfile_triggered()
{
    QString filename = QFileDialog::getOpenFileName();
    if(filename == nullptr)
    {
        QMessageBox::information(nullptr,"Error", "head file");
        return;
    }
    src = cv::imread(filename.toStdString());
    if(!src.empty()){
        cv::imshow("src",src);
    }
}

void MainWindow::on_findContour_clicked()
{
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(dst, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    int count=0;
//    for(size_t i=0; i<contours.size();i++)
//    {
//        dst = cv::Scalar::all(0);
//        cv::drawContours(dst, contours, -1, cv::Scalar::all(255));
//        qDebug() << cv::contourArea(contours[i]);
//        if(cv::contourArea(contours[i])>1000 && cv::contourArea(contours[i])<3000){
//            count++;
//        }
//    }
    dst = cv::Scalar::all(0);
    cv::drawContours(dst, contours, -1, cv::Scalar::all(255));
    cv::imshow("proc",dst);
    QString message = "There are" + QString::number(count) + "of rice grains.";
    qDebug() << message;
}

void MainWindow::on_bgprocess_clicked()
{
    dst = src.clone();
    if(dst.empty()){
        QMessageBox::information(nullptr,"Error","Head file");
        return;
    }
    cv::cvtColor(dst, dst, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(dst,dst,cv::Size(3,3),1);
    cv::threshold(dst,dst,150,255,cv::THRESH_BINARY);
    cv::imshow("pro1",dst);
}
