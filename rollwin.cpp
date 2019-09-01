#include "rollwin.h"
#include <QDebug>

RollWin::RollWin(QWidget *parent) :
    QWidget(parent)
{
    offset = 0;
    myTimerId = 0;
}

RollWin::~RollWin()
{

}


void RollWin::setText(const QString &newText)

{
     myText = newText;
     update();
     updateGeometry();
}


QSize RollWin::sizeHint() const
{
     return fontMetrics().size(0, text());
}


void RollWin::paintEvent(QPaintEvent * )
{
     QPainter painter(this);
     int textWidth = fontMetrics().width(text());
     if (textWidth < 1)
         return;
     int x = offset;
     int clong = (width()-textWidth)-x;
     painter.drawText(clong, 0, width(), height(),
                     Qt::AlignLeft | Qt::AlignVCenter, text());
     if(clong<0)
     {
         painter.drawText(width()+clong, 0, width(), height(),
                         Qt::AlignLeft | Qt::AlignVCenter, text());
     }
     x += textWidth;
}


void RollWin::showEvent(QShowEvent * )
{
     myTimerId = startTimer(30);
}

void RollWin::timerEvent(QTimerEvent *event)
{
     if (event->timerId() == myTimerId) {
         ++offset;
//         if (offset >= fontMetrics().width(text()))
//             offset = 0;
         if (offset >= width())
             offset = 0;
         scroll(-1, 0);
     } else {
         QWidget::timerEvent(event);
     }
}


void RollWin::hideEvent(QHideEvent * )
{
     killTimer(myTimerId);
     myTimerId = 0;
}
