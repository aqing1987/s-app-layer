#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedMemory>
#include <QBuffer>
#include <QDataStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSharedMemory *smem;

private slots:
    void loadFromFileSlot();
};

#endif // MAINWINDOW_H
