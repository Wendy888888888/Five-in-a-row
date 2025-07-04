#ifndef FIVE_H
#define FIVE_H

#include <stdio.h>
#include <time.h>
#include <QTimer>
#include <QTextStream>
#include <QMessageBox>
#include <QMainWindow>
#include <QFileDialog>
#include <QPushButton>
#include <QMouseEvent>
#include <QByteArray>
#include <QMenuBar>
#include <QPainter>
#include <QDialog>
#include <QString>
#include <QLabel>
#include <QPoint>
#include <QMenu>
#include <QFile>
#include <Qt>
#include <QVBoxLayout>  // 添加布局头文件
#include <QWidget>      // 确保QWidget头文件包含

namespace Ui {

    class Five;
}

struct StackPersonToPerson{

    struct StackPersonToPerson *pointer;
    bool isHumanGo;
    int x;
    int y;
};

struct StackPersonToComputer{

    struct StackPersonToComputer *pointer;
    int xPerson;
    int yPerson;
    int xComputer;
    int yComputer;
};


class Five : public QMainWindow{
        Q_OBJECT
        
    public:
        explicit Five(QWidget *parent = 0);
        ~Five();

    private:
        void paintEvent(QPaintEvent *);
        void drawChessBoard(QPainter *painter);
        void drawChess(QPainter *painter);
        void initCheseData();
        void mousePressEvent(QMouseEvent *);
        QLabel *timeLabel;       // 显示时间的标签
        QTimer *timer;           // 用于计时的定时器
        int elapsedSeconds = 0;  // 已用时间（秒）


    private slots:
        void loadFile();
        void saveFile();

        void againstPerson();
        void againstComputer();
        void funny();
        void chooseFirst();
        void chooseSecond();
        void chooseBlack();
        void chooseWhite();
        void simpleMode();
        void hardMode();

        void helpShow();
        void aboutShow();

        void updateDisplaySettings();

        void startGame();
        void stopGame();
        void regretGame();
        void checkWin();
        void computerGo(int *x, int *y);
        void computerGoHard(int *x, int *y);

    private:
        int data[15][15];
        int level;
        bool isfunny;
        bool isStart;
        bool isHumanGo;
        bool isHumanBlackColor;
        bool isAgainstPerson;

        struct StackPersonToPerson *stackPersonToPerson;
        struct StackPersonToComputer *stackPersonToComputer;

        QPushButton *startButton;
        QPushButton *stopButton;
        QPushButton *regretButton;
        QLabel *count;
        QLabel *state;
        QLabel *stateAll;
        QLabel *stateHard;
};

#endif // FIVE_H
