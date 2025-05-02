#include "Camera.h"

void Camera::setCameraPlayerPosition(float x, float y, float z) {
    if (!isCameraPerspect) {
        return;
    }
    if (!f_cameraOnCurrentPlayer){
        return;
    }
    //Center of the pawn 
    currentViewCamera.center[0] = x;
    currentViewCamera.center[1] = y;
    currentViewCamera.center[2] = z;

    //Eye of the pawn
    currentViewCamera.eye[0] = x;
    currentViewCamera.eye[1] = y + pawnWidth * 2;
    currentViewCamera.eye[2] = z;

}

void Camera::initCamera(int wx, int wy) {
    //Print camera position
    printf("Camera position : %f %f %f\n", currentViewCamera.eye[0], currentViewCamera.eye[1], currentViewCamera.eye[2]);
    //Print camera center
    printf("Camera center : %f %f %f\n", currentViewCamera.center[0], currentViewCamera.center[1], currentViewCamera.center[2]);
    //Print camera up
    printf("Camera up : %f %f %f\n", currentViewCamera.up[0], currentViewCamera.up[1], currentViewCamera.up[2]);

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
    } else {
        gluPerspective(FOV, ratio, 0.1, (dist + ray)*100);
        computeDist();
       
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(
            currentViewCamera.eye[0], currentViewCamera.eye[1], currentViewCamera.eye[2],
            currentViewCamera.center[0], currentViewCamera.center[1], currentViewCamera.center[2],
            currentViewCamera.up[0], currentViewCamera.up[1], currentViewCamera.up[2]
        );
    }
}
