#include <windows.h> 
#include <glut.h> 
#include <cmath>
#include <iostream>


const int width = 640;
const int height = 480;

class Box
{
public:
	void draw()
	{
		glBegin(GL_QUADS);           
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(-0.3f, 0.6f);
		glVertex2f(0, 0.6f);
		glVertex2f(0, 0.9f);
		glVertex2f(-0.3f, 0.9f);
		glEnd();
	}
};

class Circle
{
public:
	void draw()
	{
		// Draw Circle
		glBegin(GL_LINE_LOOP);
		int num_segments = 100;
		float r = 0.25, cx = 0.7, cy = -0.25;
		for (int ii = 0; ii < num_segments; ii++) {
			float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
			float x = r * cosf(theta);//calculate the x component 
			float y = r * sinf(theta);//calculate the y component 
			glVertex2f(x + cx, y + cy);//output vertex 
		}
		glEnd();
	}
};

template <class DrawObject>
class GeometricObjectInterface
{
public:
	void draw()
	{
		DrawObject draw_in_shape;
		draw_in_shape.draw();
	}
};

void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
;
	GeometricObjectInterface<Box> box_;
	GeometricObjectInterface<Circle> circle_;

	box_.draw();
	circle_.draw();
	glFlush();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 
	glutCreateWindow("OpenGL Setup Test");
	glutInitWindowSize(width, height); 
	glutInitWindowPosition(50, 50); 
	glutReshapeWindow(width, height);
	glutDisplayFunc(display);
	glutMainLoop();  
	return 0;
}