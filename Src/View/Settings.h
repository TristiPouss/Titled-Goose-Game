#ifndef SETTINGS_H
#define SETTINGS_H

static float rx = 0.0F;            // Rotation angle of the scene around the x-axis
static float ry = 0.0F;            // Rotation angle of the scene around the y-axis
static float rz = 0.0F;            // Rotation angle of the scene around the z-axis
static float sens = 1.0F;          // Rotation direction of the scene around the x-axis
static float mx = 0.0F;            // Movement length of the scene around the x-axis
static float my = 0.0F;            // Movement length of the scene around the y-axis
static float mz = 0.0F;            // Movement length of the scene around the z-axis
static float zoom = 2.86F;

static int mouseActive = 0;        // Flag indicating whether the mouse is active (button pressed) or not
static int mouseX = 0;             // Last recorded x position of the mouse

static int wTx = 480;              // Horizontal resolution of the window
static int wTy = 480;              // Vertical resolution of the window
static int wPx = 50;               // Horizontal position of the window
static int wPy = 50;               // Vertical position of the window

static int anim = 0;               // Flag for enabling/disabling animation
static int polygonMode = 1;        // Flag for switching between wireframe and fill display modes
static int materialLightMode = 1;
static int light1 = 0;
static int light2 = 1;
static int light3 = 1;
static int light4 = 0;
static int normalize = 1;          // Flag for switching with and without normalization
static int fond = 1;               // Flag for switching between black and light gray background colors
static int culling = 0;            // Flag for switching between display with and without culling
static int fullscreen = 0;
static int cameraPerspect = 1;
static int cameraOnCurrentPlayer = 0;

static float scenerySize = 100.0F; // Size of one face of a cube
static int facetNumber = 20;       // Level of faceting

#ifndef M_PI 
#define M_PI 3.14159
#endif

#endif // !SETTINGS_H