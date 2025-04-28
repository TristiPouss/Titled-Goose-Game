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

extern GLuint texturesYellow[6];
extern GLuint texturesRed[6];
extern GLuint texturesGreen[6];
extern GLuint texturesBlue[6];

extern GLuint textureWall;
extern GLuint textureFloor;
extern GLuint textureTest;
extern GLuint textureWood;
extern GLuint textureTable;

extern GLuint textureRed;
extern GLuint textureGreen;
extern GLuint textureBlue;
extern GLuint textureYellow;

unsigned int chargementTexturePNG(char *filename);
void initTexture();

#endif // !TEXTURE_H