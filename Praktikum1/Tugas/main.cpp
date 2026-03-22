#include <GL/glut.h>
#include <math.h>

// 1. LINE STRIP
void drawLineStrip()
{
    glBegin(GL_LINE_STRIP);
        glColor3f(1,0,0);
        glVertex2f(-0.9,0.8);
        glVertex2f(-0.7,0.6);
        glVertex2f(-0.5,0.8);
        glVertex2f(-0.3,0.6);
    glEnd();
}

// 2. LINE LOOP
void drawLineLoop()
{
    glBegin(GL_LINE_LOOP);
        glColor3f(0,1,0);
        glVertex2f(-0.2,0.8);
        glVertex2f(0.0,0.6);
        glVertex2f(0.2,0.8);
        glVertex2f(0.0,1.0);
    glEnd();
}

// 3. TRIANGLE FAN (lingkaran sederhana)
void drawTriangleFan()
{
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1,1,0);
        glVertex2f(0.6,0.8);
        for(int i=0;i<=20;i++){
            float angle = i * 3.14159 * 2 / 20;
            glVertex2f(0.6 + 0.1*cos(angle), 0.8 + 0.1*sin(angle));
        }
    glEnd();
}

// 4. TRIANGLE STRIP
void drawTriangleStrip()
{
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0,1,1);
        glVertex2f(-0.9,0.4);
        glVertex2f(-0.8,0.2);
        glVertex2f(-0.7,0.4);
        glVertex2f(-0.6,0.2);
    glEnd();
}

// 5. QUADS
void drawQuads()
{
    glBegin(GL_QUADS);
        glColor3f(1,0,1);
        glVertex2f(-0.4,0.4);
        glVertex2f(-0.2,0.4);
        glVertex2f(-0.2,0.2);
        glVertex2f(-0.4,0.2);
    glEnd();
}

// 6. QUAD STRIP
void drawQuadStrip()
{
    glBegin(GL_QUAD_STRIP);
        glColor3f(0.5,0.5,1);
        glVertex2f(0.0,0.4);
        glVertex2f(0.0,0.2);
        glVertex2f(0.2,0.4);
        glVertex2f(0.2,0.2);
        glVertex2f(0.4,0.4);
        glVertex2f(0.4,0.2);
    glEnd();
}

// 7. Kubus bertingkat (5 kotak)
void drawCube(float x, float y)
{
    glBegin(GL_QUADS);
        glColor3f(0.2,0.6,1);
        glVertex2f(x,y);
        glVertex2f(x+0.15,y);
        glVertex2f(x+0.15,y+0.15);
        glVertex2f(x,y+0.15);
    glEnd();
}

void drawCubes()
{
    // bawah (3 kubus)
    drawCube(-0.3,-0.6);
    drawCube(-0.1,-0.6);
    drawCube(0.1,-0.6);

    // atas (2 kubus)
    drawCube(-0.2,-0.4);
    drawCube(0.0,-0.4);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawLineStrip();
    drawLineLoop();
    drawTriangleFan();
    drawTriangleStrip();
    drawQuads();
    drawQuadStrip();
    drawCubes();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Tugas OpenGL Primitive");

    glClearColor(0,0,0,1);

    glutDisplayFunc(display);
    glutMainLoop();
}
