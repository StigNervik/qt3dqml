QT += 3dcore 3drender 3dinput 3dquick 3dlogic qml quick 3dquickextras 3dextras

SOURCES += \
    main.cpp \
    node/entity.cpp \
    node/line.cpp \
    linetest.cpp

OTHER_FILES += \
    main.qml

RESOURCES += \
    simple-qml.qrc

HEADERS += \
    node/entity.h \
    linetest.h \
    node/line.h
