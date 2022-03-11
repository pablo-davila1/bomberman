#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <player.h>
#include <grass.h>
#include <wall.h>
#include <brick.h>

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QList>
#include <QString>
#include <string>
#include <sstream>
#include <QMainWindow>
#include <QGraphicsRectItem>
#include <fstream>
#include <QKeyEvent>
#include <QGraphicsRectItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void keyPressEvent(QKeyEvent *event);


private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;

    player *man;
    player *man2;
    grass *grassblock;
    wall *wallblock;
    brick *brickblock;



};
#endif // MAINWINDOW_H
