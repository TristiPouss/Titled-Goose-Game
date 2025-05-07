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
#include "Lights.h"
#include "Settings.h"

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
        
        void showDiceFace(int value);

        void changeDayTime();

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
            cam.switchCameraOnDice();
            timerDiceRolling = TIMER_DICE_ROLLING; // Set the duration for the dice rolling animation
        }

        void switchCameraOnCurrentPlayer() {
            cam.switchCameraOnCurrentPlayer();
        }


        void switchCameraOnDice() {
            cam.switchCameraOnDice();
        }

        void switchCameraPerspect() {
            cam.switchCameraPerspect();
        }

        void setDicesValues(int value1, int value2) {
            dicesValues[0] = value1;
            dicesValues[1] = value2;
        }

        void reshape(int w, int h) {
            wTx = w;
            wTy = h;
            
        }

        void initCamera() {
            cam.initCamera(wTx, wTy);
        }

		void initLights() {
			lights.init();
		}

        Camera cam;
        Lights lights;
    private:

        std::vector<pos3D> posCells;
        std::vector<pos3D> posPlayers;

        currentScene scene;
        

        float timerChangeTurn = 0;
        float timerDiceRolling = 0;
        float timerDiceShowing = 0;
		float timerChangeTimeOfDay = 0;

        unsigned long currentPlayer = 0;

        bool f_anim = false;
        bool f_diceRolling = false;
        bool f_diceShowing = false;
		bool f_changeTimeOfDay = false;

        gooseGameModel::Board board_cpy;
        int dicesValues[2] = { 1, 1 }; // Values of the two dices

        // Angle of rotation for the dices animation
        float angled1 = 0.0f;
        float angled2 = 0.0f;

        int wTx = INIT_wTx;              // Horizontal resolution of the window
        int wTy = INIT_wTx;              // Vertical resolution of the window
        
};

#endif // VIEW_H