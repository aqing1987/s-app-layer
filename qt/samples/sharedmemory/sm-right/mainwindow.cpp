#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->smem = new QSharedMemory;
    this->smem->setKey("kk123");
    this->setWindowTitle("sharedmem-right");

    this->connect(ui->loadMemoryButton, SIGNAL(clicked()), this, SLOT(loadFromMemorySLot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadFromMemorySLot()
{
    if (!smem->attach()) {
        QMessageBox::information(this, "Error", "attach error");
        return;
    }

    QBuffer buffer;
    QDataStream out(&buffer);
    QImage image;

    smem->lock();
    buffer.setData((char*)smem->constData(), smem->size());
    bool ok = buffer.open(QBuffer::ReadOnly);
    if (ok) {
        out >> image;
    }
    else {
        QMessageBox::information(this, "Error", "buffer.open failed.");
        return;
    }
    smem->unlock();

    smem->detach();
    ui->label->setPixmap(QPixmap::fromImage(image));
}
