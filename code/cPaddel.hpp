#ifndef CPADDEL_HPP
#define CPADDEL_HPP
#include "HCSR04.hpp" 
#include "controler.hpp"
class cPaddel
{
    private:
            int x, y;
            int originalX, originalY;
            char paddel = 10;
            controler & inputcontroler;
    public:
        cPaddel(int posX, int posY, controler & inputcontroler);
        
        void Reset();
        int getX();
        int getY();
        char paddelSize(char newSize = 0);
        void update();

};

#endif // CPADDEL_HPP
