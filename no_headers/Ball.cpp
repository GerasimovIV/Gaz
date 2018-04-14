#include <iostream>
#include "Ball.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ball.hpp"
using std::cout;
using std::endl;
void Ball::SetSpeed( double newSpeed)
{
    this->speed = newSpeed;
}

void Ball::SetCenter(int newx, int newy)
{
    this->x = newx;
    this->y = newy;
}

void Ball::SetDirection(double newDir)
{
    this->direction = newDir;
}

Rect Ball::GetRegion()
{
    return this->region;
}

Ball* Ball::GetLink()
{
    return this->pLink;
}

double Ball::GetSpeed()
{
    return this->speed;
}

void Ball::GetCenter(int* x, int* y)
{
    *x = this->x;
    *y = this->y;
}

double Ball::GetDirection()
{
    return this->direction();
}

int Ball::GetMass()
{
    return this->mass:
}

Ball::Ball( int x, int y, int mass, CBall* pNextBall )
{
    this->SetCenter( x, y );
    this->SetDirection( 0 );
    this->pLink = pNextBall;
    this->mass = mass;

}

void Ball::Draw()
{
    glColor3ub( 0, 0, 255 );
    glPointSize( (float)region.Width() );
    glEnable( GL_POINT_SMOOTH );
    glBegin( GL_POINTS );
    int cx, cy;
    region.CenterPoint( &cx, &cy );
    glVertex2i( cx, cy );
    glEnd();
    glDisable( GL_POINT_SMOOTH );
}

double Ball::GetAngleCenters(int x1, int y1, int x2, int y2)
{
    if ((x1 == x2) && (y1 < y2))
    {
        return pi/2;
    }
    if ((x1 = x2) && (y1 > y2))
    {
        return -pi/2;
    }
    if ((y1 = y2) && (x1 > x2))
    {
        return pi;
    }
                            }
    if ((y1 = y2) && (x1 < x2))
    { 
        return 0;
    }

    return atan((y2-y1)/(x2-x1));
}
}

void HitBy( Ball* pBall)
{
    //расчет нового направления для шаров
    int x1, y1, x2, y2;
    GetCenter( &x1, &y1);
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
    this->SetDirection(angle_lab1);
    pBall->SetDirection(angle_lab2);

    //расчеты для модулей скоростей
    this->SetSpeed( sqrt(newv1x*newv1x + newv1y*newv1y));
    pBall->SetSpeed( sqrt(newv1x*newv2x + newv1y*newv2y));
}


