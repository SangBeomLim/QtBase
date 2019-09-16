#ifndef AUDIOWIDGET_H
#define AUDIOWIDGET_H

#include <QWidget>
#include <QUrl>
#include <QFileDialog>
#include <QFileInfo>
#include <QMediaPlayer>     //음악을 재생하기 위해
#include <QMediaPlaylist>   //재생 목록을 만들기 위해 사용
#include <QProgressBar>
#include <QLabel>
#include <QAudioProbe> //재생 혹은 녹음 중인 오디오를 모니터링 할 경우 사용
#include <QObject>      //connect()를 사용하기 위해
#include <QString>
#include <QDebug>

namespace Ui {
class AudioWidget;
}

class AudioWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AudioWidget(QWidget *parent = nullptr);
    ~AudioWidget();
protected:
private:
    void InitGui(); //GUI 환경을 구성
    void Print(QString str);    //디버깅 프린트
    double GetPosition();   //현재 진행 시간
    double GetLength();     //뮤직 총 재생 시간

signals:
    void WindowStart();
public slots:
    void onPrevMusic(); //이전 곡 재생
    void onNextMusic(); //다음 곡 재생
    void onTimecode();  //재생 목록의 재생 시간
private slots:
    void on_slider_volumn_valueChanged(int value);  //볼륨 조절
    void on_btn_mute_clicked(bool checked);

public:
    QAudioProbe *m_probe;
protected:
private:
    Ui::AudioWidget *ui;
    QMediaPlayer *m_player;
    QMediaPlaylist *m_playlist;
    int m_volumn;
    int m_index;

};

#endif // AUDIOWIDGET_H
