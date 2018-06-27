#include "HCSR04.hpp"
/// @author Thomas Theil
/// @date 25-06-2018 14:00
/// @brief HCSR04 sensor class 
/// @details
/// This class wil read out the HC-SR04 Ultrasonic Sensor.\n
/// 
/// @pre 
/// To construct this class will need one output pin and one inputpin !.
/// @endpre
///
/// HCSR04 initialize(exampel)
/// @code
/// auto trigger = target::pin_out(target::pins::d7);
/// auto echo    = target::pin_in(target::pins::d6);
/// HCSR04 sensor2(trigger,echo);
/// @endcode
/// 
/// @warning This class needs hwlib to work.

HCSR04::HCSR04(hwlib::target::pin_out & trigger, hwlib::target::pin_in & echo):
            trigger(trigger),
            echo(echo)
{}
/// @brief Get()
/// @details
/// Getting the distance that calculate of the HC-SR04
/// The distance is in % calculate of the max distance 150. 
///
/// @warning The bigger the distance is the slower the function will response
///
/// @returns int  
///
/// HCSR04.get()
///
/// @par example
/// @code
/// sensor2.get();
/// @endcode
/// 
int  HCSR04::get(){
    long long int timestamps[1]={};
    
    trigger.set(1);
    hwlib::wait_ms(10);
    trigger.set(0);
    int i = 0; //secure
    
    while(echo.get() == 0 && i < 11000){i++;};
    timestamps[0] = hwlib::now_us();
    i=0;
    
    while(echo.get() == 1 && i < 11000 ){i++;};
    timestamps[1] = hwlib::now_us();
    i=0;
    
    trigger.set(0);

    long long int mm =(timestamps[1]-timestamps[0])/58;
    if(mm > 30) return 100;
    
    return  mm/0.3;
}