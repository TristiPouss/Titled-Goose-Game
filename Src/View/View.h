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
#include "Settings.h"

// General settings for the view
static float roomLength = scenerySize;
static float tableHeight = roomLength * 0.15f;
static float tableWidth = roomLength * 0.18f;
static float pawnWidth = 0.4f;
static float dice_edge = 0.9f;
static float dice_radius = 0.1f;

static float litVoitureWidth = roomLength * 0.65f;
static float litVoitureDepth = litVoitureWidth * 0.5f;
static float shelfLength = 40;
static float kaplaLength = 5;
static float castleLength = 10;

static float cellWidth = roomLength / 100.0f;

typedef struct {
    float x;
    float y;
    float z;
    unsigned int caseNumber;
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

        void draw(int facetNumber);

        void drawMainScene(int facetNumber);
        void drawDiceScene(int facetNumber);

        void update(float deltaTime);

        void updateMainScene(float deltaTime);
        void updateDiceScene(float deltaTime);
        
        void setCurrentPlayer(unsigned long player) {
            currentPlayer = player;
        }

        void setBoard(gooseGameModel::Board board) {
            board_cpy = board;
        }

        void setScene(currentScene s) {
            scene = s;
        }

        bool isAnimating() {
            return f_anim;
        }

        void switchToDiceScene() {
            scene = DICE_SCENE;
            f_anim = true;
            f_diceRolling = true;
            timerDiceRolling = TIMER_DICE_ROLLING; // Set the duration for the dice rolling animation
        }

    private:
        std::vector<pos3D> posCells;
        std::vector<pos3D> posPlayers;

        currentScene scene;

        float timerChangeTurn = 0;
        float timerDiceRolling = 0;
        float timerDiceShowing = 0;

        unsigned long currentPlayer = 0;

        bool f_anim = false;
        bool f_diceRolling = false;
        bool f_diceShowing = false;

        gooseGameModel::Board board_cpy;

        // Angle of rotation for the dices animation
        float angled1 = 0.0f;
        float angled2 = 0.0f;

};

#endif // VIEW_H