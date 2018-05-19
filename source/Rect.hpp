#ifndef Rect_H
#define Rect_H
class Rect {
    public:
        Rect();
        Rect(float nx1, float ny1, float nx2, float ny2);
        void SetRect( float left, float top, float right, float bottom);
        void OffsetRect(float dx, float dy);
        void CenterPoint (float* x, float* y);
        bool IsRectEmpty();
        int Width();
        int Height();
        bool IntersectRect(Rect another);
        void NormalizeRect();
        float x1, y1, x2, y2;
};

#endif
