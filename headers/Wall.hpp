#ifndef Wall_H
#define Wall_H
#include "Rect.hpp"
#include "Ball.hpp"
class Wall {
    public:
        Wall (float left, float top, float right, float bottom, double cf, Wall* pNextWall );
        void Draw();
        void HitBy( Ball* pBall);
        Rect GetRegion() { return region; }
        Wall* GetLink() { return pLink; }
        double GetConvertFactor() { return convertFactor; }
    private :
        Wall* pLink;
        Rect region;
        double convertFactor;
};
#endif
