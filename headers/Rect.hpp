#ifndef Rect_H
#define Rect_H
class Rect {
    public:
        Rect();
        Rect(int nx1, int ny1, int nx2, int ny2);
        void SetRect( int left, int top, int right, int bottom);
        void OffsetRect(int dx, int dy);
        void CenterPoint (int* x, int* y);
        bool IsRectEmpty();
        int Width();
        int Height();
        Rect IntersectRect(Rect& another);
        void NormalizeRect();
        int x1, y1, x2, y2;
};

#endif
