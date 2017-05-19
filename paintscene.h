#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include <vector>


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

    void updatePoints();

private:
    QPointF     previousPoint;      // Координаты предыдущей точки
    QTimer *tmr;


private:
    std::vector<points> Vector_point;
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};



#endif // PAINTSCENE_H
