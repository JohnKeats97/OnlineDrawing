#include "paintscene.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex my_mutex;

void updatePoint( std::vector<points>& Vector_point ) // std::vector<double> NewPoints )
{
    while (true) {
        std::cerr <<  "ПРоверка" << "\n";
        bool status = true;
        //status = IsStatus();
        if (status == true) {
//            std::vector<points> points (500);
//            for (int i = 0; i < 500; i++) {
//                points[i].x = i+ 5;
//                points[i].y = i+ 15;
//            }

            std::vector<points> points;
            //points = changes();
            // примет изменения
            // Паттерн команда
            // результат перекинет в поток отрисовки и встанет в очередь на отрисовку или отрисуется сразу
            my_mutex.lock();
            Vector_point = points;
//            v1.clear();
//            v1.insert(v1.begin(), v2.begin(), v2.end());
            my_mutex.unlock();
        }


        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

}


void paintScene::updatePoints ()
{
    my_mutex.lock();
    if (!Vector_point.empty()) {
        for (int i = 0; i < Vector_point.size(); i++) {
            addEllipse(Vector_point[i].x - 5,
                       Vector_point[i].y - 5,
                       10,
                       10,
                       QPen(Qt::NoPen),
                       QBrush(Qt::red));
        }
        Vector_point.clear();
    }
    my_mutex.unlock();

}

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{
    bool status = false;
    //status = IsStatus();
    if (status == true) {
        //points = changes();
//        my_mutex.lock();
//        for (int i = 0; i < points.size(); i++) {
//            addEllipse(points[i].x - 5,
//                       points[i].y - 5,
//                       10,
//                       10,
//                       QPen(Qt::NoPen),
//                       QBrush(Qt::red));
//        }
//        my_mutex.unlock();
    }

    // открываю поток по принятию изменений в вечном цикле вызывю updatePoint ///// QTread или qsocketnotifaer

    std::thread thr (updatePoint, std::ref(Vector_point));

    thr.detach();

    tmr = new QTimer(this); // Создаем объект класса QTimer и передаем адрес переменной
    tmr->setInterval(110); // Задаем интервал таймера
    connect(tmr, &QTimer::timeout, this, &paintScene::updatePoints); // Подключаем сигнал таймера к нашему слоту
    tmr->start(); // Запускаем таймер

}



paintScene::~paintScene()
{
    tmr->stop();
}



void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // При нажатии кнопки мыши отрисовываем эллипс
//    my_mutex.lock();
    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               10,
               10,
               QPen(Qt::NoPen),
               QBrush(Qt::red));
//    my_mutex.unlock();

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
//    my_mutex.lock();
    addEllipse(event->scenePos().x() - 5,
                   event->scenePos().y() - 5,
                   10,
                   10,
                   QPen(Qt::NoPen),
                   QBrush(Qt::red));
//    my_mutex.unlock();

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
