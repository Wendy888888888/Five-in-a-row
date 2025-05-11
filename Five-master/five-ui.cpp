#include "Five.h"
#include <QMenuBar>
#include <QPainter>
#include <QFont>
#include <QLabel>
#include <QPushButton>

Five::Five(QWidget *parent) : QMainWindow(parent) {
    this->setFixedSize(640, 520);

// Init Menu 初始化菜单
QMenuBar *menubar = new QMenuBar(this);
menubar->setStyleSheet(
    "QMenuBar { background-color: #f0f0f0; font-weight: bold; }"
    "QMenuBar::item { padding: 4px 10px; background: transparent; }"
    "QMenuBar::item:selected { background: #d0d0d0; }"
    "QMenu { background-color: white; }"
    "QMenu::item:selected { background-color: #87cefa; }"
);

    // 文件菜单
    QMenu *fileMenu = menubar->addMenu("文件");

    QAction *loadfile = new QAction("读取游戏进度", this);
    connect(loadfile, &QAction::triggered, this, &Five::loadFile);
    fileMenu->addAction(loadfile);

    QAction *savefile = new QAction("保存游戏进度", this);
    connect(savefile, &QAction::triggered, this, &Five::saveFile);
    fileMenu->addAction(savefile);

    // 设置菜单
    QMenu *settingsMenu = menubar->addMenu("设置");

    // 子菜单：对战模式
    QMenu *modeMenu = settingsMenu->addMenu("对战模式");
    modeMenu->addAction("人对人", this, SLOT(againstPerson()));
    modeMenu->addAction("人对机", this, SLOT(againstComputer()));
    modeMenu->addAction("机对机", this, SLOT(funny()));

    // 子菜单：先后手设置
    QMenu *firstMoveMenu = settingsMenu->addMenu("先后手设置");
    firstMoveMenu->addAction("选择先手", this, SLOT(chooseFirst()));
    firstMoveMenu->addAction("选择后手", this, SLOT(chooseSecond()));

    // 子菜单：棋子颜色
    QMenu *colorMenu = settingsMenu->addMenu("棋子颜色");
    colorMenu->addAction("选择黑子", this, SLOT(chooseBlack()));
    colorMenu->addAction("选择白子", this, SLOT(chooseWhite()));

    // 子菜单：难度模式
    QMenu *difficultyMenu = settingsMenu->addMenu("难度选择");
    difficultyMenu->addAction("简单模式", this, SLOT(simpleMode()));
    difficultyMenu->addAction("困难模式", this, SLOT(hardMode()));

    // 帮助菜单
    QMenu *helpMenu = menubar->addMenu("帮助");
    helpMenu->addAction("帮助", this, SLOT(helpShow()));


    this->setMenuBar(menubar);


    // 初始化棋盘数据
    initCheseData();

    this->isfunny = false;
    this->isStart = false;
    this->isHumanGo = false;
    this->isHumanBlackColor = false;
    this->isAgainstPerson = false;
    this->level = 1;

    // 标签
    QFont font;
    font.setPointSize(12);

    QLabel *label1 = new QLabel("当前步数:", this);
    label1->setFont(font);
    label1->setGeometry(500, 20, 100, 30);

    this->count = new QLabel("0", this);
    count->setGeometry(500, 50, 100, 30);

    QLabel *label2 = new QLabel("当前状态:", this);
    label2->setFont(font);
    label2->setGeometry(500, 80, 100, 30);

    this->state = new QLabel("游戏未开始", this);
    state->setGeometry(500, 110, 100, 30);

    this->stateAll = new QLabel("人机 后手 白子", this);
    stateAll->setGeometry(500, 140, 100, 30);

    this->stateHard = new QLabel("简单模式", this);
    stateHard->setGeometry(500, 170, 100, 30);
    QLabel *timeTitle = new QLabel("游戏时间:", this);
                                   timeTitle->setFont(font);
                                   timeTitle->setGeometry(500, 200, 100, 30);

                                   this->timeLabel = new QLabel("00:00", this);
                                   timeLabel->setGeometry(500, 230, 100, 30);

                                   // 初始化定时器
                                   this->timer = new QTimer(this);
                                   connect(timer, &QTimer::timeout, this, [=]() {
                                       elapsedSeconds++;
                                       int minutes = elapsedSeconds / 60;
                                       int seconds = elapsedSeconds % 60;
                                       timeLabel->setText(QString("%1:%2")
                                                              .arg(minutes, 2, 10, QChar('0'))
                                                              .arg(seconds, 2, 10, QChar('0')));
                                   });

    // 按钮
    this->startButton = new QPushButton("开始游戏", this);
    startButton->setGeometry(500, 320, 100, 40);
    startButton->setEnabled(true);
    connect(startButton, &QPushButton::clicked, this, &Five::startGame);

    this->stopButton = new QPushButton("停止游戏", this);
    stopButton->setGeometry(500, 370, 100, 40);
    stopButton->setEnabled(false);
    connect(stopButton, &QPushButton::clicked, this, &Five::stopGame);

    this->regretButton = new QPushButton("我要悔棋", this);
    regretButton->setGeometry(500, 420, 100, 40);
    regretButton->setEnabled(false);
    connect(regretButton, &QPushButton::clicked, this, &Five::regretGame);

    // 初始化悔棋栈
    this->stackPersonToComputer = nullptr;
    this->stackPersonToPerson = nullptr;
}

Five::~Five() {}

void Five::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    drawChessBoard(&painter);
    drawChess(&painter);
}

void Five::drawChessBoard(QPainter *painter) {
    painter->setBrush(QBrush(QColor(245, 222, 179))); // 浅棕色背景
    painter->drawRect(10, 10, 480, 480);

    painter->setPen(QPen(QColor(100, 100, 100), 1));
    for (int i = 0; i < 15; i++) {
        painter->drawLine(30, 30 + i * 30, 450, 30 + i * 30);  // 横线
        painter->drawLine(30 + i * 30, 30, 30 + i * 30, 450);  // 竖线
    }

    // 定位点
    painter->setBrush(Qt::black);
    QVector<QPoint> points = {
        QPoint(30 + 3 * 30, 30 + 3 * 30),
        QPoint(30 + 11 * 30, 30 + 3 * 30),
        QPoint(30 + 3 * 30, 30 + 11 * 30),
        QPoint(30 + 11 * 30, 30 + 11 * 30),
        QPoint(30 + 7 * 30, 30 + 7 * 30)
    };

    for (const QPoint &pt : points) {
        painter->drawEllipse(pt, 4, 4);
    }
}

void Five::drawChess(QPainter *painter) {
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (data[i][j] == 0) continue;

            QPoint center(30 + j * 30, 30 + i * 30);
            QRadialGradient gradient(center, 15, center);

            if (data[i][j] == 1) { // 白棋
                gradient.setColorAt(0, Qt::white);
                gradient.setColorAt(1, Qt::lightGray);
            } else if (data[i][j] == -1) { // 黑棋
                gradient.setColorAt(0, Qt::black);
                gradient.setColorAt(1, Qt::gray);
            }

            painter->setBrush(QBrush(gradient));
            painter->setPen(Qt::NoPen);
            painter->drawEllipse(center, 12, 12);
        }
    }
}
