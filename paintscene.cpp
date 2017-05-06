#include "paintscene.h"
#include <iostream>
#include <vector>

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{
    bool status = false;
    //status = IsStatus();
    if (status == true) {
        std::vector<points> points;
        //points = changes();
        for (int i = 0; i < points.size(); i++) {
            addEllipse(points[i].x - 5,
                       points[i].y - 5,
                       10,
                       10,
                       QPen(Qt::NoPen),
                       QBrush(Qt::red));
        }
    }
}

paintScene::~paintScene()
{

}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // При нажатии кнопки мыши отрисовываем эллипс
    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               10,
               10,
               QPen(Qt::NoPen),
               QBrush(Qt::red));

    points point;
    point.x = event->scenePos().x();
    point.y = event->scenePos().y();
    //point.color = user.color;
    //request (point);
    std::cerr <<  event->scenePos().x() << "\n";

    // Сохраняем координаты точки нажатия
//    previousPoint = event->scenePos();
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // При нажатии кнопки мыши отрисовываем эллипс
    addEllipse(event->scenePos().x() - 5,
                   event->scenePos().y() - 5,
                   10,
                   10,
                   QPen(Qt::NoPen),
                   QBrush(Qt::red));

    points point;
    point.x = event->scenePos().x();
    point.y = event->scenePos().y();
    //point.color = user.color;
    //request (point);
    std::cerr <<  event->scenePos().x() << "\n";

    // Отрисовываем линии с использованием предыдущей координаты
//    addLine(previousPoint.x(),
//            previousPoint.y(),
//            event->scenePos().x(),
//            event->scenePos().y(),
//            QPen(Qt::red,10,Qt::SolidLine,Qt::RoundCap));
    // Обновляем данные о предыдущей координате
//    previousPoint = event->scenePos();
}
