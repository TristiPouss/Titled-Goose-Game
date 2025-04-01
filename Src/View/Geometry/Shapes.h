/* Author : Tristan de Saint Gilles */

#ifndef SHAPES_H
#define SHAPES_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../Settings.h"

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

/*
    Function to draw a edge_length*edge_length cube with a facetisation level of facet_number
*/
void drawCube(float edgeLength, int facetNumber, int normalDirection = 1);

void drawCircle(float cx, float cy, float r, int num_segments);

/*
    Function to draw a cylinder
*/
void drawCylinder(float r, float h, int n, int m);

#endif // !SHAPES_H