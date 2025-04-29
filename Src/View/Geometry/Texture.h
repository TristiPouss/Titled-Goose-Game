#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdlib.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "PNG/ChargePngFile.h"

extern GLuint texturesTest[6];
extern GLuint texturesRoom[6];
extern GLuint texturesTableTop[6];
extern GLuint texturesTableLeg[6];
extern GLuint texturesDiceFaces[6];

extern GLuint texturesYellow[6];
extern GLuint texturesRed[6];
extern GLuint texturesGreen[6];
extern GLuint texturesBlue[6];
extern GLuint texturesPurple[6];

extern GLuint textureWall;
extern GLuint textureFloor;
extern GLuint textureTest;
extern GLuint textureWood;
extern GLuint textureTableFeet;
extern GLuint textureTablePlate;
extern GLuint textureKaaris;
extern GLuint textureEvanescence;
extern GLuint texturePulp;
extern GLuint textureFenetre;

extern GLuint textureRed;
extern GLuint textureGreen;
extern GLuint textureBlue;
extern GLuint textureYellow;
extern GLuint texturePurple;

extern GLuint textureCubeRed;
extern GLuint textureCubeGreen;
extern GLuint textureCubeBlue;
extern GLuint textureCubeYellow;
extern GLuint textureCubePurple;

extern GLuint textureEdgeDice;
extern GLuint textureCornerDice;

unsigned int chargementTexturePNG(char *filename);
void initTexture();

#endif // !TEXTURE_H