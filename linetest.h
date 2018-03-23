#ifndef LINE_H
#define LINE_H

#include <QObject>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>

#include <Qt3DRender/QAttribute>
#include <Qt3DRender/QBuffer>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>
#include <Qt3DRender/QGeometryRenderer>
#include <Qt3DRender/QGeometry>

#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QFirstPersonCameraController>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DRender/QGeometryRenderer>

#include <QColor>
#include <QtMath>

class Line : public QObject
{
    Q_OBJECT

public:
    Line(QObject * parent = 0);

    Qt3DRender::QGeometryRenderer * createLine();
};

#endif // LINE_H
