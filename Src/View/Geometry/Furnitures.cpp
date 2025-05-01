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

void drawDice(float diceEdgeLength, float diceRadius, int facetNumber) {
	glPushMatrix();
	drawRoundedCube(diceEdgeLength, diceRadius, facetNumber, 1, texturesDiceFaces, textureEdgeDice, textureCornerDice, 1);
	glPopMatrix();
}

void drawPawn(float horizontalEdgeLength, int facetNumber, GLuint textureID) {
	glPushMatrix();

	float verticalEdgeLength = horizontalEdgeLength * 2.5;

	// Head Sphere
	float headRadius = horizontalEdgeLength / 2;
	float headHeight = verticalEdgeLength - headRadius;
	glTranslatef(0.0F, headHeight, 0.0F);
	drawSphere(headRadius, facetNumber, textureID);
	glTranslatef(0.0F, -headHeight, 0.0F);

	// Base Cylinder
	float baseHeight = headHeight - headRadius;
	float baseRadius = horizontalEdgeLength;
	drawCylinder(headRadius / 2, baseRadius, baseHeight, facetNumber, facetNumber, textureID, textureID, textureID);

	// Head Torus
	float headTorusInnerRadius = headRadius / 5;
	float headTorusOuterRadius = headRadius / 2;
	glTranslatef(0.0F, baseHeight, 0.0F);
	glRotatef(90.0, 1.0F, 0.0F, 0.0F);
	drawTorus(headTorusInnerRadius, headTorusOuterRadius, facetNumber, textureID);
	glRotatef(-90.0, 1.0F, 0.0F, 0.0F);
	glTranslatef(0.0F, -baseHeight, 0.0F);

	// Base Cylinder
	drawCylinder(baseRadius, baseRadius, baseHeight / 7, facetNumber, facetNumber, textureID, textureID, textureID);

	glPopMatrix();
}

void drawLitVoiture(float horizontalEdgeLength, float depthEdgeLength, int facetNumber) {
	glPushMatrix();

	float verticalEdgeLength = horizontalEdgeLength * 0.3;
	float thinEdge = horizontalEdgeLength * 0.01;

	// Left Side
	glPushMatrix();
	glTranslatef(0.0F, 0.0F, -depthEdgeLength / 2 + thinEdge / 4);
	glScalef(1.0F, (verticalEdgeLength - verticalEdgeLength / 4) / horizontalEdgeLength, thinEdge / horizontalEdgeLength);
	drawCube(horizontalEdgeLength, facetNumber, 1, texturesRed);
	glPopMatrix();

	// Right Side
	glPushMatrix();
	glTranslatef(0.0F, 0.0F, depthEdgeLength / 2 - thinEdge / 4);
	glScalef(1.0F, (verticalEdgeLength - verticalEdgeLength / 4) / horizontalEdgeLength, thinEdge / horizontalEdgeLength);
	drawCube(horizontalEdgeLength, facetNumber, 1, texturesRed);
	glPopMatrix();

	// Back Side
	glPushMatrix();
	glTranslatef(-horizontalEdgeLength / 2 + thinEdge / 2, 0.0F, 0.0F);
	glScalef(thinEdge / depthEdgeLength, (verticalEdgeLength - verticalEdgeLength * 0.1) / depthEdgeLength, 1.0F);
	drawCube(depthEdgeLength, facetNumber, 1, texturesRed);
	glPopMatrix();

	// Front Side
	GLuint texturesFront[6] = { textureRed,textureRed,textureRed,textureRed,textureMcqueenFace,textureRed };
	glPushMatrix();
	glTranslatef(horizontalEdgeLength / 2 - thinEdge / 2, 0.0F, 0.0F);
	glRotatef(45, 0.0F, 0.0F, 1.0F);
	glScalef(thinEdge / depthEdgeLength, verticalEdgeLength / depthEdgeLength, 1.0F);
	drawCube(depthEdgeLength, facetNumber, 1, texturesFront, 0.1);
	glPopMatrix();

	// Top Side
	glPushMatrix();
	glTranslatef(-horizontalEdgeLength/12, verticalEdgeLength / 2 - thinEdge / 2, 0.0F);
	glScalef((horizontalEdgeLength - horizontalEdgeLength/6) / depthEdgeLength, thinEdge / horizontalEdgeLength, 1.0F);
	drawCube(depthEdgeLength, facetNumber, 1, texturesWhite, 4.0);
	glPopMatrix();

	// Cushion
	glPushMatrix();
	glTranslatef(- depthEdgeLength + depthEdgeLength * 0.1, verticalEdgeLength / 2 - thinEdge / 2 + depthEdgeLength * 0.05, - depthEdgeLength / 2);
	glRotatef(90, 1.0F, 0.0F, 0.0F);
	drawCylinder(depthEdgeLength*0.1, depthEdgeLength * 0.1, depthEdgeLength, facetNumber, facetNumber, textureCubeWhite, textureCubeWhite, textureCubeWhite);
	glPopMatrix();

	glPopMatrix();
}

void drawCubeStack(float l, int facetNumber, GLuint *texture1, GLuint *texture2, GLuint *texture3) {
	glPushMatrix();

	glTranslatef(-l * 0.75, 0.0F, 0.0F); 
	glRotatef(10, 0.0F, 1.0F, 0.0F);
	drawCube(l, facetNumber, 1, texture1);
	glRotatef(-10, 0.0F, 1.0F, 0.0F);

	glTranslatef(l * 1.5, 0.0F, 0.0F);
	drawCube(l, facetNumber, 1, texture2);
	
	glTranslatef(-l * 0.75, l, 0.0F);
	glRotatef(20, 0.0F, 1.0F, 0.0F);
	drawCube(l, facetNumber, 1, texture3);
	glRotatef(20, 0.0F, 1.0F, 0.0F);

	glPopMatrix();
}

void drawKaplaTowerSpiral(float l, int nbKapla, int facetNumber) {
	float L = l/4;
	float h = l/10;

	glPushMatrix();

	for (int i = 0; i < nbKapla; i++) {
		drawCuboid(l,h,L,facetNumber, 1, texturesTableTop, 1.0F);
		glTranslatef(0.0F, h, 0.0F);
		glRotatef(25.0F, 0.0F, 1.0F, 0.0F);
	}

	glPopMatrix();
}

void drawKaplaTower(float l, int height, int facetNumber) {
	float h = l/4;
	float L = l/10;
	float offset = L;

	glPushMatrix();

	for (int i = 0; i < height; i++) {
		glTranslatef(0.0F, 0.0F, l/2 - offset);
		drawCuboid(l,h,L,facetNumber, 1, texturesTableTop, 1.0F);
		glTranslatef(0.0F, 0.0F, -l + offset*2);
		drawCuboid(l,h,L,facetNumber, 1, texturesTableTop, 1.0F);
		glTranslatef(0.0F, h, l/2 - offset);
		glRotatef(90.0F, 0.0F, 1.0F, 0.0F);
	}

	glPopMatrix();
}

void drawCastle(float l, int facetNumber) {
	float L = l/3;
	float h = L/2;
	float r = L/3;

	glPushMatrix();

	glTranslatef(-L, 0.0F, 0.0F);
	drawCube(L,facetNumber, 1, texturesBlue);
	glTranslatef(L*2, 0.0F, 0.0F);
	drawCube(L,facetNumber, 1, texturesGreen);
	glTranslatef(-L, L, 0.0F);
	drawCuboid(l,h,L,facetNumber, 1, texturesYellow, 1.0F);
	
	glTranslatef(-L, h, 0.0F);
	drawCylinder(r, r, L*2, facetNumber, facetNumber, textureRed, textureRed, textureRed);
	glTranslatef(L*2, 0.0F, 0.0F);
	drawCylinder(0, h, L, facetNumber, facetNumber, textureBlue, textureBlue, textureBlue);
	glTranslatef(-L*2, L*2, 0.0F);
	drawCylinder(0, h, L, facetNumber, facetNumber, textureYellow, textureYellow, textureYellow);

	glPopMatrix();
}

void drawCell(float l, int facetNumber) {
	float x = l/10;
	drawCylinder(l, l, x, facetNumber, facetNumber);
	drawCylinder(l-x, l-x, x+x, facetNumber, facetNumber, textureBlue, textureBlue, textureBlue);
}

void drawGooseCell(float l, int facetNumber) {
	float x = l/10;
	drawCylinder(l, l, x, facetNumber, facetNumber);
	drawCylinder(l-x, l-x, x+x, facetNumber, facetNumber, textureGreen, textureGreen, textureGreen);
}

void drawTrapCell(float l, int facetNumber) {
	float x = l/10;
	drawCylinder(l, l, x, facetNumber, facetNumber);
	drawCylinder(l-x, l-x, x+x, facetNumber, facetNumber, textureRed, textureRed, textureRed);
}

void drawTeleportCell(float l, int facetNumber) {
	float x = l/10;
	drawCylinder(l, l, x, facetNumber, facetNumber);
	drawCylinder(l-x, l-x, x+x, facetNumber, facetNumber, texturePurple, texturePurple, texturePurple);
}

void drawShelf(float l, int facetNumber) {
	float L = l/4;
	float x = L/4;

	glPushMatrix();

	for (int i = 0; i < 3; i++) {
		drawCuboid(l, x, L, facetNumber, 1, texturesTableLeg, 1.0F);
		glTranslatef(-l/2 + x/2, x, 0.0F); 
		for (int i = 0; i < 4; i++) {
			drawCuboid(x, L, L, facetNumber, 1, texturesTableLeg, 1.0F);
			glTranslatef(L + x, 0.0F, 0.0F); 
		}
		glTranslatef(-l/2 - L - x/2, L, 0.0F); 
	}
	drawCuboid(l, x, L, facetNumber, 1, texturesTableLeg, 1.0F);

	glPopMatrix();
}

void drawDoor(float h, int facetNumber) {
	float l = h/2;
	float L = l/10;

	glPushMatrix();
	drawCuboid(l, h, L, facetNumber, 1, texturesTableLeg, 1.0F);
	glTranslatef(-l/3, h/2, 0.0F);
	drawSphere(L, facetNumber);
	glPopMatrix();
}

void drawPoster(float width, float height, int facetNumber, GLuint texture) {
	GLuint textures[6] = {0,0,0,0,0,texture};
    float L = width/50;
	glPushMatrix();
	drawCuboid(width, height, L, facetNumber, 1, textures, 1.0F);
    glPopMatrix();
}
