#include "mainWidget.h"

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(480,300);
    this->setMaximumSize(480,300);
    this->setWindowIcon(QIcon(":/new/prefix1/img/icon.png"));
    this->setWindowTitle("GreedySnake");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/prefix1/img/back.jpg").scaled(this->size())));
    this->setPalette(palette);

    startbtn=new QPushButton(this);
    startbtn->setIcon(QIcon(":/new/prefix1/img/start.png"));
    startbtn->setIconSize(QSize(75,75));
    startbtn->setGeometry(QRect(250,170,75,75));
    startbtn->setFlat(true);

    exitbtn=new QPushButton(this);
    exitbtn->setIcon(QIcon(":/new/prefix1/img/quit.png"));
    exitbtn->setIconSize(QSize(70,70));
    exitbtn->setGeometry(QRect(350,170,70,70));
    exitbtn->setFlat(true);

    QFont font;
    font.setFamily("Consolas");
    font.setBold(true);
    font.setPixelSize(13);
    label=new QLabel(this);
    label->setText("Instruction：Buttons or w a s d to control !");
    label->setFont(font);
    label->setGeometry(QRect(10,10,400,50));

    connect(exitbtn,SIGNAL(clicked()),this,SLOT(exitSlot()));
    connect(startbtn,SIGNAL(clicked()),this,SLOT(startSlot()));
}

mainWidget::~mainWidget()
{
    delete startbtn;
    delete exitbtn;
}
void mainWidget::exitSlot()
{
    if(QMessageBox::question(this,"quit","Are you sure to quit",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        delete this;
        exit(0);
    }
}
void mainWidget::startSlot()
{

    g=new GameWidget(this);
    g->show();
}
