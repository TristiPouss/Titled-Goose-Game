#include "Texture.h"

GLuint texturesTest[6];
GLuint texturesRoom[6];
GLuint texturesTableTop[6];
GLuint texturesTableLeg[6];

GLuint texturesYellow[6];
GLuint texturesRed[6];
GLuint texturesGreen[6];
GLuint texturesBlue[6];
GLuint texturesPurple[6];

GLuint textureWall;
GLuint textureFloor;
GLuint textureTest;
GLuint textureWood;
GLuint textureTable;

GLuint textureRed;
GLuint textureGreen;
GLuint textureBlue;
GLuint textureYellow;
GLuint texturePurple;

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

void initTexture() {
    textureWall = chargementTexturePNG("../Assets/wall.png24");
    textureFloor = chargementTexturePNG("../Assets/floor.png24");
    textureTest = chargementTexturePNG("../Assets/Test.png");
    textureWood = chargementTexturePNG("../Assets/Bois.png");
    textureTable = chargementTexturePNG("../Assets/table.png24");

    textureRed = chargementTexturePNG("../Assets/red.png24");
    textureGreen = chargementTexturePNG("../Assets/green.png24");
    textureBlue = chargementTexturePNG("../Assets/blue.png24");
    textureYellow = chargementTexturePNG("../Assets/yellow.png24");
    texturePurple = chargementTexturePNG("../Assets/purple.png24");

    texturesRoom[0] = textureWall;
    texturesRoom[1] = textureFloor;
    texturesRoom[2] = textureWall;
    texturesRoom[3] = textureWall;
    texturesRoom[4] = textureWall;
    texturesRoom[5] = textureWall;

    texturesTest[0] = textureTest;
    texturesTest[1] = textureTest;
    texturesTest[2] = textureTest;
    texturesTest[3] = textureTest;
    texturesTest[4] = textureTest;
    texturesTest[5] = textureTest;

    texturesTableTop[0] = textureTable;
    texturesTableTop[1] = textureTable;
    texturesTableTop[2] = textureTable;
    texturesTableTop[3] = textureTable;
    texturesTableTop[4] = textureTable;
    texturesTableTop[5] = textureTable;

    texturesTableLeg[0] = textureWood;
    texturesTableLeg[1] = textureWood;
    texturesTableLeg[2] = textureWood;
    texturesTableLeg[3] = textureWood;
    texturesTableLeg[4] = textureWood;
    texturesTableLeg[5] = textureWood;

    texturesRed[0] = textureRed;
    texturesRed[1] = textureRed;
    texturesRed[2] = textureRed;
    texturesRed[3] = textureRed;
    texturesRed[4] = textureRed;
    texturesRed[5] = textureRed;

    texturesGreen[0] = textureGreen;
    texturesGreen[1] = textureGreen;
    texturesGreen[2] = textureGreen;
    texturesGreen[3] = textureGreen;
    texturesGreen[4] = textureGreen;
    texturesGreen[5] = textureGreen;

    texturesBlue[0] = textureBlue;
    texturesBlue[1] = textureBlue;
    texturesBlue[2] = textureBlue;
    texturesBlue[3] = textureBlue;
    texturesBlue[4] = textureBlue;
    texturesBlue[5] = textureBlue;

    texturesYellow[0] = textureYellow;
    texturesYellow[1] = textureYellow;
    texturesYellow[2] = textureYellow;
    texturesYellow[3] = textureYellow;
    texturesYellow[4] = textureYellow;
    texturesYellow[5] = textureYellow;

    texturesPurple[0] = texturePurple;
    texturesPurple[1] = texturePurple;
    texturesPurple[2] = texturePurple;
    texturesPurple[3] = texturePurple;
    texturesPurple[4] = texturePurple;
    texturesPurple[5] = texturePurple;
}