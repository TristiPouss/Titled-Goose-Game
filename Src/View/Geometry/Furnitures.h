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

void drawDice(float diceEdgeLength, float diceRadius, int facetNumber);

void drawLitVoiture(float horizontalEdgeLength, float depthEdgeLength, int facetNumber);

void drawCubeStack(float l, int facetNumber, GLuint *texture1, GLuint *texture2, GLuint *texture3);

void drawKaplaTowerSpiral(float l, int nbKapla, int facetNumber);

void drawKaplaTower(float l, int height, int facetNumber);

void drawCastle(float l, int facetNumber);

void drawCell(float l, int facetNumber);
void drawGooseCell(float l, int facetNumber);
void drawTrapCell(float l, int facetNumber);
void drawTeleportCell(float l, int facetNumber);

void drawShelf(float l, int facetNumber);

void drawDoor(float h, int facetNumber);

void drawPoster(float width, float height, int facetNumber, GLuint texture);

#endif // !FURNITURES_H
