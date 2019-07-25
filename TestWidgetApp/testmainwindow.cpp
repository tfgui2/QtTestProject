#include "testmainwindow.h"
#include "ui_testmainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QDebug>

TestMainWindow::TestMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestMainWindow)
{
    ui->setupUi(this);
}

TestMainWindow::~TestMainWindow()
{
    delete ui;
}

void TestMainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName( this, tr("Open file"), ".", tr("Text files (*.txt)"));
    QFile file(filename);
    if (!file.open((QFile::ReadOnly | QFile::Text))) {
        qDebug() << "fail : open file " << filename;
        return;
    }

    QTextStream in(&file);
    QString data = in.readAll();
    ui->textEdit->setText(data);

    this->setFileName(filename);
}

void TestMainWindow::setFileName(QString filename)
{
    m_filename = filename;
    this->setWindowTitle("TestMainWindow " + m_filename );
}
