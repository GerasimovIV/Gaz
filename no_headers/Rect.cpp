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

Rect::Rect( int nx1, int ny1, int nx2, int ny2 )
{
    x1 = nx1; 
    y1 = ny1; 
    x2 = nx2; 
    y2 = ny2;
}

void Rect::SetRect( int left, int top, int right, int bottom )
{
    x1 = left; 
    y1 = top; 
    x2 = right; 
    y2 = bottom;
}
void Rect::OffsetRect( int dx, int dy )
{
    x1 += dx; 
    y1 += dy; 
    x2 += dx; 
    y2 += dy;
}
void Rect::CenterPoint( int* x, int* y )
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
Rect Rect::IntersectRect( Rect& another )
{
    // potom

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
