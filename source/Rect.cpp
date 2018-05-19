#include <iostream>
#include "Rect.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using std::cout;
using std::endl;
Rect::Rect()
{
    x1 = 0;
    x2 = 0;
    y1 = 0;
    y2 = 0;
}

Rect::Rect( float nx1, float ny1, float nx2, float ny2 )
{
    x1 = nx1; 
    y1 = ny1; 
    x2 = nx2; 
    y2 = ny2;
}

void Rect::SetRect( float left, float top, float right, float bottom )
{
    x1 = left; 
    y1 = top; 
    x2 = right; 
    y2 = bottom;
}
void Rect::OffsetRect( float dx, float dy )
{
    x1 += dx; 
    y1 += dy; 
    x2 += dx; 
    y2 += dy;
}
void Rect::CenterPoint( float* x, float* y )
{
    *x = (x1 + x2)/2; 
    *y = (y1 + y2)/2;
}
bool Rect::IsRectEmpty()
{
    return ( x1 == x2 && y1 == y2 );
}
int Rect::Width()
{
    return x2 - x1 + 1;
}
int Rect::Height()
{
    return y2 - y1 + 1;
}
bool  Rect::IntersectRect( Rect another )
{
    this->NormalizeRect();
    another.NormalizeRect();
//    printf("%f | %f | %f \n", this->x1, another.x1, this->x2);
    //обнаружим пересечение по первой координате
    if (((this->x1 <= another.x1) && (another.x1 <= this->x2)) || ((this->x1 <= another.x2) && (another.x2 <= this->x2)))
    {
        //по второй координате
        if (((this->y1 >= another.y1) && (another.y1 >= this->y2)) || ((this->y1 >= another.y2) && (another.y2 >= this->y2)))
        {

            return true;
        }
    }
    return false;
}
void Rect::NormalizeRect()
{
    if (this->x1 > this->x2)
    {
        int t = this->x1;
        this->x1 = this->x2;
        this->x2 = t;
    }
    if (this->y1 < this->y2)
    {
        int r = this->y1;
        this->y1 = this->y2;
        this->y2 = r;
    }
}
