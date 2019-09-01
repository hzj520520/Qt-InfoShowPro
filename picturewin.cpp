#include "picturewin.h"
#include "ui_picturewin.h"


#include <QPainter>

PictureWin::PictureWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PictureWin)
{
    ui->setupUi(this);
}

PictureWin::~PictureWin()
{
    delete ui;
}

void PictureWin::setPicture(QString filename)
{
    mmp.load(filename);
    mmp.scaled(this->size());
    update();
}

void PictureWin::setPicture(QByteArray array)
{
   mmp.loadFromData(array);
   mmp.scaled(this->size());
   update();
}

void PictureWin::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(this->geometry(),mmp);
}


