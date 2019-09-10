#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_Text = nullptr;
    m_Display = nullptr;
    m_Button = nullptr;
    m_isPush = false;
    Initialize();
}

MainWindow::~MainWindow()
{
    delete m_Text;
    delete m_Display;
    delete m_Button;
    delete ui;
}

void MainWindow::Initialize()
{
    //button
    m_Button = new QPushButton("Click Here", this);
    m_Button->setGeometry(50, 450, 200, 100);
    connect(m_Button, SIGNAL(clicked()), this, SLOT(onClick()));
    //label
    m_Text = new QLabel("Coding Sample" , this);
    m_Text->setGeometry(50, 300, 200, 100);
    //display
    m_Display = new QLCDNumber(this);
    m_Display->setGeometry(50, 50, 500, 100);
    QString time = QDateTime::currentDateTime().toString(Qt::TextDate);
    m_Display->display(time);
//    QMessageBox::warning(NULL, "popup title", time);
}

void MainWindow::onClick()
{
    QString str;
//    qDebug() << "HelloWorld";
    if(m_isPush)
    {
        str = "Welcome to Qt World!";
        m_Text->setText(str);
        m_isPush = false;
    }
    else
    {
        str = "Hello World";
        m_Text->setText(str);
        m_isPush = true;
    }
}
