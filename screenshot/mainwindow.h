#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDesktopWidget>
#include <QPixmap>
#include <QFileDialog>
#include <QDesktopServices>
#include <QClipboard>
#include <QDebug>

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
    void on_screenshotButton_clicked();
    void shotScreenSlot();
    void saveScreenSlot();
    void on_exitButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QPixmap pixmap;

};

#endif // MAINWINDOW_H
