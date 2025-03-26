/* Author : Tristan de Saint Gilles */

#ifndef SHAPES_H
#define SHAPES_H

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

/*
    Function to draw a edge_length*edge_length cube with a facetisation level of facet_number
*/
void drawCube(float edgeLength, int facetNumber);

#endif // !SHAPES_H