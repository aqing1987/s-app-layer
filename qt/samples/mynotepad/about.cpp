#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->setWindowTitle("About Software");

    this->movie = new QMovie("bin_images/about.gif");
    qDebug() << "total frames: " << this->movie->frameCount();
    ui->movieLabel->setMovie(this->movie);
    this->movie->start();

    this->sound = new QSound("bin_music/sky.wav");
    this->sound->play();
}

about::~about()
{
    delete ui;
}

void about::closeEvent(QCloseEvent *event)
{
    this->sound->stop();
    event->accept();
}
