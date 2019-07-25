#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class TestMainWindow;
}

class TestMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestMainWindow(QWidget *parent = 0);
    ~TestMainWindow();

private slots:
    void on_actionOpen_triggered();

private:
    Ui::TestMainWindow *ui;

public:
    void setFileName(QString filename);
    QString m_filename;
};

#endif // TESTMAINWINDOW_H
