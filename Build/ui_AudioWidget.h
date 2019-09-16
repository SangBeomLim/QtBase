/********************************************************************************
** Form generated from reading UI file 'AudioWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOWIDGET_H
#define UI_AUDIOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioWidget
{
public:
    QToolButton *btn_mute;
    QGroupBox *gbox_button;
    QProgressBar *progressBar_task;
    QToolButton *btn_next;
    QToolButton *btn_stop;
    QToolButton *btn_play;
    QToolButton *btn_prev;
    QToolButton *btn_pause;
    QSlider *slider_volumn;
    QSlider *slider_control;
    QLabel *lb_timecode;

    void setupUi(QWidget *AudioWidget)
    {
        if (AudioWidget->objectName().isEmpty())
            AudioWidget->setObjectName(QString::fromUtf8("AudioWidget"));
        AudioWidget->resize(400, 300);
        btn_mute = new QToolButton(AudioWidget);
        btn_mute->setObjectName(QString::fromUtf8("btn_mute"));
        btn_mute->setGeometry(QRect(20, 220, 24, 21));
        gbox_button = new QGroupBox(AudioWidget);
        gbox_button->setObjectName(QString::fromUtf8("gbox_button"));
        gbox_button->setGeometry(QRect(10, 10, 120, 80));
        gbox_button->setContextMenuPolicy(Qt::NoContextMenu);
        progressBar_task = new QProgressBar(AudioWidget);
        progressBar_task->setObjectName(QString::fromUtf8("progressBar_task"));
        progressBar_task->setGeometry(QRect(260, 240, 118, 23));
        progressBar_task->setValue(0);
        btn_next = new QToolButton(AudioWidget);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));
        btn_next->setGeometry(QRect(170, 30, 24, 21));
        btn_stop = new QToolButton(AudioWidget);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        btn_stop->setGeometry(QRect(140, 30, 24, 21));
        btn_play = new QToolButton(AudioWidget);
        btn_play->setObjectName(QString::fromUtf8("btn_play"));
        btn_play->setGeometry(QRect(140, 50, 24, 21));
        btn_prev = new QToolButton(AudioWidget);
        btn_prev->setObjectName(QString::fromUtf8("btn_prev"));
        btn_prev->setGeometry(QRect(170, 50, 24, 21));
        btn_pause = new QToolButton(AudioWidget);
        btn_pause->setObjectName(QString::fromUtf8("btn_pause"));
        btn_pause->setGeometry(QRect(210, 50, 24, 21));
        slider_volumn = new QSlider(AudioWidget);
        slider_volumn->setObjectName(QString::fromUtf8("slider_volumn"));
        slider_volumn->setGeometry(QRect(60, 230, 160, 16));
        slider_volumn->setOrientation(Qt::Horizontal);
        slider_control = new QSlider(AudioWidget);
        slider_control->setObjectName(QString::fromUtf8("slider_control"));
        slider_control->setGeometry(QRect(170, 160, 160, 16));
        slider_control->setOrientation(Qt::Horizontal);
        lb_timecode = new QLabel(AudioWidget);
        lb_timecode->setObjectName(QString::fromUtf8("lb_timecode"));
        lb_timecode->setGeometry(QRect(80, 160, 47, 14));

        retranslateUi(AudioWidget);

        QMetaObject::connectSlotsByName(AudioWidget);
    } // setupUi

    void retranslateUi(QWidget *AudioWidget)
    {
        AudioWidget->setWindowTitle(QApplication::translate("AudioWidget", "Form", nullptr));
        btn_mute->setText(QApplication::translate("AudioWidget", "mute", nullptr));
        gbox_button->setTitle(QApplication::translate("AudioWidget", "function", nullptr));
        btn_next->setText(QApplication::translate("AudioWidget", "next", nullptr));
        btn_stop->setText(QApplication::translate("AudioWidget", "stop", nullptr));
        btn_play->setText(QApplication::translate("AudioWidget", "play", nullptr));
        btn_prev->setText(QApplication::translate("AudioWidget", "prev", nullptr));
        btn_pause->setText(QApplication::translate("AudioWidget", "pause", nullptr));
        lb_timecode->setText(QApplication::translate("AudioWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioWidget: public Ui_AudioWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOWIDGET_H
