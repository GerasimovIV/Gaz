#ifndef Ball_H
#define Ball_H
#include "Rect.hpp"
class Ball{
    public:
        Ball(int x, int y, int mass,  Ball* pNextBall);
        vooid Draw();
        void Update();
        void HitBy( Ball* pBall);
        doulble HitAngle(double dx, double dy);
        //для доступа к переменным класса
        void SetSpeed( double newSpeed);
        void SetCenter(int newx, int newy);
        void SetDirection( double newDir);
        Rect GetRegion();
        Ball* GetLink();
        void GetCenter(int* x, int* y);
        double GetSpeed();
        double GetDirection();
        int GetMass();
        double GetAngleCenters(int x1, int y1, int x2, int y2)
    private:
        Ball* pLink;
        Rect region;
        double direction;
        int x;
        int y;
        double speed;
        int mass;
};
#endif
