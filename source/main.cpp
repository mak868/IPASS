/// 
/// @author Thomas Theil
/// @date 25-06-2018 14:00
/// @brief IPASS pong project
/// @details
/// This project is a end of the year school project. \n
/// the project will run on a Arduino DUE
/// \n \n
/// with a number of sensor as input


#include "hwlib.hpp"
#include "piezo.hpp"
#include "pongManger.hpp"

// sensors
#include "YL40.hpp"
#include "GY61.hpp"
#include "potmeter.hpp"
#include "tinyLidar.hpp"
#include "HCSR04.hpp"

#include <stdlib.h>     

int main(int argc, char **argv)
{
    
       // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    

    namespace target = hwlib::target;
    auto scl     = target::pin_oc( target::pins::scl );
    auto sda      = target::pin_oc( target::pins::sda );
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
    
    auto trigger = target::pin_out(target::pins::d7);
    auto echo    = target::pin_in(target::pins::d6);
    auto buzzerPin  = target::pin_out(target::pins::d5);   

    auto oled = hwlib::glcd_oled_buffered( i2c_bus, 0x3c ); 
   
    piezo buzzer(buzzerPin);
     
    //create controlers
    YL40 ADCi2(i2c_bus, 0x48);
    //tinyLider controler2(0x10,i2c_bus);
    potmeter controler2(ADCi2);
    //GY61 controler2(ADCi2);    // aceloromter
    HCSR04 controler1(trigger, echo);
 
    //create main objects
    cBall ball(64,32);
    cPaddel player1(1,0,controler1);
    cPaddel player2(127,0,controler2);
    
    //start the game
    pongManger pong(oled,ball,player1,player2,buzzer);
    


    while(1){
        pong.Update();
        pong.Draw();
    }    
}



