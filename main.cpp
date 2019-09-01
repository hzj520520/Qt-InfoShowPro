#include "mymainwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainWin w;
    w.show();

    return a.exec();
}
