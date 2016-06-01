#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebView>
#include <QUrl>
#include <QProgressBar>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void setUrlSlot(QUrl url);
    void setTitleSlot(QString title);
    void browserWebSlot();
    void delProgressBar(bool ok);

private:
    Ui::MainWindow *ui;
    QProgressBar *progress;
};

#endif // MAINWINDOW_H
