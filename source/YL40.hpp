#ifndef YL40_HPP
#define YL40_HPP
#include "hwlib.hpp"
#include "controler.hpp"

class YL40 : public controler
{
private:
    uint8_t slave;
    uint8_t readpin =  0x40;
    hwlib::i2c_bus_bit_banged_scl_sda & i2c_bus;
    
public:
    YL40(hwlib::i2c_bus_bit_banged_scl_sda & i2c_bus,char  slave);
    int get();
    void changreadout(char pin);
    void wirte();
    void singeWave(char waveType, int duration);

};

#endif // YL40_HPP
