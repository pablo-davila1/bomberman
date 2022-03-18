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
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(Qt::black);
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
                wallsblock.push_back(new wall(i*35+35 ,j*35+35, 35, 35));
                scene->addItem(wallsblock.back());

            }
            else{
                bricksblock.push_back(new brick(i*35+35 ,j*35+35, 35, 35));
                scene->addItem(bricksblock.back());
            }


        }
    }


    man = new player(60 ,60, 15, 20);
    scene->addItem(man);
    man->setFocus();

    Score = new score();
    scene->addItem(Score);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
     if((event->key() == Qt::Key_A)){
         if(EvaluarColision()!=1){
             man->move_lef();
         }
         else{
            man->move_rith();
            man->move_rith();
         }
         if(EvaluarColision()==2){

         }

     }
     if(event->key() == Qt::Key_D ){
         if(EvaluarColision()!=1){
            man->move_rith();
         }
         else{
            man->move_lef();
            man->move_lef();
         }

     }
     if(event->key() == Qt::Key_W){
         if(EvaluarColision()!=1){
            man->move_up();
         }
         else{
            man->move_down();
            man->move_down();
         }
     }
     if(event->key() == Qt::Key_S){
         if(EvaluarColision()!=1){
            man->move_down();
         }
         else{
            man->move_up();
            man->move_up();
         }

     }

}

int MainWindow::EvaluarColision()
{
    int x=0,y=0;
    QList<wall*>::iterator it;
    for(it=wallsblock.begin();it != wallsblock.end() ;it++){
        if((*it)->collidesWithItem(man))
            return 1;//muro
    }
    QList<brick*>::iterator it2;
    for(it2=bricksblock.begin(); it2 != bricksblock.end() ; it2++){
        if((*it2)->collidesWithItem(man)){
            grassblock = new grass((*it2)->getPosx(),(*it2)->getPosy(), 35, 35);
            scene->removeItem(*it2);
            scene->addItem(grassblock);
            x=man->getPosx();
            y=man->getPosy();
            scene->removeItem(man);
            man = new player(x ,y, 15, 20);
            scene->addItem(man);
            Score->increase();

            return 2;//ladrillo
        }
    }
    return 0;

}
