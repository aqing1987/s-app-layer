#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Id" << "Date" << "Hour" << "Temperature");
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

    connect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(setId(int, int)));
    connect(ui->customPlot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(showCoordinates(QMouseEvent *)));

    if (!readXML()) {
        qFatal("read XML err");
    }
    dbInit();
    drawData("");

    plotPaint();
    ui->tabWidget->setCurrentIndex(0);
    setWindowTitle("Body Temperature Monitor");
}

void MainWindow::setId(int row, int column)
{
    QTableWidgetItem * item1 = new QTableWidgetItem;
    item1 = ui->tableWidget->item(row, 0);
    ui->lineEditId->setText(item1->text());
}

void MainWindow::plotPaint()
{
    // create graph and assign data to it:
    ui->customPlot->addGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    ui->customPlot->graph(0)->setPen(QPen(QColor(255, 100, 0)));
    ui->customPlot->graph(0)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // fill with texture of specified image
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    ui->customPlot->graph(0)->setData(xHour, yCentigrade);

    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("hour");
    ui->customPlot->yAxis->setLabel("°C");

    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, 23);
    ui->customPlot->yAxis->setRange(35, 40);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->customPlot->replot();
}

void MainWindow::dbInit()
{
    mSql = QSqlDatabase::addDatabase("QSQLITE");
    mSql.setDatabaseName(dataBaseName);
    if (!mSql.open()) {
        qFatal("database open err");
    }

    qDebug("Connected!");

    QSqlQuery qry;

    // create table if not exist
    qry.prepare("CREATE TABLE IF NOT EXISTS body_temp (id INTEGER UNIQUE PRIMARY KEY, date VARCHAR(30), hour INTEGER, temp REAL)");
    if (!qry.exec()) {
        qDebug() << qry.lastError();
    }
    else {
        qDebug() << "Table created!";
    }
}

void MainWindow::drawData(QString curDate)
{
    QSqlQuery query;
    QString maxDate;
    QString cmd;

    if (curDate.isEmpty()) {
        cmd = "SELECT max(date) FROM body_temp";
        query.prepare(cmd);
        if (!query.exec()) {
            qDebug() << query.lastError();
            return;
        }
        else {
            if (query.next()) {
                maxDate = query.value(0).toString();
                qDebug() << "max date = " + maxDate;
                ui->lineEditDateShow->setText(maxDate);
            }
        }
    } else {
        maxDate = curDate;
    }

    cmd = "SELECT * FROM body_temp WHERE date='" + maxDate+"'";
    query.prepare(cmd);
    if (!query.exec()) {
        qDebug() << query.lastError();
    }
    else {
        qDebug() << "select ok!";

        xHour.clear();
        yCentigrade.clear();
        while (query.next()) {
            xHour.push_back(query.value("hour").toDouble());
            yCentigrade.push_back(query.value("temp").toDouble());
        }
    }
}

bool MainWindow::readXML()
{
    QFile *file = new QFile("db.xml");
    if (!file->open(QIODevice::ReadOnly)) {
        return false;
    }

    QDomDocument dom;
    if (!dom.setContent(file))  { //load xml to dom
        file->close();
        return false;
    }
    file->close();

    int flag = 0;

    // return root node
    QDomElement docElem = dom.documentElement();
    // return first child node of root node
    QDomNode node = docElem.firstChild();
    while (!node.isNull()) {
        if (node.isElement()) { // if node is element
            // change node to element
            QDomElement element = node.toElement();
            // draw this node's all child nodes && save to list
            QDomNodeList list = element.childNodes();

            for (int i = 0; i < list.count(); i++) {
                QDomNode domNode = list.at(i);
                if (domNode.isElement()) {
                    // get the data
                    switch(i) {
                    case 0:
                        ip = domNode.toElement().text();
                        qDebug() << ip;
                        break;
                    case 1:
                        port = domNode.toElement().text();
                        qDebug() << port;
                        break;
                    case 2:
                        dataBaseVersion = domNode.toElement().text();
                        qDebug() << dataBaseVersion;
                        break;
                    case 3:
                        dataBaseName = domNode.toElement().text();
                        qDebug() << dataBaseName;
                        break;
                    case 4:
                        userName = domNode.toElement().text();
                        qDebug() << userName;
                        break;
                    case 5:
                        passWord = domNode.toElement().text();
                        qDebug() << passWord;
                        break;
                    }
                }
            }
        }

        flag = 1;
        // next sibling
        node=node.nextSibling();
    }

    if (flag) {
        return true;
    }

    return false;
}

MainWindow::~MainWindow()
{
    mSql.close();

    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->setRowCount(0);
    QSqlQuery query;

    query.prepare("SELECT * FROM body_temp");
    if ( !query.exec() ) {
        qDebug() << query.lastError();
    }
    else {
        qDebug() << "select ok!";
    }

    while (query.next())
    {
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem(query.value("id").toString()));
        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(query.value("date").toString()));
        ui->tableWidget->setItem(0, 2, new QTableWidgetItem(query.value("hour").toString()));
        QString val = QString::number(query.value("temp").toFloat(), 'f', 1);
        ui->tableWidget->setItem(0, 3, new QTableWidgetItem(val));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if (ui->lineEditDate->text().isEmpty() ||
            ui->lineEditHour->text().isEmpty() ||
            ui->lineEditTemp->text().isEmpty()) {
        qFatal("empty content");
    } else {
        QString date = ui->lineEditDate->text();
        QString hour = ui->lineEditHour->text();
        QString temp = ui->lineEditTemp->text();

        QSqlQuery query;

        QString cmd = "INSERT INTO body_temp VALUES(null, '"+ date + "', " + hour + ", " + temp + ")";
        qDebug() << cmd;

        query.prepare(cmd);
        if ( !query.exec() ) {
            qDebug() << query.lastError();
        }
        else {
            qDebug() << "insert ok!";
            on_pushButton_2_clicked();
        }
    }
}

void MainWindow::on_pushButtonRefresh_clicked()
{
    drawData(ui->lineEditDateShow->text());
    plotPaint();
}

void MainWindow::on_pushButtonDelete_clicked()
{
    QString id = ui->lineEditId->text();
    if (id.isEmpty() || id.toInt() < 0) {
        qDebug() << "id = " << id;
        return;
    }

    QString cmd = "DELETE FROM body_temp WHERE id=" + id;
    qDebug() << cmd;

    QSqlQuery query;
    query.prepare(cmd);
    if ( !query.exec() ) {
        qDebug() << query.lastError();
    }
    else {
        qDebug() << "delete ok!";
    }

    on_pushButton_2_clicked();
}

void MainWindow::on_pushButtonDaysRefresh_clicked()
{
    QSqlQuery query;

    query.prepare("SELECT DISTINCT date FROM body_temp");
    if ( !query.exec() ) {
        qDebug() << query.lastError();
    }
    else {
        qDebug() << "select ok!";
    }

    ui->listWidgetDaysInfo->clear();
    while (query.next()) {
        ui->listWidgetDaysInfo->addItem(query.value("date").toString());
    }
}

void MainWindow::on_pushButtonShowDayCurve_clicked()
{
    ui->lineEditDateShow->setText(ui->listWidgetDaysInfo->currentItem()->text());
    ui->tabWidget->setCurrentIndex(0);

    drawData(ui->lineEditDateShow->text());
    plotPaint();
}

void MainWindow::on_pushButtonSave_clicked()
{
    QString defaultName = ui->lineEditDateShow->text() + "_body_temp.jpg";
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                 defaultName, tr("Images (*.jpg)"));
    if (fileName.isNull()) {
        return;
    }

    qDebug() << fileName;
    ui->customPlot->saveJpg(fileName, 640, 480);
}

void MainWindow::showCoordinates(QMouseEvent *me)
{
    double x = ui->customPlot->xAxis->pixelToCoord(me->pos().x());
    int x1 = int(x);
    int index = xHour.indexOf(x1);

    if (index >= 0) {
        QString content = "(" + QString::number(x1) + "h, "
                + QString::number(yCentigrade.at(index), 'f', 1) + "°C)";
        ui->lineEditPointValue->setText(content);
        QBrush myBrush;
        QPalette palette;
        myBrush = QBrush(Qt::red, Qt::DiagCrossPattern);
        palette.setBrush( QPalette::Text,  myBrush);
        ui->lineEditPointValue->setPalette(palette);
    }
}
