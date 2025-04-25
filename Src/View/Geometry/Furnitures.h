/* Author : Tristan de Saint Gilles */

#ifndef FURNITURES_H
#define FURNITURES_H

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Texture.h"

void tableLeg(float tableLegHeight, float tableLegWidth, int facetNumber);

void tableTop(float tableTopHeight, float tableTopWidth, int facetNumber);

void drawTable(float verticalEdgeLength, float horizontalEdgeLength, int facetNumber);

void drawPawn(float horizontalEdgeLength, int facetNumber, GLuint textureID = 0);

void drawLitVoiture(float horizontalEdgeLength, int facetNumber);

void drawCubeStack(float l, int facetNumber);

void drawKaplaTowerSpiral(float l, int nbKapla, int facetNumber);

void drawKaplaTower(float l, int height, int facetNumber);

void drawCastle(float l, int facetNumber);

#endif // !FURNITURES_H
