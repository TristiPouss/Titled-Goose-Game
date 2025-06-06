#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/Board.h"
#include "../model/Player.h"
#include "../model/Game.h"
#include "../View/View.h"
#include "../View/Camera/Camera.h"
#include <time.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Controller
{
public:
    Controller();

    void update(time_t frameTime);
    void display(int facetNumber);

    void playTurn();
    void resetGame();

    void launchGame();

    //Camera control

    void switchCameraPerspect() {
        view.switchCameraPerspect();
    }

    void switchCameraOnDice() {
        view.switchCameraOnDice();
    }

    void switchCameraOnPlayer() {
        view.switchCameraOnCurrentPlayer();
    }

    void reshape(int w, int h) {
        view.reshape(w, h);
    }

    
    View view;
private:
    gooseGameModel::Game game;
    

    time_t lastFrameTime;
};



#endif // !CONTROLLER_H