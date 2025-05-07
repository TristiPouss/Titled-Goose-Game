#include "Lights.h"

Lights::Lights(): transitionProgress(0.0F), currentLight(2), nextLight(0), transitioning(false) {}

void Lights::interpolate(const LightConfig& from, const LightConfig& to, float t, LightConfig& result) {
    // Interpolation pour GL_LIGHT1
    for (int i = 0; i < 4; i++) {
        result.light1Diffuse[i] = from.light1Diffuse[i] + t * (to.light1Diffuse[i] - from.light1Diffuse[i]);
        result.light1Ambient[i] = from.light1Ambient[i] + t * (to.light1Ambient[i] - from.light1Ambient[i]);
        result.light1Specular[i] = from.light1Specular[i] + t * (to.light1Specular[i] - from.light1Specular[i]);
        result.light1Position[i] = from.light1Position[i] + t * (to.light1Position[i] - from.light1Position[i]);
    }

    // Interpolation pour GL_LIGHT2
    for (int i = 0; i < 4; i++) {
        result.light2Diffuse[i] = from.light2Diffuse[i] + t * (to.light2Diffuse[i] - from.light2Diffuse[i]);
        result.light2Ambient[i] = from.light2Ambient[i] + t * (to.light2Ambient[i] - from.light2Ambient[i]);
        result.light2Specular[i] = from.light2Specular[i] + t * (to.light2Specular[i] - from.light2Specular[i]);
        result.light2Position[i] = from.light2Position[i] + t * (to.light2Position[i] - from.light2Position[i]);
    }
    for (int i = 0; i < 3; i++) {
        result.light2SpotDirection[i] = from.light2SpotDirection[i] + t * (to.light2SpotDirection[i] - from.light2SpotDirection[i]);
    }
    result.light2SpotCutoff = from.light2SpotCutoff + t * (to.light2SpotCutoff - from.light2SpotCutoff);
}

void Lights::updateTransition() {
    if (transitioning) {
        transitionProgress += 0.01f; // Incrément progressif (ajustez la vitesse ici)
        if (transitionProgress >= 1.0f) {
            transitionProgress = 0.0f;
            currentLight = nextLight;
            nextLight = (nextLight + 1) % 3;
            transitioning = false;
        }

        LightConfig interpolatedLight;
        interpolate(lightConfigs[currentLight], lightConfigs[nextLight], transitionProgress, interpolatedLight);

        // Appliquer les propriétés interpolées à GL_LIGHT1
        glLightfv(GL_LIGHT1, GL_DIFFUSE, interpolatedLight.light1Diffuse);
        glLightfv(GL_LIGHT1, GL_AMBIENT, interpolatedLight.light1Ambient);
        glLightfv(GL_LIGHT1, GL_SPECULAR, interpolatedLight.light1Specular);
        glLightfv(GL_LIGHT1, GL_POSITION, interpolatedLight.light1Position);

        // Appliquer les propriétés interpolées à GL_LIGHT2
        glLightfv(GL_LIGHT2, GL_DIFFUSE, interpolatedLight.light2Diffuse);
        glLightfv(GL_LIGHT2, GL_AMBIENT, interpolatedLight.light2Ambient);
        glLightfv(GL_LIGHT2, GL_SPECULAR, interpolatedLight.light2Specular);
        glLightfv(GL_LIGHT2, GL_POSITION, interpolatedLight.light2Position);
        glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, interpolatedLight.light2SpotDirection);
        glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, interpolatedLight.light2SpotCutoff);

    }
    else
    {
        // GL_LIGHT1
        glLightfv(GL_LIGHT1, GL_DIFFUSE, lightConfigs[currentLight].light1Diffuse);
        glLightfv(GL_LIGHT1, GL_AMBIENT, lightConfigs[currentLight].light1Ambient);
        glLightfv(GL_LIGHT1, GL_SPECULAR, lightConfigs[currentLight].light1Specular);
        glLightfv(GL_LIGHT1, GL_POSITION, lightConfigs[currentLight].light1Position);

        // GL_LIGHT2
        glLightfv(GL_LIGHT2, GL_DIFFUSE, lightConfigs[currentLight].light2Diffuse);
        glLightfv(GL_LIGHT2, GL_AMBIENT, lightConfigs[currentLight].light2Ambient);
        glLightfv(GL_LIGHT2, GL_SPECULAR, lightConfigs[currentLight].light2Specular);
        glLightfv(GL_LIGHT2, GL_POSITION, lightConfigs[currentLight].light2Position);
        glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, lightConfigs[currentLight].light2SpotDirection);
        glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, lightConfigs[currentLight].light2SpotCutoff);
    }
}

void Lights::startTransition() {
    if (!transitioning) {
        transitioning = true;
    }
}

/*static void lightDay() {
    GLfloat light1Diff[] = { 1.0, 1.0, 0.8, 1.0 };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1Diff);
    GLfloat light1Ambient[] = { 0.0, 0.0, 0.0 };
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambient);
    GLfloat light1Spec[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1Spec);
    GLfloat light1Pos[] = { roomLength / 2, roomLength / 2, roomLength / 2, 1.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, light1Pos);

    GLfloat light2Diff[] = { 0.25, 0.61, 1.0, 1.0 };
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light2Diff);
    GLfloat light2Ambient[] = { 0.0, 0.0, 0.0 };
    glLightfv(GL_LIGHT2, GL_AMBIENT, light2Ambient);
    GLfloat light2Spec[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT2, GL_SPECULAR, light2Spec);
    GLfloat light2Pos[] = { 0.0, roomLength, 0.0, 1.0 };
    glLightfv(GL_LIGHT2, GL_POSITION, light2Pos);
    GLfloat dir[] = { 0.0, -roomLength, 0.0 };
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dir);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 60.0);
}

static void lightTwilight() {
    GLfloat light1Diff[] = { 0.98, 0.88, 0.74, 1.0 };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1Diff);
    GLfloat light1Ambient[] = { 0.0, 0.0, 0.0 };
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambient);
    GLfloat light1Spec[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1Spec);
    GLfloat light1Pos[] = { roomLength / 2, roomLength / 2, roomLength / 2, 1.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, light1Pos);

    GLfloat vid[] = { 0.0, 0.0, 0.0 };
    glLightfv(GL_LIGHT2, GL_DIFFUSE, vid);
    glLightfv(GL_LIGHT2, GL_AMBIENT, vid);
}

static void lightNight() {
    GLfloat light1Diff[] = { 0.75, 0.6, 0.9, 1.0 };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1Diff);
    GLfloat light1Ambient[] = { 0.0, 0.0, 0.0 };
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambient);
    GLfloat light1Spec[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1Spec);
    GLfloat light1Pos[] = { roomLength / 2, roomLength / 2, roomLength / 2, 0.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, light1Pos);

    GLfloat light2Diff[] = { 0.8, 0.8, 0.6, 1.0 };
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light2Diff);
    GLfloat light2Ambient[] = { 0.0, 0.0, 0.0 };
    glLightfv(GL_LIGHT2, GL_AMBIENT, light2Ambient);
    GLfloat light2Spec[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT2, GL_SPECULAR, light2Spec);
    GLfloat light2Pos[] = { 0.0, roomLength, 0.0, 1.0 };
    glLightfv(GL_LIGHT2, GL_POSITION, light2Pos);
    GLfloat dir[] = { 0.0, -roomLength, 0.0 };
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dir);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 32.0);
}

static void initLight() {
    switch (timeOfDay) {
    case 0:
        lightDay();
        break;
    case 1:
        lightTwilight();
        break;
    case 2:
        lightNight();
        break;
    }
}

static void switchTimeDay() {
    timeOfDay = (timeOfDay + 1) % 3; // Cycle through day, twilight, and night
    initLight();
}*/