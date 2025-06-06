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
void drawCube(float edgeLength, int facetNumber, int normalDirection = 1, GLuint textures[6] = nullptr, float ratioTexture=1.0F);

void drawPlane(float edgeLength,int facetNumber,float normal,float ratioTexture);
void drawCenteredPlane(float edgeLength,int facetNumber,float normal,float ratioTexture);

void drawCircle(float originX, float originY, float radius, int facetNumber);

/*
    Function to draw a cylinder
*/
void drawCylinder(float topRadius, float botRadius, float height, int facetNumberX, int facetNumberY, GLuint sideTexture = 0, GLuint topTexture = 0, GLuint botTexture = 0);

void drawSphere(float radius, int facetNumber, GLuint texture = 0);

void drawTorus(float innerRadius, float outerRadius, int facetNumber, GLuint texture = 0);

void drawCuboid(float width, float height, float depth, int facetNumber, int normalDirection = 1, GLuint textures[6] = nullptr, float ratioTexture=1.0F);

void drawRoundedCube(float edgeLength,float radius, int facetNumber, int normalDirection = 1,GLuint facesTextures[6] = nullptr, GLuint edgesTexture = 0, GLuint cornersTexture = 0 , float ratioTexture = 1.0F);

#endif // !SHAPES_H