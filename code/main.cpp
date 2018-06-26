#include "hwlib.hpp"
#include "tinyLidar.hpp"
#include "HCSR04.hpp"
#include "piezo.hpp"
#include "cBall.hpp"
#include "cPaddel.hpp"
#include "controler.hpp"
#include "pongManger.hpp"
#include "YL40.hpp"
#include "GY61.hpp"
#include "potmeter.hpp"
#include <stdlib.h>     

int main(int argc, char **argv)
{
    srand(hwlib::now_ticks());
    namespace target = hwlib::target;
    auto scl     = target::pin_oc( target::pins::scl );
    auto sda      = target::pin_oc( target::pins::sda );
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
    
    auto trigger = target::pin_out(target::pins::d7);
    auto echo    = target::pin_in(target::pins::d6);
    
    auto adc   = target::pin_in(target::pins::a1);

    
    auto buzzerPin  = target::pin_out(target::pins::d5);
    piezo buzzer(buzzerPin);
     
    auto oled = hwlib::glcd_oled( i2c_bus, 0x3c );  
    YL40 ADCi2(i2c_bus, 0x48);
    potmeter controler2(ADCi2);

    HCSR04 controler1(trigger, echo);
 
 
    cBall ball(64,32);
    cPaddel player1(1,0,controler1);
    cPaddel player2(127,0,controler2);
    
    pongManger pong(oled,ball,player1,player2,buzzer);
    
      

    pong.Draw();
    while(1){

        pong.Update();
        pong.Draw();
        
       
    }
    
/*
    piezo buzzer(buzzerPin);
    int  notes[8]  = {'c','d','e','f','g','a','b','C'};
    int  lenght[8] = {300,300,300,300,300,300,300,300};
    for(int i = 0; i < 7;i++){
        buzzer.song(notes,lenght,8);
        hwlib::wait_ms(2000);
    }
*/
    
}



