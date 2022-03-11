#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>
#include <QVector>



#include <QKeyEvent>
#include <QGraphicsScene>
#include <QList>
#include <QString>
#include <string>
#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsRectItem>


int c=0;
#define filas 15
#define columnas 17

//QVector <player> players;

using namespace std;

int **generar_matriz(QWidget *parent);//definicion de la funcion que genera matriz

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1020,900);
    scene->setBackgroundBrush(Qt::blue);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    int floor[filas][columnas];
    int random[2]={2,3};
    int randomnum =0;
    for (int i=0; i<filas ; i++){
        for (int j=0; j<columnas ; j++){
            if(i==0 || j==0 || i == filas-1 || j==columnas-1){ // los extremos laterales
                floor[i][j]=1;
            }
            else if(i%2 ==0 && j%2==0){ // los indestructibles del interios
                floor[i][j]=1;
            }
            else if ((i==1 && j==1) || (i==2 && j==1) || (i==1 && j==2) || (i==filas-2 && j==columnas-2) // los 6 del
                     || (i==filas-3 && j==columnas-2) || (i==filas-2 && j==columnas-3)){//extremo superior izquierdo e inferior derecho
                floor[i][j]=2;
            }
            else{//el resto de bloques seran aleatorios
                randomnum = rand()%2;
                floor[i][j]=random[randomnum];
                randomnum=0;
            }
        }
    }

    for (int i=0; i<filas ; i++){
        for (int j=0; j<columnas ; j++){
            if(floor[i][j]==2){
                grassblock = new grass(i*35+35 ,j*35+35, 35, 35);
                scene->addItem(grassblock);
            }
            else if(floor[i][j] == 1){
                wallblock = new wall(i*35+35 ,j*35+35, 35, 35);
                scene->addItem(wallblock);

            }
            else{
                brickblock = new brick(i*35+35 ,j*35+35, 35, 35);
                scene->addItem(brickblock);
            }


        }
    }


    man = new player(60 ,60, 15, 20);
    scene->addItem(man);
    man2 = new player(180 ,180, 15, 20);
    scene->addItem(man2);

    //players.append(*man);
    //players.append(*man2);

//    QVector<player>::iterator itt;
//        for (itt = players.begin(); itt != players.end(); ++itt) {
//            qDebug() << players.at(*itt);
//         }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
     if((event->key() == Qt::Key_A)  ){
         man->move_lef();
     }
     if(event->key() == Qt::Key_D && !man->collidesWithItem(wallblock)){
         man->move_rith();
     }
     if(event->key() == Qt::Key_W && !man->collidesWithItem(wallblock)){
         man->move_up();
     }
     if(event->key() == Qt::Key_S && !man->collidesWithItem(wallblock)){
         man->move_down();
     }
     if(man->collidesWithItem(man2)== true){

         qDebug() << "its touching"<<c ;
         c++;
     }

}
