#include "Materials.h"

static GLfloat no_mat[4] = { 0.0F,0.0F,0.0F,1.0F };
static GLfloat full_mat[4] = { 1.0F,1.0F,1.0F,1.0F };

void resetMaterial() {
    // Couleur ambiante (reflet de la lumière ambiante)
    GLfloat mat_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };

    // Couleur diffuse (couleur principale du matériau)
    GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };

    // Couleur spéculaire (reflets brillants)
    GLfloat mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };

    // Brillance (intensité des reflets spéculaires)
    GLfloat mat_shininess[] = { 0.0f };

    // Appliquer les propriétés du matériau
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void setPlasticMaterial() {
    // Couleur ambiante (faible reflet de la lumière ambiante)
    GLfloat mat_ambient[] = { 0.8f, 0.8f, 0.8f, 1.0f };

    // Couleur diffuse (couleur principale du matériau)
    GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; // brillant

    // Couleur spéculaire (reflets brillants)
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    // Brillance (intensité des reflets spéculaires)
    GLfloat mat_shininess[] = { 128.0f }; // Valeur élevée pour un effet brillant

    // Appliquer les propriétés du matériau
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void setWoodMaterial() {
    // Couleur ambiante (faible reflet de la lumière ambiante)
    GLfloat mat_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };

    // Couleur diffuse (couleur principale du matériau)
    GLfloat mat_diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };

    // Couleur spéculaire (reflets doux)
    GLfloat mat_specular[] = { 0.2f, 0.1f, 0.05f, 1.0f };

    // Brillance (intensité des reflets spéculaires)
    GLfloat mat_shininess[] = { 20.0f }; // Valeur basse pour un effet mat

    // Appliquer les propriétés du matériau
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void setWallMaterial() {
    // Couleur ambiante (faible reflet de la lumière ambiante)
    GLfloat mat_ambient[] = { 0.1f, 0.1f, 0.2f, 1.0f }; // Bleu foncé

    // Couleur diffuse (couleur principale du matériau)
    GLfloat mat_diffuse[] = { 0.1f, 0.1f, 0.2f, 1.0f }; // Bleu clair

    // Couleur spéculaire (reflets doux)
    GLfloat mat_specular[] = { 0.1f, 0.1f, 0.3f, 1.0f }; // Reflets bleutés

    // Brillance (intensité des reflets spéculaires)
    GLfloat mat_shininess[] = { 10.0f }; // Valeur basse pour un effet doux

    // Appliquer les propriétés du matériau
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
