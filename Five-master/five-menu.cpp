#include "Five.h"
#include <QMessageBox>


//Switch to Against Person 切换到人人对战
void Five::againstPerson(){

    this->isfunny = false;
    this->isAgainstPerson = true;
    this->updateDisplaySettings();
}


//Switch to Against Computer 切换到人机对战
void Five::againstComputer(){

    this->isfunny = false;
    this->isAgainstPerson = false;
    this->updateDisplaySettings();
}

//Switch to Simple Mode 切换到简单模式
void Five::simpleMode(){

    this->level = 1;
    this->stateHard->setText("简单模式");
}

//Switch to PC vs PC 切换到机机对战
void Five::funny(){

    this->isfunny = true;
    this->updateDisplaySettings();
}



//Switch First Go 切换先手
void Five::chooseFirst(){

    this->isHumanGo = true;
    this->updateDisplaySettings();
}



//Switch Second Go 切换后手
void Five::chooseSecond(){

    this->isHumanGo = false;
    this->updateDisplaySettings();
}

//Switch to Hard Mode 切换到困难模式
void Five::hardMode(){

    this->level = 2;
    this->stateHard->setText("困难模式");
}


//Choose Black 选择黑子
void Five::chooseBlack(){

    this->isHumanBlackColor = true;
    this->updateDisplaySettings();
}
//Choose White 选择白子
void Five::chooseWhite(){

    this->isHumanBlackColor = false;
    this->updateDisplaySettings();
}



//Define Help Window 构造帮助窗口
void Five::helpShow(){

    class HelpWindow : public QMainWindow {

        public:

            explicit HelpWindow(){

                this->setFixedSize(300,280);

                QLabel *label = new QLabel("帮助", this);

                QFont font;
                font.setPointSize(20);
                label->setFont(font);
                label->setGeometry(QRect(130,20,80,40));

                QLabel *label1 = new QLabel("支持人人对战", this);
                label1->setGeometry(QRect(100,60,150,40));


                QLabel *label2 = new QLabel("支持人机对战", this);
                label2->setGeometry(QRect(100,90,150,40));


                QLabel *label3 = new QLabel("支持机机对战", this);
                label3->setGeometry(QRect(100,120,150,40));


                QLabel *label4 = new QLabel("支持选择先后手", this);
                label4->setGeometry(QRect(100,150,150,40));


                QLabel *label5 = new QLabel("支持选择黑白子", this);
                label5->setGeometry(QRect(100,180,150,40));


                QLabel *label6 = new QLabel("支持保存游戏", this);
                label6->setGeometry(QRect(100,210,150,40));
            }

        ~HelpWindow(){}
    };

    //Show Help Window 显示帮助窗口
    HelpWindow *help = new HelpWindow();
    help->show();
}






//Update Display Settings 更新设置标签
void Five::updateDisplaySettings(){

    if (!this->isfunny){

        if (this->isAgainstPerson){

            this->stateAll->setText("人人对战");
        } else {

            if (this->isHumanGo){

                if (this->isHumanBlackColor){

                    this->stateAll->setText("人机 先手 黑子");
                } else {

                    this->stateAll->setText("人机 先手 白子");
                }
            } else {

                if (this->isHumanBlackColor){

                    this->stateAll->setText("人机 后手 黑子");
                } else {

                    this->stateAll->setText("人机 后手 白子");
                }
            }
        }

    }else {

        this->stateAll->setText("机机对战");
    }
}


