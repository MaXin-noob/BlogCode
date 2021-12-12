#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qmqtt.h"
#include<QDebug>
using namespace QMQTT;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pb_connect_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QMQTT::Client *client; //MQTT客户端指针

public slots:
    void doConnected();  //MQTT 连接成功
    void doDisconnected();//MQTT连接断开
    void doDataReceived(QMQTT::Message);//MQTT收到数据
};

#endif // MAINWINDOW_H
