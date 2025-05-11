#include "Five.h"
#include <QMessageBox>
#include <cstdlib>
#include <ctime>


//Init Chess Data, All to Zero 初始化棋盘数据
void Five::initCheseData(){

    for (int i=0; i<15; i++){

        for (int j=0; j<15; j++){

            this->data[i][j] = 0;
        }
    }
}


//Start Game 开始游戏
void Five::startGame(){

    //Init Button 初始化按钮
    this->isStart = true;
    this->startButton->setEnabled(false);
    this->stopButton->setEnabled(true);
    this->regretButton->setEnabled(false);

    //Init Label 初始化标签
    this->count->setText(QString::number(0));
    this->state->setText("游戏进行中");

    //Init Data 初始化数据
    this->initCheseData();
    if (!this->isAgainstPerson){

        if (!this->isHumanGo){

            if (!this->isHumanBlackColor){

                this->data[6][6] = 1;
            } else {

                this->data[6][6] = -1;
            }
        }
    }
    // 重置时间
    elapsedSeconds = 0;
    timeLabel->setText("00:00");
    timer->start(1000);  // 每秒触发一次
    this->update();

    //Is Funny 如果机机对战
    if (this->isfunny){

        //Romdom a point to start 随机其实点
        int style = 1;
        int x = (int)rand()%15;
        int y = (int)rand()%15;

        this->data[x][y] = style;
        this->isStart = true;
        this->update();

        while(this->isStart){

            style = -style;

            int nextX=0, nextY=0;
            int *pX = &nextX;
            int *pY = &nextY;

            this->computerGo(pX, pY);
            this->data[nextX][nextY] = style;
            this->update();
            this->checkWin();
        }
    }

}


//Clean Stack Memory 清楚悔棋堆栈内存
void Five::stopGame(){

    struct StackPersonToPerson *temp = this->stackPersonToPerson;

    while(temp!=NULL){

        this->stackPersonToPerson = this->stackPersonToPerson->pointer;
        free(temp);
        temp = this->stackPersonToPerson;
    }

    struct StackPersonToComputer *temptemp = this->stackPersonToComputer;

    while(temptemp!=NULL){

        this->stackPersonToComputer = this->stackPersonToComputer->pointer;
        free(temptemp);
        temptemp = this->stackPersonToComputer;
    }

    //Stop Button 更新按钮
    this->isStart = false;
    this->startButton->setEnabled(true);
    this->stopButton->setEnabled(false);
    this->regretButton->setEnabled(false);
    timer->stop();

    //Stop Label 更新标签
    this->state->setText("游戏结束");
}





//Regret Game 悔棋
void Five::regretGame(){

    if (this->isAgainstPerson){

        //Restore 还原
        this->data[this->stackPersonToPerson->y][this->stackPersonToPerson->x] = 0;
        this->isHumanGo = this->stackPersonToPerson->isHumanGo;

        //Clean Node 清楚节点
        struct StackPersonToPerson *temp = this->stackPersonToPerson;
        this->stackPersonToPerson = this->stackPersonToPerson->pointer;
        free(temp);

        if (this->stackPersonToPerson == NULL){

            this->regretButton->setEnabled(false);
        }
    } else {

        //Restore 还原
        this->data[this->stackPersonToComputer->yPerson][this->stackPersonToComputer->xPerson] = 0;
        this->data[this->stackPersonToComputer->yComputer][this->stackPersonToComputer->xComputer] = 0;

        //Clean Node 清楚节点
        struct StackPersonToComputer *temp = this->stackPersonToComputer;
        this->stackPersonToComputer = this->stackPersonToComputer->pointer;
        free(temp);

        if (this->stackPersonToComputer == NULL){

            this->regretButton->setEnabled(false);
        }
    }

    this->update();
}

