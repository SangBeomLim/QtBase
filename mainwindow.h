#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QDateTime>
#include <QString>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
private:
    void Initialize();
public slots:
    void onClick();
public:

private:
    Ui::MainWindow *ui;
    QLabel *m_Text;
    QLCDNumber *m_Display;
    QPushButton *m_Button;
    bool m_isPush;
};
#endif // MAINWINDOW_H
