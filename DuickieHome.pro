TEMPLATE = app

QT += qml quick widgets svg multimedia

SOURCES += main.cpp \
    types/player/duck.cpp \
    types/player/ball.cpp \
    types/obstacles/barrel/barrels.cpp \
    types/obstacles/barrel/barrel.cpp \
    types/obstacles/obstacles.cpp \
    types/obstacles/cloud/clouds.cpp \
    types/obstacles/obstacle.cpp \
    types/outline.cpp \
    types/obstacles/cloud/cloud.cpp \
    types/game.cpp \
    types/background/trees.cpp \
    types/background/tree.cpp \
    types/visibleitem.cpp \
    types/fileIO/filestream.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml

HEADERS += \
    types/player/duck.h \
    types/player/ball.h \
    types/obstacles/barrel/barrels.h \
    types/obstacles/barrel/barrel.h \
    types/obstacles/obstacles.h \
    types/obstacles/cloud/clouds.h \
    types/obstacles/obstacle.h \
    types/outline.h \
    types/obstacles/cloud/cloud.h \
    types/game.h \
    types/background/trees.h \
    types/background/tree.h \
    types/visibleitem.h \
    types/fileIO/filestream.h

