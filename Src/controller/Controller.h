#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/Board.h"
#include "../model/Player.h"
#include "../model/Game.h"
#include "../View/View.h"
#include "../View/Camera/Camera.h"
#include <bits/types/time_t.h>
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

private:
    gooseGameModel::Game game;
    View view;

    time_t lastFrameTime;
};



#endif // !CONTROLLER_H