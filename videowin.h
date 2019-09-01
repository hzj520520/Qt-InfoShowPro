#ifndef VIDEOWIN_H
#define VIDEOWIN_H

#include <QWidget>
#include <QProcess>

//#define PC //电脑上播放时用
#define MPLAYER_CMD_PC  "F:/hzj_file/CODE_C++/QtProject/InfoDisplay/pcmplayer/mplayer.exe"


namespace Ui {
class VideoWin;
}

class VideoWin : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWin(QWidget *parent = nullptr);
    ~VideoWin();
    void play(QString filename=QString());
    void stop();
    void addFile(QString file);
    void clear();
private slots:
    void finished_fun();
private:
    Ui::VideoWin *ui;
    QProcess mProcess;
    QStringList fileList;
    int count;
    int flag;
};

#endif // VIDEOWIN_H

