#include <iostream>
#include "Wall.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using std::cout;
using std::endl;


Wall::Wall( int left, int top, int right, int bottom,
        double cf, CWall* pNextWall )
{
    convertFactor = cf;
    region.SetRect( left, top, right, bottom );
    pLink = pNextWall;
}

void Wall::Draw()
{
    glColor3ub( 0, 255, 0 );
    glRecti( region.x1, region.y1, region.x2, region.y2 );
}

void Wall::HitBy( Ball* pBall )
{
    pBall->SetDirection( this->convertFactor - pBall->GetDirection() );
}




