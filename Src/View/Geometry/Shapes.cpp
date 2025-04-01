#include "Shapes.h"
#include "../Colors.h"

void drawCube(float edgeLength, int facetNumber, int normalDirection, GLuint textures[6]) {
    float normal = (normalDirection) ? -0.1F : 0.1F;

    glPushMatrix();

    // Origin setup
    //glTranslatef(0.0F, -edgeLength / 2, 0.0F);

    // Up
    glPushMatrix();
    glTranslatef(-edgeLength / 2, edgeLength, -edgeLength / 2);
    glRotatef(90, 1.0F, 0.0F, 0.0F);
    if (textures && textures[0] != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[0]);
    }
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glTexCoord2f(j / (float)facetNumber, i / (float)facetNumber);
            glVertex3f(0, i * (edgeLength / facetNumber), 0);
            glTexCoord2f((j + 1) / (float)facetNumber, i / (float)facetNumber);
            glVertex3f(edgeLength / facetNumber, i * (edgeLength / facetNumber), 0);
        }
        glEnd();
        glTranslatef(edgeLength / facetNumber, 0.0, 0.0);
    }
    if (textures && textures[0] != 0) {
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

    // Down
    glPushMatrix();
    glTranslatef(-edgeLength / 2, 0, edgeLength / 2);
    glRotatef(-90, 1.0F, 0.0F, 0.0F);
    if (textures && textures[1] != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[1]);
    }
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glTexCoord2f(j / (float)facetNumber, i / (float)facetNumber);
            glVertex3f(0, i * (edgeLength / facetNumber), 0);
            glTexCoord2f((j + 1) / (float)facetNumber, i / (float)facetNumber);
            glVertex3f(edgeLength / facetNumber, i * (edgeLength / facetNumber), 0);
        }
        glEnd();
        glTranslatef(edgeLength / facetNumber, 0.0, 0.0);
    }
    if (textures && textures[1] != 0) {
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

    // Left
    glPushMatrix();
    glTranslatef(-edgeLength / 2, 0, edgeLength / 2);
    glRotatef(90, 0.0F, 1.0F, 0.0F);
    if (textures && textures[2] != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[2]);
    }
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glTexCoord2f(j / (float)facetNumber, i / (float)facetNumber);
            glVertex3f(0, i * (edgeLength / facetNumber), 0);
            glTexCoord2f((j + 1) / (float)facetNumber, i / (float)facetNumber);
            glVertex3f(edgeLength / facetNumber, i * (edgeLength / facetNumber), 0);
        }
        glEnd();
        glTranslatef(edgeLength / facetNumber, 0.0, 0.0);
    }
    if (textures && textures[2] != 0) {
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

    // Right
    glPushMatrix();
    glTranslatef(edgeLength / 2, 0, -edgeLength / 2);
    glRotatef(-90, 0.0F, 1.0F, 0.0F);
    if (textures && textures[3] != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[3]);
    }
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glTexCoord2f(j / (float)facetNumber, i / (float)facetNumber);
            glVertex3f(0, i * (edgeLength / facetNumber), 0);
            glTexCoord2f((j + 1) / (float)facetNumber, i / (float)facetNumber);
            glVertex3f(edgeLength / facetNumber, i * (edgeLength / facetNumber), 0);
        }
        glEnd();
        glTranslatef(edgeLength / facetNumber, 0.0, 0.0);
    }
    if (textures && textures[3] != 0) {
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

    // Back
    glPushMatrix();
    glTranslatef(edgeLength / 2, 0, edgeLength / 2);
    glRotatef(180, 0.0F, 1.0F, 0.0F);
    if (textures && textures[4] != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[4]);
    }
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glTexCoord2f(j / (float)facetNumber, i / (float)facetNumber);
            glVertex3f(0, i * (edgeLength / facetNumber), 0);
            glTexCoord2f((j + 1) / (float)facetNumber, i / (float)facetNumber);
            glVertex3f(edgeLength / facetNumber, i * (edgeLength / facetNumber), 0);
        }
        glEnd();
        glTranslatef(edgeLength / facetNumber, 0.0, 0.0);
    }
    if (textures && textures[4] != 0) {
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

    // Front
    glPushMatrix();
    glTranslatef(-edgeLength / 2, 0, -edgeLength / 2);
    if (textures && textures[5] != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[5]);
    }
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glTexCoord2f(j / (float)facetNumber, i / (float)facetNumber);
            glVertex3f(0, i * (edgeLength / facetNumber), 0);
            glTexCoord2f((j + 1) / (float)facetNumber, i / (float)facetNumber);
            glVertex3f(edgeLength / facetNumber, i * (edgeLength / facetNumber), 0);
        }
        glEnd();
        glTranslatef(edgeLength / facetNumber, 0.0, 0.0);
    }
    if (textures && textures[5] != 0) {
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

    glPopMatrix();
}

void drawCircle(float cx, float cy, float r, int num_segments) {
    glPushMatrix();
    double twicePi = 2.0 * M_PI;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(cx, cy); // center of circle
    for (int i = 0; i <= num_segments; i++) {
        glVertex2f(
            (cy + (r * sin(i * twicePi / num_segments))), (cx + (r * cos(i * twicePi / num_segments)))
        );
    }
    glEnd(); //END
    glPopMatrix();
}

void drawCylinder(float rTop, float rBot, float h, int n, int m) {
    glPushMatrix();

    glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
    glTranslatef(0.0F, 0.0F, -h);

    glPushMatrix();
    drawCircle(0.0F, 0.0F, rTop, n); // Top Circle
    glTranslatef(0.0F, 0.0F, h);
    drawCircle(0.0F, 0.0F, rBot, n); // Bottom Circle
    glPopMatrix();

    glPushMatrix();
    GLUquadricObj* qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluCylinder(qobj, rTop, rBot, h, n, m);
    gluDeleteQuadric(qobj);
    glPopMatrix();

    glPopMatrix();
}