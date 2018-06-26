#ifndef CBALL_HPP
#define CBALL_HPP  
#include "hwlib.hpp" 

class cBall
{
private:
    int originalX,originalY;
    int x,y;
    int direction;

 public:
    cBall(int posX, int posY);
    void Reset();
    void changeDir(int newDir);
    void ramdomdir(char tresholdLeft = 3, char tresholdRight = 1);
    
    void update();
    
    int getX();
    int getY();
    int getDir();
    
};

#endif // CBALL_HPP
