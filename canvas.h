#ifndef CANVAS_H
#define CANVAS_H

#include <QLabel>
#include <QPainter>
#include <vector>
#include <string>

using namespace std;

struct point{
    int x, y, number;
};

struct info{
    int i, j;
    float distance;
};

class Canvas : public QWidget, public QPainter{
private:
    vector<point> vectorOfPoints;
    QLabel *pointList = new QLabel(this);
    vector<info> vectorOfInfo;

    void TextOut(int x, int y, QString text);
public:
    Canvas(QWidget *ptr=nullptr);


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
};

#endif // CANVAS_H
