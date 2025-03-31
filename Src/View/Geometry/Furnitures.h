/* Author : Tristan de Saint Gilles */

#ifndef FURNITURES_H
#define FURNITURES_H

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void tableLeg(float tableLegHeight, float tableLegWidth, int facetNumber);

void tableTop(float tableTopHeight, float tableTopWidth, int facetNumber);

void drawTable(float verticalEdgeLength, float horizontalEdgeLength, int facetNumber);

void room_skeleton(float edgeLength, int facetNumber);

#endif // !FURNITURES_H
