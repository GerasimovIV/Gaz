#include <math.h>
#include <GL/freeglut.h> 
#include "Ball.hpp"
#include "Wall.hpp"
#include <cmath>
#include <stdio.h>
float angle = 0.0f; 

// х у радиус направление масса скорость след
Ball* ball1 = new Ball(3, 0, 0.2, 3.1415, 1, 0.1,  NULL);
Ball* ball2= new Ball(-2, 0.2, 1, 1, 8, 0,  ball1);



Wall* left_wall = new Wall(-4.0, 4.0, -3.5, -4.0, 3.1415, NULL);
Wall* right_wall = new Wall(3.5, 4.0, 4.0, -4.0, -3.1415, left_wall);
Wall* top_wall = new Wall(-4.0, 5.0, 4.0, 4.0, 0, right_wall);
Wall* bottom_wall = new Wall(-4.0, -4.0, 4.0, -5.0, 0, top_wall);

float modul(float a)
{
    if ( a >= 0 )
    {
        return a;
    }
    return -a;
    
}

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


    // проверка на соударения со стенками
    // Проверка на попадание в стенку
    //


    Ball* ball = ball2;
    while (ball != NULL)
    {
        Ball* t = ball2;

        float x5, x6;
        ball->GetCenter(&x5, &x6);
        ball->SetCenter(x5 + (ball->GetSpeed())*cosf(ball->GetDirection()), x6 + (ball->GetSpeed())*sin(ball->GetDirection()));

	    Wall* stena = bottom_wall;
        printf("%f | %f\n", (ball1->GetRegion()).x1, (ball2->GetRegion()).x1);
	    while ( stena != NULL )
	    {
		    if ( (stena->GetRegion()).IntersectRect( ball->GetRegion() ) == true )
            {
                ball->SetDirection(stena->GetConvertFactor() - ball->GetDirection());
                ball->SetCenter(x5 + (ball->GetSpeed())*cosf(ball->GetDirection()), x6 + (ball->GetSpeed())*sin(ball->GetDirection()));

            }
            stena = stena->GetLink();
        }
        while (t != NULL)
        {
            if (t != ball)
            {
                float x_1, y_1;
                float x_2, y_2;
                t->GetCenter(&x_1, &y_1);
                ball->GetCenter(&x_2, &y_2);
                float distance = sqrt((x_1 - x_2)*(x_1 - x_2) + (y_1 - y_2)*(y_1 - y_2));
                if ( distance <= (t->GetRadius() + ball->GetRadius()))
                {
                    printf("YES\n");
                    ball->HitBy(t);
                    printf("2222 %f | %f\n", (ball1->GetRegion()).x1, (ball2->GetRegion()).x1);
                }
            }
            t = t->GetLink();
        }
        ball = ball->GetLink();
    }

/*    if (ball1->GetRadius() >= modul( x5 + 3.5))
    {
        ball1->SetDirection(3.1415 - ball1->GetDirection());
        ball1->SetCenter(x5 + (ball1->GetSpeed())*cosf(ball1->GetDirection()), x6 + (ball1->GetSpeed())*sin(ball1->GetDirection()));

    }*/
    ball1->Draw();
    ball2->Draw();
//    printf("%f\n", ball1->speed);
   

    bottom_wall->Draw();
    left_wall->Draw();
    right_wall->Draw();
    top_wall->Draw();
    
    




/*    glColor3f(0.0, 0.0, 1.0);
    float x2 = -1;
    float y2 = -1;
    float r2 = 0.2;

   
    glBegin(GL_POLYGON);
    for(int j = 0; j < 100 ; j++)
    {
        float angle12 = 2.0 * 3.1415926 * float(j) / float(100);
        float dx2 = r2 * cosf(angle12);
        float dy2 = r2 * sinf(angle12);
        glVertex3f(x2 + dx2 - i, y2 + dy2, 0.0);
    }
    glEnd();*/
//    angle+=0.9f; 
   



    glutSwapBuffers(); 
} 

int main(int argc, char **argv) 
{ 

// Инициализация GLUT и создание окна 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
    glutInitWindowPosition(100,100); 
    glutInitWindowSize(800,800); 
    glutCreateWindow("treeangle"); 

// регистрация вызываемых функций
    glutDisplayFunc(renderScene); 
    glutReshapeFunc(changeSize); 
    glutIdleFunc(renderScene); 

// основной цикл 
    glutMainLoop(); 

    return 0; 
}
