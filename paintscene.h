#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include <vector>
#include <thread>


struct points {
  int x, y;
  int color;
};



class paintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();
    static void changePoint(std::vector<points>& Vector_point);
    void updatePoints();

private:
    QPointF     previousPoint;      // Координаты предыдущей точки
    QTimer *tmr;
    std::thread *thr;
    std::vector<points> Vector_point;

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};



#endif // PAINTSCENE_H
