#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("regbits");
    this->setMaximumSize(490, 312);
    this->setMinimumSize(490, 312);

    this->g_val = 0;
    ui->binaryLineEdit->setText("0");
    ui->decLineEdit->setText("0");
    ui->hexLineEdit->setText("0");


    this->connect(ui->button0, SIGNAL(clicked()), this, SLOT(bit0_slot()));
    this->connect(ui->button1, SIGNAL(clicked()), this, SLOT(bit1_slot()));
    this->connect(ui->button2, SIGNAL(clicked()), this, SLOT(bit2_slot()));
    this->connect(ui->button3, SIGNAL(clicked()), this, SLOT(bit3_slot()));
    this->connect(ui->button4, SIGNAL(clicked()), this, SLOT(bit4_slot()));
    this->connect(ui->button5, SIGNAL(clicked()), this, SLOT(bit5_slot()));
    this->connect(ui->button6, SIGNAL(clicked()), this, SLOT(bit6_slot()));
    this->connect(ui->button7, SIGNAL(clicked()), this, SLOT(bit7_slot()));
    this->connect(ui->button8, SIGNAL(clicked()), this, SLOT(bit8_slot()));
    this->connect(ui->button9, SIGNAL(clicked()), this, SLOT(bit9_slot()));
    this->connect(ui->button10, SIGNAL(clicked()), this, SLOT(bit10_slot()));
    this->connect(ui->button11, SIGNAL(clicked()), this, SLOT(bit11_slot()));
    this->connect(ui->button12, SIGNAL(clicked()), this, SLOT(bit12_slot()));
    this->connect(ui->button13, SIGNAL(clicked()), this, SLOT(bit13_slot()));
    this->connect(ui->button14, SIGNAL(clicked()), this, SLOT(bit14_slot()));
    this->connect(ui->button15, SIGNAL(clicked()), this, SLOT(bit15_slot()));
    this->connect(ui->button16, SIGNAL(clicked()), this, SLOT(bit16_slot()));
    this->connect(ui->button17, SIGNAL(clicked()), this, SLOT(bit17_slot()));
    this->connect(ui->button18, SIGNAL(clicked()), this, SLOT(bit18_slot()));
    this->connect(ui->button19, SIGNAL(clicked()), this, SLOT(bit19_slot()));
    this->connect(ui->button20, SIGNAL(clicked()), this, SLOT(bit20_slot()));
    this->connect(ui->button21, SIGNAL(clicked()), this, SLOT(bit21_slot()));
    this->connect(ui->button22, SIGNAL(clicked()), this, SLOT(bit22_slot()));
    this->connect(ui->button23, SIGNAL(clicked()), this, SLOT(bit23_slot()));
    this->connect(ui->button24, SIGNAL(clicked()), this, SLOT(bit24_slot()));
    this->connect(ui->button25, SIGNAL(clicked()), this, SLOT(bit25_slot()));
    this->connect(ui->button26, SIGNAL(clicked()), this, SLOT(bit26_slot()));
    this->connect(ui->button27, SIGNAL(clicked()), this, SLOT(bit27_slot()));
    this->connect(ui->button28, SIGNAL(clicked()), this, SLOT(bit28_slot()));
    this->connect(ui->button29, SIGNAL(clicked()), this, SLOT(bit29_slot()));
    this->connect(ui->button30, SIGNAL(clicked()), this, SLOT(bit30_slot()));
    this->connect(ui->button31, SIGNAL(clicked()), this, SLOT(bit31_slot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_number()
{
    ui->decLineEdit->setText(QString::number(this->g_val, 10));
    ui->hexLineEdit->setText(QString::number(this->g_val, 16).toUpper());
    ui->binaryLineEdit->setText(QString::number(this->g_val, 2));
}

void MainWindow::update_bits_val()
{
    if (this->g_val & (1 << 31)) {
        ui->button31->setText("1");
    }
    else {
        ui->button31->setText("0");
    }

    if (this->g_val & (1 << 30)) {
        ui->button30->setText("1");
    }
    else {
        ui->button30->setText("0");
    }

    if (this->g_val & (1 << 29)) {
        ui->button29->setText("1");
    }
    else {
        ui->button29->setText("0");
    }

    if (this->g_val & (1 << 28)) {
        ui->button28->setText("1");
    }
    else {
        ui->button28->setText("0");
    }

    if (this->g_val & (1 << 27)) {
        ui->button27->setText("1");
    }
    else {
        ui->button27->setText("0");
    }

    if (this->g_val & (1 << 26)) {
        ui->button26->setText("1");
    }
    else {
        ui->button26->setText("0");
    }

    if (this->g_val & (1 << 25)) {
        ui->button25->setText("1");
    }
    else {
        ui->button25->setText("0");
    }

    if (this->g_val & (1 << 24)) {
        ui->button24->setText("1");
    }
    else {
        ui->button24->setText("0");
    }

    if (this->g_val & (1 << 23)) {
        ui->button23->setText("1");
    }
    else {
        ui->button23->setText("0");
    }

    if (this->g_val & (1 << 22)) {
        ui->button22->setText("1");
    }
    else {
        ui->button22->setText("0");
    }

    if (this->g_val & (1 << 21)) {
        ui->button21->setText("1");
    }
    else {
        ui->button21->setText("0");
    }

    if (this->g_val & (1 << 20)) {
        ui->button20->setText("1");
    }
    else {
        ui->button20->setText("0");
    }

    if (this->g_val & (1 << 19)) {
        ui->button19->setText("1");
    }
    else {
        ui->button19->setText("0");
    }

    if (this->g_val & (1 << 18)) {
        ui->button18->setText("1");
    }
    else {
        ui->button18->setText("0");
    }

    if (this->g_val & (1 << 17)) {
        ui->button17->setText("1");
    }
    else {
        ui->button17->setText("0");
    }

    if (this->g_val & (1 << 16)) {
        ui->button16->setText("1");
    }
    else {
        ui->button16->setText("0");
    }

    if (this->g_val & (1 << 15)) {
        ui->button15->setText("1");
    }
    else {
        ui->button15->setText("0");
    }

    if (this->g_val & (1 << 14)) {
        ui->button14->setText("1");
    }
    else {
        ui->button14->setText("0");
    }

    if (this->g_val & (1 << 13)) {
        ui->button13->setText("1");
    }
    else {
        ui->button13->setText("0");
    }

    if (this->g_val & (1 << 12)) {
        ui->button12->setText("1");
    }
    else {
        ui->button12->setText("0");
    }

    if (this->g_val & (1 << 11)) {
        ui->button11->setText("1");
    }
    else {
        ui->button11->setText("0");
    }

    if (this->g_val & (1 << 10)) {
        ui->button10->setText("1");
    }
    else {
        ui->button10->setText("0");
    }

    if (this->g_val & (1 << 9)) {
        ui->button9->setText("1");
    }
    else {
        ui->button9->setText("0");
    }

    if (this->g_val & (1 << 8)) {
        ui->button8->setText("1");
    }
    else {
        ui->button8->setText("0");
    }

    if (this->g_val & (1 << 7)) {
        ui->button7->setText("1");
    }
    else {
        ui->button7->setText("0");
    }

    if (this->g_val & (1 << 6)) {
        ui->button6->setText("1");
    }
    else {
        ui->button6->setText("0");
    }

    if (this->g_val & (1 << 5)) {
        ui->button5->setText("1");
    }
    else {
        ui->button5->setText("0");
    }

    if (this->g_val & (1 << 4)) {
        ui->button4->setText("1");
    }
    else {
        ui->button4->setText("0");
    }

    if (this->g_val & (1 << 3)) {
        ui->button3->setText("1");
    }
    else {
        ui->button3->setText("0");
    }

    if (this->g_val & (1 << 2)) {
        ui->button2->setText("1");
    }
    else {
        ui->button2->setText("0");
    }

    if (this->g_val & (1 << 1)) {
        ui->button1->setText("1");
    }
    else {
        ui->button1->setText("0");
    }

    if (this->g_val & (1 << 0)) {
        ui->button0->setText("1");
    }
    else {
        ui->button0->setText("0");
    }
}

void MainWindow::bit0_slot()
{
    if (ui->button0->text() == "0") {
        ui->button0->setText("1");
        this->g_val |= (1 << 0);
    }
    else {
        ui->button0->setText("0");
        this->g_val &= ~(1 << 0);
    }

    this->update_number();
}

void MainWindow::bit1_slot()
{
    if (ui->button1->text() == "0") {
        ui->button1->setText("1");
        this->g_val |= (1 << 1);
    }
    else {
        ui->button1->setText("0");
        this->g_val &= ~(1 << 1);
    }

    this->update_number();
}

void MainWindow::bit2_slot()
{
    if (ui->button2->text() == "0") {
        ui->button2->setText("1");
        this->g_val |= (1 << 2);
    }
    else {
        ui->button2->setText("0");
        this->g_val &= ~(1 << 2);
    }

    this->update_number();
}

void MainWindow::bit3_slot()
{
    if (ui->button3->text() == "0") {
        ui->button3->setText("1");
        this->g_val |= (1 << 3);
    }
    else {
        ui->button3->setText("0");
        this->g_val &= ~(1 << 3);
    }

    this->update_number();
}

void MainWindow::bit4_slot()
{
    if (ui->button4->text() == "0") {
        ui->button4->setText("1");
        this->g_val |= (1 << 4);
    }
    else {
        ui->button4->setText("0");
        this->g_val &= ~(1 << 4);
    }

    this->update_number();
}

void MainWindow::bit5_slot()
{
    if (ui->button5->text() == "0") {
        ui->button5->setText("1");
        this->g_val |= (1 << 5);
    }
    else {
        ui->button5->setText("0");
        this->g_val &= ~(1 << 5);
    }

    this->update_number();
}

void MainWindow::bit6_slot()
{
    if (ui->button6->text() == "0") {
        ui->button6->setText("1");
        this->g_val |= (1 << 6);
    }
    else {
        ui->button6->setText("0");
        this->g_val &= ~(1 << 6);
    }

    this->update_number();
}

void MainWindow::bit7_slot()
{
    if (ui->button7->text() == "0") {
        ui->button7->setText("1");
        this->g_val |= (1 << 7);
    }
    else {
        ui->button7->setText("0");
        this->g_val &= ~(1 << 7);
    }

    this->update_number();
}

void MainWindow::bit8_slot()
{
    if (ui->button8->text() == "0") {
        ui->button8->setText("1");
        this->g_val |= (1 << 8);
    }
    else {
        ui->button8->setText("0");
        this->g_val &= ~(1 << 8);
    }

    this->update_number();
}

void MainWindow::bit9_slot()
{
    if (ui->button9->text() == "0") {
        ui->button9->setText("1");
        this->g_val |= (1 << 9);
    }
    else {
        ui->button9->setText("0");
        this->g_val &= ~(1 << 9);
    }

    this->update_number();
}

void MainWindow::bit10_slot()
{
    if (ui->button10->text() == "0") {
        ui->button10->setText("1");
        this->g_val |= (1 << 10);
    }
    else {
        ui->button10->setText("0");
        this->g_val &= ~(1 << 10);
    }

    this->update_number();
}

void MainWindow::bit11_slot()
{
    if (ui->button11->text() == "0") {
        ui->button11->setText("1");
        this->g_val |= (1 << 11);
    }
    else {
        ui->button11->setText("0");
        this->g_val &= ~(1 << 11);
    }

    this->update_number();
}

void MainWindow::bit12_slot()
{
    if (ui->button12->text() == "0") {
        ui->button12->setText("1");
        this->g_val |= (1 << 12);
    }
    else {
        ui->button12->setText("0");
        this->g_val &= ~(1 << 12);
    }

    this->update_number();
}

void MainWindow::bit13_slot()
{
    if (ui->button13->text() == "0") {
        ui->button13->setText("1");
        this->g_val |= (1 << 13);
    }
    else {
        ui->button13->setText("0");
        this->g_val &= ~(1 << 13);
    }

    this->update_number();
}

void MainWindow::bit14_slot()
{
    if (ui->button14->text() == "0") {
        ui->button14->setText("1");
        this->g_val |= (1 << 14);
    }
    else {
        ui->button14->setText("0");
        this->g_val &= ~(1 << 14);
    }

    this->update_number();
}

void MainWindow::bit15_slot()
{
    if (ui->button15->text() == "0") {
        ui->button15->setText("1");
        this->g_val |= (1 << 15);
    }
    else {
        ui->button15->setText("0");
        this->g_val &= ~(1 << 15);
    }

    this->update_number();
}

void MainWindow::bit16_slot()
{
    if (ui->button16->text() == "0") {
        ui->button16->setText("1");
        this->g_val |= (1 << 16);
    }
    else {
        ui->button16->setText("0");
        this->g_val &= ~(1 << 16);
    }

    this->update_number();
}

void MainWindow::bit17_slot()
{
    if (ui->button17->text() == "0") {
        ui->button17->setText("1");
        this->g_val |= (1 << 17);
    }
    else {
        ui->button17->setText("0");
        this->g_val &= ~(1 << 17);
    }

    this->update_number();
}

void MainWindow::bit18_slot()
{
    if (ui->button18->text() == "0") {
        ui->button18->setText("1");
        this->g_val |= (1 << 18);
    }
    else {
        ui->button18->setText("0");
        this->g_val &= ~(1 << 18);
    }

    this->update_number();
}

void MainWindow::bit19_slot()
{
    if (ui->button19->text() == "0") {
        ui->button19->setText("1");
        this->g_val |= (1 << 19);
    }
    else {
        ui->button19->setText("0");
        this->g_val &= ~(1 << 19);
    }

    this->update_number();
}

void MainWindow::bit20_slot()
{
    if (ui->button20->text() == "0") {
        ui->button20->setText("1");
        this->g_val |= (1 << 20);
    }
    else {
        ui->button20->setText("0");
        this->g_val &= ~(1 << 20);
    }

    this->update_number();
}

void MainWindow::bit21_slot()
{
    if (ui->button21->text() == "0") {
        ui->button21->setText("1");
        this->g_val |= (1 << 21);
    }
    else {
        ui->button21->setText("0");
        this->g_val &= ~(1 << 21);
    }

    this->update_number();
}

void MainWindow::bit22_slot()
{
    if (ui->button22->text() == "0") {
        ui->button22->setText("1");
        this->g_val |= (1 << 22);
    }
    else {
        ui->button22->setText("0");
        this->g_val &= ~(1 << 22);
    }

    this->update_number();
}

void MainWindow::bit23_slot()
{
    if (ui->button23->text() == "0") {
        ui->button23->setText("1");
        this->g_val |= (1 << 23);
    }
    else {
        ui->button23->setText("0");
        this->g_val &= ~(1 << 23);
    }

    this->update_number();
}

void MainWindow::bit24_slot()
{
    if (ui->button24->text() == "0") {
        ui->button24->setText("1");
        this->g_val |= (1 << 24);
    }
    else {
        ui->button24->setText("0");
        this->g_val &= ~(1 << 24);
    }

    this->update_number();
}

void MainWindow::bit25_slot()
{
    if (ui->button25->text() == "0") {
        ui->button25->setText("1");
        this->g_val |= (1 << 25);
    }
    else {
        ui->button25->setText("0");
        this->g_val &= ~(1 << 25);
    }

    this->update_number();
}

void MainWindow::bit26_slot()
{
    if (ui->button26->text() == "0") {
        ui->button26->setText("1");
        this->g_val |= (1 << 26);
    }
    else {
        ui->button26->setText("0");
        this->g_val &= ~(1 << 26);
    }

    this->update_number();
}

void MainWindow::bit27_slot()
{
    if (ui->button27->text() == "0") {
        ui->button27->setText("1");
        this->g_val |= (1 << 27);
    }
    else {
        ui->button27->setText("0");
        this->g_val &= ~(1 << 27);
    }

    this->update_number();
}

void MainWindow::bit28_slot()
{
    if (ui->button28->text() == "0") {
        ui->button28->setText("1");
        this->g_val |= (1 << 28);
    }
    else {
        ui->button28->setText("0");
        this->g_val &= ~(1 << 28);
    }

    this->update_number();
}

void MainWindow::bit29_slot()
{
    if (ui->button29->text() == "0") {
        ui->button29->setText("1");
        this->g_val |= (1 << 29);
    }
    else {
        ui->button29->setText("0");
        this->g_val &= ~(1 << 29);
    }

    this->update_number();
}

void MainWindow::bit30_slot()
{
    if (ui->button30->text() == "0") {
        ui->button30->setText("1");
        this->g_val |= (1 << 30);
    }
    else {
        ui->button30->setText("0");
        this->g_val &= ~(1 << 30);
    }

    this->update_number();
}

void MainWindow::bit31_slot()
{
    if (ui->button31->text() == "0") {
        ui->button31->setText("1");
        this->g_val |= (1 << 31);
    }
    else {
        ui->button31->setText("0");
        this->g_val &= ~(1 << 31);
    }

    this->update_number();
}

void MainWindow::on_hexLineEdit_textChanged(const QString &arg1)
{
    bool ok;
    this->g_val = ui->hexLineEdit->text().toUInt(&ok, 16);

    ui->binaryLineEdit->setText(QString::number(this->g_val, 2));
    ui->decLineEdit->setText(QString::number(this->g_val, 10));
    this->update_bits_val();
}

void MainWindow::on_decLineEdit_textChanged(const QString &arg1)
{
    bool ok;
    this->g_val = ui->decLineEdit->text().toUInt(&ok, 10);

    ui->binaryLineEdit->setText(QString::number(this->g_val, 2));
    ui->hexLineEdit->setText(QString::number(this->g_val, 16));
    this->update_bits_val();
}

void MainWindow::on_binaryLineEdit_textChanged(const QString &arg1)
{
    bool ok;
    this->g_val = ui->binaryLineEdit->text().toUInt(&ok, 2);

    ui->decLineEdit->setText(QString::number(this->g_val, 10));
    ui->hexLineEdit->setText(QString::number(this->g_val, 16));
    this->update_bits_val();
}
