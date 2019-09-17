#include "AudioWidget.h"
#include "ui_AudioWidget.h"

AudioWidget::AudioWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioWidget)
{
    ui->setupUi(this);

    InitGui();      //오디오 기능 초기화

}

AudioWidget::~AudioWidget()
{
    delete ui;


    delete m_player;
    delete m_playlistModel;
    delete m_playlist;
}

void AudioWidget::InitGui()
{
//    m_index = 0;
    m_volumn = 0;

    m_playlistModel = new QStandardItemModel(this);
    ui->playlistView->setModel(m_playlistModel);
    m_playlistModel->setHorizontalHeaderLabels(QStringList() << tr("Audio Track") << tr("File Path"));
    ui->playlistView->hideColumn(1);
    ui->playlistView->verticalHeader()->setVisible(false);
    ui->playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->playlistView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->playlistView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->playlistView->horizontalHeader()->setStretchLastSection(true);

    m_player = new QMediaPlayer(this);

    m_playlist = new QMediaPlaylist(m_player);
//    m_playlist->addMedia(QUrl::fromLocalFile("C:/Dev/MultiMedia/Never Be Like You ft. Kai - Flume [Audio]-320.mp3"));
//    m_playlist->addMedia(QUrl::fromLocalFile("C:/Dev/MultiMedia/Challa (Main Lad Jaana) - URI _ Vicky Kaushal , Yami Gautam _ Shashwat S _ Romy , Vivek _ Kumaar-320.mp3"));
//    m_playlist->addMedia(QUrl::fromLocalFile("C:/Dev/MultiMedia/bad guy - 320.mp3"));
//    m_playlist->setCurrentIndex(m_index);
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);

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
    ui->lb_timecode->setText("time");
    //add button
    ui->btn_add->setGeometry(500, 50, 75, 50);
    //listview
    ui->playlistView->setGeometry(25, 120, 550, 450);
    //current playlist
    ui->currentTrack->setGeometry(50, 570, 550, 50);
//    qDebug() << GetLength();
//    int now, min, sec;
//    int total, tmin, tsec;
//    now = static_cast<int>(GetPosition());
//    min = now / 60;
//    sec = now % 60;

//    total = static_cast<int>(GetLength());
//    tmin = total / 60;
//    tsec = total % 60;

//    //timecode
//    QString timeformat;
//    timeformat = QString("%1:%2/%3:%4").arg(min).arg(sec).arg(tmin).arg(tsec);

//    ui->lb_timecode->setText(timeformat);
//    //audioprobe
//    m_probe = new QAudioProbe();
//    m_probe->setSource(m_player);

    registerSignalandSlots();
}

void AudioWidget::registerSignalandSlots()
{
    connect(ui->btn_play, &QToolButton::clicked, m_player, &QMediaPlayer::play);
    connect(ui->btn_stop, &QToolButton::clicked, m_player, &QMediaPlayer::stop);
    connect(ui->btn_pause, &QToolButton::clicked, m_player, &QMediaPlayer::pause);
    connect(ui->btn_next, &QToolButton::clicked, m_playlist, &QMediaPlaylist::next);
    connect(ui->btn_prev, &QToolButton::clicked, m_playlist, &QMediaPlaylist::previous);
    connect(m_player, &QMediaPlayer::durationChanged, ui->progressBar_task, &QProgressBar::setMaximum);
    connect(m_player, &QMediaPlayer::positionChanged, ui->progressBar_task, &QProgressBar::setValue);
    connect(m_player, &QMediaPlayer::durationChanged, ui->slider_control, &QSlider::setMaximum);
    connect(m_player, &QMediaPlayer::positionChanged, ui->slider_control, &QSlider::setValue);
    connect(ui->slider_control, &QSlider::sliderMoved, m_player, &QMediaPlayer::setPosition);
    connect(m_player, &QMediaPlayer::positionChanged, this, &AudioWidget::onTimecode);
    //list
    connect(ui->playlistView, &QTableView::doubleClicked, [this](const QModelIndex &index){
        m_playlist->setCurrentIndex(index.row());});
    connect(m_playlist, &QMediaPlaylist::currentIndexChanged, [this](int index){
        ui->currentTrack->setText(m_playlistModel->data(m_playlistModel->index(index, 0)).toString());
    });
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

//void AudioWidget::onPrevMusic()
//{
//    if(m_index < 0)
//        m_index = 2;
//    else
//    {
//        m_index = m_index - 1;
//    }

//    m_playlist->setCurrentIndex(m_index);
////    m_player->setPlaylist(m_playlist);
//    m_player->play();
//}

//void AudioWidget::onNextMusic()
//{
//    if(m_index > 2)
//        m_index = 0;
//    else
//    {
//        m_index = m_index  + 1;
//    }

//    m_playlist->setCurrentIndex(m_index);
////    m_player->setPlaylist(m_playlist);
//    m_player->play();

//}

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
    return m_player->duration() / static_cast<double>(1000);
}


double AudioWidget::GetPosition()
{
    return m_player->position() / static_cast<double>(1000);
}

void AudioWidget::onTimecode()
{
    int now, min, sec;
    int total, tmin, tsec;
    now = static_cast<int>(GetPosition());
    min = now / 60;
    sec = now % 60;

    total = static_cast<int>(GetLength());
    tmin = total / 60;
    tsec = total % 60;

    //timecode
    QString timeformat;
    timeformat = QString("%1:%2/%3:%4").arg(min).arg(sec).arg(tmin).arg(tsec);

    ui->lb_timecode->setText(timeformat);
//    connect(m_probe, SIGNAL(audioBufferProbed(QAudioBuffer)), this, SLOT(processBuffer(QAudioBuffer)));
}

//void AudioWidget::processBuffer(QAudioBuffer buf)
//{
//    const quint16* data = buf.constData<quint16>();

//    int samples = buf.sampleCount();
//    double sumsquared = 0;
//    for(int i = 0; i <samples; i++)
//    {
//        sumsquared += data[i] * data[i];
//    }

//    double rms = sqrt((double(1) / samples) * (sumsquared));

//    if(rms <= 100)
//    {
//        m_silence += buf.duration();
//    }

//    if(m_silence >= MSG_RECORD_MAX_SILENCE_US)
//    {
//        m_silence = 0;
//    }
//}

void AudioWidget::on_btn_add_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      tr("open files"),
                                                      QString(),
                                                      tr("Audio Files ( *.mp3 )"));

    foreach(QString filePath, files)
    {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(QDir(filePath).dirName()));
        items.append(new QStandardItem(filePath));
        m_playlistModel->appendRow(items);
        m_playlist->addMedia(QUrl(filePath));
    }
}
