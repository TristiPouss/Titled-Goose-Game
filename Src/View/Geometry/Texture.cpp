#include "Texture.h"

GLuint texturesTest[6];
GLuint texturesRoom[6];
GLuint texturesTableTop[6];
GLuint texturesTableLeg[6];
GLuint texturesDiceFaces[6];
GLuint texturesLitVoiture[6];

GLuint texturesYellow[6];
GLuint texturesRed[6];
GLuint texturesGreen[6];
GLuint texturesBlue[6];
GLuint texturesPurple[6];
GLuint texturesWhite[6];

GLuint texturesPawn[4];

GLuint textureWall;
GLuint textureFloor;
GLuint textureTest;
GLuint textureWood;
GLuint textureTableFeet;
GLuint textureTablePlate;
GLuint textureTable;
GLuint textureKaaris;
GLuint textureEvanescence;
GLuint texturePulp;
GLuint textureFenetre;
GLuint textureRedStripes;
GLuint textureMcqueenFace;

GLuint textureRed;
GLuint textureGreen;
GLuint textureBlue;
GLuint textureYellow;
GLuint texturePurple;

GLuint textureCubeRed;
GLuint textureCubeGreen;
GLuint textureCubeBlue;
GLuint textureCubeYellow;
GLuint textureCubePurple;
GLuint textureCubeWhite;

GLuint textureEdgeDice;
GLuint textureCornerDice;

unsigned int chargementTexturePNG(char *filename) {
    unsigned int textureID = 0;
    glGenTextures(1,&textureID);
    int rx;
    int ry;
    unsigned char *img = chargeImagePng(filename,&rx,&ry);
    if ( img && textureID ) {
        glBindTexture(GL_TEXTURE_2D,textureID);
        glPixelStorei(GL_UNPACK_ALIGNMENT,1);
        glTexImage2D(GL_TEXTURE_2D,0,3,rx,ry,0,GL_RGB,GL_UNSIGNED_BYTE,img); 
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT); 
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); 
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        free(img); }
    else {
    if ( img ) {
        free(img); }
    if ( textureID ) {
        glDeleteTextures(1,&textureID);
        textureID = 0; } }
    return textureID;
}

void initCubeTextureSingle(GLuint textureID, GLuint textures[6]) {
    for (int i = 0; i < 6; i++) {
        textures[i] = textureID;
    }
}

void initTexture() {
    textureWall = chargementTexturePNG("../Assets/greysand.png24");
    textureFloor = chargementTexturePNG("../Assets/wood.png24");
    textureTest = chargementTexturePNG("../Assets/Test.png");
    textureWood = chargementTexturePNG("../Assets/bg_wood.png24");
    textureTableFeet = chargementTexturePNG("../Assets/trunk_side.png24");
    textureTablePlate = chargementTexturePNG("../Assets/bg_wood.png24");
    textureKaaris = chargementTexturePNG("../Assets/kaaris.png24");
    textureEvanescence = chargementTexturePNG("../Assets/evanescence.png24");
    texturePulp = chargementTexturePNG("../Assets/pulp.png24");
    textureFenetre = chargementTexturePNG("../Assets/fenetre.png24");
	textureRedStripes = chargementTexturePNG("../Assets/red_stripes.png24");
	textureMcqueenFace = chargementTexturePNG("../Assets/mcqueen_face.png24");
    /*
	textureLitVoitureBack = chargementTexturePNG("../Assets/lit_voiture_back.png24");
	textureLitVoitureLeft = chargementTexturePNG("../Assets/lit_voiture_left.png24");
	textureLitVoitureRight = chargementTexturePNG("../Assets/lit_voiture_right.png24");
	textureLitVoitureTop = chargementTexturePNG("../Assets/lit_voiture_top.png24");
    */


    textureRed = chargementTexturePNG("../Assets/red.png24");
    textureGreen = chargementTexturePNG("../Assets/green.png24");
    textureBlue = chargementTexturePNG("../Assets/blue.png24");
    textureYellow = chargementTexturePNG("../Assets/yellow.png24");
    texturePurple = chargementTexturePNG("../Assets/purple.png24");

    textureCubePurple = chargementTexturePNG("../Assets/cube_purple.png24");
    textureCubeRed = chargementTexturePNG("../Assets/cube_red.png24");
    textureCubeGreen = chargementTexturePNG("../Assets/cube_green.png24");
    textureCubeBlue = chargementTexturePNG("../Assets/cube_blue.png24");
    textureCubeYellow = chargementTexturePNG("../Assets/cube_yellow.png24");
	textureCubeWhite = chargementTexturePNG("../Assets/cube_white.png24");

    //Init dice 
    textureEdgeDice = chargementTexturePNG("../Assets/edgeDice.png24");
    textureCornerDice = chargementTexturePNG("../Assets/edgeDice.png24");

    texturesDiceFaces[0] = chargementTexturePNG("../Assets/diceRed2.png24");
    texturesDiceFaces[1] = chargementTexturePNG("../Assets/diceRed5.png24");
    texturesDiceFaces[2] = chargementTexturePNG("../Assets/diceRed1.png24");
    texturesDiceFaces[3] = chargementTexturePNG("../Assets/diceRed6.png24");
    texturesDiceFaces[4] = chargementTexturePNG("../Assets/diceRed4.png24");
    texturesDiceFaces[5] = chargementTexturePNG("../Assets/diceRed3.png24");

    /* For a cube, we have the following corresponding table: 
    0 - Front
    1 - Back
    2 - Top
    3 - Bottom
    4 - Right
    5 - Left
    */

    texturesRoom[0] = textureWall;
    texturesRoom[1] = textureWall;
    texturesRoom[2] = textureWall;
    texturesRoom[3] = textureFloor;
    texturesRoom[4] = textureWall;
    texturesRoom[5] = textureWall;

    texturesPawn[0] = textureRed;
    texturesPawn[1] = textureGreen;
    texturesPawn[2] = textureBlue;
    texturesPawn[3] = textureYellow;

    initCubeTextureSingle(textureTest,texturesTest);

    texturesTableTop[0] = textureTableFeet;
    texturesTableTop[1] = textureTableFeet;
    texturesTableTop[2] = textureTablePlate;
    texturesTableTop[3] = textureTablePlate;
    texturesTableTop[4] = textureTableFeet;
    texturesTableTop[5] = textureTableFeet;

    initCubeTextureSingle(textureTableFeet,texturesTableLeg);


    initCubeTextureSingle(textureCubeRed, texturesRed);
    initCubeTextureSingle(textureCubeGreen, texturesGreen);
    initCubeTextureSingle(textureCubeBlue, texturesBlue);
    initCubeTextureSingle(textureCubeYellow, texturesYellow);
    initCubeTextureSingle(textureCubePurple, texturesPurple);
	initCubeTextureSingle(textureCubeWhite, texturesWhite);

	initCubeTextureSingle(textureRedStripes, texturesLitVoiture);
}