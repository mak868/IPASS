#include "piezo.hpp"
/// @author Thomas Theil
/// @date 25-06-2018 15:30
/// @brief Piezo buzzer class. 
/// @details
/// This class wil output a sound over a piezo buzzer. \n
/// 
/// @pre 
/// To construct this class will need a output pin.
/// @endpre
///
/// Piezo initialize
/// @code
/// auto buzzerPin  = target::pin_out(target::pins::d5);
/// piezo buzzer(buzzerPin);
/// @endcode
/// 
/// @warning This class requers hwlib to work.

piezo::piezo(hwlib::target::pin_out & output):
    output(output)
{}

/// @brief Tone
/// 
/// It will ouput a tone over the piezo buzzer.
///
/// @param char tone    (The tone that will be will sound) 
///        \n input can be your own note or one of the Preloaded
/// @param int duration (The miliseconds the tone will sound for)
///
/// @par Preloaded notes
///  <b>c</b> 262Hz \n
///  <b>d</b> 294Hz \n
///  <b>e</b> 330Hz \n
///  <b>f</b> 349Hz \n
///  <b>g</b> 392Hz \n
///  <b>a</b> 440Hz \n
///  <b>b</b> 494Hz \n
///  <b>C</b> 523Hz \n
///
/// @warning duration of 0 stil result in a sound
///
/// @par example
/// @code
/// buzzer.tone('a',1000);
/// @endcode
/// @returns void
void piezo::tone(unsigned int tone, int duration )
{   
    duration *= 1000;
    int startTime =  hwlib::now_us();
    int waitTime  = Hz(tone);

    while(((int)hwlib::now_us() - startTime)  < duration){
        output.set(1);
        hwlib::wait_us(waitTime);
        output.set(0);
    }
}
/// @brief song
/// 
/// will play the song you made
/// juses @ref tone() as base
///
/// @param int notes[]    (Array of all the notes that will be played) 
///        \n input can be your own note or one of the Preloaded \ref tone(). 
/// @param int duration [] (Array of all the lenghs that the notes will play for)
/// @param int lenght (The lenght of the input arrays)
///
///
/// @par example
/// @code
///   char  notes[8]  = {'c','d','e','f','g','a','b','C'};
///   int  lenght[8] = {300,300,300,300,300,300,300,300};
///   buzzer.song(notes,lenght,8);
/// @endcode
/// @returns void
void piezo::song(int notes[], int duration[], int lenght){
    for(int i=0; i < lenght; i++){
        tone(notes[i], duration[i]);
        hwlib::wait_us(10);
    }
}

/// @brief Hz
/// 
/// Private function calcute the Hz
///
/// @param int notes    the tone that needs to bee played
/// @par workings
/// will return the Hz of a given note
/// 
/// @returns int (Hz)
int piezo::Hz(int tone){
    switch(tone){
        case 'c': //262hz
            return 227;
        break;
        
        case 'd': //294 Hz
            return 342;
        break;
        
        case 'e': //330 Hz
            return 303;
        break;
        
        case 'f': //349 Hz
            return 286;
        break;
        
        case 'g': //392 Hz
            return 255;
        break;
        
        case 'a': //440 Hz
            return 227;
        break;
        
        case 'b': //494 Hz
            return 202;
        break;
        
        case 'C': //523 Hz
            return 191;
        break;
    }
    return tone;
}