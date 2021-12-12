#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<qnetwork.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client = new QMQTT::Client(QHostAddress("127.0.0.1"),1883);
    client->setClientId("clientid");
    client->setUsername("user");
    client->setPassword("password");
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    connect(client,SIGNAL(connected()),this,SLOT(doConnected()));
    connect(client,SIGNAL(disconnected()),this,SLOT(doDisconnected()));
    connect(client,SIGNAL(received(QMQTT::Message)),this,SLOT(doDataReceived(QMQTT::Message)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_connect_clicked()
{

    if(!client->isConnectedToHost())
    {
        client->connectToHost();
    }
    else {
        client->disconnectFromHost();
    }

}

void MainWindow::doConnected()
{
    ui->rb_status->setChecked(true);
    ui->pb_connect->setText("Disconnect");
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
}

void MainWindow::doDisconnected()
{
    ui->rb_status->setChecked(false);
    ui->pb_connect->setText("Connect");
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
}

void MainWindow::doDataReceived(Message message)
{
    QString mes = QString(message.id())+" "+QString(message.qos())+" "+message.topic()+" "+message.payload()+"\n";
    ui->te_log->append(mes);
}


void MainWindow::on_pushButton_clicked()
{
    QString topic = ui->le_pb_topic->text().trimmed();
    QString payload = ui->le_pu_payload->text().trimmed();
    if(topic.isEmpty() || payload.isEmpty())
    {
        qDebug()<<"pub topic and payload is empty!";
        return;
    }
    QMQTT::Message message(136,topic,payload.toUtf8());

    client->publish(message);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString topic = ui->le_sub_topic->text().trimmed();
    if(topic.isEmpty())
    {
        qDebug()<<"sub topic and payload is empty!";
        return;
    }
    qDebug()<<topic;
    client->subscribe(topic);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString topic = ui->le_sub_topic->text().trimmed();
    if(topic.isEmpty())
    {
        qDebug()<<"sub topic and payload is empty!";
        return;
    }
    client->unsubscribe(topic);

}
