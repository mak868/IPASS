#ifndef PIEZO_HPP
#define PIEZO_HPP
#include "hwlib.hpp"

class piezo
{
    private:
        hwlib::target::pin_out  & output;
        int Hz(int tone);

    public:
        piezo( hwlib::target::pin_out  & output);
        
        
        void tone(unsigned int tone, int duration);
        void song(int notes[],int duration[], int lenght);
};

#endif // PIEZO_HPP
