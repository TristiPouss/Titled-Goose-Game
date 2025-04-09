#include "Texture.h"

GLuint texturesTest[6];
GLuint texturesRoom[6];
GLuint texturesTableTop[6];
GLuint texturesTableLeg[6];

GLuint textureWall;
GLuint textureFloor;
GLuint textureTest;
GLuint textureWood;
GLuint textureTable;

GLuint textureRed;
GLuint textureGreen;
GLuint textureBlue;
GLuint textureYellow;

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
}