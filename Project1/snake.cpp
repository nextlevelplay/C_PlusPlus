#include "snake.h"
#include "globals.h"
#include "apple.h"
#include <GL/glut.h>

Segment snake[100];
int num = 4;
int dir = 0;

void InitSnake() {
    snake[0].x = 10;
    snake[0].y = 10;
}

void MoveSnake() {
    for (int i = num; i > 0; --i) {
        snake[i] = snake[i - 1];
    }

    if (dir == 0) snake[0].y += 1;
    if (dir == 1) snake[0].x -= 1;
    if (dir == 2) snake[0].x += 1;
    if (dir == 3) snake[0].y -= 1;

    for (int i = 0; i < 10; i++) {
        if (snake[0].x == apples[i].x && snake[0].y == apples[i].y) {
            num++; apples[i].New();
        }
    }

    if (snake[0].x >= n) dir = 1;
    if (snake[0].x < 0) dir = 2;
    if (snake[0].y >= m) dir = 3;
    if (snake[0].y < 0) dir = 0;

    for (int i = 1; i < num; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            num = i;
    }
}

void DrawSnake() {
    glColor3f(0.0, 0.0, 1.0);
    for (int i = 0; i < num; i++) {
        glRectf(snake[i].x * scale, snake[i].y * scale,
            (snake[i].x + 1) * scale, (snake[i].y + 1) * scale);
    }
}
