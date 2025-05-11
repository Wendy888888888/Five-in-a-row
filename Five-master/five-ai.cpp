#include "Five.h"
#include <ctime>

void Five::computerGo(int *x, int *y){

    int computer[15][15] = {{0}};
    int human[15][15] = {{0}};

    int computerSign = 0; int humanSign = 0;

    if (this->isHumanBlackColor){

        computerSign = -1; humanSign = 1;

    } else {

        computerSign = 1; humanSign = -1;
    }

    //Computer Search 搜索电脑棋子
    for (int i=0 ;i<15; i++){

        for (int j=0; j<15; j++){

            if (this->data[i][j] == 0){

                //Horizonal Left 横左
                if (j>3){

                    if (this->data[i][j-1]==computerSign &&
                        this->data[i][j-2]==computerSign &&
                        this->data[i][j-3]==computerSign &&
                        this->data[i][j-4]==computerSign){

                        computer[i][j] += 4;

                    } else if (this->data[i][j-1]==computerSign &&
                               this->data[i][j-2]==computerSign &&
                               this->data[i][j-3]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i][j-1]==computerSign &&
                               this->data[i][j-2]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i][j-1]==computerSign){

                        computer[i][j] += 1;

                    }

                } else if (j==3){

                    if (this->data[i][j-1]==computerSign &&
                        this->data[i][j-2]==computerSign &&
                        this->data[i][j-3]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i][j-1]==computerSign &&
                               this->data[i][j-2]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i][j-1]==computerSign){

                        computer[i][j] += 1;

                    }

                } else if (j==2){

                    if (this->data[i][j-1]==computerSign &&
                        this->data[i][j-2]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i][j-1]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (j==1){

                    if (this->data[i][j-1]==computerSign){

                        computer[i][j] += 1;
                    }
                }

                //Horizonal Right 横右
                if (j<11){

                    if (this->data[i][j+1]==computerSign &&
                        this->data[i][j+2]==computerSign &&
                        this->data[i][j+3]==computerSign &&
                        this->data[i][j+4]==computerSign){

                        computer[i][j] += 4;

                    } else if (this->data[i][j+1]==computerSign &&
                               this->data[i][j+2]==computerSign &&
                               this->data[i][j+3]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i][j+1]==computerSign &&
                               this->data[i][j+2]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i][j+1]==computerSign){

                        computer[i][j] += 1;

                    }

                } else if (j==11){

                    if (this->data[i][j+1]==computerSign &&
                        this->data[i][j+2]==computerSign &&
                        this->data[i][j+3]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i][j+1]==computerSign &&
                               this->data[i][j+2]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i][j+1]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (j==12){

                    if (this->data[i][j+1]==computerSign &&
                        this->data[i][j+2]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i][j+1]==computerSign){

                        computer[i][j] += 1;

                    }
                } else if (j==13){

                    if (this->data[i][j+1]==computerSign){

                        computer[i][j] += 1;

                    }
                }

                //Vertical Top 竖上
                if (i>3){

                    if (this->data[i-1][j]==computerSign &&
                        this->data[i-2][j]==computerSign &&
                        this->data[i-3][j]==computerSign &&
                        this->data[i-4][j]==computerSign){

                        computer[i][j] += 4;

                    } else if (this->data[i-1][j]==computerSign &&
                               this->data[i-2][j]==computerSign &&
                               this->data[i-3][j]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i-1][j]==computerSign &&
                               this->data[i-2][j]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i-1][j]==computerSign){

                        computer[i][j] += 1;

                    }

                } else if (i==3){

                    if (this->data[i-1][j]==computerSign &&
                        this->data[i-2][j]==computerSign &&
                        this->data[i-3][j]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i-1][j]==computerSign &&
                               this->data[i-2][j]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i-1][j]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (i==2){

                    if (this->data[i-1][j]==computerSign &&
                        this->data[i-2][j]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i-1][j]==computerSign){

                        computer[i][j] += 1;

                    }

                } else if (i==1){

                    if (this->data[i-1][j]==computerSign){

                        computer[i][j] += 1;
                    }
                }

                //Vertical Buttom 竖下
                if (i<11){

                    if (this->data[i+1][j]==computerSign &&
                        this->data[i+2][j]==computerSign &&
                        this->data[i+3][j]==computerSign &&
                        this->data[i+4][j]==computerSign){

                        computer[i][j] += 4;

                    } else if (this->data[i+1][j]==computerSign &&
                               this->data[i+2][j]==computerSign &&
                               this->data[i+3][j]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i+1][j]==computerSign &&
                               this->data[i+2][j]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i+1][j]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (i==11){

                    if (this->data[i+1][j]==computerSign &&
                        this->data[i+2][j]==computerSign &&
                        this->data[i+3][j]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i+1][j]==computerSign &&
                               this->data[i+2][j]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i+1][j]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (i==12){

                    if (this->data[i+1][j]==computerSign &&
                        this->data[i+2][j]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i+1][j]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (i==13){

                    if (this->data[i+1][j]==computerSign){

                        computer[i][j] += 1;
                    }
                }
            }
        }
    }


    //Human Search 搜索人棋子
    for (int i=0 ;i<15; i++){

        for (int j=0; j<15; j++){

            if (this->data[i][j] == 0){

                //Horizonal Left 横左
                if (j>3){

                    if (this->data[i][j-1]==humanSign &&
                        this->data[i][j-2]==humanSign &&
                        this->data[i][j-3]==humanSign &&
                        this->data[i][j-4]==humanSign){

                        human[i][j] += 4;

                    } else if (this->data[i][j-1]==humanSign &&
                               this->data[i][j-2]==humanSign &&
                               this->data[i][j-3]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i][j-1]==humanSign &&
                               this->data[i][j-2]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i][j-1]==humanSign){

                        human[i][j] += 1;
                    }

                } else if (j==3){

                    if (this->data[i][j-1]==humanSign &&
                        this->data[i][j-2]==humanSign &&
                        this->data[i][j-3]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i][j-1]==humanSign &&
                               this->data[i][j-2]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i][j-1]==humanSign){

                        human[i][j] += 1;
                    }

                } else if (j==2){

                    if (this->data[i][j-1]==humanSign &&
                        this->data[i][j-2]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i][j-1]==humanSign){

                        human[i][j] += 1;

                    }
                } else if (j==1){

                    if (this->data[i][j-1]==humanSign){

                        human[i][j] += 1;
                    }
                }

                //Horizonal Right 横右
                if (j<11){

                    if (this->data[i][j+1]==humanSign &&
                        this->data[i][j+2]==humanSign &&
                        this->data[i][j+3]==humanSign &&
                        this->data[i][j+4]==humanSign){

                        human[i][j] += 4;

                    } else if (this->data[i][j+1]==humanSign &&
                               this->data[i][j+2]==humanSign &&
                               this->data[i][j+3]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i][j+1]==humanSign &&
                               this->data[i][j+2]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i][j+1]==humanSign){

                        human[i][j] += 1;
                    }

                } else if (j==11){

                    if (this->data[i][j+1]==humanSign &&
                        this->data[i][j+2]==humanSign &&
                        this->data[i][j+3]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i][j+1]==humanSign &&
                               this->data[i][j+2]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i][j+1]==humanSign){

                        human[i][j] += 1;
                    }

                } else if (j==12){

                    if (this->data[i][j+1]==humanSign &&
                        this->data[i][j+2]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i][j+1]==humanSign){

                        human[i][j] += 1;
                    }

                } else if (j==13){

                    if (this->data[i][j+1]==humanSign){

                        human[i][j] += 1;

                    }
                }

                //Vertical Top 竖上
                if (i>3){

                    if (this->data[i-1][j]==humanSign &&
                        this->data[i-2][j]==humanSign &&
                        this->data[i-3][j]==humanSign &&
                        this->data[i-4][j]==humanSign){

                        human[i][j] += 4;

                    } else if (this->data[i-1][j]==humanSign &&
                               this->data[i-2][j]==humanSign &&
                               this->data[i-3][j]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i-1][j]==humanSign &&
                               this->data[i-2][j]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i-1][j]==humanSign){

                        human[i][j] += 1;
                    }

                } else if (i==3){

                    if (this->data[i-1][j]==humanSign &&
                        this->data[i-2][j]==humanSign &&
                        this->data[i-3][j]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i-1][j]==humanSign &&
                               this->data[i-2][j]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i-1][j]==humanSign){

                        human[i][j] += 1;
                    }

                } else if (i==2){

                    if (this->data[i-1][j]==humanSign &&
                        this->data[i-2][j]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i-1][j]==humanSign){

                        human[i][j] += 1;

                    }
                } else if (i==1){

                    if (this->data[i-1][j]==humanSign){

                        human[i][j] += 1;
                    }
                }
                //Vertical Buttom 竖下
                if (i<11){

                    if (this->data[i+1][j]==humanSign &&
                        this->data[i+2][j]==humanSign &&
                        this->data[i+3][j]==humanSign &&
                        this->data[i+4][j]==humanSign){

                        human[i][j] += 4;

                    } else if (this->data[i+1][j]==humanSign &&
                               this->data[i+2][j]==humanSign &&
                               this->data[i+3][j]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i+1][j]==humanSign &&
                               this->data[i+2][j]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i+1][j]==humanSign){

                        human[i][j] += 1;
                    }

                } else if (i==11){

                    if (this->data[i+1][j]==humanSign &&
                        this->data[i+2][j]==humanSign &&
                        this->data[i+3][j]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i+1][j]==humanSign &&
                               this->data[i+2][j]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i+1][j]==humanSign){

                        human[i][j] += 1;

                    }

                } else if (i==12){

                    if (this->data[i+1][j]==humanSign &&
                        this->data[i+2][j]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i+1][j]==humanSign){

                        human[i][j] += 1;
                    }

                } else if (i==13){

                    if (this->data[i+1][j]==humanSign){

                        human[i][j] += 1;
                    }
                }

            }
        }
    }



    //Search The Point 查找点

    //Random a Point 随机一个点
    srand(time(NULL));
    *x = (int)rand()%15;
    *y = (int)rand()%15;

    while(this->data[*x][*y] != 0){

        *x = (int)rand()%15;
        *y = (int)rand()%15;
    }


    int max = 0;

    //Computer 搜索电脑价值
    for (int i=0; i<15; i++){

        for (int j=0; j<15; j++){

            if (computer[i][j]>max && this->data[i][j] == 0){

                max = computer[i][j];
                *x = i; *y = j;
            }
        }
    }

    //Human 搜索人价值
    for (int i=0; i<15; i++){

        for (int j=0; j<15; j++){

            if (human[i][j]>max && this->data[i][j] == 0){

                max = human[i][j];
                *x = i; *y = j;
            }
        }
    }

}


void Five::computerGoHard(int *x, int *y){

    int computer[15][15] = {{0}};
    int human[15][15] = {{0}};

    int computerSign = 0; int humanSign = 0;

    if (this->isHumanBlackColor){

        computerSign = -1; humanSign = 1;
    } else {

        computerSign = 1; humanSign = -1;
    }

    //Computer Search 搜索电脑棋子
    for (int i=0 ;i<15; i++){

        for (int j=0; j<15; j++){

            if (this->data[i][j] == 0){

                //Horizonal Left 横左
                if (j>3){

                    if (this->data[i][j-1]==computerSign &&
                        this->data[i][j-2]==computerSign &&
                        this->data[i][j-3]==computerSign &&
                        this->data[i][j-4]==computerSign){

                        computer[i][j] += 4;

                    } else if (this->data[i][j-1]==computerSign &&
                               this->data[i][j-2]==computerSign &&
                               this->data[i][j-3]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i][j-1]==computerSign &&
                               this->data[i][j-2]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i][j-1]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (j==3){

                    if (this->data[i][j-1]==computerSign &&
                        this->data[i][j-2]==computerSign &&
                        this->data[i][j-3]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i][j-1]==computerSign &&
                               this->data[i][j-2]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i][j-1]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (j==2){

                    if (this->data[i][j-1]==computerSign &&
                        this->data[i][j-2]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i][j-1]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (j==1){
                    if (this->data[i][j-1]==computerSign){

                        computer[i][j] += 1;
                    }
                }
                //Horizonal Right 横右
                if (j<11){

                    if (this->data[i][j+1]==computerSign &&
                        this->data[i][j+2]==computerSign &&
                        this->data[i][j+3]==computerSign &&
                        this->data[i][j+4]==computerSign){

                        computer[i][j] += 4;

                    } else if (this->data[i][j+1]==computerSign &&
                               this->data[i][j+2]==computerSign &&
                               this->data[i][j+3]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i][j+1]==computerSign &&
                               this->data[i][j+2]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i][j+1]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (j==11){

                    if (this->data[i][j+1]==computerSign &&
                        this->data[i][j+2]==computerSign &&
                        this->data[i][j+3]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i][j+1]==computerSign &&
                               this->data[i][j+2]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i][j+1]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (j==12){

                    if (this->data[i][j+1]==computerSign &&
                        this->data[i][j+2]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i][j+1]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (j==13){
                    if (this->data[i][j+1]==computerSign){

                        computer[i][j] += 1;
                    }
                }
                //Vertical Top 竖上
                if (i>3){

                    if (this->data[i-1][j]==computerSign &&
                        this->data[i-2][j]==computerSign &&
                        this->data[i-3][j]==computerSign &&
                        this->data[i-4][j]==computerSign){

                        computer[i][j] += 4;

                    } else if (this->data[i-1][j]==computerSign &&
                               this->data[i-2][j]==computerSign &&
                               this->data[i-3][j]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i-1][j]==computerSign &&
                               this->data[i-2][j]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i-1][j]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (i==3){

                    if (this->data[i-1][j]==computerSign &&
                        this->data[i-2][j]==computerSign &&
                        this->data[i-3][j]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i-1][j]==computerSign &&
                               this->data[i-2][j]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i-1][j]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (i==2){

                    if (this->data[i-1][j]==computerSign &&
                        this->data[i-2][j]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i-1][j]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (i==1){

                    if (this->data[i-1][j]==computerSign){

                        computer[i][j] += 1;
                    }
                }
                //Vertical Buttom 竖下
                if (i<11){

                    if (this->data[i+1][j]==computerSign &&
                        this->data[i+2][j]==computerSign &&
                        this->data[i+3][j]==computerSign &&
                        this->data[i+4][j]==computerSign){

                        computer[i][j] += 4;

                    } else if (this->data[i+1][j]==computerSign &&
                               this->data[i+2][j]==computerSign &&
                               this->data[i+3][j]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i+1][j]==computerSign &&
                               this->data[i+2][j]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i+1][j]==computerSign){

                        computer[i][j] += 1;

                    }

                } else if (i==11){
                    if (this->data[i+1][j]==computerSign &&
                        this->data[i+2][j]==computerSign &&
                        this->data[i+3][j]==computerSign){

                        computer[i][j] += 3;

                    } else if (this->data[i+1][j]==computerSign &&
                               this->data[i+2][j]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i+1][j]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (i==12){

                    if (this->data[i+1][j]==computerSign &&
                        this->data[i+2][j]==computerSign){

                        computer[i][j] += 2;

                    } else if (this->data[i+1][j]==computerSign){

                        computer[i][j] += 1;
                    }

                } else if (i==13){

                    if (this->data[i+1][j]==computerSign){

                        computer[i][j] += 1;

                    }
                }

                //Up Left 上左
                if(i==1){

                    if (j>=1){

                        if(this->data[i-1][j-1]==computerSign){

                            computer[i][j] += 1;
                        }
                    }
                } else if (i==2){

                    if (j==1){

                        if(this->data[i-1][j-1]==computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j>=2){
                        if (this->data[i-2][j-2] == computerSign &&
                            this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 2;

                        } else  if (this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }
                } else if (i==3){

                    if (j==1){

                        if(this->data[i-1][j-1]==computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==2){

                        if (this->data[i-2][j-2] == computerSign &&
                            this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }else if (j>=3){

                        if (this->data[i-3][j-3] == computerSign &&
                            this->data[i-2][j-2] == computerSign &&
                            this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 3;

                        } else if (this->data[i-2][j-2] == computerSign &&
                                   this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 2;

                        }else  if (this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }
                } else if (i>=4){

                    if (j==1){

                        if(this->data[i-1][j-1]==computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==2){

                        if (this->data[i-2][j-2] == computerSign &&
                            this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }else if (j==3){

                        if (this->data[i-3][j-3] == computerSign &&
                            this->data[i-2][j-2] == computerSign &&
                            this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 3;

                        } else if (this->data[i-2][j-2] == computerSign &&
                                   this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 2;

                        }else  if (this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }else if (j>=4){

                        if (this->data[i-4][j-4] == computerSign &&
                            this->data[i-3][j-3] == computerSign &&
                            this->data[i-2][j-2] == computerSign &&
                            this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 4;

                        } else if (this->data[i-3][j-3] == computerSign &&
                                   this->data[i-2][j-2] == computerSign &&
                                   this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 3;

                        } else if (this->data[i-2][j-2] == computerSign &&
                                   this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 2;

                        }else  if (this->data[i-1][j-1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }
                }

                //Up Right 上右
                if(i==1){

                    if (j<=13){

                        if (this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }

                } else if (i==2){

                    if (j<=12){

                        if (this->data[i-2][j+2] == computerSign &&
                            this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==13){

                        if (this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }

                } else if (i==3){

                    if (j<=11){

                        if (this->data[i-3][j+3] == computerSign &&
                            this->data[i-2][j+2] == computerSign &&
                            this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 3;

                        } else if (this->data[i-2][j+2] == computerSign &&
                                   this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==12){

                        if (this->data[i-2][j+2] == computerSign &&
                            this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==13){

                        if (this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 1;
                        }
                    }

                } else if (i>=4){

                    if (j<=10){

                        if (this->data[i-4][j+4] == computerSign &&
                            this->data[i-3][j+3] == computerSign &&
                            this->data[i-2][j+2] == computerSign &&
                            this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 4;

                        } else if (this->data[i-3][j+3] == computerSign &&
                                   this->data[i-2][j+2] == computerSign &&
                                   this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 3;

                        } else if (this->data[i-2][j+2] == computerSign &&
                                   this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==11){

                        if (this->data[i-3][j+3] == computerSign &&
                            this->data[i-2][j+2] == computerSign &&
                            this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 3;

                        } else if (this->data[i-2][j+2] == computerSign &&
                                   this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==12){

                        if (this->data[i-2][j+2] == computerSign &&
                            this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==13){

                        if (this->data[i-1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }

                }

                //Down Left 下左
                if (i<=10){

                    if (j>=4){

                        if (this->data[i+4][j-4] == computerSign &&
                            this->data[i+3][j-3] == computerSign &&
                            this->data[i+2][j-2] == computerSign &&
                            this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 4;

                        } else if (this->data[i+3][j-3] == computerSign &&
                                   this->data[i+2][j-2] == computerSign &&
                                   this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 3;

                        } else if (this->data[i+2][j-2] == computerSign &&
                                   this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==3){

                        if (this->data[i+3][j-3] == computerSign &&
                            this->data[i+2][j-2] == computerSign &&
                            this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 3;

                        } else if (this->data[i+2][j-2] == computerSign &&
                                   this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 1;
                        }
                    } else if (j==2){

                        if (this->data[i+2][j-2] == computerSign &&
                            this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==1){

                        if (this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 1;
                        }
                    }
                } else if (i==11){

                    if (j>=3){

                        if (this->data[i+3][j-3] == computerSign &&
                            this->data[i+2][j-2] == computerSign &&
                            this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 3;

                        } else if (this->data[i+2][j-2] == computerSign &&
                                   this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==2){

                        if (this->data[i+2][j-2] == computerSign &&
                            this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==1){

                        if (this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }
                } else if (i==12){

                    if (j>=2){

                        if (this->data[i+2][j-2] == computerSign &&
                            this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==1){

                        if (this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 1;
                        }
                    }
                } else if (i==13){

                    if (j>=1){

                        if (this->data[i+1][j-1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }
                }

                //Down Right 下右
                if (i<=10){

                    if (j<=10){

                        if (this->data[i+4][j+4] == computerSign &&
                            this->data[i+3][j+3] == computerSign &&
                            this->data[i+2][j+2] == computerSign &&
                            this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 4;

                        } else if (this->data[i+3][j+3] == computerSign &&
                                   this->data[i+2][j+2] == computerSign &&
                                   this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 3;

                        } else if (this->data[i+2][j+2] == computerSign &&
                                   this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==11){

                        if (this->data[i+3][j+3] == computerSign &&
                            this->data[i+2][j+2] == computerSign &&
                            this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 3;

                        } else if (this->data[i+2][j+2] == computerSign &&
                                   this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==12){

                        if (this->data[i+2][j+2] == computerSign &&
                            this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==13){

                        if (this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }
                } else if (i==11){

                    if (j<=11){

                        if (this->data[i+3][j+3] == computerSign &&
                            this->data[i+2][j+2] == computerSign &&
                            this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 3;

                        } else if (this->data[i+2][j+2] == computerSign &&
                                   this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==12){

                        if (this->data[i+2][j+2] == computerSign &&
                            this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==13){

                        if (this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 1;
                        }
                    }

                } else if (i==12){

                    if (j<=12){

                        if (this->data[i+2][j+2] == computerSign &&
                            this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 2;

                        } else if (this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    } else if (j==13){

                        if (this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }
                } else if (i==13){

                    if (j<=13){

                        if (this->data[i+1][j+1] == computerSign){

                            computer[i][j] += 1;

                        }
                    }
                }
            }
        }
    }


    //Human Search 搜索人棋子
    for (int i=0 ;i<15; i++){

        for (int j=0; j<15; j++){

            if (this->data[i][j] == 0){

                //Horizonal Left 横左
                if (j>3){

                    if (this->data[i][j-1]==humanSign &&
                        this->data[i][j-2]==humanSign &&
                        this->data[i][j-3]==humanSign &&
                        this->data[i][j-4]==humanSign){

                        human[i][j] += 4;

                    } else if (this->data[i][j-1]==humanSign &&
                               this->data[i][j-2]==humanSign &&
                               this->data[i][j-3]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i][j-1]==humanSign &&
                               this->data[i][j-2]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i][j-1]==humanSign){

                        human[i][j] += 1;

                    }

                } else if (j==3){

                    if (this->data[i][j-1]==humanSign &&
                        this->data[i][j-2]==humanSign &&
                        this->data[i][j-3]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i][j-1]==humanSign &&
                               this->data[i][j-2]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i][j-1]==humanSign){

                        human[i][j] += 1;

                    }

                } else if (j==2){
                    if (this->data[i][j-1]==humanSign &&
                        this->data[i][j-2]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i][j-1]==humanSign){

                        human[i][j] += 1;

                    }
                } else if (j==1){
                    if (this->data[i][j-1]==humanSign){

                        human[i][j] += 1;
                    }
                }
                //Horizonal Right
                if (j<11){
                    if (this->data[i][j+1]==humanSign &&
                        this->data[i][j+2]==humanSign &&
                        this->data[i][j+3]==humanSign &&
                        this->data[i][j+4]==humanSign){

                        human[i][j] += 4;

                    } else if (this->data[i][j+1]==humanSign &&
                               this->data[i][j+2]==humanSign &&
                               this->data[i][j+3]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i][j+1]==humanSign &&
                               this->data[i][j+2]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i][j+1]==humanSign){

                        human[i][j] += 1;

                    }

                } else if (j==11){

                    if (this->data[i][j+1]==humanSign &&
                        this->data[i][j+2]==humanSign &&
                        this->data[i][j+3]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i][j+1]==humanSign &&
                               this->data[i][j+2]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i][j+1]==humanSign){

                        human[i][j] += 1;
                    }

                } else if (j==12){

                    if (this->data[i][j+1]==humanSign &&
                        this->data[i][j+2]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i][j+1]==humanSign){

                        human[i][j] += 1;

                    }
                } else if (j==13){

                    if (this->data[i][j+1]==humanSign){

                        human[i][j] += 1;
                    }
                }
                //Vertical Top 竖上
                if (i>3){

                    if (this->data[i-1][j]==humanSign &&
                        this->data[i-2][j]==humanSign &&
                        this->data[i-3][j]==humanSign &&
                        this->data[i-4][j]==humanSign){

                        human[i][j] += 4;

                    } else if (this->data[i-1][j]==humanSign &&
                               this->data[i-2][j]==humanSign &&
                               this->data[i-3][j]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i-1][j]==humanSign &&
                               this->data[i-2][j]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i-1][j]==humanSign){

                        human[i][j] += 1;

                    }

                } else if (i==3){

                    if (this->data[i-1][j]==humanSign &&
                        this->data[i-2][j]==humanSign &&
                        this->data[i-3][j]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i-1][j]==humanSign &&
                               this->data[i-2][j]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i-1][j]==humanSign){

                        human[i][j] += 1;

                    }

                } else if (i==2){

                    if (this->data[i-1][j]==humanSign &&
                        this->data[i-2][j]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i-1][j]==humanSign){

                        human[i][j] += 1;

                    }
                } else if (i==1){

                    if (this->data[i-1][j]==humanSign){

                        human[i][j] += 1;

                    }
                }
                //Vertical Buttom 竖下
                if (i<11){

                    if (this->data[i+1][j]==humanSign &&
                        this->data[i+2][j]==humanSign &&
                        this->data[i+3][j]==humanSign &&
                        this->data[i+4][j]==humanSign){

                        human[i][j] += 4;

                    } else if (this->data[i+1][j]==humanSign &&
                               this->data[i+2][j]==humanSign &&
                               this->data[i+3][j]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i+1][j]==humanSign &&
                               this->data[i+2][j]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i+1][j]==humanSign){

                        human[i][j] += 1;

                    }

                } else if (i==11){

                    if (this->data[i+1][j]==humanSign &&
                        this->data[i+2][j]==humanSign &&
                        this->data[i+3][j]==humanSign){

                        human[i][j] += 3;

                    } else if (this->data[i+1][j]==humanSign &&
                               this->data[i+2][j]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i+1][j]==humanSign){

                        human[i][j] += 1;

                    }

                } else if (i==12){

                    if (this->data[i+1][j]==humanSign &&
                        this->data[i+2][j]==humanSign){

                        human[i][j] += 2;

                    } else if (this->data[i+1][j]==humanSign){

                        human[i][j] += 1;

                    }
                } else if (i==13){

                    if (this->data[i+1][j]==humanSign){

                        human[i][j] += 1;

                    }
                }

                //Up Left
                if(i==1){

                    if (j>=1){

                        if(this->data[i-1][j-1]==humanSign){

                            human[i][j] += 1;
                        }
                    }

                } else if (i==2){

                    if (j==1){

                        if(this->data[i-1][j-1]==humanSign){

                            human[i][j] += 1;
                        }

                    } else if (j>=2){
                        if (this->data[i-2][j-2] == humanSign &&
                            this->data[i-1][j-1] == humanSign){

                            human[i][j] += 2;

                        } else  if (this->data[i-1][j-1] == humanSign){

                            human[i][j] += 1;

                        }
                    }
                } else if (i==3){

                    if (j==1){

                        if(this->data[i-1][j-1]==humanSign){

                            human[i][j] += 1;
                        }

                    } else if (j==2){

                        if (this->data[i-2][j-2] == humanSign &&
                            this->data[i-1][j-1] == humanSign){

                            human[i][j] += 2;

                        } else  if (this->data[i-1][j-1] == humanSign){

                            human[i][j] += 1;

                        }
                    }else if (j>=3){

                        if (this->data[i-3][j-3] == humanSign &&
                            this->data[i-2][j-2] == humanSign &&
                            this->data[i-1][j-1] == humanSign){

                            human[i][j] += 3;

                        } else if (this->data[i-2][j-2] == humanSign &&
                                   this->data[i-1][j-1] == humanSign){

                            human[i][j] += 2;

                        }else if (this->data[i-1][j-1] == humanSign){

                            human[i][j] += 1;

                        }
                    }
                } else if (i>=4){

                    if (j==1){

                        if(this->data[i-1][j-1]==humanSign){

                            human[i][j] += 1;

                        }
                    } else if (j==2){

                        if (this->data[i-2][j-2] == humanSign &&
                            this->data[i-1][j-1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i-1][j-1] == humanSign){

                            human[i][j] += 1;

                        }

                    }else if (j==3){

                        if (this->data[i-3][j-3] == humanSign &&
                            this->data[i-2][j-2] == humanSign &&
                            this->data[i-1][j-1] == humanSign){

                            human[i][j] += 3;

                        } else if (this->data[i-2][j-2] == humanSign &&
                                   this->data[i-1][j-1] == humanSign){

                            human[i][j] += 2;

                        }else if (this->data[i-1][j-1] == humanSign){

                            human[i][j] += 1;
                        }

                    }else if (j>=4){

                        if (this->data[i-4][j-4] == humanSign &&
                            this->data[i-3][j-3] == humanSign &&
                            this->data[i-2][j-2] == humanSign &&
                            this->data[i-1][j-1] == humanSign){

                            human[i][j] += 4;

                        } else if (this->data[i-3][j-3] == humanSign &&
                                   this->data[i-2][j-2] == humanSign &&
                                   this->data[i-1][j-1] == humanSign){

                            human[i][j] += 3;

                        } else if (this->data[i-2][j-2] == humanSign &&
                                   this->data[i-1][j-1] == humanSign){

                            human[i][j] += 2;

                        }else  if (this->data[i-1][j-1] == humanSign){

                            human[i][j] += 1;

                        }
                    }
                }

                //Up Right 上右
                if(i==1){

                    if (j<=13){

                        if (this->data[i-1][j+1] == humanSign){

                            human[i][j] += 1;
                        }
                    }

                } else if (i==2){

                    if (j<=12){

                        if (this->data[i-2][j+2] == humanSign &&
                            this->data[i-1][j+1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i-1][j+1] == humanSign){

                            human[i][j] += 1;
                        }

                    } else if (j==13){

                        if (this->data[i-1][j+1] == humanSign){

                            human[i][j] += 1;

                        }
                    }

                } else if (i==3){

                    if (j<=11){

                        if (this->data[i-3][j+3] == humanSign &&
                            this->data[i-2][j+2] == humanSign &&
                            this->data[i-1][j+1] == humanSign){

                            human[i][j] += 3;

                        } else if (this->data[i-2][j+2] == humanSign &&
                                   this->data[i-1][j+1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i-1][j+1] == humanSign){

                            human[i][j] += 1;

                        }

                    } else if (j==12){

                        if (this->data[i-2][j+2] == humanSign &&
                            this->data[i-1][j+1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i-1][j+1] == humanSign){

                            human[i][j] += 1;

                        }

                    } else if (j==13){

                        if (this->data[i-1][j+1] == humanSign){

                            human[i][j] += 1;
                        }
                    }

                } else if (i>=4){

                    if (j<=10){

                        if (this->data[i-4][j+4] == humanSign &&
                            this->data[i-3][j+3] == humanSign &&
                            this->data[i-2][j+2] == humanSign &&
                            this->data[i-1][j+1] == humanSign){

                            human[i][j] += 4;

                        } else if (this->data[i-3][j+3] == humanSign &&
                                   this->data[i-2][j+2] == humanSign &&
                                   this->data[i-1][j+1] == humanSign){

                            human[i][j] += 3;

                        } else if (this->data[i-2][j+2] == humanSign &&
                                   this->data[i-1][j+1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i-1][j+1] == humanSign){

                            human[i][j] += 1;
                        }

                    } else if (j==11){

                        if (this->data[i-3][j+3] == humanSign &&
                            this->data[i-2][j+2] == humanSign &&
                            this->data[i-1][j+1] == humanSign){

                            human[i][j] += 3;

                        } else if (this->data[i-2][j+2] == humanSign &&
                                   this->data[i-1][j+1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i-1][j+1] == humanSign){

                            human[i][j] += 1;
                        }

                    } else if (j==12){

                        if (this->data[i-2][j+2] == humanSign &&
                            this->data[i-1][j+1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i-1][j+1] == humanSign){

                            human[i][j] += 1;

                        }

                    } else if (j==13){

                        if (this->data[i-1][j+1] == humanSign){

                            human[i][j] += 1;
                        }
                    }

                }

                //Down Left
                if (i<=10){

                    if (j>=4){

                        if (this->data[i+4][j-4] == humanSign &&
                            this->data[i+3][j-3] == humanSign &&
                            this->data[i+2][j-2] == humanSign &&
                            this->data[i+1][j-1] == humanSign){

                            human[i][j] += 4;

                        } else if (this->data[i+3][j-3] == humanSign &&
                                   this->data[i+2][j-2] == humanSign &&
                                   this->data[i+1][j-1] == humanSign){

                            human[i][j] += 3;

                        } else if (this->data[i+2][j-2] == humanSign &&
                                   this->data[i+1][j-1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i+1][j-1] == humanSign){

                            human[i][j] += 1;

                        }

                    } else if (j==3){

                        if (this->data[i+3][j-3] == humanSign &&
                            this->data[i+2][j-2] == humanSign &&
                            this->data[i+1][j-1] == humanSign){

                            human[i][j] += 3;

                        } else if (this->data[i+2][j-2] == humanSign &&
                                   this->data[i+1][j-1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i+1][j-1] == humanSign){

                            human[i][j] += 1;

                        }

                    } else if (j==2){

                        if (this->data[i+2][j-2] == humanSign &&
                            this->data[i+1][j-1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i+1][j-1] == humanSign){

                            human[i][j] += 1;

                        }

                    } else if (j==1){

                        if (this->data[i+1][j-1] == humanSign){

                            human[i][j] += 1;
                        }
                    }

                } else if (i==11){

                    if (j>=3){

                        if (this->data[i+3][j-3] == humanSign &&
                            this->data[i+2][j-2] == humanSign &&
                            this->data[i+1][j-1] == humanSign){

                            human[i][j] += 3;

                        } else if (this->data[i+2][j-2] == humanSign &&
                                   this->data[i+1][j-1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i+1][j-1] == humanSign){

                            human[i][j] += 1;

                        }

                    } else if (j==2){

                        if (this->data[i+2][j-2] == humanSign &&
                            this->data[i+1][j-1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i+1][j-1] == humanSign){

                            human[i][j] += 1;

                        }
                    } else if (j==1){

                        if (this->data[i+1][j-1] == humanSign){

                            human[i][j] += 1;
                        }
                    }
                } else if (i==12){

                    if (j>=2){

                        if (this->data[i+2][j-2] == humanSign &&
                            this->data[i+1][j-1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i+1][j-1] == humanSign){

                            human[i][j] += 1;
                        }

                    } else if (j==1){

                        if (this->data[i+1][j-1] == humanSign){

                            human[i][j] += 1;

                        }
                    }

                } else if (i==13){

                    if (j>=1){

                        if (this->data[i+1][j-1] == humanSign){

                            human[i][j] += 1;

                        }
                    }
                }

                //Down Right
                if (i<=10){

                    if (j<=10){

                        if (this->data[i+4][j+4] == humanSign &&
                            this->data[i+3][j+3] == humanSign &&
                            this->data[i+2][j+2] == humanSign &&
                            this->data[i+1][j+1] == humanSign){

                            human[i][j] += 4;

                        } else if (this->data[i+3][j+3] == humanSign &&
                                   this->data[i+2][j+2] == humanSign &&
                                   this->data[i+1][j+1] == humanSign){

                            human[i][j] += 3;

                        } else if (this->data[i+2][j+2] == humanSign &&
                                   this->data[i+1][j+1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i+1][j+1] == humanSign){

                            human[i][j] += 1;

                        }

                    } else if (j==11){

                        if (this->data[i+3][j+3] == humanSign &&
                            this->data[i+2][j+2] == humanSign &&
                            this->data[i+1][j+1] == humanSign){

                            human[i][j] += 3;

                        } else if (this->data[i+2][j+2] == humanSign &&
                                   this->data[i+1][j+1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i+1][j+1] == humanSign){

                            human[i][j] += 1;

                        }

                    } else if (j==12){

                        if (this->data[i+2][j+2] == humanSign &&
                            this->data[i+1][j+1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i+1][j+1] == humanSign){

                            human[i][j] += 1;

                        }

                    } else if (j==13){

                        if (this->data[i+1][j+1] == humanSign){

                            human[i][j] += 1;
                        }
                    }

                } else if (i==11){

                    if (j<=11){

                        if (this->data[i+3][j+3] == humanSign &&
                            this->data[i+2][j+2] == humanSign &&
                            this->data[i+1][j+1] == humanSign){

                            human[i][j] += 3;

                        } else if (this->data[i+2][j+2] == humanSign &&
                                   this->data[i+1][j+1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i+1][j+1] == humanSign){

                            human[i][j] += 1;
                        }

                    } else if (j==12){

                        if (this->data[i+2][j+2] == humanSign &&
                            this->data[i+1][j+1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i+1][j+1] == humanSign){

                            human[i][j] += 1;

                        }

                    } else if (j==13){

                        if (this->data[i+1][j+1] == humanSign){

                            human[i][j] += 1;
                        }
                    }

                } else if (i==12){

                    if (j<=12){

                        if (this->data[i+2][j+2] == humanSign &&
                            this->data[i+1][j+1] == humanSign){

                            human[i][j] += 2;

                        } else if (this->data[i+1][j+1] == humanSign){

                            human[i][j] += 1;

                        }

                    } else if (j==13){

                        if (this->data[i+1][j+1] == humanSign){

                            human[i][j] += 1;

                        }
                    }

                } else if (i==13){

                    if (j<=13){

                        if (this->data[i+1][j+1] == humanSign){

                            human[i][j] += 1;

                        }
                    }
                }
            }
        }
    }



    //Search The Point 查找点

    //Random a Point 随机点
    srand(time(NULL));
    *x = (int)rand()%15;
    *y = (int)rand()%15;

    while(this->data[*x][*y] != 0){

        *x = (int)rand()%15;
        *y = (int)rand()%15;
    }

    int max = 0;

    //Computer 搜索电脑价值
    for (int i=0; i<15; i++){

        for (int j=0; j<15; j++){

            if (computer[i][j]>max && this->data[i][j] == 0){

                max = computer[i][j];
                *x = i; *y = j;
            }
        }
    }

    //Human 搜索人价值
    for (int i=0; i<15; i++){

        for (int j=0; j<15; j++){

            if (human[i][j]>max && this->data[i][j] == 0){

                max = human[i][j];
                *x = i; *y = j;
            }
        }
    }

}
