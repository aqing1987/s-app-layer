#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->progress = new QProgressBar;
    ui->statusBar->addWidget(this->progress);

    QObject::connect(ui->webView, SIGNAL(urlChanged(QUrl)), this, SLOT(setUrlSlot(QUrl)));
    QObject::connect(ui->webView, SIGNAL(titleChanged(QString)), this, SLOT(setTitleSlot(QString)));
    QObject::connect(ui->webView, SIGNAL(loadProgress(int)), this->progress, SLOT(setValue(int)));
    QObject::connect(ui->urlLineEdit, SIGNAL(returnPressed()), this, SLOT(browserWebSlot()));
    QObject::connect(ui->webView, SIGNAL(loadFinished(bool)), this, SLOT(delProgressBar(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUrlSlot(QUrl url)
{
    ui->urlLineEdit->setText(url.toString());
}

void MainWindow::setTitleSlot(QString title)
{
    this->setWindowTitle(title);
}

void MainWindow::browserWebSlot()
{
    ui->webView->load(QUrl(ui->urlLineEdit->text()));
}

void MainWindow::delProgressBar(bool ok)
{
    if (ok) {
        delete this->progress;
        this->progress = NULL;
        this->statusBar()->showMessage("done");
    }
}
