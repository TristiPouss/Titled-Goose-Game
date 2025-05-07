#ifndef MATERIALS_H
#define MATERIALS_H

#include <stdlib.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

extern GLfloat no_mat[4];
extern GLfloat full_mat[4];

void resetMaterial();

void setPlasticMaterial(int number = -1);

void setWoodMaterial();

void setWallMaterial();

#endif // !MATERIALS_H
