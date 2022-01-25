/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *rb_status;
    QPushButton *pb_connect;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *le_pb_topic;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *le_pu_payload;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *le_sub_topic;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QTextBrowser *te_log;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(452, 384);
        gridLayout = new QGridLayout(MainWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        rb_status = new QRadioButton(MainWindow);
        rb_status->setObjectName(QString::fromUtf8("rb_status"));

        horizontalLayout_5->addWidget(rb_status);

        pb_connect = new QPushButton(MainWindow);
        pb_connect->setObjectName(QString::fromUtf8("pb_connect"));

        horizontalLayout_5->addWidget(pb_connect);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MainWindow);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        le_pb_topic = new QLineEdit(MainWindow);
        le_pb_topic->setObjectName(QString::fromUtf8("le_pb_topic"));

        horizontalLayout->addWidget(le_pb_topic);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(MainWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        le_pu_payload = new QLineEdit(MainWindow);
        le_pu_payload->setObjectName(QString::fromUtf8("le_pu_payload"));

        horizontalLayout_2->addWidget(le_pu_payload);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(MainWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        le_sub_topic = new QLineEdit(MainWindow);
        le_sub_topic->setObjectName(QString::fromUtf8("le_sub_topic"));

        horizontalLayout_4->addWidget(le_sub_topic);

        pushButton_2 = new QPushButton(MainWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(MainWindow);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(MainWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        te_log = new QTextBrowser(MainWindow);
        te_log->setObjectName(QString::fromUtf8("te_log"));

        verticalLayout_2->addWidget(te_log);


        verticalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        rb_status->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\347\212\266\346\200\201", nullptr));
        pb_connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Topic\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Payload:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Publish", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Topic:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Subscribe", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "UnSubscribe", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "LOG:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
