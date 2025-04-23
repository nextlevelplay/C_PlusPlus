#include "apple.h"
#include <GL/glut.h>
#include <cstdlib>
#include "globals.h"

Apple apples[10];

void Apple::New() {
    x = rand() % n;
    y = rand() % m;
}

void Apple::Draw() {
    glColor3f(0.0, 1.0, 0.0);
    glRectf(x * scale, y * scale, (x + 1) * scale, (y + 1) * scale);
}
