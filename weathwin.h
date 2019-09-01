#ifndef WEATHWIN_H
#define WEATHWIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QMap>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>


class WeatherData{
public:
    QString high;
    QString low;
    QString notice;
    QString week;
    QString ymd; //日期 ymd.remove("2019-");

    QString fx;
    QString fl;
    QString type;

};

namespace Ui {
class WeathWin;
}

class WeathWin : public QWidget
{
    Q_OBJECT

public:
    explicit WeathWin(QWidget *parent = nullptr);
    ~WeathWin();
    void update_weather(QString address);

    //添加事件过滤器
    bool eventFilter(QObject *watched, QEvent *event);

protected slots:
    void read_weather(QNetworkReply *reply);
private slots:
    void weather_show(int count=0);


private:
    Ui::WeathWin *ui;

    QString address;
    QMap<QString , QString> cityId;
    QNetworkAccessManager manager;
    QVector<WeatherData> weathers;

  //当天天气情况
    QString tempstr; //温度
    QString humstr;  //湿度


    QPoint start;
    QPoint end;

    int count;


};

#endif // WEATHWIN_H
