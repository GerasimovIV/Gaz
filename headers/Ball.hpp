#ifndef Ball_H
#define Ball_H
#include "Rect.hpp"
class Ball{
    public:
        Ball(float x, float y, float radius, double dir, int mass, float speed, Ball* pNextBall);
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
        float GetSpeed();
        double GetDirection();
        int GetMass();
        double GetAngleCenters(int x1, int y1, int x2, int y2);
        Rect GetRegion() { return region; }
        
        
        
    private:
        Ball* pLink;
        Rect region;
        float x;
        float y;
        float speed;
        float radius;
        double direction;
        int mass;
};
#endif
