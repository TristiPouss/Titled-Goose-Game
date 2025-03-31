#include "Furnitures.h"
#include "Shapes.h"

void tableLeg(float tableLegHeight, float tableLegWidth, int facetNumber) {
	glPushMatrix();

	glTranslatef(0.0F, tableLegHeight /2, 0.0F);
	glScalef(tableLegWidth, 1.0F, tableLegWidth);
	drawCube(tableLegHeight, facetNumber);

	glPopMatrix();
}

void tableTop(float tableTopLength, float tableTopWidth, int facetNumber) {
	glPushMatrix();

	glTranslatef(0.0F, tableTopWidth, 0.0F);
	glScalef(1.0F, tableTopWidth / tableTopLength, 1.0F);
	drawCube(tableTopLength, facetNumber);

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

void room_skeleton(float c, int n) {
    glPushMatrix();

    GLfloat wallColor[] = { 0.0, 1.0, 0.0, 1.0 }; // Couleur verte pour les murs
    GLfloat floorColor[] = { 1.0, 0.0, 0.0, 1.0 }; // Couleur rouge pour le sol

    // Floor
    glPushMatrix();

    glTranslatef(-c / 2, 0, c / 2);
    glRotatef(-90, 1.0F, 0.0F, 0.0F);
    for (int j = 0; j < n; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= n; i++) {
            glNormal3f(0.0F, 0.0F, 1.0F);
            glColor3f(1.0F, 0.0F, 0.0F);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, floorColor);

            glVertex3f(0, i * (c / n), 0);
            glVertex3f(c / n, i * (c / n), 0);
        }
        glEnd();
        glTranslatef(c / n, 0.0, 0.0);
    }

    glPopMatrix();

    // Wall Left
    glPushMatrix();

    glTranslatef(-c / 2, 0, -c / 2);
    for (int j = 0; j < n; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= n; i++) {
            glNormal3f(0.0F, 1.0F, 0.0F);
            glColor3f(0.0F, 1.0F, 0.0F);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, wallColor);

            glVertex3f(0, i * (c / n), 0);
            glVertex3f(c / n, i * (c / n), 0);
        }
        glEnd();
        glTranslatef(c / n, 0.0, 0.0);
    }

    glPopMatrix();

    // Wall Right
    glPushMatrix();

    glTranslatef(c / 2, 0, -c / 2);
    glRotatef(-90, 0.0F, 1.0F, 0.0F);
    for (int j = 0; j < n; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= n; i++) {
            glNormal3f(0.0F, 1.0F, 0.0F);
            glColor3f(0.0F, 0.0F, 1.0F);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, wallColor);

            glVertex3f(0, i * (c / n), 0);
            glVertex3f(c / n, i * (c / n), 0);
        }
        glEnd();
        glTranslatef(c / n, 0.0, 0.0);
    }

    glPopMatrix();

    glPopMatrix();
}
