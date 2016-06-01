#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setViewMode(QListView::IconMode);

    this->connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addCitySlot()));
    this->connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(addCitySlot()));
    this->connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteCitySlot()));
    this->connect(ui->deleteAllButton, SIGNAL(clicked()), this, SLOT(deleteAllSlot()));
    this->connect(ui->showDirButton, SIGNAL(clicked()), this, SLOT(showDirSlot()));
    //this->connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(singleClickedSlot(QListWidgetItem*)));
    this->connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(doubleClickedSlot(QListWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCitySlot()
{
    QString cityName = ui->lineEdit->text();

    if (cityName.isEmpty()) {
        QMessageBox::information(this, "Error", "Input City Name");
        return;
    }

    QListWidgetItem *item = new QListWidgetItem;
    item->setText(cityName);

    ui->listWidget->addItem(item);
    ui->lineEdit->clear();


}

void MainWindow::deleteCitySlot()
{
    QListWidgetItem *item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}

void MainWindow::deleteAllSlot()
{
    int total = ui->listWidget->count();


    for (int i = 0; i < total; i++) {
        //qDebug() << "i = " << i;
        delete ui->listWidget->item(0);
    }
}

void MainWindow::showDirSlot()
{
    QDir::currentPath();
    QDir dir = QDir::current();
    QStringList fileNames = dir.entryList();

    if (fileNames.size() == 0) {
        QMessageBox::information(this, "error", "please select files");
        return;
    }

    for (int i = 0; i < fileNames.size(); i++) {
        if (fileNames.at(i) == "." || fileNames.at(i) == "..") {
            continue;
        }
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(fileNames.at(i));
        ui->listWidget->addItem(item);
    }
}

/*
void MainWindow::singleClickedSlot(QListWidgetItem *item)
{
    QMessageBox::information(this, "info", "single clicked text: " + item->text());
}
*/


void MainWindow::doubleClickedSlot(QListWidgetItem *item)
{
    QMessageBox::information(this, "info", "double clicked text: " + item->text());
}
