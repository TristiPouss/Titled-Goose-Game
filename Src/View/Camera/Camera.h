#ifndef CAMERA_H
#define CAMERA_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../Settings.h"
#include "../View.h"

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

// Type for the camera
typedef struct {
    float eye[3];
    float center[3];
    float up[3];
} camera_t;

// Predefined camera positions
static camera_t isometricCamera = { 
    { 0.0,  25 + scenerySize, 0.0},
    { 0.0,  0.0,   -100.0},
    { 0.0,  1.0,    0.0} 
};

static camera_t playerTrackingCamera = { 
    { 0.0,  0.0, 0.0},
    { 0.0,  0.0, 0.0},
    { 0.0,  0.0, 1.0} 
};

static camera_t diceCamera = { 
    { 0.0,  50.0, 0.0},
    { 0.0,  0.0,  0.0},
    { 0.0,  0.0,  1.0} 
};


class Camera {


public:
    Camera() {
        isCameraPerspect = true;
    
        // Initialize the camera to the isometric view
        currentViewCamera = isometricCamera;


        dist = sqrt(pow(currentViewCamera.center[0] - currentViewCamera.eye[0], 2) + pow(currentViewCamera.center[1] - currentViewCamera.eye[1], 2) + pow(currentViewCamera.center[2] - currentViewCamera.eye[2], 2));
        ray = scenerySize;
        ang = asin(ray / dist) * 2 * 180 / M_PI; 
    }
    
    void initCamera(int wx, int wy);
    void setCameraPlayerPosition(float x, float y, float z);

    void computeDist() {
        dist = sqrt(pow(currentViewCamera.center[0] - currentViewCamera.eye[0], 2) + pow(currentViewCamera.center[1] - currentViewCamera.eye[1], 2) + pow(currentViewCamera.center[2] - currentViewCamera.eye[2], 2));
    }

    void switchPerspective() {
        
    }

    void switchCameraPerspect() {
        isCameraPerspect = !isCameraPerspect;
    }

    void switchCameraOnCurrentPlayer() {
        if (f_cameraOnCurrentPlayer) {
            currentViewCamera = isometricCamera;
        } else {
            currentViewCamera = playerTrackingCamera;
        }
        f_cameraOnCurrentPlayer = !f_cameraOnCurrentPlayer;
        f_cameraOnDice = false;
    }

    void switchCameraOnDice() {
        if (f_cameraOnDice) {
            currentViewCamera = isometricCamera;
        } else {
            currentViewCamera = diceCamera;
        }
        f_cameraOnDice = !f_cameraOnDice;
        f_cameraOnCurrentPlayer = false;
    }

    private: 
        camera_t currentViewCamera;

        bool isCameraPerspect;

        static double dist;
        static double ray;
        static double ang; 

        static bool f_cameraOnCurrentPlayer;
        static bool f_cameraOnDice;
        static bool f_cameraOnIsometric;
    
};

#endif // !CAMERA_H
