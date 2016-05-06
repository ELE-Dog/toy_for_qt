#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(saveScreenSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_screenshotButton_clicked()
{
    if(ui->checkBox->isChecked())
    {
        this->hide();
        this->timer =new QTimer;
        QObject::connect(this->timer,SIGNAL(timeout()),SLOT(shotScreenSlot()));
        this->timer->start(ui->spinBox->value()*1000);
    }
    else
    {
        qApp->beep();
    }
}

void MainWindow::shotScreenSlot()
{
    this->pixmap=QPixmap::grabWindow(QApplication::desktop()->winId());
    ui->screenlabel->setPixmap(this->pixmap.scaled(ui->screenlabel->size()));
    QClipboard *clipboard =QApplication::clipboard();
    //QString originalText=clipboard->text();
    //qDebug()<<"current clipboard text is"<<originalText;
    clipboard->setPixmap(this->pixmap);
    this->show();
    this->timer->stop();
}

void MainWindow::on_exitButton_clicked()
{
    this->close();
}

void MainWindow::saveScreenSlot()
{

}
