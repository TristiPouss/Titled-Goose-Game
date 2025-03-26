#include "Camera.h"
#include "../Settings.h"

static float isometricCamera[3][3] = { 
    { 0.0, 25.0 + c, -25.0 -c},
    { 0.0,  0.0,   0.0},
    { 0.0,  1.0,   0.0} 
};

static float (*cam)[3][3] = &isometricCamera; // in case we want to make multiple preconfigured cameras

static double dist = sqrt(pow((*cam)[1][0] - (*cam)[0][0], 2) + pow((*cam)[1][1] - (*cam)[0][1], 2) + pow((*cam)[1][2] - (*cam)[0][2], 2));
static double ray = c;
static double ang = asin(ray / dist) * 2 * 180 / M_PI;

void initCamera(bool isCameraOrtho) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double ratio = (double)wTx / wTy;
    if (isCameraOrtho) {
        if (wTx > wTy)
            glOrtho((-10.0 - c) * ratio, (10.0 + c) * ratio, -10.0 - c, 10.0 + c, -25.0 - c, 25.0 + c);
        else
            glOrtho(-10.0 - c, 10.0 + c, (-10.0 - c) / ratio, (10.0 + c) / ratio, -25.0 - c, 25.0 + c);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    else {
        gluPerspective(ang, ratio, dist - ray, dist + ray);
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
