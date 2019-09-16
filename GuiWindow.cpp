#include "GuiWindow.h"
#include "ui_GuiWindow.h"

GuiWindow::GuiWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuiWindow)
{
    ui->setupUi(this);

    this->setGeometry(3200, 100, 600, 800);

    m_audio = new AudioWidget(this);
    m_audio->setGeometry(0,0,1000,1000);

}

GuiWindow::~GuiWindow()
{
    delete ui;
}
