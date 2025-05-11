#include "Five.h"
#include <QMouseEvent>
//Check Win 检查是否获胜

void Five::checkWin(){

    int whoWin = 0;

    //Check Horizontal 检查横向
    for (int i=0; i<15; i++){

        for (int j=0; j<11; j++){

            if ( this->data[i][j]==1 &&
                 this->data[i][j+1]==1 &&
                 this->data[i][j+2]==1 &&
                 this->data[i][j+3]==1 &&
                 this->data[i][j+4]==1 ){

                whoWin = 1;
                this->stopGame();

            } else if ( this->data[i][j]==-1 &&
                        this->data[i][j+1]==-1 &&
                        this->data[i][j+2]==-1 &&
                        this->data[i][j+3]==-1 &&
                        this->data[i][j+4]==-1 ){

                whoWin = -1;
                this->stopGame();

            } else ;
        }
    }


    //Check Verticality 检查纵向
    for (int i=0; i<11; i++){

        for (int j=0; j<15; j++){

            if ( this->data[i][j]==1 &&
                 this->data[i+1][j]==1 &&
                 this->data[i+2][j]==1 &&
                 this->data[i+3][j]==1 &&
                 this->data[i+4][j]==1 ){

                whoWin = 1;
                this->stopGame();

            } else if ( this->data[i][j]==-1 &&
                        this->data[i+1][j]==-1 &&
                        this->data[i+2][j]==-1 &&
                        this->data[i+3][j]==-1 &&
                        this->data[i+4][j]==-1 ){

                whoWin = -1;
                this->stopGame();

            } else ;
        }
    }


    //Check Slant Left 检查斜左
    for (int i=0; i<11; i++){

        for (int j=4; j<15; j++){

            if ( this->data[i][j]==1 &&
                 this->data[i+1][j-1]==1 &&
                 this->data[i+2][j-2]==1 &&
                 this->data[i+3][j-3]==1 &&
                 this->data[i+4][j-4]==1 ){

                whoWin = 1;
                this->stopGame();

            } else if ( this->data[i][j]==-1 &&
                        this->data[i+1][j-1]==-1 &&
                        this->data[i+2][j-2]==-1 &&
                        this->data[i+3][j-3]==-1 &&
                        this->data[i+4][j-4]==-1 ){

                whoWin = -1;
                this->stopGame();

            } else ;
        }
    }


    //Check Slant Right 检查斜右
    for (int i=0; i<11; i++){

        for (int j=0; j<11; j++){

            if ( this->data[i][j]==1 &&
                 this->data[i+1][j+1]==1 &&
                 this->data[i+2][j+2]==1 &&
                 this->data[i+3][j+3]==1 &&
                 this->data[i+4][j+4]==1 ){

                whoWin = 1;
                this->stopGame();

            } else if ( this->data[i][j]==-1 &&
                        this->data[i+1][j+1]==-1 &&
                        this->data[i+2][j+2]==-1 &&
                        this->data[i+3][j+3]==-1 &&
                        this->data[i+4][j+4]==-1 ){

                whoWin = -1;
                this->stopGame();

            } else ;
        }
    }


    //Popup Window 提示窗口
    if (whoWin == 1){

        QMessageBox::information(this, "", "黑子胜利", QMessageBox::Ok | QMessageBox::Cancel);

    } else if (whoWin == -1){

        QMessageBox::information(this, "", "白子胜利", QMessageBox::Ok | QMessageBox::Cancel);

    }
}



//Handle Mouse Click When Game Start 处理鼠标点击事件
void Five::mousePressEvent(QMouseEvent *event){

    if (this->isStart){

        QPoint point = event->pos();

        if (this->isAgainstPerson){

            if (point.x()>25 && point.x()<475 && point.y()>25 && point.y()<475) {

                int xIndex = (point.x()-10+15)/30 - 1;
                int yIndex = (point.y()-10+15)/30 - 1;

                if (this->data[yIndex][xIndex]==0){

                    //Record 堆栈纪录
                    struct StackPersonToPerson *temp = (struct StackPersonToPerson *)malloc(sizeof(struct StackPersonToPerson));
                    temp->pointer = NULL;
                    temp->x = xIndex;
                    temp->y = yIndex;
                    temp->isHumanGo = this->isHumanGo;

                    if (this->stackPersonToPerson == NULL){

                        this->stackPersonToPerson = temp;
                    } else {

                        struct StackPersonToPerson *temptemp = this->stackPersonToPerson;
                        this->stackPersonToPerson = temp;
                        temp->pointer = temptemp;
                    }
                    this->regretButton->setEnabled(true);
                    //Record Compelet 记录完毕


                    //Update Count Number 更新步数
                    this->count->setText(QString::number((this->count->text()).toInt()+1, 10));

                    if (this->isHumanGo) {

                        this->data[yIndex][xIndex] = 1;
                        this->isHumanGo = false;
                    } else {

                        this->data[yIndex][xIndex] = -1;
                        this->isHumanGo = true;
                    }
                }
            }
            this->checkWin();

        } else {

            if (point.x()>25 && point.x()<475 && point.y()>25 && point.y()<475) {

                int xIndex = (point.x()-10+15)/30 - 1;
                int yIndex = (point.y()-10+15)/30 - 1 ;

                if (this->data[yIndex][xIndex]==0){

                    //Human Put Chess 人放棋
                    if (this->isHumanBlackColor) {

                        this->data[yIndex][xIndex] = 1;
                        this->checkWin();

                    } else {

                        this->data[yIndex][xIndex] = -1;
                        this->checkWin();

                    }

                    //Calculate Computer Point 计算棋子
                    int xAI = 0;
                    int yAI = 0;
                    int *pointxAI = & xAI;
                    int *pointyAI = & yAI;

                    if (this->level == 1){

                        this->computerGo(pointyAI, pointxAI);

                    }else if (this->level == 2){

                        this->computerGoHard(pointyAI, pointxAI);
                    }

                    //Record 堆栈纪录
                    struct StackPersonToComputer *temp = (struct StackPersonToComputer *)malloc(sizeof(struct StackPersonToComputer));
                    temp->pointer = NULL;
                    temp->xPerson = xIndex;
                    temp->yPerson = yIndex;
                    temp->xComputer = xAI;
                    temp->yComputer = yAI;

                    if (this->stackPersonToComputer == NULL){

                        this->stackPersonToComputer = temp;
                    } else {

                        struct StackPersonToComputer *temptemp = this->stackPersonToComputer;
                        this->stackPersonToComputer = temp;
                        temp->pointer = temptemp;
                    }

                    this->regretButton->setEnabled(true);
                    //Record Compelet

                    //Computer Put Chess 电脑放棋
                    if (this->isStart){

                        if (this->isHumanBlackColor) {

                            this->data[yAI][xAI] = -1;
                            this->checkWin();
                        } else {

                            this->data[yAI][xAI] = 1;
                            this->checkWin();
                        }
                    }

                    //Update Count Number 更新步数
                    this->count->setText(QString::number((this->count->text()).toInt()+1, 10));
                }
            }
        }

        this->update();
    }
}


//Load File 加载文件
void Five::loadFile(){


    QString filename = QFileDialog::getOpenFileName(this, "加载文件", QDir::currentPath(),"游戏类型 (*.five)");

    if (!filename.isNull()) {


        this->stopGame();
        this->startGame();

        QByteArray byte = filename.toLatin1();
        FILE *fin = fopen(byte.data(),"r");

            //Restore Game Style: isAgainstPerson 还原设置
            int gameStyle = 0;
            fscanf(fin, "%d", &gameStyle);

            if (gameStyle == 1){

                this->isAgainstPerson = true;
            } else {

                this->isAgainstPerson = false;
            }

            //Restore WhosNext: isHumanGo 还原设置
            int whosNext = 0;
            fscanf(fin ,"%d", &whosNext);

            if (whosNext == 1){

                this->isHumanGo = true;
            } else {

                this->isHumanGo = false;
            }

            //Restore Chess Color: isHumanBlackColor 还原设置
            int colorBlack = 0;
            fscanf(fin ,"%d", &colorBlack);

            if (colorBlack == 1){

                this->isHumanBlackColor = true;
            } else {

                this->isHumanBlackColor = false;
            }


            //Restore count: count 清零
            int tempNumber = 0;
            fscanf(fin, "%d", &tempNumber);

            this->count->setText(QString::number(tempNumber, 10));

            for (int i=0; i<15; i++){

                for (int j=0; j<15; j++){

                    //Restore Data: data[][] 还原棋盘
                    fscanf(fin, "%d", &data[i][j]);
                }
            }

        fclose(fin);

        this->updateDisplaySettings();

        //Loaded 加载完成
        QMessageBox::information(this, "", "进度已加载", QMessageBox::Ok | QMessageBox::Cancel);

    } else {

        //No Load 未加载
        QMessageBox::information(this, "", "没有选择文件", QMessageBox::Ok | QMessageBox::Cancel);
    }

    this->update();
    this->checkWin();
}



//Save Game 保存游戏
void Five::saveFile(){


    if(!this->isfunny){

        QString filename = QFileDialog::getSaveFileName(this, "保存游戏进度", QDir::currentPath(),"游戏类型 (*.five)");

        if (!filename.isNull()) {

            //Save File 保存文件
            QByteArray byte = filename.toLatin1();

            FILE *fout = fopen(byte.data(),"w");

                //Write Start 开始写入
                if (this->isHumanGo) {

                    //Game Style: isAgainstPerson 保存设置
                    fprintf(fout, "1 ");
                } else {

                    fprintf(fout, "0 ");
                }

                if (this->isHumanGo) {

                    //Who's Next: isHumanGo 保存设置
                    fprintf(fout, "1 ");
                } else {

                    fprintf(fout, "0 ");
                }

                if (this->isHumanBlackColor) {

                    //Chess Color: isHumanBlackColor 保存设置
                    fprintf(fout, "1 ");
                } else {

                    fprintf(fout, "0 ");
                }

                    //Game Count: count 保存数
                fprintf(fout, "%d ", this->count->text().toInt());

                for (int i=0; i<15; i++){

                    for (int j=0; j<15; j++){

                        //Storage Data: Data[][] 保存棋盘
                        fprintf(fout, "%d ", this->data[i][j]);
                    }
                }
                //Write Complete 写入完毕

            fclose(fout);

            //Saved 加载完成
            QMessageBox::information(this, "",  "文件已保存", QMessageBox::Ok | QMessageBox::Cancel);
        } else {

            //No Save 未加载
            QMessageBox::information(this, "", "没有选择文件", QMessageBox::Ok | QMessageBox::Cancel);
        }
    }else{

        //Warning 警告
        QMessageBox::information(this, "", "在机对机模式中不允许保存", QMessageBox::Ok | QMessageBox::Cancel);
    }
}
