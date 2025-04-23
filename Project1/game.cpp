#include "game.h"
#include "snake.h"
#include "apple.h"
#include "globals.h"
#include <GL/glut.h>

void DrawField() {
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    for (int i = 0; i < w; i += scale) {
        glVertex2f(i, 0); glVertex2f(i, h);
    }
    for (int j = 0; j < h; j += scale) {
        glVertex2f(0, j); glVertex2f(w, j);
    }
    glEnd();
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < 10; i++)
        apples[i].Draw();

    DrawField();
    DrawSnake();
    glFlush();
}

void Timer(int) {
    Display();
    MoveSnake();
    glutTimerFunc(120, Timer, 0);
}

void Keyboard(int key, int, int) {
    switch (key) {
    case 101: dir = 0; break;
    case 102: dir = 2; break;
    case 100: dir = 1; break;
    case 103: dir = 3; break;
    }
}
