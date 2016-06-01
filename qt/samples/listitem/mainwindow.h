#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QtDebug>
#include <QStringList>
#include <QFileDialog>
#include <QDir>

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

private slots:
    void addCitySlot();
    void deleteCitySlot();
    void deleteAllSlot();
    void showDirSlot();
    //void singleClickedSlot(QListWidgetItem *);
    void doubleClickedSlot(QListWidgetItem *);
};

#endif // MAINWINDOW_H
