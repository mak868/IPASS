#ifndef TINYLIDAR_HPP
#define TINYLIDAR_HPP
#include "hwlib.hpp"
#include "controler.hpp"

class tinyLider: public controler 
{
    private:
        uint8_t slave_1;
        uint8_t handshake_init[1] = {0x44};
        hwlib::i2c_bus_bit_banged_scl_sda i2c_bus;
        int distance();
            
    public:
        tinyLider(char  slave , hwlib::i2c_bus_bit_banged_scl_sda & i2c_bus);   
        int get();

};

#endif // TINYLIDAR_HPP
