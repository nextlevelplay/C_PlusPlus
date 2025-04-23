#pragma once

struct Segment {
    int x, y;
};

void InitSnake();
void MoveSnake();
void DrawSnake();

extern Segment snake[100];
extern int num;
extern int dir;