//
// Created by XinMouRen on 2022/1/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "Headers/mainwindow.h"
//  #include "ui_MainWindow.h"    这是原来的
#include "Forms/ui_MainWindow.h"

MainWindow::MainWindow (QWidget *parent) :
	QWidget (parent), ui (new Ui::MainWindow)
{
  ui->setupUi (this);
  client = new QMQTT::Client ();
  client->setHostName ("127.0.0.1");
  client->setPort (1883);
  client->setClientId ("clientid");
  client->setUsername ("user");
  client->setPassword ("password");
  ui->pushButton->setEnabled (false);
  ui->pushButton_2->setEnabled (false);
  connect (this->client, &QMQTT::Client::connected, this, &MainWindow::doConnected);
  connect (this->client, &QMQTT::Client::disconnected, this, &MainWindow::doDisconnected);
  connect (this->client, &QMQTT::Client::received, this, &MainWindow::doDataReceived);
}
void MainWindow::on_pb_connect_clicked ()
{

  if (!client->isConnectedToHost ())
	{
	  client->connectToHost ();
	}
  else
	{
	  client->disconnectFromHost ();
	}

}

void MainWindow::doConnected ()
{
  ui->rb_status->setChecked (true);
  ui->pb_connect->setText ("Disconnect");
  ui->pushButton->setEnabled (true);
  ui->pushButton_2->setEnabled (true);
}

void MainWindow::doDisconnected ()
{
  ui->rb_status->setChecked (false);
  ui->pb_connect->setText ("Connect");
  ui->pushButton->setEnabled (false);
  ui->pushButton_2->setEnabled (false);
}

void MainWindow::doDataReceived (const QMQTT::Message &message)
{
  QString mes =
	  QString (message.id ()) + " " + QString (message.qos ()) + " " + message.topic () + " " + message.payload ()
	  + "\n";
  ui->te_log->append (mes);
}

void MainWindow::on_pushButton_clicked ()
{
  QString topic = ui->le_pb_topic->text ().trimmed ();
  QString payload = ui->le_pu_payload->text ().trimmed ();
  if (topic.isEmpty () || payload.isEmpty ())
	{
	  qDebug () << "pub topic and payload is empty!";
	  return;
	}
  QMQTT::Message message (136, topic, payload.toUtf8 ());

  client->publish (message);
}

void MainWindow::on_pushButton_2_clicked ()
{
  QString topic = ui->le_sub_topic->text ().trimmed ();
  if (topic.isEmpty ())
	{
	  qDebug () << "sub topic and payload is empty!";
	  return;
	}
  qDebug () << topic;
  client->subscribe (topic);
}

void MainWindow::on_pushButton_3_clicked ()
{
  QString topic = ui->le_sub_topic->text ().trimmed ();
  if (topic.isEmpty ())
	{
	  qDebug () << "sub topic and payload is empty!";
	  return;
	}
  client->unsubscribe (topic);

}

MainWindow::~MainWindow ()
{
  delete ui;
}

