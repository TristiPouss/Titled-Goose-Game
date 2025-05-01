#include "View.h"
#include "Geometry/Furnitures.h"
#include "Settings.h"
#include <GL/gl.h>



View::View() {
    // Initialize the view
    scene = MAIN_SCENE;
    posCells.resize(DEFAULT_SIZE_BOARD); // Assuming 40 cells on the board
    posPlayers.resize(4); // Assuming 4 players
    init();
}

void View::init() {
    std::vector<pos3D> positions = {
        {tableWidth/3,           tableHeight, tableWidth/3,          0},
        {0.0F,                   tableHeight, tableWidth/3,          1},
        {-tableWidth/3,          tableHeight, tableWidth/3,          2},
        {-tableWidth/3,          tableHeight, 0.0F,                  3},
        {-tableWidth/3,          tableHeight, -tableWidth/3,         4},
        {0.0F,                   tableHeight, -tableWidth/3,         5},
        {0.0F,                   0.0F,        -tableWidth,           6},
        {0.0F,                   0.0F,        -tableWidth*1.5F,      7},
        {tableWidth/2.0F,        0.0F,        -tableWidth*1.5F,      8},
        {tableWidth,             0.0F,        -tableWidth*1.5F,      9},
        {tableWidth*1.5F,        0.0F,        -tableWidth*1.5F,      10},
        {tableWidth*1.75F,       0.0F,        -tableWidth*1.25F,     11},
        {tableWidth*2.0F,        0.0F,        -tableWidth,           12},
        {tableWidth*2.0F,        0.0F,        -tableWidth/2.0F,      13},
        {tableWidth*2.0F,        0.0F,        0.0F,                  14},
        {tableWidth*2.0F,        0.0F,        tableWidth/2.0F,       15},
        {tableWidth*1.5F,        0.0F,        tableWidth/2.0F,       16},
        {tableWidth*1.25F,       0.0F,        tableWidth/1.25F,      17},
        {tableWidth,             0.0F,        tableWidth,            18},
        {tableWidth,             0.0F,        tableWidth*1.5F,       19},
        {tableWidth/1.25F,       0.0F,        tableWidth*1.75F,      20},
        {tableWidth/2.0F,        0.0F,        tableWidth*2.0F,       21},
        {tableWidth/4.0F,        0.0F,        tableWidth*2.25F,      22},
        {0.0F,                   0.0F,        tableWidth*2.5F,       23},
        {-tableWidth/2.0F,       0.0F,        tableWidth*2.5F,       24},
        {-tableWidth+5.0F,       0.0F,        tableWidth*2.0F+5.0F,  25},
        {-tableWidth*1.5F-2.0F,  9.8F,        tableWidth*1.5F-2.0F,  26},
        {-tableWidth*2.0F,       9.8F,        tableWidth,            27},
        {-tableWidth*2.25F,      9.8F,        tableWidth/1.25F,      28},
        {-tableWidth*2.5F,       9.8F,        tableWidth/2.0F,       29},
        {-tableWidth*2.75F,      9.8F,        tableWidth/4.0F,       30},
        {-tableWidth*3.0F,       9.8F,        0.0F,                  31},
        {-tableWidth*2.75F,      9.8F,        -tableWidth/4.0F,      32},
        {-tableWidth*2.5F,       9.8F,        -tableWidth/2.0F,      33},
        {-tableWidth*2.0F,       shelfLength, -tableWidth*1.5F,      34},
        {-tableWidth*1.75F,      shelfLength, -tableWidth*1.75F,     35},
        {-tableWidth*1.5F,       shelfLength, -tableWidth*2.0F,      36},
        {-tableWidth*1.25F,      shelfLength, -tableWidth*2.25F,     37},
        {-tableWidth,            shelfLength, -tableWidth*2.5F,      38},
        {0.0F,                castleLength/2, -tableWidth*2.75F,     39}
    };

    //Place cells
    for (int i = 0; i < DEFAULT_SIZE_BOARD; i++) {
        posCells[i] = positions[i];
    }

    // Place players in the room on the table
    for (int i = 0; i < 4; i++) {
        // Put one per quadrant on the cell
        int signX = (i % 2 == 0) ? -1 : 1;
        int signZ = (i < 2) ? -1 : 1;

        posPlayers[i].x = posCells[0].x + pawnWidth * signX;
        posPlayers[i].y = posCells[0].y;
        posPlayers[i].z = posCells[0].z + pawnWidth * signZ;
        posPlayers[i].caseNumber = 0;
    }
}

void View::drawMainScene(int facetNumber) {
   
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

    // Cells
    for (int i = 0; i < DEFAULT_SIZE_BOARD; i++) {
        glPushMatrix();
        glTranslatef(posCells[i].x, posCells[i].y, posCells[i].z);
        drawCell(cellWidth, facetNumber);
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
   glTranslatef(0.0F, 0.0F, roomLength/5);
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

   //Window
   glPushMatrix();    
   glRotatef(45, 0.0, 1.0, 0.0);
   glTranslatef(-roomLength/2, roomLength/4, 0.0F);
   glRotatef(-90, 0.0, 1.0, 0.0);
   drawPoster(40, 40, facetNumber, textureFenetre);
   glPopMatrix();

   //Dice for decoration
   glPushMatrix();
   glTranslatef(tableWidth/3, tableHeight + dice_edge/2, -tableWidth/3);
   glRotatef(45, 0.0, 1.0, 0.0);
   drawDice(dice_edge, dice_radius, facetNumber);
   glTranslatef(0.0, dice_edge, 0.0);
   glRotatef(45, 0.0, 1.0, 0.0);
   drawDice(dice_edge, dice_radius, facetNumber);   
   glPopMatrix();
   
   //bed
   glPushMatrix();
   glRotatef(45, 0.0, -1.0, 0.0);
   glTranslatef(-roomLength / 2 + litVoitureWidth / 2, 0.0F, roomLength / 2 - litVoitureDepth / 2);
   drawLitVoiture(litVoitureWidth, litVoitureDepth, facetNumber);
   glPopMatrix();

   glPopMatrix();
}


void View::drawDiceScene(int facetNumber) {
    float roomLength = scenerySize;

    float dice_edge = 9.0;
    float dice_radius = 1;

    glPushMatrix();
    glTranslatef(0.0F, -roomLength/2, 0.0F);

    //room
    glPushMatrix();
    drawCuboid(1000, 10, 1000, facetNumber, 1, texturesTableLeg, 3);
    glPopMatrix();    

    //Dice
    glPushMatrix();
    glTranslatef(-dice_edge, roomLength/2, 0.0F);
    drawDice(dice_edge, dice_radius, facetNumber);
    glTranslatef(dice_edge*2, 0.0F, 0.0F);
    drawDice(dice_edge, dice_radius, facetNumber);
    glPopMatrix();
    
    glPopMatrix();
}

void View::updateMainScene() {
    // Update the main scene
    // For example, update player positions or other dynamic elements
    posPlayers[0].x += 0.1f; // Example of moving the first player
    posPlayers[0].z += 0.1f; // Example of moving the first player
    if (posPlayers[0].x > tableWidth / 2) {
        posPlayers[0].x = -tableWidth / 2; // Reset position if out of bounds
    }
    if (posPlayers[0].z > tableWidth / 2) {
        posPlayers[0].z = -tableWidth / 2; // Reset position if out of bounds
    }

    setCameraPlayerPosition(posPlayers[0].x, posPlayers[0].y, posPlayers[0].z);
}

void View::updateDiceScene() {
    // Update the dice scene
    // For example, animate the dice rolling or other effects
}

void View::update() {
    // Update the view based on the current scene
    switch (scene) {
        case MAIN_SCENE:
            // Update main scene
            updateMainScene();
            break;
        case DICE_SCENE:
            // Update dice scene
            updateDiceScene();
            break;
    }
}

void View::draw(int facetNumber) {
    // Draw the current scene
    switch (scene) {
        case MAIN_SCENE:
            drawMainScene(facetNumber);
            break;
        case DICE_SCENE:
            drawDiceScene(facetNumber);
            break;
    }
}

