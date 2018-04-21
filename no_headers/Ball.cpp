#include <iostream>
#include "Ball.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Ball.hpp>
#include <GL/freeglut.h>

float pi = 3.14159;

using std::cout;
using std::endl;
void Ball::SetSpeed( double newSpeed)
{
    this->speed = newSpeed;
}

void Ball::SetCenter(float newx, float newy)
{
    this->x = newx;
    this->y = newy;
}

void Ball::SetDirection(double newDir)
{
    this->direction = newDir;
}

float Ball::GetRadius()
{
    return this->radius;
}

Ball* Ball::GetLink()
{
    return this->pLink;
}

double Ball::GetSpeed()
{
    return this->speed;
}

void Ball::GetCenter(float *x, float *y)
{
    *x = this->x;
    *y = this->y;
}

double Ball::GetDirection()
{
    return this->direction;
}

int Ball::GetMass()
{
    return this->mass;
}

Ball::Ball( int x, int y, float radius, double dir, int mass, Ball* pNextBall )
{
    this->SetCenter( x, y );
    this->SetDirection( dir );
    this->pLink = pNextBall;
    this->mass = mass;
    this->radius = radius;

}

void Ball::Draw()
{ 
    float x = this->x;
    float y = this->y;
    float r = this->radius;
    float amountSegments = 100;
    glBegin(GL_POLYGON);
    for(int i = 0; i < amountSegments ; i++)
    {
        float angle1 = 2.0 * 3.1415926 * float(i) / float(amountSegments);
        float dx = r * cosf(angle1);
        float dy = r * sinf(angle1);
        glVertex3f(x + dx, y + dy, 0.0);
    }
    glEnd();
}


double Ball::GetAngleCenters(int x1, int y1, int x2, int y2)
{
    if ((x1 == x2) && (y1 < y2))
    {
        return pi/2;
    }
    if ((x1 == x2) && (y1 > y2))
    {
        return -pi/2;
    }
    if ((y1 == y2) && (x1 > x2))
    {
        return pi;
    }
    if ((y1 == y2) && (x1 < x2))
    { 
        return 0;
    }

    return atan((y2-y1)/(x2-x1));
}

void Ball::HitBy( Ball* pBall)
{
    //расчет нового направления для шаров
    float x1, y1, x2, y2;
    this->GetCenter( &x1, &y1);
    pBall->GetCenter(&x2, &y2);
    double angle_centers = GetAngleCenters(x1, y1, x2, y2);
    // компонента х
    double angle_itog1 = -angle_centers + this->direction;
    double v1x = this->speed * cos(angle_itog1);
    double angle_itog2 = -angle_centers + pBall->direction;
    double v2x = pBall->speed * cos(angle_itog2);
    double a = this->mass / pBall->mass;
    double newv1x = (2*v2x + a*v1x - v1x) / (a + 1);
    double newv2x = (v2x*(1 - a) + 2*v1x*a) / (a + 1);
    // компонента у
    double v1y = this->speed * sin(angle_itog1);
    double v2y = pBall->speed * sin(angle_itog2);
    double newv1y = (2*v2y + a*v1y - v1y) / (a + 1);
    double newv2y = (v2y*(1 - a) + 2*v1y*a) / (a + 1);

    // угол в системе где ox || прямой на кот лежат центры масс
    double angle1 = atan(newv1y / newv1x);
    double angle2 = atan(newv2y / newv2x);
    // угол в лаб системе отсчета
    double angle1_lab1 = angle_centers + angle1;
    double angle1_lab2 = angle_centers + angle2;
    this->SetDirection(angle1_lab1);
    pBall->SetDirection(angle1_lab2);

    //расчеты для модулей скоростей
    this->SetSpeed( sqrt(newv1x*newv1x + newv1y*newv1y));
    pBall->SetSpeed( sqrt(newv1x*newv2x + newv1y*newv2y));
}


