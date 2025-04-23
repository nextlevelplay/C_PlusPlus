#include <GL/glut.h>
#include "snake.h"
#include "apple.h"
#include "game.h"
#include "globals.h"
#include "windows.h"


int main(int argc, char** argv) {

    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);

    for (int i = 0; i < 10; i++)
        apples[i].New();

    InitSnake();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(w, h);
    glutCreateWindow("SnakeGame_v0.04");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glutDisplayFunc(Display);
    glutTimerFunc(120, Timer, 0);
    glutSpecialFunc(Keyboard);
    glutKeyboardFunc(NormalKeyboard);
    glutMainLoop();
}