#include "Camera.h"
#include "../Settings.h"

static float isometricCamera[3][3] = { 
    { 0.0,  25 + scenerySize, 0.0},
    { 0.0,  0.0,   -100.0},
    { 0.0,  1.0,    0.0} 
};

static float (*cam)[3][3] = &isometricCamera; // in case we want to make multiple preconfigured cameras

static double dist = sqrt(pow((*cam)[1][0] - (*cam)[0][0], 2) + pow((*cam)[1][1] - (*cam)[0][1], 2) + pow((*cam)[1][2] - (*cam)[0][2], 2));
static double ray = scenerySize;
static double ang = asin(ray / dist) * 2 * 180 / M_PI;

void initCamera(bool isCameraPerspect, int wx, int wy) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double ratio = (double)wx / wy;
    if (!isCameraPerspect) {
        if (wx > wy)
            glOrtho((-10.0 - scenerySize) * ratio, (10.0 + scenerySize) * ratio, -10.0 - scenerySize, 10.0 + scenerySize, 0.0 - scenerySize, 1000.0 + scenerySize);
        else
            glOrtho(-10.0 - scenerySize, 10.0 + scenerySize, (-10.0 - scenerySize) / ratio, (10.0 + scenerySize) / ratio, 0.0 - scenerySize, 1000.0 + scenerySize);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    else {
        gluPerspective(ang, ratio, dist - ray - 20, (dist + ray)*100);
        dist = sqrt(pow((*cam)[1][0] - (*cam)[0][0], 2) + pow((*cam)[1][1] - (*cam)[0][1], 2) + pow((*cam)[1][2] - (*cam)[0][2], 2));
        ang = asin(ray / dist) * 2 * 180 / M_PI;
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(
            (*cam)[0][0], (*cam)[0][1], (*cam)[0][2],
            (*cam)[1][0], (*cam)[1][1], (*cam)[1][2],
            (*cam)[2][0], (*cam)[2][1], (*cam)[2][2]);
    }
}
