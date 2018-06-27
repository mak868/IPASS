#include "tinyLidar.hpp"
/// @author Thomas Theil
/// @date 24-06-2018 16:00
/// @brief tinyLider
/// @details
/// This class will read out the tinyLidar module
/// 
/// @pre 
/// It needs i2c to read the tinylidar
/// @endpre
///
/// @par i2c adress
///  the i2c adress is 0x10.
///  for more information go to <a href="https://microedco.s3.amazonaws.com/tinyLiDAR/Documentation/tinyLiDAR%20Reference%20Manual%20rev1.26.pdf">tinyLidar</a> 
///
/// tinyLider initialize(example)
/// @code
///    auto scl     = target::pin_oc( target::pins::scl );
///    auto sda      = target::pin_oc( target::pins::sda );
///    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
///    tinylidar sensor1 (0x10 ,i2c_bus);
/// @endcode
/// 
/// @warning This class needs hwlib to work.
tinyLider::tinyLider(char  slave , hwlib::i2c_bus_bit_banged_scl_sda & i2c_bus):
            slave_1(slave),
            i2c_bus(i2c_bus)
{
    i2c_bus.write(0x10, handshake_init, 1);
}  

/// @brief distance()
/// @details
/// getting the distance of the tinyLidar sensor
/// 
int tinyLider::distance(){
    uint8_t read_register[2] = {};
    
    i2c_bus.write(0x10, handshake_init, 1);
    i2c_bus.read(0x10, read_register , 2); 
    
    //hwlib::wait_ms(10);
    return read_register[1];
}

/// @brief get()
/// @details
/// Get the distance in MM of the tinyLidar
/// 
///
/// @par Workings
///  The class will get a average of 3 readings.
///
/// tinyLider initialize(example)
/// @code
///    tinyLider.get();
/// @endcode
/// 
/// @returns int 

int tinyLider::get(){
    
    return this->distance()/(255/100);
}