//
// Created by ASUS on 2022/1/25.
//

#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QWidget>
#include "qmqtt.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QWidget {
 Q_OBJECT

 public:
  explicit MainWindow (QWidget *parent = nullptr);
  ~MainWindow () override;
  QMQTT::Client *client;
  void on_pb_connect_clicked();
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void doConnected();  //MQTT 连接成功
  void doDisconnected();//MQTT连接断开
  void doDataReceived(const QMQTT::Message &message);//MQTT收到数据
 private:
  Ui::MainWindow *ui;
};

#endif //_MAINWINDOW_H_
