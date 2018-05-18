#include <iostream>
#include "Wall.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/freeglut.h>
using std::cout;
using std::endl;


Wall::Wall( float left, float top, float right, float bottom,
        double cf, Wall* pNextWall )
{
    this->convertFactor = cf;
    region.SetRect( left, top, right, bottom );
    pLink = pNextWall;
}

void Wall::Draw()
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(float(this->region.x1), float(this->region.y1), 0.0);
    glVertex3f(float(this->region.x1), float(this->region.y2), 0.0);
    glVertex3f(float(this->region.x2), float(this->region.y2), 0.0);
    glVertex3f(float(this->region.x2), float(this->region.y1), 0.0);
    glEnd();
}

void Wall::HitBy( Ball* pBall )
{
    pBall->SetDirection( this->convertFactor - pBall->GetDirection() );
}




