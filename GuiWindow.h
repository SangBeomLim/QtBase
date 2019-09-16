#ifndef GUIWINDOW_H
#define GUIWINDOW_H

#include <QMainWindow>
#include "AudioWidget.h"

namespace Ui {
class GuiWindow;
}

class GuiWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuiWindow(QWidget *parent = nullptr);
    ~GuiWindow();

private:
    Ui::GuiWindow *ui;
    AudioWidget *m_audio;
};

#endif // GUIWINDOW_H
