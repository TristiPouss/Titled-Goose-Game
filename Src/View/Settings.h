#ifndef SETTINGS_H
#define SETTINGS_H

static float rx = 0.0F;            // Angle de rotation de la scene sur elle-meme autour de l'axe x
static float ry = 0.0F;            // Angle de rotation de la scene sur elle-meme autour de l'axe y
static float rz = 0.0F;            // Angle de rotation de la scene sur elle-meme autour de l'axe z
static float sens = 1.0F;          // Sens de rotation de la scene sur elle-meme autour de l'axe x
static float zoom = 2.6F;

static int mouseActive = 0;        // Flag de d'indication que la souris est active (bouton presse) ou non 
static int mouseX = 0;             // Derniere position en x relevee pour la souris

static int wTx = 480;              // Resolution horizontale de la fenetre
static int wTy = 480;              // Resolution verticale de la fenetre
static int wPx = 50;               // Position horizontale de la fenetre
static int wPy = 50;               // Position verticale de la fenetre

static int anim = 0;               // Flag d'activation/desactivation de l'animation
static int polygonMode = 1;        // Flag de switch entre modes d'affichage wireframe et fill 
static int materialLightMode = 1;
static int light1 = 1;
static int light2 = 1;
static int light3 = 1;
static int light4 = 0;
static int normalize = 1;          // Flag de switch avec et sans normalisation
static int fond = 1;               // Flag de switch entre couleurs de fond noir et gris clair
static int culling = 0;            // Flag de switch entre affichages avec et sans culling
static int fullscreen = 0;
static int cameraPerspect = 1;

static float c = 100.0F;            // Taille de la face d'un cube
static int n = 50;                 // Niveau de facettisation

#ifndef M_PI
#define M_PI 3.14159
#endif

#endif // !SETTINGS_H
