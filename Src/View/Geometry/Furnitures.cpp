#include "Furnitures.h"
#include "Shapes.h"

void tableLeg(float tableLegHeight, float tableLegWidth, int facetNumber) {
	glPushMatrix();
	glScalef(tableLegWidth, 1.0F, tableLegWidth);
	drawCube(tableLegHeight - 1.0F, facetNumber, 1, texturesTableLeg);
	glPopMatrix();
}

void tableTop(float tableTopLength, float tableTopWidth, int facetNumber) {
	glPushMatrix();
	glScalef(1.0F, tableTopWidth / tableTopLength, 1.0F);
	drawCube(tableTopLength, facetNumber, 1, texturesTableTop);
	glPopMatrix();
}

/* Draws a table with a center at the center of the (X,Z) 2D plane */
void drawTable(float verticalEdgeLength, float horizontalEdgeLength, int facetNumber) {
	glPushMatrix();

	float tableLegHeight = verticalEdgeLength;
	float tableLegWidth = horizontalEdgeLength * 0.2F;

	for (size_t i = 0; i < 4; i++){
		glPushMatrix();

		glRotatef(90 * i, 0.0F, 1.0F, 0.0F);
		glTranslatef(horizontalEdgeLength / 2 - tableLegWidth, 0.0F, horizontalEdgeLength / 2 - tableLegWidth);
		tableLeg(tableLegHeight, tableLegWidth / verticalEdgeLength, facetNumber);

		glPopMatrix();
	}

	float tableTopWidth = verticalEdgeLength * 0.2F;
	float tableTopLength = horizontalEdgeLength;

	glTranslatef(0.0F, verticalEdgeLength - tableTopWidth, 0.0F);
	tableTop(tableTopLength, tableTopWidth, facetNumber);

	glPopMatrix();
}

void drawPawn(float horizontalEdgeLength, int facetNumber, GLuint textureID) {
	glPushMatrix();

	float verticalEdgeLength = horizontalEdgeLength * 2.5;

	// Head Sphere
	float headRadius = horizontalEdgeLength / 2;
	float headHeight = verticalEdgeLength - headRadius;
	glPushMatrix();
	glTranslatef(0.0F, headHeight, 0.0F);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glutSolidSphere(headRadius, facetNumber, facetNumber);
	glPopMatrix();

	// Base Cylinder
	float baseHeight = headHeight - headRadius;
	float baseRadius = horizontalEdgeLength;
	drawCylinder(headRadius / 2, baseRadius, baseHeight, facetNumber, facetNumber, textureID, textureID, textureID);

	// Head Torus
	float headTorusInnerRadius = headRadius / 5;
	float headTorusOuterRadius = headRadius / 2;
	glPushMatrix();
	glTranslatef(0.0F, baseHeight, 0.0F);
	glRotatef(90.0, 1.0F, 0.0F, 0.0F);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glutSolidTorus(headTorusInnerRadius, headTorusOuterRadius, facetNumber, facetNumber);
	glPopMatrix();

	// Base Cylinder
	glPushMatrix();
	drawCylinder(baseRadius, baseRadius, baseHeight / 7, facetNumber, facetNumber, textureID, textureID, textureID);
	glPopMatrix();

	glPopMatrix();
}

void drawLitVoiture(float horizontalEdgeLength, int facetNumber) {
	glPushMatrix();

	float verticalEdgeLength = horizontalEdgeLength * 2.5;

	float thinEdge = 2.0F;
	
	// Side
	glPushMatrix();
	glScalef(thinEdge / horizontalEdgeLength, 1.0F, 1.0F);
	drawCube(horizontalEdgeLength, facetNumber);
	glPopMatrix();

	glPopMatrix();
}