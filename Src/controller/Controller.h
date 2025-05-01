#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/Board.h"
#include "../model/Player.h"
#include "../model/Game.h"
#include "../View/View.h"
#include "../View/Camera/Camera.h"

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Controller
{
public:
    Controller();

    void update();
    void display(int facetNumber);

    void playTurn();

private:
    gooseGameModel::Game game;
    View view;
};



#endif // !CONTROLLER_H