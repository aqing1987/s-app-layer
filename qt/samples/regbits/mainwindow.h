#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void update_number();
    void update_bits_val();

private:
    Ui::MainWindow *ui;
    unsigned int g_val;

private slots:
    void bit31_slot();
    void bit30_slot();
    void bit29_slot();
    void bit28_slot();
    void bit27_slot();
    void bit26_slot();
    void bit25_slot();
    void bit24_slot();
    void bit23_slot();
    void bit22_slot();
    void bit21_slot();
    void bit20_slot();
    void bit19_slot();
    void bit18_slot();
    void bit17_slot();
    void bit16_slot();
    void bit15_slot();
    void bit14_slot();
    void bit13_slot();
    void bit12_slot();
    void bit11_slot();
    void bit10_slot();
    void bit9_slot();
    void bit8_slot();
    void bit7_slot();
    void bit6_slot();
    void bit5_slot();
    void bit4_slot();
    void bit3_slot();
    void bit2_slot();
    void bit1_slot();
    void bit0_slot();
    void on_hexLineEdit_textChanged(const QString &arg1);
    void on_decLineEdit_textChanged(const QString &arg1);
    void on_binaryLineEdit_textChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
