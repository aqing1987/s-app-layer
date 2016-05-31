#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Untitled - notepad");

    QObject::connect(ui->newAction, SIGNAL(triggered()), this, SLOT(newFileSlot()));
    QObject::connect(ui->openAction, SIGNAL(triggered()), this, SLOT(openFileSlot()));
    QObject::connect(ui->saveAction, SIGNAL(triggered()), this, SLOT(saveFileSlot()));
    QObject::connect(ui->saveAsAction, SIGNAL(triggered()), this, SLOT(saveAsFileSlot()));
    QObject::connect(ui->printAction, SIGNAL(triggered()), this, SLOT(printFileSlot()));
    QObject::connect(ui->exitAction, SIGNAL(triggered()), this, SLOT(close()));

    // edit menu
    QObject::connect(ui->undoAction, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    QObject::connect(ui->redoAction, SIGNAL(triggered()), ui->textEdit, SLOT(redo()));
    QObject::connect(ui->copyAction, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    QObject::connect(ui->pasteAction, SIGNAL(triggered()), ui->textEdit, SLOT(paste()));
    QObject::connect(ui->selectAllAction, SIGNAL(triggered()), ui->textEdit, SLOT(selectAll()));
    QObject::connect(ui->cutAction, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));

    QObject::connect(ui->setFontAction, SIGNAL(triggered()), this, SLOT(setFontSlot()));
    QObject::connect(ui->setColorAction, SIGNAL(triggered()), this, SLOT(setColorSlot()));
    QObject::connect(ui->datetimeAction, SIGNAL(triggered()), this, SLOT(currentDateTimeSlot()));

    // help menu
    QObject::connect(ui->aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    QObject::connect(ui->aboutWebAction, SIGNAL(triggered()), this, SLOT(aboutWebSlot()));
    QObject::connect(ui->aboutSoftwareAction, SIGNAL(triggered()), this, SLOT(aboutSoftwareSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (ui->textEdit->document()->isModified()) {
        event->ignore();

        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);

        int ret = msgBox.exec(); // QDialog exec
        switch (ret) {
        case QMessageBox::Save:
            // Save was clicked
            this->saveFileSlot();
            break;

        case QMessageBox::Discard:
            // Don't Save was clicked
            event->accept();
            break;

        case QMessageBox::Cancel:
            // Cancel was clicked
            event->ignore();
            break;

        default:
            // should never be reached
            break;
        }
    }
}

void MainWindow::newFileSlot()
{
    if (ui->textEdit->document()->isModified()) {
        qDebug() << "current file modified";
    }
    else {
        //qDebug() << "not modified";
        ui->textEdit->clear();
        this->setWindowTitle("untitled.txt");
    }
}

void MainWindow::openFileSlot()
{
    // get the file name
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath());
    //qDebug() << fileName;

    if (fileName.isEmpty()) {
        QMessageBox::information(this, "Error Message", "Please select a text file");
        return;
    }

    QFile *file = new QFile;
    file->setFileName(fileName);
    bool ok = file->open(QIODevice::ReadOnly);

    if (ok) {
        QTextStream in(file);
        ui->textEdit->setText(in.readAll()); // read all content from the file
        file->close();
        delete file;
    }
    else {
        QMessageBox::information(this, "Error Message", "File Open Err"+file->errorString());
        return;
    }

}

void MainWindow::saveFileSlot()
{
    if (this->g_saveFileName.isEmpty()) {
        this->saveAsFileSlot();
    }
    else {
        QFile *file = new QFile;
        file->setFileName(this->g_saveFileName);
        bool ok = file->open(QIODevice::WriteOnly);

        if (ok) {
            QTextStream out(file);
            out << ui->textEdit->toPlainText();
            file->close();
            this->setWindowTitle(this->g_saveFileName+" - notepad");
            delete file;
        }
    }
}

void MainWindow::saveAsFileSlot()
{
    this->g_saveFileName = QFileDialog::getSaveFileName(this, "Save File", QDir::currentPath());

    if (this->g_saveFileName.isEmpty()) {
        QMessageBox::information(this, "Error Message", "Save Err");
        return;
    }

    QFile *file = new QFile;
    file->setFileName(this->g_saveFileName);
    bool ok = file->open(QIODevice::WriteOnly);

    if (ok) {
        QTextStream out(file);
        out << ui->textEdit->toPlainText();
        file->close();
        this->setWindowTitle(this->g_saveFileName+" - notepad");
        delete file;
    }
    else {
        QMessageBox::information(this, "Error Message", "Save File Err");
        return;
    }
}

void MainWindow::printFileSlot()
{
    // QPrintDialog
}

void MainWindow::setFontSlot()
{
    // get user selected font
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        ui->textEdit->setFont(font);
    } else {
        QMessageBox::information(this, "Error Message", "Set font err");
        return;
    }
}

void MainWindow::setColorSlot()
{
    const QColor color = QColorDialog::getColor(Qt::green, this);

    if (color.isValid()) {
        ui->textEdit->setTextColor(color);
    }
    else {
        QMessageBox::information(this, "Error Message", "color invalid");
        return;
    }
}

void MainWindow::currentDateTimeSlot()
{
    QDateTime cdt = QDateTime::currentDateTime();
    QString stime = cdt.toString("yyyy-MM-dd hh:mm:ss");
    ui->textEdit->append(stime);
}

void MainWindow::aboutWebSlot()
{
    QDesktopServices::openUrl(QUrl("http://www.qt.io/", QUrl::TolerantMode));
}

void MainWindow::aboutSoftwareSlot()
{
    about *dialog_p = new about();

    //dialog_p->show(); // unmodal dialog
    dialog_p->exec(); // modal dialog
}
