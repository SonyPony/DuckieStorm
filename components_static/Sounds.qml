import QtQuick 2.0
import QtMultimedia 5.0

Item {

    /*------Přenesení id do popředí------*/
    property alias scoreSound: scoreSound
    property alias lightingSound: lightingSound
    property alias outWaterSound: outWaterSound
    property alias inWaterSound: inWaterSound
    property alias soundtrack: soundtrack
    /*-----------------------------------*/

    /*--------------Skóre----------------*/
    Audio {
        id: scoreSound

        property bool isPlaying: false

        source: "../res/sounds/scoreSound.wav"

        onPlaying: isPlaying = true
        onStopped: isPlaying = false
    }
    /*-----------------------------------*/

    /*---------------Blesk---------------*/
    Audio {
        id: lightingSound

        property bool isPlaying: false

        source: "../res/sounds/lightingSound.wav"
        volume: 0.5

        onPlaying: isPlaying = true
        onStopped: isPlaying = false
    }
    /*-----------------------------------*/

    /*-----------Skok z vody-------------*/
    Audio {
        id: outWaterSound

        source: "../res/sounds/outFromWaterSound.wav"
        volume: 0.8
    }
    /*-----------------------------------*/

    /*-----------Skok do vody------------*/
    Audio {
        id: inWaterSound

        source: "../res/sounds/intoWaterSound.wav"
        volume: 0.6
    }
    /*-----------------------------------*/

    /*---------Hudba na pozadí-----------*/
    Audio {
        id: soundtrack

        source: "../res/sounds/test.mp3"
        onStopped: soundtrack.play()

        function handleGamePause() {
            if(game.paused)
                soundtrack.pause()
            else
                soundtrack.play()
        }
    }
    /*-----------------------------------*/
}

