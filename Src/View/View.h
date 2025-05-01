#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include "../model/Board.h"
#include "Geometry/Shapes.h"
#include "Geometry/Furnitures.h"
#include "Geometry/Texture.h"



typedef struct {
    float x;
    float y;
    float z;
} pos3D;

typedef enum {
    MAIN_SCENE,
    DICE_SCENE
} currentScene;

class View
{
    public:
        View();

        void draw();

        void drawMainScene();
        void drawDiceScene();

        void update();
        

    private:
        std::vector<pos3D> posCells;
        std::vector<pos3D> posPlayers;

        currentScene scene;

        unsigned long delta = 0;
};

#endif // VIEW_H