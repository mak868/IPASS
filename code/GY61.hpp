#ifndef GY61_HPP
#define GY61_HPP
#include "hwlib.hpp"
#include "controler.hpp"
#include "YL40.hpp"


class GY61: public controler
{
public:
        YL40 & ADCi2;
        char axis = 0;
        int  base;
public:
    GY61(YL40 & ADCi2, char axis );
    int get();

};

#endif // GY61_HPP
