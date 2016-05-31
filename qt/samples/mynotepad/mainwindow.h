#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtDebug>
#include <QFileDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QDateTime>
#include <QDesktopServices>
#include <QUrl>
#include <QCloseEvent>

#include "about.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    QString g_saveFileName;

private slots:
    void newFileSlot();
    void openFileSlot();
    void saveFileSlot();
    void saveAsFileSlot();
    void printFileSlot();
    void setFontSlot();
    void setColorSlot();
    void currentDateTimeSlot();
    void aboutWebSlot();
    void aboutSoftwareSlot();
};

#endif // MAINWINDOW_H
