#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractButton>
#include <QAction>
#include <QIcon>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString str1[3]={"Game","Office","Develop"};
    QString str2[3]={"P&rogramming","Q&t","Q&S"};



    chk_group[0]=new QButtonGroup;
    chk_group[1]=new QButtonGroup;

    for(int i=0;i<3;i++)
    {
        exclusive[i]=new QCheckBox(str1[i],this);
        exclusive[i]->setGeometry(xpos,ypos,100,30);
        chk_group[0]->addButton(exclusive[i]);

        non_exclusive[i]=new QCheckBox(str2[i],this);
        non_exclusive[i]->setGeometry(xpos+120,ypos,100,30);
        chk_group[1]->addButton(non_exclusive[i]);
        connect(exclusive[i],SIGNAL(clicked(bool)),this,SLOT(chkChanged()));

        ypos +=40;
    }

    chk_group[0]->setExclusive(false);
    chk_group[1]->setExclusive(true);
    exclusive[0]->setIcon(QIcon(":/Resourse/Ok"));
    exclusive[1]->setIcon(QIcon(":/Resourse/mail"));
    exclusive[2]->setIcon(QIcon(":/Resourse/Set"));

    non_exclusive[0]->setIcon(QIcon(":/Resourse/television"));
    non_exclusive[1]->setIcon(QIcon(":/Resourse/users"));
    non_exclusive[2]->setIcon(QIcon(":/Resourse/wifi"));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::chkChanged()
{
    for(int i=0;i<3;i++)
    {
        if(exclusive[i]->checkState())
        {
            qDebug("checkbox %d selected ",i+1);
        }
    }
}
