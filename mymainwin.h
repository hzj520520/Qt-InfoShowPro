#ifndef MYMAINWIN_H
#define MYMAINWIN_H


#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimer>
#include <QTcpSocket>

#define Server_Socket_Ip "192.168.1.14" //tcp服务器
#define HTTP_SERVER_IP  "192.168.1.19" //apache服务器

namespace Ui {
class MyMainWin;
}

class MyMainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWin(QWidget *parent = nullptr);
    ~MyMainWin();

    void timerEvent(QTimerEvent* e);

    void play_picture();
    void play_movie();

private slots:
    void read_movie_path(QNetworkReply *reply);
    void read_picture_path(QNetworkReply *reply);
    void read_picture_data(QNetworkReply *reply);

    void read_control_data();

private:
    Ui::MyMainWin *ui;
    QNetworkAccessManager pictureManager;
    QNetworkAccessManager movieManager;
    QNetworkAccessManager dataManager;
    QStringList picturesUrl;

    int timerid;

    //网络客户端
    QTcpSocket msocket;
};



#endif // MYMAINWIN_H
