#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "View/Camera/Camera.h"
#include "View/Settings.h"
#include "View/Geometry/Texture.h"
#include "View/View.h"

#include "model/Board.h"
#include "model/Cell.h"
#include "model/Dice.h"
#include "model/Game.h"
#include "model/Player.h"

static float angle = 0.0;
gooseGameModel::Game game;
View view;

static void init(void) {
    game = gooseGameModel::Game();
    view = View();
    initTexture();
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
}

static void ambient() {
    GLfloat light1Pos[] = { 1.0, 1.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1Pos);
    GLfloat light1Ambient[] = { 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambient);
}

static void spot_top() {
    GLfloat diff[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diff);
    GLfloat pos[] = { 0.0, 80.0, 0.0, 1.0 };
    glLightfv(GL_LIGHT2, GL_POSITION, pos);
    GLfloat dir[] = { 0.0, -80.0, 0.0 };
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dir);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 90.0);
}

static void diffuse() {
    GLfloat light3Pos[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT3, GL_DIFFUSE, light3Pos);
    GLfloat light3Diffuse[] = { 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT3, GL_DIFFUSE, light3Diffuse);
}

static void initLight() {
    ambient();
    diffuse();
    spot_top();
}

static void scene() {
    view.draw();
}

/* Fonction executee lors d'un rafraichissement */
/* de la fenetre de dessin                      */

static void display(void) {
    if (culling)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT_AND_BACK, (polygonMode) ? GL_FILL : GL_LINE);
    if (normalize)
        glEnable(GL_NORMALIZE);
    else
        glDisable(GL_NORMALIZE);
    if (fond)
        glClearColor(0.8F, 0.8F, 0.8F, 1.0F);
    else
        glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
    if (materialLightMode)
        glEnable(GL_LIGHTING);
    else
        glDisable(GL_LIGHTING);
    if (light1)
        glEnable(GL_LIGHT1);
    else
        glDisable(GL_LIGHT1);
    if (light2)
        glEnable(GL_LIGHT2);
    else
        glDisable(GL_LIGHT2);
    if (light3)
        glEnable(GL_LIGHT3);
    else
        glDisable(GL_LIGHT3);
    if (light4)
        glEnable(GL_LIGHT4);
    else
        glDisable(GL_LIGHT4);
    glPolygonMode(GL_FRONT_AND_BACK, (polygonMode == 1) ? GL_FILL : GL_LINE);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    setCurrentPlayerPosition(100, 100, 100);
    // setCurrentPlayerPosition(game->getCurrentPlayerPosition()[0], game->getCurrentPlayerPosition()[1], game->getCurrentPlayerPosition()[2]);
    initCamera(cameraPerspect, cameraOnCurrentPlayer, wTx, wTy);

    glTranslatef(0.0F, 0.0F, -100.0F);

    // Camera movements, rotation and zoom
    glTranslatef(mx, my, mz);

    glRotatef(rx, 1.0F, 0.0F, 0.0F);
    glRotatef(ry, 0.0F, 1.0F, 0.0F);
    glRotatef(rz, 0.0F, 0.0F, 1.0F);

    glScalef(zoom, zoom, zoom);
    printf("%f\n", zoom);

    // Light init
    initLight();

    // Scene
    scene();

    glPopMatrix();

    glFlush();
    glutSwapBuffers();
    int error = glGetError();
    if (error != GL_NO_ERROR)
        printf("Attention erreur %d\n", error);
}

/* Fonction executee lors d'un changement       */
/* de la taille de la fenetre OpenGL            */

static void reshape(int wx, int wy) {
    printf("R\n");
    wTx = wx;
    wTy = wy;
    glViewport(0, 0, wx, wy);
}

/* Fonction executee lorsqu'aucun evenement     */
/* facetNumber'est en file d'attente                      */

static void idle(void) {
    view.update();
    angle = (float)(((int)(angle)+1)%360);
    glutPostRedisplay();
}


/* Fonction executee lors de l'appui            */
/* d'une touche alphanumerique du clavier       */

static void keyboard(unsigned char key, int x, int y) {
    printf("K  %4c %4d %4d\n", key, x, y);
    switch (key) {
    case 'n':
        facetNumber--;
        if (facetNumber < 1)
            facetNumber = 1;
        glutPostRedisplay();
        break;
    case 'N':
        facetNumber++;
        glutPostRedisplay();
        break;
    case 'k':
        zoom /= 1.1;
        if (zoom <= 2.86)
            zoom = 2.86;
        glutPostRedisplay();
        break;
    case 'K':
        zoom *= 1.1;
        glutPostRedisplay();
        break;
    case 'Z':
    case 'z':
        mz+= 2.0F;
        glutPostRedisplay();
        break;
    case 'S':
    case 's':
        mz-= 2.0F;
        glutPostRedisplay();
        break;
    case 'Q':
    case 'q':
        mx+= 2.0F;
        glutPostRedisplay();
        break;
    case 'D':
    case 'd':
        mx-= 2.0F;
        glutPostRedisplay();
        break;
    case 'f':
    case 'F':
        if (fullscreen) {
            glutFullScreen();
            fullscreen = 0;
        }
        else {
            glutReshapeWindow(480, 480);
            glutPositionWindow(wPx, wPy);
            fullscreen = 1;
        }
        break;
    case 'b':
        fond = !fond;
        glutPostRedisplay();
        break;
    case 0x0D:
        anim = !anim;
        glutIdleFunc((anim) ? idle : NULL);
        break;
    case 'c':
        culling = !culling;
        glutPostRedisplay();
        break;
    case 'C':
        cameraPerspect = !cameraPerspect;
        glutPostRedisplay();
        break;
    case 'm':
        polygonMode = !polygonMode;
        glutPostRedisplay();
        break;
    case 'P':
    case 'p':
        cameraOnCurrentPlayer = !cameraOnCurrentPlayer;
        glutPostRedisplay();
        break;
    case 0x20:
        normalize = !normalize;
        glutPostRedisplay();
        break;
    case 0x1B:
        exit(0);
        break;
    }
}

/* Fonction executee lors de l'appui            */
/* d'une touche speciale du clavier :           */
/*   - touches de curseur                       */
/*   - touches de fonction                      */

static void special(int specialKey, int x, int y) {
    switch (specialKey) {
    case GLUT_KEY_RIGHT:
        ry -= 1.0F;
        //if (ry < -50.0) ry = -50.0;
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        ry += 1.0F;
        //if (ry > 50.0) ry = 50.0;
        glutPostRedisplay();
        break;
    case GLUT_KEY_UP:
        rx += 1.0F;
        //if (rx > 30.0) rx = 30.0;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        rx -= 1.0F;
        //if (rx < -30.0) rx = -30.0;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F10:
        materialLightMode = !materialLightMode;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F1:
        light1 = !light1;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F2:
        light2 = !light2;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F3:
        light3 = !light3;
        glutPostRedisplay();
        break;
    case GLUT_KEY_F4:
        light4 = !light4;
        glutPostRedisplay();
        break;
    }
}

/* Fonction executee lors de l'utilisation      */
/* de la souris sur la fenetre                  */

static void mouse(int button, int state, int x, int y) {
    /*if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
        mouseX = x;
        mouseActive = 1;
    }
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP)) {
        mouseActive = 0;
    }
    if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_UP))
        sens *= -1.0F;*/
}

/* Fonction executee lors du passage            */
/* de la souris sur la fenetre                  */
/* avec un bouton presse                        */

static void mouseMotion(int x, int y) {
    if (mouseActive) {
        rz += (mouseX - x);
        mouseX = x;
        glutPostRedisplay();
    }
}

/* Fonction executee lors du passage            */
/* de la souris sur la fenetre                  */
/* sans bouton presse                           */

static void passiveMouseMotion(int x, int y) {
}

/* Fonction exécutée automatiquement            */
/* lors de l'exécution de la fonction exit()    */

static void clean(void) {
    printf("Bye\n");
}



/* Fonction principale                          */

int main(int argc, char** argv) {

    atexit(clean);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(wTx, wTy);
    glutInitWindowPosition(wPx, wPy);
    glutCreateWindow("Jeu de l'Oie");
    init();
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return(0);
}
