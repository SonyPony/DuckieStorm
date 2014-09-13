import QtQuick 2.0

Item {
    Image {
        id: duckImage

        source: duck.imageURL
        opacity: 0.3
        x: duck.defaultX
        y: duck.defaultY-duck.heightOfJump
        z: 1

        width: duck.size
        height: width

        /*----Renderovací velikost----*/
        sourceSize.width: 1400
        sourceSize.height: 1400
        /*----------------------------*/
    }

    Image {
        id: ballImage
        objectName: "ballImage"

        source: ball.imageURL
        opacity: 0.3
        x: 350
        y: 100
        z: 1

        height: game.sizeOfPixel * 4
        width: height

        /*----Renderovací velikost----*/
        sourceSize.width: 1100
        sourceSize.height: 1100
        /*----------------------------*/
    }
}
