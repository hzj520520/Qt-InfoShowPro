#ifndef PICTUREWIN_H
#define PICTUREWIN_H


#include <QWidget>
#include <QPixmap>
namespace Ui {
class PictureWin;
}

class PictureWin : public QWidget
{
    Q_OBJECT

public:
    explicit PictureWin(QWidget *parent = nullptr);
    ~PictureWin();
    void setPicture(QString filename);
    void setPicture(QByteArray array);
    void paintEvent(QPaintEvent *e);
private:
    Ui::PictureWin *ui;
    QPixmap mmp;
};


#endif // PICTUREWIN_H
