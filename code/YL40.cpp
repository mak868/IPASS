#include "YL40.hpp"
/// @author Thomas Theil
/// @date 26-06-2018 14:00
/// @brief YL-40 ADC/DAC chip 
/// @details
/// This class controles the YL-40 board using the PCF8591 chip. \n
/// The PCF891 chip is a A/D and D/A converter controled via I2C. \n
/// for the data sheet folow  <a href="https://www.aurel32.net/elec/pcf8591.pdf">This</a> link. 
/// After boot the chip wil auto read Analog in 0 
///
/// @par i2c adress
///     the i2c adress is 0x48.
///
/// @pre 
/// This chips needs a hwlib i2c  to work
/// @endpre
///
/// YL-40 initialize(exampel)
/// @code
///    auto scl     = target::pin_oc( target::pins::scl );
///    auto sda      = target::pin_oc( target::pins::sda );
///    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
///    YL40 ADCi2(i2c_bus, 0x48);
/// @endcode
/// 
/// @warning This class needs hwlib to work.
YL40::YL40(hwlib::i2c_bus_bit_banged_scl_sda & i2c_bus,char  slave):
slave(slave),
i2c_bus(i2c_bus)
{
uint8_t handshake_init[1] = {0x40};
i2c_bus.write(slave, handshake_init, 1);
}

/// @brief changereadout(char pin)
/// @details
/// This function changes the read out pin of the chip
///
/// @par Pins
///     <b>AIN0</b> 0 \n
///     <b>AIN1</b> 1 \n
///     <b>AIN2</b> 2 \n
///     <b>AIN3</b> 3 \n
///
///

void YL40::changreadout(char pin){
    switch(pin){ 
        default:
            readpin = 0x0;
        break;
        case 1:
            readpin = 0x01;
        break;
        case 2:
            readpin = 0x02;
        break;
        case 3:
            readpin = 0x03;
        break;
    }
}
/// @brief get()
/// @details
/// Get the output of the A/D
///
/// @results returns int


int YL40::get(){
    uint8_t read_register[1] = {};
    uint8_t sendByte[1] = {readpin};
    
    i2c_bus.write(slave, sendByte, 1);
    i2c_bus.read(slave, read_register , 1);        
     return read_register[0];
}

