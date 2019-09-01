#include "mymainwin.h"
#include "ui_mymainwin.h"

MyMainWin::MyMainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWin)
{
    ui->setupUi(this);


    //自适应屏幕 分辨率
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //显示图片
    ui->rollWidget->setText("今天是星期六天气很好很适合学习");
    ui->pictureWidget->setPicture(QString("./a.jpg"));

    //播放视频

    qDebug()<<"ui->videoWidget->winId()="<<ui->videoWidget->winId();
//    ui->videoWidget->play("http://192.168.1.36/movie/1.mp4");
//    ui->videoWidget->addFile("http://192.168.1.36/movie/1.mp4");


    ui->weatherWidget->update_weather("广州");


    //获取路径picture， movie
    connect(&movieManager,SIGNAL(finished(QNetworkReply*)),
            this, SLOT(read_movie_path(QNetworkReply *)));
    connect(&pictureManager,SIGNAL(finished(QNetworkReply*)),
            this, SLOT(read_picture_path(QNetworkReply *)));
    connect(&dataManager,SIGNAL(finished(QNetworkReply*)),
            this, SLOT(read_picture_data(QNetworkReply *)));

    //请求图片路径， 请求视频路径
    QUrl picurl(QString("http://%1/picture/picture").arg(HTTP_SERVER_IP));
    QUrl movieurl(QString("http://%1/movie/movie").arg(HTTP_SERVER_IP));

    QNetworkRequest request(picurl);
    pictureManager.get(request);

    QNetworkRequest mrequest(movieurl);
    movieManager.get(mrequest);


    //启动定时器事件
    timerid = startTimer(3000);


    connect(&msocket, &QTcpSocket::readyRead, this, &MyMainWin::read_control_data);
    //链接服务器
    msocket.connectToHost(Server_Socket_Ip,7788);

}

MyMainWin::~MyMainWin()
{
    delete ui;
}


void MyMainWin::read_movie_path(QNetworkReply *reply)
{
    while(reply->canReadLine())
    {
        QString linestr = reply->readLine();
        linestr.remove("\n");
        QString url = QString("http://%1/movie/%2").arg(HTTP_SERVER_IP).arg(linestr);
        ui->videoWidget->addFile(url);
    }
}
void MyMainWin::read_picture_path(QNetworkReply *reply)
{
    picturesUrl.clear();
    while(reply->canReadLine())
    {
        QString linestr = reply->readLine();
        linestr.remove("\n");
        QString url = QString("http://%1/picture/%2").arg(HTTP_SERVER_IP).arg(linestr);
        qDebug()<<url;
        picturesUrl.append(url);
    }
}

void MyMainWin::timerEvent(QTimerEvent *e)
{
    static int num = 0;
    if(num >= picturesUrl.size()) num=0;

    QNetworkRequest mrequest(picturesUrl.at(num++));
    dataManager.get(mrequest);
}

void MyMainWin::play_picture()
{
    ui->videoWidget->stop();
    ui->videoWidget->hide();
    ui->pictureWidget->show();
    killTimer(timerid);
    timerid = startTimer(3000);
}

void MyMainWin::play_movie()
{
    killTimer(timerid);
    ui->pictureWidget->hide();
    ui->videoWidget->show();
    ui->videoWidget->play();
}

void MyMainWin::read_picture_data(QNetworkReply *reply)
{
    QByteArray array = reply->readAll();
    ui->pictureWidget->setPicture(array);
}

void MyMainWin::read_control_data()
{
    QString data = msocket.readAll();
    if(data.indexOf("picture") >=0)
    {
        play_picture();
    }
    else if(data.indexOf("movie")>=0){
        play_movie();
    }else {
        ui->rollWidget->setText(data);
    }
}
