#include "Shapes.h"
#include "../Colors.h"
#include <GL/gl.h>


void drawPlane(float edgeLength,int facetNumber,float normal,float ratioTexture){
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glTexCoord2f(j / (float)facetNumber * ratioTexture, i / (float)facetNumber * ratioTexture);
            glVertex3f(0, i * (edgeLength / facetNumber), 0);
            glTexCoord2f((j + 1) / (float)facetNumber * ratioTexture, i / (float)facetNumber * ratioTexture);
            glVertex3f(edgeLength / facetNumber, i * (edgeLength / facetNumber), 0);
        }
        glEnd();
        glTranslatef(edgeLength / facetNumber, 0.0, 0.0);
    }
}

void drawCenteredPlane(float edgeLength,int facetNumber,float normal,float ratioTexture){
    glPushMatrix();
    glTranslatef(-edgeLength/2, -edgeLength/2, 0);
    glPushMatrix();
    drawPlane(edgeLength,facetNumber, normal, ratioTexture);
    glPopMatrix();

    glPopMatrix();
}

void drawCube(float edgeLength, int facetNumber, int normalDirection, GLuint textures[6], float ratioTexture) {
    float normal = (normalDirection) ? -0.1F : 0.1F;
    GLUquadric* quadric = gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
    glPushMatrix();

    for (int i = 0; i < 6; i++) {
        glPushMatrix();

        // Position and orient the face
        switch (i) {
            case 0: // Front face
                glTranslatef(-edgeLength / 2, 0, -edgeLength / 2);
                break; 
            case 1: // Back face
                glTranslatef(edgeLength / 2, 0, edgeLength / 2);
                glRotatef(180, 0.0F, 1.0F, 0.0F);
                break; 
            case 2:  // Top face
                glTranslatef(-edgeLength / 2, edgeLength, -edgeLength / 2);
                glRotatef(90, 1.0F, 0.0F, 0.0F); 
                break; 

            case 3: // Bottom face
                glTranslatef(-edgeLength / 2, 0, edgeLength / 2);
                glRotatef(-90, 1.0F, 0.0F, 0.0F);
                break;
            
            case 4: //Right face
                glTranslatef(edgeLength / 2, 0, -edgeLength / 2);
                glRotatef(-90, 0.0F, 1.0F, 0.0F);
                break; 

            case 5: //Left face
                glTranslatef(-edgeLength / 2, 0, edgeLength / 2);
                glRotatef(90, 0.0F, 1.0F, 0.0F);
                break; 
        }
        if (textures && textures[i] != 0) {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, textures[i]);
        }
       drawPlane(edgeLength, facetNumber, normal, ratioTexture);
        if (textures && textures[i] != 0) {
            glDisable(GL_TEXTURE_2D);
        }

        glPopMatrix();
        
    }
  
    glPopMatrix();
    gluDeleteQuadric(quadric);
}
//A cube with (rounded) edges - modelized from the true center
void drawRoundedCube(float edgeLength, int facetNumber, int normalDirection,float radius, GLuint textures[6], float ratioTexture){
        float normal = (normalDirection) ? -0.1F : 0.1F;
        GLUquadric* quadric = gluNewQuadric();
        gluQuadricNormals(quadric, GLU_SMOOTH);
        glPushMatrix();
        float fullEdge = edgeLength + radius*2;
        float HalfEdge = edgeLength/2 + radius;
        // Draw the six faces of the cube with rounded edges
        for (int i = 0; i < 6; i++) {
            glPushMatrix();
    
           // Position and orient the face
            switch (i) {
                case 0: // Front face
                    glTranslatef(0, 0, -fullEdge / 2);
                    break; 
                case 1: // Back face
                    glTranslatef(0, 0, fullEdge / 2);
                    glRotatef(180, 0.0F, 1.0F, 0.0F);
                    break; 
                case 2:  // Top face
                    glTranslatef(0, fullEdge/2, 0);
                    glRotatef(90, 1.0F, 0.0F, 0.0F); 
                    break; 

                case 3: // Bottom face
                    glTranslatef(0, -fullEdge/2, 0);
                    glRotatef(-90, 1.0F, 0.0F, 0.0F);
                    break;
                
                case 4: //Right face
                    glTranslatef(fullEdge / 2, 0, 0);
                    glRotatef(-90, 0.0F, 1.0F, 0.0F);
                    break; 

                case 5: //Left face
                    glTranslatef(-fullEdge / 2, 0, 0);
                    glRotatef(90, 0.0F, 1.0F, 0.0F);
                    break; 
            }
    
            // Draw the face
            if (textures && textures[i] != 0) {
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, textures[i]);
            }
            drawCenteredPlane(edgeLength, facetNumber, normal, ratioTexture);
            if (textures && textures[i] != 0) {
                glDisable(GL_TEXTURE_2D);
            }
            glPopMatrix();
            // Draw the rounded edges
            
        }
    
        gluDeleteQuadric(quadric);
        glPopMatrix();
}


void drawCircle(float originX, float originY, float radius, int facetNumber, GLuint textureID = 0) {
    glPushMatrix();
    double twicePi = 2.0 * M_PI;

    if (textureID != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
    }

    glBegin(GL_TRIANGLE_FAN); // BEGIN CIRCLE
    glVertex2f(originX, originY); // center of circle
    for (int i = 0; i <= facetNumber; i++) {
        float x = originX + (radius * cos(i * twicePi / facetNumber));
        float y = originY + (radius * sin(i * twicePi / facetNumber));
        glTexCoord2f((x + radius) / (2 * radius), (y + radius) / (2 * radius));
        glVertex2f(y, x);
    }
    glEnd(); // END

    if (textureID != 0) {
        glDisable(GL_TEXTURE_2D);
    }

    glPopMatrix();
}

void drawCylinder(float topRadius, float botRadius, float height, int facetNumberX, int facetNumberY, GLuint sideTexture, GLuint topTexture, GLuint botTexture) {
    glPushMatrix();

    glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
    glTranslatef(0.0F, 0.0F, -height);

    // Draw top circle with texture
    glPushMatrix();
    drawCircle(0.0F, 0.0F, topRadius, facetNumberX, topTexture); // Top Circle
    glTranslatef(0.0F, 0.0F, height);
    drawCircle(0.0F, 0.0F, botRadius, facetNumberX, botTexture); // Bottom Circle
    glPopMatrix();

    // Draw cylinder body with texture
    glPushMatrix();
    GLUquadricObj* qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);
    gluQuadricDrawStyle(qobj, GLU_FILL);

    if (sideTexture != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, sideTexture);
    }

    gluCylinder(qobj, topRadius, botRadius, height, facetNumberX, facetNumberY);

    if (sideTexture != 0) {
        glDisable(GL_TEXTURE_2D);
    }

    gluDeleteQuadric(qobj);
    glPopMatrix();

    glPopMatrix();
}

void drawSphere(float radius, int facetNumber, GLuint texture) {
    glPushMatrix();

    GLUquadricObj* qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);
    gluQuadricDrawStyle(qobj, GLU_FILL);

    if (texture != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
    }

    gluSphere(qobj, radius, facetNumber, facetNumber);

    if (texture != 0) {
        glDisable(GL_TEXTURE_2D);
    }

    gluDeleteQuadric(qobj);
    glPopMatrix();
}

void drawTorus(float innerRadius, float outerRadius, int facetNumber, GLuint texture) {
    glPushMatrix();

    if (texture != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
    }

    glutSolidTorus(innerRadius, outerRadius, facetNumber, facetNumber);

    if (texture != 0) {
        glDisable(GL_TEXTURE_2D);
    }

    glPopMatrix();
}

void drawCuboid(float width, float height, float depth, int facetNumber, int normalDirection, GLuint textures[6], float ratioTexture) {
    float normal = (normalDirection) ? -1.0F : 1.0F;

    glPushMatrix();

    // Top Face
    glPushMatrix();
    glTranslatef(-width/2, height, -depth/2);
    glRotatef(90, 1.0F, 0.0F, 0.0F);
    if (textures && textures[0] != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[0]);
    }
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glTexCoord2f(j/(float)facetNumber * ratioTexture, i/(float)facetNumber * ratioTexture);
            glVertex3f(0, i*(depth/facetNumber), 0);
            glTexCoord2f((j+1)/(float)facetNumber * ratioTexture, i/(float)facetNumber * ratioTexture);
            glVertex3f(width/facetNumber, i*(depth/facetNumber), 0);
        }
        glEnd();
        glTranslatef(width/facetNumber, 0.0F, 0.0F);
    }
    if (textures && textures[0] != 0) glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    // Bottom Face
    glPushMatrix();
    glTranslatef(-width/2, 0, depth/2);
    glRotatef(-90, 1.0F, 0.0F, 0.0F);
    if (textures && textures[1] != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[1]);
    }
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glTexCoord2f(j/(float)facetNumber * ratioTexture, i/(float)facetNumber * ratioTexture);
            glVertex3f(0, i*(depth/facetNumber), 0);
            glTexCoord2f((j+1)/(float)facetNumber * ratioTexture, i/(float)facetNumber * ratioTexture);
            glVertex3f(width/facetNumber, i*(depth/facetNumber), 0);
        }
        glEnd();
        glTranslatef(width/facetNumber, 0.0F, 0.0F);
    }
    if (textures && textures[1] != 0) glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    // Left Face
    glPushMatrix();
    glTranslatef(-width/2, 0, depth/2);
    glRotatef(90, 0.0F, 1.0F, 0.0F);
    if (textures && textures[2] != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[2]);
    }
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glTexCoord2f(j/(float)facetNumber * ratioTexture, i/(float)facetNumber * ratioTexture);
            glVertex3f(0, i*(height/facetNumber), 0);
            glTexCoord2f((j+1)/(float)facetNumber * ratioTexture, i/(float)facetNumber * ratioTexture);
            glVertex3f(depth/facetNumber, i*(height/facetNumber), 0);
        }
        glEnd();
        glTranslatef(depth/facetNumber, 0.0F, 0.0F);
    }
    if (textures && textures[2] != 0) glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    // Right Face
    glPushMatrix();
    glTranslatef(width/2, 0, -depth/2);
    glRotatef(-90, 0.0F, 1.0F, 0.0F);
    if (textures && textures[3] != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[3]);
    }
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glTexCoord2f(j/(float)facetNumber * ratioTexture, i/(float)facetNumber * ratioTexture);
            glVertex3f(0, i*(height/facetNumber), 0);
            glTexCoord2f((j+1)/(float)facetNumber * ratioTexture, i/(float)facetNumber * ratioTexture);
            glVertex3f(depth/facetNumber, i*(height/facetNumber), 0);
        }
        glEnd();
        glTranslatef(depth/facetNumber, 0.0F, 0.0F);
    }
    if (textures && textures[3] != 0) glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    // Back Face
    glPushMatrix();
    glTranslatef(width/2, 0, depth/2);
    glRotatef(180, 0.0F, 1.0F, 0.0F);
    if (textures && textures[4] != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[4]);
    }
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glTexCoord2f(j/(float)facetNumber * ratioTexture, i/(float)facetNumber * ratioTexture);
            glVertex3f(0, i*(height/facetNumber), 0);
            glTexCoord2f((j+1)/(float)facetNumber * ratioTexture, i/(float)facetNumber * ratioTexture);
            glVertex3f(width/facetNumber, i*(height/facetNumber), 0);
        }
        glEnd();
        glTranslatef(width/facetNumber, 0.0F, 0.0F);
    }
    if (textures && textures[4] != 0) glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    // Front Face
    glPushMatrix();
    glTranslatef(-width/2, 0, -depth/2);
    if (textures && textures[5] != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[5]);
    }
    for (int j = 0; j < facetNumber; j++) {
        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= facetNumber; i++) {
            glNormal3f(0.0F, 0.0F, normal);
            glTexCoord2f(j/(float)facetNumber * ratioTexture, i/(float)facetNumber * ratioTexture);
            glVertex3f(0, i*(height/facetNumber), 0);
            glTexCoord2f((j+1)/(float)facetNumber * ratioTexture, i/(float)facetNumber * ratioTexture);
            glVertex3f(width/facetNumber, i*(height/facetNumber), 0);
        }
        glEnd();
        glTranslatef(width/facetNumber, 0.0F, 0.0F);
    }
    if (textures && textures[5] != 0) glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPopMatrix();
}