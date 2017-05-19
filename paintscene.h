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
    std::vector<points> Vector_point;

private:
    QPointF     previousPoint;      // Координаты предыдущей точки
    QTimer *tmr;


private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void updatePoints();
};



#endif // PAINTSCENE_H
