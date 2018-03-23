#include "line.h"

#include <Qt3DLogic/QFrameAction>

Grapicis::Line::Line(Qt3DCore::QEntity *parent)
    : Qt3DCore::QEntity(parent)
{
    auto mesh = new Qt3DRender::QGeometryRenderer();
    auto geometry = new Qt3DRender::QGeometry(mesh);
    auto dataBuffer = new Qt3DRender::QBuffer(Qt3DRender::QBuffer::VertexBuffer, geometry);
    auto posAttribute = new Qt3DRender::QAttribute();

    QVector<QVector3D> vertices;
    vertices.resize(500000);
    const int s = 20000;
    for (auto& v : vertices) {
        v.setX(s/2 - rand() % s);
        v.setY(s/2 - rand() % s);
        v.setZ(s/2 - rand() % s);
    }

    QByteArray vertexBufferData;
    vertexBufferData.resize(vertices.size() * 3 * sizeof(float));
    float *rawVertexArray = reinterpret_cast<float *>(vertexBufferData.data());
    int idx = 0;
    Q_FOREACH (const QVector3D &v, vertices) {
        rawVertexArray[idx++] = v.x();
        rawVertexArray[idx++] = v.y();
        rawVertexArray[idx++] = v.z();
    }

    dataBuffer->setData(vertexBufferData);

    posAttribute->setAttributeType(Qt3DRender::QAttribute::VertexAttribute);
    posAttribute->setBuffer(dataBuffer);
    posAttribute->setDataType(Qt3DRender::QAttribute::Float);
    posAttribute->setDataSize(3);
    posAttribute->setName(Qt3DRender::QAttribute::defaultPositionAttributeName());

    geometry->addAttribute(posAttribute);

    mesh->setInstanceCount(1);
    mesh->setIndexOffset(0);
    mesh->setFirstInstance(0);
    mesh->setVertexCount(vertices.size());
    mesh->setPrimitiveType(Qt3DRender::QGeometryRenderer::LineStrip);

    mesh->setGeometry(geometry);

    auto lines = new Qt3DCore::QEntity();
    auto frameAction = new Qt3DLogic::QFrameAction(lines);
    QObject::connect(frameAction, &Qt3DLogic::QFrameAction::triggered, [ = ](float dt){
        // qDebug() << "FPS" << 1/dt;
    });

    auto linesTransform = new Qt3DCore::QTransform();

    Qt3DRender::QGeometryRenderer *linesMesh = mesh;
    auto material = new Qt3DExtras::QPhongMaterial(this);
    material->setAmbient(QColor(0, 120, 0));

    lines->addComponent(linesMesh);
    lines->addComponent(material);
    lines->addComponent(linesTransform);
    lines->setParent(this);


}
