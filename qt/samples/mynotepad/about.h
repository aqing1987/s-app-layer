#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QMovie>
#include <QtDebug>
#include <QSound>
#include <QCloseEvent> // all events are protected

namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = 0);
    ~about();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::about *ui;
    QMovie *movie;
    QSound *sound;
};

#endif // ABOUT_H
