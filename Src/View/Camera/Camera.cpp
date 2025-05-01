#include "Camera.h"
#include "../Settings.h"
#include "../View.h"

static float isometricCamera[3][3] = { 
    { 0.0,  25 + scenerySize, 0.0},
    { 0.0,  0.0,   -100.0},
    { 0.0,  1.0,    0.0} 
};

static float playerTrackingCamera[3][3] = { 
    { 0.0,  25 + scenerySize, 0.0},
    { 0.0,  0.0,  -100.0},
    { 0.0,  0.0,    1.0} 
};

static float (*cam)[3][3] = &isometricCamera; // in case we want to make multiple preconfigured cameras

static double dist = sqrt(pow((*cam)[1][0] - (*cam)[0][0], 2) + pow((*cam)[1][1] - (*cam)[0][1], 2) + pow((*cam)[1][2] - (*cam)[0][2], 2));
static double ray = scenerySize;
static double ang = asin(ray / dist) * 2 * 180 / M_PI;

void setCameraPlayerPosition(float x, float y, float z) {
    //Center of the pawn 
    playerTrackingCamera[1][0] = x;
    playerTrackingCamera[1][1] = y;
    playerTrackingCamera[1][2] = z;

    playerTrackingCamera[0][0] = x;
    playerTrackingCamera[0][1] = y + pawnWidth * 3;
    playerTrackingCamera[0][2] = z;
}

void initCamera(bool isCameraPerspect, bool cameraOnCurrentPlayer, int wx, int wy) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double ratio = (double)wx / wy;

    if (cameraOnCurrentPlayer) {
        cam = &playerTrackingCamera;
    } else {
        cam = &isometricCamera;
    }

    if (!isCameraPerspect) {
        if (wx > wy)
            glOrtho((-10.0 - scenerySize) * ratio, (10.0 + scenerySize) * ratio, -10.0 - scenerySize, 10.0 + scenerySize, 0.0 - scenerySize, 1000.0 + scenerySize);
        else
            glOrtho(-10.0 - scenerySize, 10.0 + scenerySize, (-10.0 - scenerySize) / ratio, (10.0 + scenerySize) / ratio, 0.0 - scenerySize, 1000.0 + scenerySize);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    } else {
        gluPerspective(FOV, ratio, 0.1, (dist + ray)*100);
        dist = sqrt(pow((*cam)[1][0] - (*cam)[0][0], 2) + pow((*cam)[1][1] - (*cam)[0][1], 2) + pow((*cam)[1][2] - (*cam)[0][2], 2));
       
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(
            (*cam)[0][0], (*cam)[0][1], (*cam)[0][2],
            (*cam)[1][0], (*cam)[1][1], (*cam)[1][2],
            (*cam)[2][0], (*cam)[2][1], (*cam)[2][2]);
    }
}
