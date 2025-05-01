#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include "../model/Board.h"
#include "Geometry/Shapes.h"
#include "Geometry/Furnitures.h"
#include "Geometry/Texture.h"

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Camera/Camera.h"

// General settings for the view
static float roomLength = scenerySize;
static float tableHeight = roomLength * 0.15f;
static float tableWidth = roomLength * 0.18f;
static float pawnWidth = 0.4f;
static float dice_edge = 0.9f;
static float dice_radius = 0.1f;
static float litVoitureWidth = roomLength * 0.1f;
static float shelfLength = 40;
static float kaplaLength = 5;
static float castleLength = 10;

static float cellWidth = roomLength / 100.0f;

typedef struct {
    float x;
    float y;
    float z;
    int caseNumber;
} pos3D;

typedef enum {
    MAIN_SCENE,
    DICE_SCENE
} currentScene;

class View
{
    public:
        View();
        void init();

        void draw();

        void drawMainScene();
        void drawDiceScene();

        void update();

        void updateMainScene();
        void updateDiceScene();
        

    private:
        std::vector<pos3D> posCells;
        std::vector<pos3D> posPlayers;

        currentScene scene;

        unsigned long delta = 0;
};

#endif // VIEW_H