#include "Shapes.h"

void draw_cube(float edge_length, int facet_number) {
    glPushMatrix();

    // Origin setup
    glTranslatef(0.0F, -edge_length / 2, 0.0F);

    // Up
    glPushMatrix();

    glTranslatef(-edge_length / 2, edge_length, -edge_length / 2);
    glRotatef(90, 1.0F, 0.0F, 0.0F);
    for (int j = 0; j < facet_number; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facet_number; i++) {
            glNormal3f(0.0F, 0.0F, -1.0F);
            //glColor3f(0.0F, 0.0F, 1.0F);

            glVertex3f(0, i * (edge_length / facet_number), 0);
            glVertex3f(edge_length / facet_number, i * (edge_length / facet_number), 0);
        }
        glEnd();
        glTranslatef(edge_length / facet_number, 0.0, 0.0);
    }

    glPopMatrix();

    // Down
    glPushMatrix();

    glTranslatef(-edge_length / 2, 0, edge_length / 2);
    glRotatef(-90, 1.0F, 0.0F, 0.0F);
    for (int j = 0; j < facet_number; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facet_number; i++) {
            glNormal3f(0.0F, 0.0F, -1.0F);
            //glColor3f(1.0F, 0.0F, 0.0F);

            glVertex3f(0, i * (edge_length / facet_number), 0);
            glVertex3f(edge_length / facet_number, i * (edge_length / facet_number), 0);
        }
        glEnd();
        glTranslatef(edge_length / facet_number, 0.0, 0.0);
    }

    glPopMatrix();

    // Left
    glPushMatrix();

    glTranslatef(-edge_length / 2, 0, edge_length / 2);
    glRotatef(90, 0.0F, 1.0F, 0.0F);
    for (int j = 0; j < facet_number; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facet_number; i++) {
            glNormal3f(0.0F, 0.0F, -1.0F);
            //glColor3f(0.0F, 0.0F, 1.0F);

            glVertex3f(0, i * (edge_length / facet_number), 0);
            glVertex3f(edge_length / facet_number, i * (edge_length / facet_number), 0);
        }
        glEnd();
        glTranslatef(edge_length / facet_number, 0.0, 0.0);
    }

    glPopMatrix();

    // Right
    glPushMatrix();

    glTranslatef(edge_length / 2, 0, -edge_length / 2);
    glRotatef(-90, 0.0F, 1.0F, 0.0F);
    for (int j = 0; j < facet_number; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facet_number; i++) {
            glNormal3f(0.0F, 0.0F, -1.0F);
            //glColor3f(0.0F, 0.0F, 1.0F);

            glVertex3f(0, i * (edge_length / facet_number), 0);
            glVertex3f(edge_length / facet_number, i * (edge_length / facet_number), 0);
        }
        glEnd();
        glTranslatef(edge_length / facet_number, 0.0, 0.0);
    }

    glPopMatrix();

    // Back
    glPushMatrix();

    glTranslatef(edge_length / 2, 0, edge_length / 2);
    glRotatef(180, 0.0F, 1.0F, 0.0F);
    for (int j = 0; j < facet_number; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facet_number; i++) {
            glNormal3f(0.0F, 0.0F, -1.0F);
            //glColor3f(0.0F, 0.0F, 1.0F);

            glVertex3f(0, i * (edge_length / facet_number), 0);
            glVertex3f(edge_length / facet_number, i * (edge_length / facet_number), 0);
        }
        glEnd();
        glTranslatef(edge_length / facet_number, 0.0, 0.0);
    }

    glPopMatrix();

    // Front
    glPushMatrix();

    glTranslatef(-edge_length / 2, 0, -edge_length / 2);
    for (int j = 0; j < facet_number; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facet_number; i++) {
            glNormal3f(0.0F, 0.0F, -1.0F);
            //glColor3f(0.0F, 1.0F, 0.0F);

            glVertex3f(0, i * (edge_length / facet_number), 0);
            glVertex3f(edge_length / facet_number, i * (edge_length / facet_number), 0);
        }
        glEnd();
        glTranslatef(edge_length / facet_number, 0.0, 0.0);
    }

    glPopMatrix();

    glPopMatrix();
}