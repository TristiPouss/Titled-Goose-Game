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
void draw_cube(float edge_length, int facet_number);

#endif // !SHAPES_H