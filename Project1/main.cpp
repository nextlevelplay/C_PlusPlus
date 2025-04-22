#include <GL/glut.h>
#include <cstdlib>

//float screen_width = 640, screen_height = 480;

int i = 0;
int n = 30;
int m = 20;
int scale = 25;

int w = scale * n;
int h = scale * m;

int dir, num = 4;

struct
{ 
	int x;
	int y;
}
s[100];

class Apple {
public:
	int x, y;

	void New() {
		x = rand() % n;
		y = rand() % m;
	}
	void DrawApple() {
		glColor3f(0.0, 1.0, 0.0);
		glRectf(x * scale, y * scale, (x + 1) * scale, (y + 1) * scale);
	}

}
a[10];


void tick() {

	for (int i = num; i > 0; --i) {
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}


	if (dir == 0) s[0].y += 1;
	if (dir == 1) s[0].x -= 1;
	if (dir == 2) s[0].x += 1;
	if (dir == 3) s[0].y -= 1;

	for (int i=0; i < 10;i++) {
		if ((s[0].x == a[i].x) && (s[0].y == a[i].y)) {
			num++; a[i].New();
		}
	}


}


void drawField() {
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

void drawSnake() {
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < num; i++) {
		glRectf(s[i].x * scale, s[i].y * scale, (s[i].x + 1) * scale, (s[i].y + 1) * scale);
	}
}

void keyboard(int key, int a, int b) {
	switch (key)
	{
	case 101: dir = 0; break;
	case 102: dir = 2; break;
	case 100: dir = 1; break;
	case 103: dir = 3; break;
	
	}

}

static void display() {
	
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0;i < 10;i++) {
		a[i].DrawApple();
	}

	drawField();
	drawSnake();
	glFlush();
}

void timer(int = 0) {
	display();
	tick();
	glutTimerFunc(120, timer, 0);
}


int main(int argc, char **argv) {
	
	for (int i = 0; i < 10;i++) {
		a[i].New();
	}
	
	s[0].x = 10;
	s[0].y = 10;


	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutCreateWindow("Test");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glutDisplayFunc(display);
	glutTimerFunc(120, timer, 0);
	glutSpecialFunc(keyboard);
	glutMainLoop();

}