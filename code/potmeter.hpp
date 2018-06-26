#ifndef POTMETER_HPP
#define POTMETER_HPP
#include "hwlib.hpp"
#include "controler.hpp"
#include "YL40.hpp"

class potmeter: public controler
{ 
public:
        YL40 & ADCi2;
public:
    potmeter(YL40 & ADCi2);
    int get();

};

#endif // POTMETER_HPP
