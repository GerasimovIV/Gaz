#ifndef Ball_H
#define Ball_H
#include "Rect.hpp"
class Ball{
    public:
        Ball(float x, float y, float radius, double dir, int mass, float speed, Ball* pNextBall);
        ~Ball() {}
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
        float GetMass();
        double GetAngleCenters(float x1, float y1, float x2, float y2);
        Rect GetRegion() { return region; }
        double GetAngle_from( float new1x, float newv1y);
        void Gravit( Ball* t);
                
        
    private:
        Ball* pLink;
        Rect region;
        float x;
        float y;
        float speed;
        float radius;
        double direction;
        float mass;
};
#endif
