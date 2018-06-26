#include "potmeter.hpp"
/// @author Thomas Theil
/// @date 26-06-2018 14:30
/// @brief potmeter readout
/// @details
/// read out the potmeter using tha YL40
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
///    potmeter controler2(ADCi2);
/// @endcode
/// 
/// @warning This class needs hwlib and YL40 to work.
potmeter::potmeter(YL40 & ADCi2):
 ADCi2(ADCi2)
{
}

/// @brief get()
/// @details
/// Get the output of the A/D
///
/// @results returns int
int potmeter::get()
{
    return ADCi2.get()/2.55;
}

