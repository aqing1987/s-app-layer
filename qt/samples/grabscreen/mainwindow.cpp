#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu = new QMenu(this);
    QAction *action = new QAction(this);
    QObject::connect(action, SIGNAL(triggered()), this, SLOT(on_saveButton_clicked()));
    action->setText("Save as");


    QAction *processAction = new QAction(this);
    QObject::connect(processAction, SIGNAL(triggered()), this, SLOT(openNotepadSlot()));
    processAction->setText("open notepad");


    menu->addAction(action);
    menu->addSeparator();
    menu->addAction(processAction);
    menu->exec(QCursor::pos());
}

void MainWindow::openNotepadSlot()
{
    QProcess *process = new QProcess(this);
    process->start("notepad");
}

void MainWindow::on_newButton_clicked()
{
    if (ui->checkBox->isChecked()) {
        this->hide();

        this->timer = new QTimer;
        QObject::connect(this->timer, SIGNAL(timeout()), this, SLOT(grabScreenSlot()));
        this->timer->start(ui->spinBox->value()*1000);
    }
    else {
        qApp->beep();
    }
}

void MainWindow::grabScreenSlot()
{    
    QScreen *screen = QGuiApplication::primaryScreen();
    this->pixmap = screen->grabWindow(QApplication::desktop()->winId());

    // save to clipboard
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setPixmap(this->pixmap);

    ui->screenLabel->setPixmap(this->pixmap.scaled(ui->screenLabel->size()));
    this->show();
    this->timer->stop();
}

void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    QDir::currentPath(),
                                                    tr("Images (*.png)"));
    this->pixmap.save(fileName);
}
