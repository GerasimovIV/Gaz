#ifndef Wall_H
#define Wall_H
#include "Rect.hpp"
class Wall {
    public:
        Wall (int left, int top, int right, int bottom, double cf, Wall* pNextWall );
        void Draw();
        void HitBy( Ball* pBall);
        Rect GetRegion() { return region; }
        Wall* GetLink() { return pLink; }
    private :
        Wall* pLink;
        Rect region;
        double converFactor;
};
#endif
