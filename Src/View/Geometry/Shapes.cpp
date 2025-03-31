#include "Shapes.h"
#include "../Colors.h"

void drawCube(float edgeLength, int facetNumber, int normalDirection) {
    float normal = (normalDirection) ? -0.1F : 0.1F;

    glPushMatrix();

    // Origin setup
    glTranslatef(0.0F, -edgeLength / 2, 0.0F);

    // Up
    glPushMatrix();

    glTranslatef(-edgeLength / 2, edgeLength, -edgeLength / 2);
    glRotatef(90, 1.0F, 0.0F, 0.0F);
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, red);

            glVertex3f(0, i * (edgeLength / facetNumber), 0);
            glVertex3f(edgeLength / facetNumber, i * (edgeLength / facetNumber), 0);
        }
        glEnd();
        glTranslatef(edgeLength / facetNumber, 0.0, 0.0);
    }

    glPopMatrix();

    // Down
    glPushMatrix();

    glTranslatef(-edgeLength / 2, 0, edgeLength / 2);
    glRotatef(-90, 1.0F, 0.0F, 0.0F);
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glMaterialfv(GL_FRONT, GL_DIFFUSE,blue);

            glVertex3f(0, i * (edgeLength / facetNumber), 0);
            glVertex3f(edgeLength / facetNumber, i * (edgeLength / facetNumber), 0);
        }
        glEnd();
        glTranslatef(edgeLength / facetNumber, 0.0, 0.0);
    }

    glPopMatrix();

    // Left
    glPushMatrix();

    glTranslatef(-edgeLength / 2, 0, edgeLength / 2);
    glRotatef(90, 0.0F, 1.0F, 0.0F);
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glMaterialfv(GL_FRONT, GL_DIFFUSE,green);

            glVertex3f(0, i * (edgeLength / facetNumber), 0);
            glVertex3f(edgeLength / facetNumber, i * (edgeLength / facetNumber), 0);
        }
        glEnd();
        glTranslatef(edgeLength / facetNumber, 0.0, 0.0);
    }

    glPopMatrix();

    // Right
    glPushMatrix();

    glTranslatef(edgeLength / 2, 0, -edgeLength / 2);
    glRotatef(-90, 0.0F, 1.0F, 0.0F);
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glMaterialfv(GL_FRONT, GL_DIFFUSE,pink);

            glVertex3f(0, i * (edgeLength / facetNumber), 0);
            glVertex3f(edgeLength / facetNumber, i * (edgeLength / facetNumber), 0);
        }
        glEnd();
        glTranslatef(edgeLength / facetNumber, 0.0, 0.0);
    }

    glPopMatrix();

    // Back
    glPushMatrix();

    glTranslatef(edgeLength / 2, 0, edgeLength / 2);
    glRotatef(180, 0.0F, 1.0F, 0.0F);
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glMaterialfv(GL_FRONT, GL_DIFFUSE,darkPurple);

            glVertex3f(0, i * (edgeLength / facetNumber), 0);
            glVertex3f(edgeLength / facetNumber, i * (edgeLength / facetNumber), 0);
        }
        glEnd();
        glTranslatef(edgeLength / facetNumber, 0.0, 0.0);
    }

    glPopMatrix();

    // Front
    glPushMatrix();

    glTranslatef(-edgeLength / 2, 0, -edgeLength / 2);
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glMaterialfv(GL_FRONT, GL_DIFFUSE,cyan);

            glVertex3f(0, i * (edgeLength / facetNumber), 0);
            glVertex3f(edgeLength / facetNumber, i * (edgeLength / facetNumber), 0);
        }
        glEnd();
        glTranslatef(edgeLength / facetNumber, 0.0, 0.0);
    }

    glPopMatrix();

    glPopMatrix();
}