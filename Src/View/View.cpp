#include "View.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>



View::View() {
    // Initialize the view
    scene = MAIN_SCENE;
    posCells.resize(DEFAULT_SIZE_BOARD); // Assuming 40 cells on the board
    posPlayers.resize(4); // Assuming 4 players
    init();
}

void View::init() {
    //Initialize posCells and posPlayers

    //Place it randomly in the room 
    for (int i = 0; i < DEFAULT_SIZE_BOARD; i++) {
        posCells[i].x = (rand() % 100) / 100.0f * scenerySize;
        posCells[i].y = (rand() % 100) / 100.0f * scenerySize;
        posCells[i].z = (rand() % 100) / 100.0f * scenerySize;
    }

    // Place players in the room on the table
    for (int i = 0; i < 4; i++) {
        posPlayers[i].x = 0.0F;
        posPlayers[i].y = tableHeight;
        posPlayers[i].z = -pawnWidth*2;
    }
}

void View::drawMainScene() {
   
    // Draw the main scene
   glPushMatrix();
   glTranslatef(0.0, -tableHeight, 0.0);

   //room
   glPushMatrix();
   glRotatef(45, 0.0, 1.0, 0.0);
   drawCube(roomLength, facetNumber, 0, texturesRoom, 5.0F);
   glPopMatrix();    

   //table
   glPushMatrix();
   drawTable(tableHeight, tableWidth, facetNumber);
   glPopMatrix();

   //pawn
   for (int i = 0; i < 4; i++) {
       glPushMatrix();
       glTranslatef(posPlayers[i].x, posPlayers[i].y, posPlayers[i].z);
       drawPawn(pawnWidth, facetNumber, texturesPawn[i]);
       glPopMatrix();
   }

   //shelf
   glPushMatrix();
   glRotatef(45, 0.0, 1.0, 0.0);
   glTranslatef(shelfLength / 4, 0.0F, -roomLength/2 + shelfLength/8);
   drawShelf(shelfLength, facetNumber);
   glTranslatef(0.0F, shelfLength/16, 0.0F);
   drawCubeStack(3, facetNumber, texturesBlue, texturesGreen, texturesRed);
   glTranslatef(-shelfLength/4 -shelfLength/16, shelfLength/4 +shelfLength/16, 0.0F);
   drawCubeStack(3, facetNumber, texturesPurple, texturesBlue, texturesYellow);
   glTranslatef(shelfLength/4 +shelfLength/16, shelfLength/4 +shelfLength/16, 0.0F);
   drawCubeStack(3, facetNumber, texturesRed, texturesGreen, texturesYellow);
   glTranslatef(shelfLength/4 +shelfLength/16, 0.0F, 0.0F);
   drawCubeStack(3, facetNumber, texturesYellow, texturesBlue, texturesGreen);
   glPopMatrix();

   //kapla
   glPushMatrix();
   glTranslatef(roomLength/4, 0.0F, 0.0F);
   drawKaplaTower(kaplaLength, 10, facetNumber);
   glTranslatef(0.0F, 0.0F, roomLength/8);
   drawKaplaTowerSpiral(kaplaLength, 15, facetNumber);
   glPopMatrix();

   //castle
   glPushMatrix();
   glTranslatef(0.0F, 0.0F, -roomLength/2);
   drawCastle(castleLength, facetNumber);
   glPopMatrix();

   //door
   glPushMatrix();
   glRotatef(45, 0.0, 1.0, 0.0);
   glTranslatef(roomLength/4 , 0.0F, roomLength/2);
   drawDoor(50, facetNumber);
   glPopMatrix();

   //poster
   glPushMatrix();    
   glRotatef(45, 0.0, 1.0, 0.0);
   glTranslatef(-roomLength/5, roomLength/4, roomLength/2);
   drawPoster(30, 30, facetNumber, textureKaaris);
   glPopMatrix();
   glPushMatrix();
   glRotatef(45, 0.0, 1.0, 0.0);
   glTranslatef(-roomLength/3.5, roomLength/4, -roomLength/2);
   glRotatef(180, 0.0, 1.0, 0.0);
   drawPoster(20, 40, facetNumber, texturePulp);
   glPopMatrix();
   glPushMatrix();
   glRotatef(45, 0.0, 1.0, 0.0);
   glTranslatef(roomLength/2, roomLength/4, -roomLength/5);
   glRotatef(90, 0.0, 1.0, 0.0);
   drawPoster(20, 20, facetNumber, textureEvanescence);
   glPopMatrix();

   //fenetre
   glPushMatrix();    
   glRotatef(45, 0.0, 1.0, 0.0);
   glTranslatef(-roomLength/2, roomLength/4, 0.0F);
   glRotatef(-90, 0.0, 1.0, 0.0);
   drawPoster(40, 40, facetNumber, textureFenetre);
   glPopMatrix();

   //Dice
   glPushMatrix();
   glTranslatef(0.0F, tableHeight + pawnWidth*2, -pawnWidth*2);
   glRotatef(45, 0.0, 1.0, 0.0);
   glTranslatef(0.0F, 0.0F, -dice_radius);
   glRotatef(90, 0.0, 1.0, 0.0);
   drawDice(dice_edge, dice_radius, facetNumber);
   glPopMatrix();
   
   //bed
   //glTranslatef(roomLength/2 - litVoitureWidth*2, 0.0F, roomLength/2 - litVoitureWidth*2);
   //glRotatef(45, 0.0, 1.0, 0.0);
   //drawLitVoiture(litVoitureWidth, facetNumber);

   glPopMatrix();
}


void View::drawDiceScene() {
    // Draw the dice scene
    glPushMatrix();
    glTranslatef(0.0F, 0.0F, -scenerySize / 2);
    drawDice(1.0, 0.5, facetNumber);
    glPopMatrix();
}

void View::update() {
    // Update the view based on the current scene
    switch (scene) {
        case MAIN_SCENE:
            // Update main scene
            break;
        case DICE_SCENE:
            // Update dice scene
            break;
    }
}

void View::draw() {
    // Draw the current scene
    switch (scene) {
        case MAIN_SCENE:
            drawMainScene();
            break;
        case DICE_SCENE:
            drawDiceScene();
            break;
    }
}

