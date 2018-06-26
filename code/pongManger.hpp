#ifndef PONGMANGER_HPP
#define PONGMANGER_HPP

#include "cBall.hpp"
#include "cPaddel.hpp"
#include "piezo.hpp"
#include "controler.hpp"
#include "hwlib.hpp"

class pongManger
{
private:
            //display
        hwlib::glcd_oled  & display;
        //object
        cBall & ball;
        cPaddel & player1;
        cPaddel & player2;
        piezo & sound;
    
        int widthLevel = 128;
        int heightLevel = 60;
        bool quit;
        void score();

        
        //movement
        //HCSR04 & movePlayer1;
        

        
    public:
        pongManger(hwlib::glcd_oled  & oled, cBall & ball, cPaddel & player1, cPaddel & player2, piezo & sound);
        
        
        void Draw();
        void Update();
        void collision();

};

#endif // PONGMANGER_HPP
