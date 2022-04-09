#include "canvas.h"
#include <QMouseEvent>
#include <string>
#include <algorithm>

Canvas::Canvas(QWidget *ptr) : QWidget(ptr){
    pointList->setGeometry(1000, 0, 200, 800);
}

void Canvas::mousePressEvent(QMouseEvent *event){
    point temp;
    if(event->buttons() & Qt::LeftButton) {
        pointList->clear();
        QString tempString;
        if(vectorOfInfo.empty()){
            tempString.append("no points lol");
        } else{
            tempString.append("Your points distance are:\n\n");
        }
        for(int k = 0; k < vectorOfInfo.size(); k++){
            tempString.append(QString::number(vectorOfInfo[k].i) + " & " +
                              QString::number(vectorOfInfo[k].j) + " is " +
                              QString::number(vectorOfInfo[k].distance) + "\n"
                              );
        }
        pointList->setText(tempString);
        pointList->show();
    }
    if(event->buttons() & Qt::RightButton) {
        temp.x = event->pos().x();
        temp.y = event->pos().y();
        vectorOfPoints.push_back(temp);
        this->update();
    }
}

void Canvas::TextOut(int x, int y, QString text){
    this->drawText(x, y, text);
}

void Canvas::paintEvent(QPaintEvent *event){
    this->begin(this);
    vectorOfInfo.clear();
    for(int i = 0; i < vectorOfPoints.size(); i++){
        this->setPen(Qt::red);
        this->setBrush(Qt::red);
        this->drawText(vectorOfPoints[i].x + 4, vectorOfPoints[i].y, QString::number(i + 1));
        this->drawEllipse(vectorOfPoints[i].x, vectorOfPoints[i].y, 4, 4);
        for(int j = i; j < vectorOfPoints.size(); j++){
            if(i % 2 == 0 && j % 2 == 0){
                this->setPen(Qt::black);
                this->drawLine(vectorOfPoints[i].x, vectorOfPoints[i].y, vectorOfPoints[j].x, vectorOfPoints[j].y);
                if(i != j){
                    float distance = sqrt(pow(vectorOfPoints[i].x - vectorOfPoints[j].x, 2) + pow(vectorOfPoints[i].y - vectorOfPoints[j].y, 2));
                    TextOut(((int)(vectorOfPoints[i].x + vectorOfPoints[j].x) / 2),
                            ((int)(vectorOfPoints[i].y + vectorOfPoints[j].y) / 2),
                            QString::number(distance)
                            );
                    info temp;
                    temp.i = i + 1;
                    temp.j = j + 1;
                    temp.distance = distance;
                    vectorOfInfo.push_back(temp);
                }
            }
        }
    }

    reverse(vectorOfInfo.begin(), vectorOfInfo.end());

    this->end();
}
