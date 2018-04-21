#ifndef Ball_H
#define Ball_H
#include "Rect.hpp"
class Ball{
    public:
        Ball(int x, int y, float radius, double dir, int mass,  Ball* pNextBall);
        void Draw();
        void Update();
        void HitBy( Ball* pBall);
        double HitAngle(double dx, double dy);
        //для доступа к переменным класса
        void SetSpeed( double newSpeed);
        void SetCenter(float newx, float newy);
        void SetDirection( double newDir);
        float GetRadius();
        Ball* GetLink();
        void GetCenter(float* x, float* y);
        double GetSpeed();
        double GetDirection();
        int GetMass();
        double GetAngleCenters(int x1, int y1, int x2, int y2);
    private:
        Ball* pLink;
        float radius;
        double direction;
        int x;
        int y;
        double speed;
        int mass;
};
#endif
