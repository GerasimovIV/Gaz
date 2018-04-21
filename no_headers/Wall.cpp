#include <iostream>
#include "Wall.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/freeglut.h>
using std::cout;
using std::endl;


Wall::Wall( int left, int top, int right, int bottom,
        double cf, Wall* pNextWall )
{
    this->convertFactor = cf;
    region.SetRect( left, top, right, bottom );
    pLink = pNextWall;
}

void Wall::Draw()
{
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




