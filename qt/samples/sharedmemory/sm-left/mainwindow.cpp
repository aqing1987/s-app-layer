#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->smem = new QSharedMemory;
    this->smem->setKey("kk123");
    this->setWindowTitle("sharedmem-left");

    this->connect(ui->loadFileButton, SIGNAL(clicked()), this, SLOT(loadFromFileSlot()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadFromFileSlot()
{
    // if shared memory exist, delete first
    if (smem->isAttached()) {
        smem->detach();
    }

    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", QString(),
                                                    tr("Image (*.png, *.bmp, *.jpg)"));
    QImage image;
    if (!image.load(fileName)) {
        QMessageBox::information(this, "Error", "image load error.");
        return;
    }

    ui->label->setPixmap(QPixmap::fromImage(image));

    // load into shared memory
    QBuffer buffer;
    bool ok = buffer.open(QBuffer::ReadWrite);
    if (ok) {
        QDataStream in(&buffer);
        in << image;
        int size = buffer.size();
        if (! smem->create(size)) {
            QMessageBox::information(this, "Error", smem->errorString());
            return;
        }

        smem->lock();
        char *to = (char *)smem->data();
        const char *from = buffer.data().data();
        memcpy(to, from, qMin(smem->size(), size));
        smem->unlock();
    }
    else {
        QMessageBox::information(this, "Error", "buffer open error.");
        return;
    }
}


