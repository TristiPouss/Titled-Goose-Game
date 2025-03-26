#include "Shapes.h"

void draw_cube(float c, int n) {
    glPushMatrix();

    // Up
    glPushMatrix();

    glTranslatef(-c / 2, c, -c / 2);
    glRotatef(90, 1.0F, 0.0F, 0.0F);
    for (int j = 0; j < n; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= n; i++) {
            glNormal3f(0.0F, 0.0F, -1.0F);
            //glColor3f(0.0F, 0.0F, 1.0F);

            glVertex3f(0, i * (c / n), 0);
            glVertex3f(c / n, i * (c / n), 0);
        }
        glEnd();
        glTranslatef(c / n, 0.0, 0.0);
    }

    glPopMatrix();

    // Down
    glPushMatrix();

    glTranslatef(-c / 2, 0, c / 2);
    glRotatef(-90, 1.0F, 0.0F, 0.0F);
    for (int j = 0; j < n; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= n; i++) {
            glNormal3f(0.0F, 0.0F, -1.0F);
            //glColor3f(1.0F, 0.0F, 0.0F);

            glVertex3f(0, i * (c / n), 0);
            glVertex3f(c / n, i * (c / n), 0);
        }
        glEnd();
        glTranslatef(c / n, 0.0, 0.0);
    }

    glPopMatrix();

    // Left
    glPushMatrix();

    glTranslatef(-c / 2, 0, c / 2);
    glRotatef(90, 0.0F, 1.0F, 0.0F);
    for (int j = 0; j < n; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= n; i++) {
            glNormal3f(0.0F, 0.0F, -1.0F);
            //glColor3f(0.0F, 0.0F, 1.0F);

            glVertex3f(0, i * (c / n), 0);
            glVertex3f(c / n, i * (c / n), 0);
        }
        glEnd();
        glTranslatef(c / n, 0.0, 0.0);
    }

    glPopMatrix();

    // Right
    glPushMatrix();

    glTranslatef(c / 2, 0, -c / 2);
    glRotatef(-90, 0.0F, 1.0F, 0.0F);
    for (int j = 0; j < n; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= n; i++) {
            glNormal3f(0.0F, 0.0F, -1.0F);
            //glColor3f(0.0F, 0.0F, 1.0F);

            glVertex3f(0, i * (c / n), 0);
            glVertex3f(c / n, i * (c / n), 0);
        }
        glEnd();
        glTranslatef(c / n, 0.0, 0.0);
    }

    glPopMatrix();

    // Back
    glPushMatrix();

    glTranslatef(c / 2, 0, c / 2);
    glRotatef(180, 0.0F, 1.0F, 0.0F);
    for (int j = 0; j < n; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= n; i++) {
            glNormal3f(0.0F, 0.0F, -1.0F);
            //glColor3f(0.0F, 0.0F, 1.0F);

            glVertex3f(0, i * (c / n), 0);
            glVertex3f(c / n, i * (c / n), 0);
        }
        glEnd();
        glTranslatef(c / n, 0.0, 0.0);
    }

    glPopMatrix();

    // Front
    glPushMatrix();

    glTranslatef(-c / 2, 0, -c / 2);
    for (int j = 0; j < n; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= n; i++) {
            glNormal3f(0.0F, 0.0F, -1.0F);
            //glColor3f(0.0F, 1.0F, 0.0F);

            glVertex3f(0, i * (c / n), 0);
            glVertex3f(c / n, i * (c / n), 0);
        }
        glEnd();
        glTranslatef(c / n, 0.0, 0.0);
    }

    glPopMatrix();

    glPopMatrix();
}