#ifndef ROLLWIN_H
#define ROLLWIN_H

#include <QWidget>
#include <QPainter>
#include <QEvent>


class RollWin : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
public:
    explicit RollWin(QWidget *parent = 0);
    ~RollWin();
    void setText(const QString &newText);
    QString text() const { return myText; }
    QSize sizeHint() const;
protected:
     void paintEvent(QPaintEvent *event);
     void timerEvent(QTimerEvent *event);
     void showEvent(QShowEvent *event);
     void hideEvent(QHideEvent *event);
signals:

public slots:

private:
     QString myText;
     int offset;
     int myTimerId;
};

#endif // RollWin_H
