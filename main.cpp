#include <QApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>

#include "types/player/duck.h"
#include "types/player/ball.h"
#include "types/obstacles/barrel/barrels.h"
#include "types/obstacles/barrel/barrel.h"
#include "types/obstacles/cloud/clouds.h"
#include "types/outline.h"
#include "types/obstacles/cloud/cloud.h"
#include "types/game.h"
#include "types/background/trees.h"
#include "types/background/tree.h"
#include "types/fileIO/filestream.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<FileStream>("FileStream", 1, 0, "FileStream");
    qmlRegisterType<Tree>("Tree", 1, 0, "Tree");
    qmlRegisterType<Trees>("Trees", 1, 0, "Trees");
    qmlRegisterType<Barrel>("Barrel", 1, 0, "Barrel");
    qmlRegisterType<Game>("Game", 1, 0, "Game");
    qmlRegisterType<Cloud>("Cloud", 1, 0, "Cloud");
    qmlRegisterType<Duck>("Duck", 1, 0, "Duck");
    qmlRegisterType<Ball>("Ball", 1, 0, "Ball");
    qmlRegisterType<Barrels>("Barrels", 1, 0, "Barrels");
    qmlRegisterType<Clouds>("Clouds", 1, 0, "Clouds");
    qmlRegisterType<Outline>("Outline",1,0,"Outline");


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
