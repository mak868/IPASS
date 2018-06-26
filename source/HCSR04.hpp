#ifndef HCSR04_HPP
#define HCSR04_HPP
#include "hwlib.hpp"
#include "controler.hpp"

class HCSR04 : public controler
{
    private:
        hwlib::target::pin_out  & trigger;
        hwlib::target::pin_in  & echo;

    public:
        HCSR04(hwlib::target::pin_out & trigger, hwlib::target::pin_in & echo);
        int get();
};

#endif // HCSR04_HPP
