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


#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "C:\ti-software\Catch2\single_include\catch.hpp"


    namespace target = hwlib::target;
    auto scl     = target::pin_oc( target::pins::scl );
    auto sda      = target::pin_oc( target::pins::sda );
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
    
    auto trigger = target::pin_out(target::pins::d7);
    auto echo    = target::pin_in(target::pins::d6);
    

    YL40 ADCi2(i2c_bus, 0x48);
    

    tinyLider controler1(0x10,i2c_bus);
    potmeter  controler2(ADCi2);
    GY61      controler3(ADCi2);    // aceloromter
    HCSR04    controler4(trigger, echo);
    
    TEST_CASE( "Controler tinylider" ){
       REQUIRE(controler1.get() == 100);   
    }

    TEST_CASE( "Controler potmeter" ){
       REQUIRE(controler2.get() == 100);   
    }

    TEST_CASE( "Controler GY61" ){
       REQUIRE(controler3.get() == 100);   
    }
    TEST_CASE( "Controler HCSR04" ){
       REQUIRE(controler4.get() == 100);   
    }    
    
    
    
    TEST_CASE( "cball test" ){
       int x, y = 2;
       cBall ball(x,y); 
       ball.ramdomdir(6,1);
       REQUIRE(ball.getDir() >=  1 );
       REQUIRE(ball.getDir() <=  6 );   
    
       REQUIRE(ball.getX() ==  x );
       REQUIRE(ball.getY() ==  y );

       ball.changeDir(1);
       REQUIRE(ball.getDir() ==  1 );
       ball.update();
       REQUIRE(ball.getX() ==  (x-1) );
    }

    TEST_CASE( "cPaddel test" ){
        int x, y = 2;
       cPaddel player1(x,y,controler1);
       REQUIRE(player1.getX() ==  x );
       REQUIRE(player1.getY() ==  y );
       REQUIRE(player1.paddelSize() ==  10);
       
       //check the paddelSize
       player1.paddelSize(10);
       REQUIRE(player1.paddelSize() ==  20);
       
       // check for the update
       player1.update();
       REQUIRE(player1.getY() ==  (controler1.get()*0.50) );
       
    }
