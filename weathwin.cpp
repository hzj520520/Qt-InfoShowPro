#include "weathwin.h"
#include "ui_weathwin.h"

#include <QFile>
#include <QMouseEvent>
#include <QDebug>

WeathWin::WeathWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeathWin)
{
    ui->setupUi(this);
    //初始化计数器
    count = 0;
    //打开文件导出数据
    QFile  file(":/citykeys.txt");
    file.open(QIODevice::ReadOnly);
    QString array = file.readAll();
    file.close();
    array.remove("\"");
    QStringList maplist = array.split(",");
    foreach (QString str, maplist) {
        QStringList cts = str.split(":");
        cityId[cts.at(1)] = cts.at(0);
    }

    connect(&manager, &QNetworkAccessManager::finished,
            this, &WeathWin::read_weather);


    //给指定的控件安装过滤器
    ui->weekLabel->installEventFilter(this);
}

WeathWin::~WeathWin()
{
    delete ui;
}

void WeathWin::update_weather(QString address)
{
    QString reqUrl = QString("http://t.weather.sojson.com/api/weather/city/%1")
            .arg(cityId[address]);

    QUrl url(reqUrl);
    QNetworkRequest request(url);
    manager.get(request);
}

//事件过滤器
bool WeathWin::eventFilter(QObject *watched, QEvent *event)
{

    //判断鼠标滑动事件
    if(event->type() == QEvent::MouseMove)
    {
        qDebug()<<"移动";
    }

    if(event->type() == QEvent::MouseButtonPress)
    {
        qDebug()<<"按下";
        QMouseEvent *e = (QMouseEvent*)event;
        start  = e->pos();
    }

    if(event->type() == QEvent::MouseButtonRelease)
    {
        qDebug()<<"释放";
        QMouseEvent *e = (QMouseEvent*)event;
        end = e->pos();

        if(end.x() - start.x() > 10)
        {
            //显示上一天
            count--;if(count < 0) count=weathers.count()-1;
            weather_show(count);
        }
        if(end.x() - start.x() < -10)
        {
            //显示下一天
            count++;if(count >= weathers.count()) count=0;
            weather_show(count);
        }
    }
    return QWidget::eventFilter(watched,event);
}

void WeathWin::read_weather(QNetworkReply *reply)
{
    QByteArray array = reply->readAll();

    //json解析
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(array, &err);
    if(err.error != QJsonParseError::NoError)
    {
        qDebug()<<"json erro";
        return ;
    }

    //最外面
    QJsonObject obj = doc.object();

    //第二层
    QJsonObject dataObj = obj.value("data").toObject();

    /*
       "shidu": "60%",
        "pm25": 17.0,
        "pm10": 36.0,
        "quality": "优",
        "wendu": "33",
        "ganmao": "各类人群可自由活动",
     */
    tempstr = dataObj.value("wendu").toString();
    humstr = dataObj.value("shidu").toString();

    //获取最近五天天气
    QJsonArray arrayJson = dataObj.value("forecast").toArray();
    if(arrayJson.size() >= 5) weathers.clear();

    for(int i=0 ; i<arrayJson.size(); i++)
    {
        QJsonObject arrayObj = arrayJson.at(i).toObject();
        WeatherData wdata;
        wdata.high = arrayObj.value("high").toString();
        wdata.low = arrayObj.value("low").toString();
        wdata.notice = arrayObj.value("notice").toString();
        wdata.ymd = arrayObj.value("ymd").toString();
        wdata.ymd = wdata.ymd.mid(5); //去掉"2019-"

        wdata.week = arrayObj.value("week").toString();
        wdata.fx  = arrayObj.value("fx").toString();
        wdata.fl  = arrayObj.value("fl").toString();
        wdata.type = arrayObj.value("type").toString();
        weathers.append(wdata);
    }

    weather_show();
}

void WeathWin::weather_show(int count)
{

//    ui->tempLabel->setText(this->tempstr);
//    ui->humLabel->setText(this->humstr);
    ui->highLabel->setText(weathers.at(count).high);
    ui->lowLabel->setText(weathers.at(count).low);
    ui->noticeLabel->setText(weathers.at(count).notice);
    ui->weekLabel->setText(weathers.at(count).week);
    ui->ymdLabel->setText(weathers.at(count).ymd);
    ui->fxLabel->setText(weathers.at(count).fx);
    ui->flLabel->setText(weathers.at(count).fl);
    ui->weathertextLabel->setText(weathers.at(count).type);

    //天气图片
    QString picpath = QString(":/images/%1.png").arg(weathers.at(count).type);
    qDebug()<<picpath;
    QPixmap mmp(picpath);
    mmp = mmp.scaled(ui->weatherpicLabel->size());
    ui->weatherpicLabel->setPixmap(mmp);


//            QString high;
//            QString low;
//            QString notice;
//            QString week;
//            QString ymd; //日期 ymd.remove("2019-");

//            QString fx;
//            QString fl;
//            QString type;
}
