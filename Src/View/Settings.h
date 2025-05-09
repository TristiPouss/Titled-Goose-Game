#ifndef SETTINGS_H
#define SETTINGS_H

#include "SceneSettings.h"

static float rx = 0.0F;            // Rotation angle of the scene around the x-axis
static float ry = 0.0F;            // Rotation angle of the scene around the y-axis
static float rz = 0.0F;            // Rotation angle of the scene around the z-axis
static float sens = 1.0F;          // Rotation sensitivity of the scene around the x-axis
static float mx = 0.0F;            // Movement length of the scene along the x-axis
static float my = 0.0F;            // Movement length of the scene along the y-axis
static float mz = 0.0F;            // Movement length of the scene along the z-axis
static float zoom = 2.86F;
static float zoomDefault = 2.86F; // Default zoom level of the scene

static int mouseActive = 0;        // Flag indicating whether the mouse is active (button pressed) or not
static int mouseX = 0;             // Last recorded x position of the mouse

static const int INIT_wTx = 480;              // Horizontal resolution of the window
static const int INIT_wTy = 480;              // Vertical resolution of the window
static int wPx = 50;               // Horizontal position of the window
static int wPy = 50;               // Vertical position of the window

static int anim = 0;               // Flag to enable/disable animation
static int polygonMode = 1;        // Flag to switch between wireframe and fill display modes
static int materialLightMode = 1;
static int light1 = 1;
static int light2 = 1;
static int normalize = 1;          // Flag to switch between normalized and non-normalized modes
static int fond = 1;               // Flag to switch between black and light gray background colors
static int culling = 0;            // Flag to switch between rendering with and without culling
static int fullscreen = 0;
static int texturesEnabled = 1;    // Flag to enable/disable textures
static int timeOfDay = 0;

static int facetNumber = 50;       // Level of tessellation

static const float FOV = 90.0F;          // Field of view for the perspective camera

static const float TIMER_TIMEOUT = 2.0F; // Timeout for the animation
static const float TIMER_DICE_ROLLING = 2.0F; // Timeout for the dice animation
static const float TIMER_DICE_SHOWING = 3.0F; // Timeout for the dice showing animation
static const float TIMER_CHANGE_TIME_OF_DAY = 100.0F; // Timeout for every tick of transition between day times

static int f_help = 1;            // Flag to enable/disable help display
static char* helpText[] = {
    "  - 'Esc'      : quit game",
    "  - 'Space'    : normalize toggle",
    "  - 'm'        : polygon mode toggle",
    "  - 'n'        : previous facetNumber",
    "  - 'N'        : next facetNumber ",
    "  - 'P'        : camera on current player toggle ",
    "  - 'O'        : camera on dice toggle ",
    "  - 'C'        : perspective camera toggle ()",
    "  - 'k'        : zoom out ",
    "  - 'K'        : zoom in ",
    "  - 'Z'        : move camera forward",
    "  - 'S'        : move camera backward ",
    "  - 'Q'        : move camera left ",
    "  - 'D'        : move camera right ",
    "  - 'Arrows'   : rotate around the camera's look point",
    "  - 'f'        : fullscreen mode ",
    "  - 'b'        : background color toggle ",
    "  - 'c'        : culling toggle ",
    "  - 'H'        : help toggle",
    "  - 'V'        : play turn",
    "  - 'r'        : reset game ",
    "  - 'R'        : reset zoom, rotation and modifications to camera ",
    "  - 'F1, F2'   : Lights 1 and 2 toggle",
    "  - 'F10'      : lighthing toggle",
    "  - 'T'        : textures toggle"
};

#ifndef M_PI 
#define M_PI 3.14159
#endif

#endif // !SETTINGS_H