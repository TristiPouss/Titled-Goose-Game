#include "Materials.h"

static GLfloat no_mat[4] = { 0.0F,0.0F,0.0F,1.0F };
static GLfloat full_mat[4] = { 1.0F,1.0F,1.0F,1.0F };

void resetMaterial() {
    // Couleur ambiante (reflet de la lumi�re ambiante)
    GLfloat mat_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };

    // Couleur diffuse (couleur principale du mat�riau)
    GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };

    // Couleur sp�culaire (reflets brillants)
    GLfloat mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };

    // Brillance (intensit� des reflets sp�culaires)
    GLfloat mat_shininess[] = { 0.0f };

    // Appliquer les propri�t�s du mat�riau
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void setPlasticMaterial() {
    // Couleur ambiante (faible reflet de la lumi�re ambiante)
    GLfloat mat_ambient[] = { 0.8f, 0.8f, 0.8f, 1.0f };

    // Couleur diffuse (couleur principale du mat�riau)
    GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; // brillant

    // Couleur sp�culaire (reflets brillants)
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    // Brillance (intensit� des reflets sp�culaires)
    GLfloat mat_shininess[] = { 128.0f }; // Valeur �lev�e pour un effet brillant

    // Appliquer les propri�t�s du mat�riau
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void setWoodMaterial() {
    // Couleur ambiante (faible reflet de la lumi�re ambiante)
    GLfloat mat_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };

    // Couleur diffuse (couleur principale du mat�riau)
    GLfloat mat_diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };

    // Couleur sp�culaire (reflets doux)
    GLfloat mat_specular[] = { 0.2f, 0.1f, 0.05f, 1.0f };

    // Brillance (intensit� des reflets sp�culaires)
    GLfloat mat_shininess[] = { 20.0f }; // Valeur basse pour un effet mat

    // Appliquer les propri�t�s du mat�riau
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void setWallMaterial() {
    // Couleur ambiante (faible reflet de la lumi�re ambiante)
    GLfloat mat_ambient[] = { 0.1f, 0.1f, 0.2f, 1.0f }; // Bleu fonc�

    // Couleur diffuse (couleur principale du mat�riau)
    GLfloat mat_diffuse[] = { 0.1f, 0.1f, 0.2f, 1.0f }; // Bleu clair

    // Couleur sp�culaire (reflets doux)
    GLfloat mat_specular[] = { 0.1f, 0.1f, 0.3f, 1.0f }; // Reflets bleut�s

    // Brillance (intensit� des reflets sp�culaires)
    GLfloat mat_shininess[] = { 10.0f }; // Valeur basse pour un effet doux

    // Appliquer les propri�t�s du mat�riau
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
