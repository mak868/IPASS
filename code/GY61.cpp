#include "GY61.hpp"
/// @author Thomas Theil
/// @date 26-06-2018 15:00
/// @brief GY-61  chip
/// @details
/// read out the GY-61 chip using tha YL-40
/// for more information loop at @ref YL40()
///
///
/// @pre 
///  This class uses YL40 for its workings
/// @endpre
///
/// potmeter initialize(exampel)
/// @code
///    auto scl     = target::pin_oc( target::pins::scl );
///    auto sda      = target::pin_oc( target::pins::sda );
///    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
///    YL40 ADCi2(i2c_bus, 0x48);
///    GY61 controler2(ADCi2);
/// @endcode
/// 
/// @warning This class needs hwlib and YL40 to work.
GY61::GY61(YL40 & ADCi2, char axis ):
 ADCi2(ADCi2),
 axis(axis)
{
    base = ADCi2.get();
}

/// @brief get()
/// @details
/// Get the output of the A/D
///
/// @results returns int
int GY61::get(){
    int data = ADCi2.get();
    return data/((base*2)/100); 
}