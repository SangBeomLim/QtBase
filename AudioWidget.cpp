#include "AudioWidget.h"
#include "ui_AudioWidget.h"

AudioWidget::AudioWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioWidget)
{
    ui->setupUi(this);

    InitGui();      //오디오 기능 초기화
    connect(ui->btn_play, SIGNAL(clicked()), m_player, SLOT(play()));
    connect(ui->btn_stop, SIGNAL(clicked()), m_player, SLOT(stop()));
    connect(ui->btn_pause, SIGNAL(clicked()), m_player, SLOT(pause()));
    connect(ui->btn_next, SIGNAL(clicked()), this, SLOT(onNextMusic()));
    connect(ui->btn_prev, SIGNAL(clicked()), this, SLOT(onPrevMusic()));
    connect(m_player, &QMediaPlayer::durationChanged, ui->progressBar_task, &QProgressBar::setMaximum);
    connect(m_player, &QMediaPlayer::positionChanged, ui->progressBar_task, &QProgressBar::setValue);

    connect(m_player, &QMediaPlayer::durationChanged, ui->slider_control, &QSlider::setMaximum);
    connect(m_player, &QMediaPlayer::positionChanged, ui->slider_control, &QSlider::setValue);
    connect(ui->slider_control, &QSlider::sliderMoved, m_player, &QMediaPlayer::setPosition);
    connect(m_player, &QMediaPlayer::positionChanged, this, &AudioWidget::onTimecode);
//    connect(m_probe, SIGNAL(audioBufferProbed(QAudioBuffer)), this, SLOT(processBuffer(QAudioBuffer)));
}

AudioWidget::~AudioWidget()
{

    delete ui;
    delete m_player;
    delete m_playlist;
}

void AudioWidget::InitGui()
{
    m_index = 0;
    m_volumn = 0;

    m_playlist = new QMediaPlaylist;
    m_playlist->addMedia(QUrl::fromLocalFile("C:/Dev/MultiMedia/Never Be Like You ft. Kai - Flume [Audio]-320.mp3"));
    m_playlist->addMedia(QUrl::fromLocalFile("C:/Dev/MultiMedia/Challa (Main Lad Jaana) - URI _ Vicky Kaushal , Yami Gautam _ Shashwat S _ Romy , Vivek _ Kumaar-320.mp3"));
    m_playlist->addMedia(QUrl::fromLocalFile("C:/Dev/MultiMedia/bad guy - 320.mp3"));

    m_playlist->setCurrentIndex(m_index);
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    m_player = new QMediaPlayer;
    m_player->setPlaylist(m_playlist);

    m_player->setVolume(50);

    ui->gbox_button->setGeometry(15, 65, 400, 100);
    ui->gbox_button->hide();
    ui->btn_prev->setGeometry(25, 700, 75, 50);
    ui->btn_play->setGeometry(100, 700, 75, 50);
    ui->btn_pause->setGeometry(175, 700, 75, 50);
    ui->btn_stop->setGeometry(250, 700, 75, 50);
    ui->btn_next->setGeometry(325, 700, 75, 50);

    ui->btn_mute->setGeometry(405, 700, 75, 50);
//    ui->btn_mute->setEnabled(true);
    ui->btn_mute->setCheckable(true);
    ui->btn_mute->setChecked(false);
    ui->slider_volumn->setRange(0, 100);
    ui->slider_volumn->setValue(m_player->volume());
    ui->slider_volumn->setGeometry(485, 710, 100, 30);

    //music status progressbar
    ui->slider_control->setRange(0, 100);
    ui->slider_control->setGeometry(25, 650, 450, 40);
//    ui->progressBar_task->setGeometry(0, 700, 300, 50);
    ui->progressBar_task->hide();
    //timecode
    ui->lb_timecode->setGeometry(500, 650, 100, 40);
    ui->lb_timecode->setText("");

//    //audioprobe
//    m_probe = new QAudioProbe(this);

    emit WindowStart();
}

void AudioWidget::Print(QString str)
{
    qDebug() << str;
}

void AudioWidget::on_slider_volumn_valueChanged(int value)
{
    //오디오의 볼륨을 조절한다.
//    QString str;
//    str.setNum(value, 10);
//    Print(str);
    m_player->setVolume(value);
}

void AudioWidget::onPrevMusic()
{
    if(m_index < 0)
        m_index = 2;
    else
    {
        m_index = m_index - 1;
    }

    m_playlist->setCurrentIndex(m_index);
//    m_player->setPlaylist(m_playlist);
    m_player->play();
}

void AudioWidget::onNextMusic()
{
    if(m_index > 2)
        m_index = 0;
    else
    {
        m_index = m_index  + 1;
    }

    m_playlist->setCurrentIndex(m_index);
//    m_player->setPlaylist(m_playlist);
    m_player->play();

}

void AudioWidget::on_btn_mute_clicked(bool checked)
{
    if(m_player->state() == QMediaPlayer::PlayingState)
    {
        m_player->setMuted(checked);
        if(m_player->isMuted())
        {
            m_volumn = ui->slider_volumn->value();
            ui->slider_volumn->setValue(0);
        }
        else
        {
            ui->slider_volumn->setValue(m_volumn);
        }
    }
    qDebug() <<m_player->isMuted();
}

double AudioWidget::GetLength()
{
    return m_player->duration() / (double)(1000.0);
}


double AudioWidget::GetPosition()
{
    return m_player->position() / (double)(1000.0);
}

void AudioWidget::onTimecode()
{
    qDebug() << "start timecode";
    //timecode
    QString str;
    str = QString::number(GetPosition());
    str += "/";
    str += QString::number(GetLength());

    ui->lb_timecode->setText(str);
}
