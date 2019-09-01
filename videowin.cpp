#include "videowin.h"
#include "ui_videowin.h"
#include <QDebug>
VideoWin::VideoWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoWin)
{
    ui->setupUi(this);
    flag = 0;//判断是否正常结束
    //关联结束信号
    connect(&mProcess, SIGNAL(finished(int)), this, SLOT(finished_fun()));
    count = 0;
}

VideoWin::~VideoWin()
{
    delete ui;
}

void VideoWin::play(QString filename)
{
    flag = 0;

    qDebug()<<"play"<<fileList;

    QString playfile;
    if(filename.isEmpty())
    {
        if(count < fileList.count())
        {
            playfile = fileList.at(count);
            count++;
            if(count == fileList.count()) count = 0;
        }
    }
    else
    {
        playfile = filename;
    }

    qDebug()<<playfile;
    if(playfile.isEmpty()) return;

    if(mProcess.state() == QProcess::Running)
    {
        mProcess.kill();
        mProcess.waitForFinished();
    }

#ifdef PC //pc
    //播放
    QString cmd=QString("%1 -slave -quiet -wid ").arg(MPLAYER_CMD_PC);
    cmd.append(QString::number(this->winId()));
     cmd.append(" ");
    cmd.append(playfile);
    mProcess.start(cmd);

    //qDebug()<<"===========list===="<<list;
    qDebug()<<cmd;


#else
    QString cmd("mplayer -slave -quiet -geometry ");
    cmd.append(QString("%1:%2").arg(QString::number(this->x())).arg(QString::number(this->y())));
    cmd.append(QString(" -zoom -x %1 -y %2 ").arg(QString::number(this->width()))
               .arg(QString::number(this->height())));
    cmd.append(playfile);
    mProcess.start(cmd);
   qDebug()<<cmd;

#endif
}

void VideoWin::stop()
{
    flag = 1;
    mProcess.kill();
    mProcess.waitForFinished();
}

void VideoWin::addFile(QString file)
{
    fileList.append(file);
}

void VideoWin::clear()
{
    fileList.clear();
}

void VideoWin::finished_fun()
{
    if(flag == 0)
    {
        play();
    }
}


