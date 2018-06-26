#include "cPaddel.hpp"
/// @author Thomas Theil
/// @date 25-06-2018 20:30
/// @brief cPaddel(int posX, int posY, controler & inputcontroler). 
/// @details
/// The main controler class for the peddels
/// 
/// @pre 
/// This class needs a controler input for it to work
/// @endpre
///
/// cPaddel initialize(exampel)
/// @code
///  HCSR04 controler1();
/// cPaddel player1(X,Y,controler1);
/// @endcode
/// 

cPaddel::cPaddel(int posX, int posY,controler & inputcontroler):
originalX(posX),
originalY(posY),
inputcontroler(inputcontroler)
{}

/// @brief Reset()
/// @details
/// Resets the paddels to its originals starting position
/// 
void cPaddel::Reset(){
    x = originalX;
    y = originalY;
}
/// @brief update()
/// @details
/// update the position of the paddel on a screen of 64px height
void cPaddel::update(){
    y = inputcontroler.get()*0.64;    
}
/// @brief getX()
/// @details
/// Get the X axis 
/// @returns int
int cPaddel::getX(){
    return x;
}
/// @brief getY()
/// @details
/// Get the Y axis 
/// @returns int
int cPaddel::getY(){
    return y;
}
/// @brief paddelSize(char newSize)
/// @details
/// You can give the paddel a newSize. if you leef the newSize empty it wil be seen as a 0 \n
/// it will return the new size of the paddel
/// @returns char
char cPaddel::paddelSize(char newSize){
    return paddel += newSize;
}

