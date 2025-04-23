#include "game.h"
#include "snake.h"
#include "apple.h"
#include "globals.h"
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

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

void RenderBitmapString(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y);
    for (const char* c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}


void Display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (gameState == MENU) {
        RenderBitmapString(w / 2 - 80, h / 2, GLUT_BITMAP_HELVETICA_18, "Press ENTER to Start");
    }
    else if (gameState == PAUSED) {
        RenderBitmapString(w / 2 - 40, h / 2, GLUT_BITMAP_HELVETICA_18, "Paused");
    }
    else {
        for (int i = 0; i < 10; i++) {
            apples[i].Draw();

            DrawField();
            DrawSnake();

            glColor3f(1.0, 1.0, 1.0);
            char scoreText[32];
            sprintf_s(scoreText, "Score: %d", score);
            RenderBitmapString(10, h - 20, GLUT_BITMAP_HELVETICA_18, scoreText);
        }
    }
    glFlush();
}

void Timer(int) {
    if (gameState == PLAYING) {
        MoveSnake();
    }

    Display();
    glutTimerFunc(120, Timer, 0);
}

void Keyboard(int key, int, int) {

    if (gameState == PLAYING) {
        switch (key) {
        case 101: dir = 0; break;
        case 102: dir = 2; break;
        case 100: dir = 1; break;
        case 103: dir = 3; break;
        }
    }
}

void NormalKeyboard(unsigned char key, int, int) {
    if (key == 13) { //27 Escape
        if (gameState == MENU || gameState == GAMEOVER) {
            gameState = PLAYING;
            score = 0;
            num = 4;
            InitSnake();
        }
    }
    else if (key == 32) {
        if (gameState == PLAYING) {
            gameState = PAUSED;
        }
        else if (gameState == PAUSED) {
            gameState = PLAYING;
        }
    }
}