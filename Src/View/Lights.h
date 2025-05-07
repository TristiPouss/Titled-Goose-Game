#ifndef LIGHTS_H
#define LIGHTS_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Settings.h"
#include "time.h"

struct LightConfig {
    // Propriétés de la première lumière (GL_LIGHT1)
    GLfloat light1Diffuse[4];
    GLfloat light1Ambient[4];
    GLfloat light1Specular[4];
    GLfloat light1Position[4];

    // Propriétés de la deuxième lumière (GL_LIGHT2)
    GLfloat light2Diffuse[4];
    GLfloat light2Ambient[4];
    GLfloat light2Specular[4];
    GLfloat light2Position[4];
    GLfloat light2SpotDirection[3];
    GLfloat light2SpotCutoff;
};


static LightConfig lightConfigs[3] = {
    // Day
    {
        // GL_LIGHT1
        { 1.0, 1.0, 0.8, 1.0 }, // Diffuse
        { 0.0, 0.0, 0.0, 1.0 }, // Ambient
        { 1.0, 1.0, 1.0, 1.0 }, // Specular
        { 0.0, roomLength / 2, 0.0, 1.0 }, // Position

        // GL_LIGHT2
        { 0.25, 0.61, 1.0, 1.0 }, // Diffuse
        { 0.0, 0.0, 0.0, 1.0 },   // Ambient
        { 1.0, 1.0, 1.0, 1.0 },   // Specular
        { 0.0, roomLength, 0.0, 1.0 }, // Position
        { 0.0, -roomLength, 0.0 },     // Spot Direction
        60.0f // Spot Cutoff
    },
    // Twilight
    {
        // GL_LIGHT1
        { 0.98, 0.88, 0.74, 1.0 }, // Diffuse
		{ 0.0, 0.0, 0.0, 1.0 },    // Ambient
		{ 1.0, 1.0, 1.0, 1.0 },    // Specular
		{ 0.0, roomLength / 2, 0.0, 1.0 }, // Position

        // GL_LIGHT2
        { 0.0, 0.0, 0.0, 1.0 }, // Diffuse
        { 0.0, 0.0, 0.0, 1.0 }, // Ambient
        { 0.0, 0.0, 0.0, 1.0 }, // Specular
        { 0.0, 0.0, 0.0, 1.0 }, // Position
        { 0.0, 0.0, 0.0 },      // Spot Direction
        180.0f // Spot Cutoff
    },
    // Night
    {
        // GL_LIGHT1
        { 0.75, 0.6, 0.8, 1.0 },
        { 0.0, 0.0, 0.0, 1.0 },
        { 1.0, 1.0, 1.0, 1.0 },
        { 0.0, roomLength / 2, 0.0, 1.0 },

        // GL_LIGHT2
        { 0.8, 0.8, 0.6, 1.0 }, // Diffuse
        { 0.0, 0.0, 0.0, 1.0 }, // Ambient
        { 1.0, 1.0, 1.0, 1.0 }, // Specular
        { 0.0, roomLength, 0.0, 1.0 }, // Position
        { 0.0, -roomLength, 0.0 },     // Spot Direction
        32.0f // Spot Cutoff
    }
};

class Lights {

    public:
        Lights();

        void init();

        void interpolate(const LightConfig& from, const LightConfig& to, float t, LightConfig& result);

        void updateTransition();

        void startTransition();
        
		int getCurrentLight() {
			return currentLight;
		}

    private:
        float transitionProgress;
        int currentLight;
        int nextLight;
        bool transitioning;
};

#endif // !LIGHTS_H