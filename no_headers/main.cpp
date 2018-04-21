#include <math.h>
#include <GL/freeglut.h> 
#include "Ball.hpp"
#include "Wall.hpp"
float angle = 0.0f; 
float i = 0.0f;
Ball* ball1 = new Ball(2, 1, 0.2, 0.0, 1,  NULL);
//Wall* right_wall = new Wall(-4.0, 4.0, -3.9999999, -4.0, 1, NULL);



void changeSize(int w, int h)
{ 
// предотвращение деления на ноль 
    if (h == 0)
    {
        h = 1;
    } 
    float ratio = w * 1.0 / h; 
// используем матрицу проекции 
    glMatrixMode(GL_PROJECTION); 
// обнуляем матрицу 
    glLoadIdentity(); 
// установить параметры вьюпорта 
    glViewport(0, 0, w, h); 
// установить корректную перспективу 
    gluPerspective(45.0f, ratio, 0.1f, 100.0f); 
// вернуться к матрице проекции 
    glMatrixMode(GL_MODELVIEW); 
} 

void renderScene(void)
{ 
// очистка буфера цвета и глубины 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
// обнуление трансформации 
    glLoadIdentity(); 
// установка камеры 
    gluLookAt( 0.0f, 0.0f, 10.0f,0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); 
  


    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    ball1->Draw();

    float x1, y1;
    ball1->GetCenter(&x1, &y1);
    ball1->SetCenter(x1-i, y1);
    glColor3f(0.0, 0.0, 1.0);
    float x = 0;
    float y = 0;
    float r = 0.2;

    glBegin(GL_POLYGON);
    for(int j = 0; j < 100 ; j++)
    {
        float angle1 = 2.0 * 3.1415926 * float(j) / float(100);
        float dx = r * cosf(angle1);
        float dy = r * sinf(angle1);
        glVertex3f(x + dx + i, y + dy, 0.0);
    }
    glEnd();
    glColor3f(0.0, 1.0 , 0.0);
//    glColor3f(1.0, 0.0, 0.0);
//    right_wall->Draw();


    ball1->SetCenter(2-i, 1);
//    angle+=0.9f; 
    i += 0.02;



    glutSwapBuffers(); 
} 

int main(int argc, char **argv) { 

// Инициализация GLUT и создание окна 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
    glutInitWindowPosition(100,100); 
    glutInitWindowSize(800,800); 
    glutCreateWindow("treeangle"); 

// регистрация 
    glutDisplayFunc(renderScene); 
    glutReshapeFunc(changeSize); 
    glutIdleFunc(renderScene); 

// основной цикл 
    glutMainLoop(); 

    return 0; 
}
