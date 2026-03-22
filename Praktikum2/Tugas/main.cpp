#include <GL/glut.h>
#include <math.h>

float posisiMobil = -1.2;
float rotasiRoda = 0;

void circle(float r)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
        float a = i * 3.14159 / 180;
        glVertex2f(r*cos(a), r*sin(a));
    }
    glEnd();
}

// ================= RODA =================
void roda()
{
    glPushMatrix();
    glRotatef(rotasiRoda,0,0,1);

    glColor3f(0,0,0);
    circle(0.08);

    glColor3f(0.8,0.8,0.8);
    glBegin(GL_LINES);
        glVertex2f(-0.08,0);
        glVertex2f(0.08,0);
        glVertex2f(0,-0.08);
        glVertex2f(0,0.08);
    glEnd();

    glPopMatrix();
}

// ================= BAYANGAN =================
void shadow()
{
    glColor4f(0,0,0,0.3);
    glBegin(GL_QUADS);
        glVertex2f(-0.3,-0.02);
        glVertex2f(0.3,-0.02);
        glVertex2f(0.25,-0.08);
        glVertex2f(-0.25,-0.08);
    glEnd();
}

// ================= MOBIL =================
void mobil()
{
    glPushMatrix();
    glTranslatef(posisiMobil, -0.35, 0);

    shadow();

    // body
    glColor3f(0.8,0,0);
    glBegin(GL_QUADS);
        glVertex2f(-0.35,0);
        glVertex2f(0.35,0);
        glVertex2f(0.35,0.18);
        glVertex2f(-0.35,0.18);
    glEnd();

    // atap
    glBegin(GL_POLYGON);
        glVertex2f(-0.2,0.18);
        glVertex2f(0.2,0.18);
        glVertex2f(0.1,0.32);
        glVertex2f(-0.1,0.32);
    glEnd();

    // kaca
    glColor3f(0.7,0.9,1);
    glBegin(GL_QUADS);
        glVertex2f(-0.18,0.19);
        glVertex2f(-0.02,0.19);
        glVertex2f(-0.02,0.3);
        glVertex2f(-0.18,0.3);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(0.02,0.19);
        glVertex2f(0.18,0.19);
        glVertex2f(0.18,0.3);
        glVertex2f(0.02,0.3);
    glEnd();

    // lampu mobil
    glPushMatrix();
    glTranslatef(0.35,0.07,0);
    glColor3f(1,1,0);
    circle(0.03);
    glPopMatrix();

    // roda kiri
    glPushMatrix();
    glTranslatef(-0.2,0,0);
    roda();
    glPopMatrix();

    // roda kanan
    glPushMatrix();
    glTranslatef(0.2,0,0);
    roda();
    glPopMatrix();

    glPopMatrix();
}

// ================= OBJEK TAMBAHAN =================
void pohon(float x)
{
    glPushMatrix();
    glTranslatef(x,-0.3,0);

    glColor3f(0.4,0.2,0);
    glBegin(GL_QUADS);
        glVertex2f(-0.02,0);
        glVertex2f(0.02,0);
        glVertex2f(0.02,0.2);
        glVertex2f(-0.02,0.2);
    glEnd();

    glColor3f(0,0.8,0);
    glTranslatef(0,0.25,0);
    circle(0.08);

    glPopMatrix();
}

void awan(float x, float y)
{
    glPushMatrix();
    glTranslatef(x,y,0);

    glColor3f(1,1,1);
    circle(0.07);
    glTranslatef(0.08,0,0);
    circle(0.07);
    glTranslatef(-0.16,0,0);
    circle(0.07);

    glPopMatrix();
}

void lampu(float x)
{
    glPushMatrix();
    glTranslatef(x,-0.3,0);

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
        glVertex2f(-0.01,0);
        glVertex2f(0.01,0);
        glVertex2f(0.01,0.4);
        glVertex2f(-0.01,0.4);
    glEnd();

    glColor3f(1,1,0);
    glTranslatef(0,0.45,0);
    circle(0.03);

    glPopMatrix();
}

// gradient langit
void skyGradient()
{
    glBegin(GL_QUADS);
        glColor3f(0.1,0.2,0.6);
        glVertex2f(-1,1);
        glVertex2f(1,1);

        glColor3f(0.5,0.7,1);
        glVertex2f(1,-1);
        glVertex2f(-1,-1);
    glEnd();
}

// jalan
void road()
{
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
        glVertex2f(-1,-0.5);
        glVertex2f(1,-0.5);
        glVertex2f(1,-0.2);
        glVertex2f(-1,-0.2);
    glEnd();

    glColor3f(1,1,1);
    for(float i=-1;i<1;i+=0.3){
        glBegin(GL_QUADS);
            glVertex2f(i,-0.36);
            glVertex2f(i+0.15,-0.36);
            glVertex2f(i+0.15,-0.34);
            glVertex2f(i,-0.34);
        glEnd();
    }
}

// ================= DISPLAY =================
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    skyGradient();
    road();

    awan(-0.5,0.6);
    awan(0.2,0.7);

    pohon(-0.7);
    pohon(-0.3);
    pohon(0.3);
    pohon(0.7);

    lampu(-0.5);
    lampu(0.5);

    mobil();

    glutSwapBuffers();
}


void update(int v)
{
    posisiMobil += 0.005;
    rotasiRoda -= 3;

    if(posisiMobil > 1.2)
        posisiMobil = -1.2;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// main
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Mobil 2D Advanced");

    glClearColor(0,0,0,1);

    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
}
