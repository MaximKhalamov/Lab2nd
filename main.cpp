#include <QtGui>
#include <QApplication>
#include "canvas.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Canvas c;
    c.setFixedSize(1200, 800);
    c.setWindowTitle("Task2");
    c.show();
    return a.exec();
}
