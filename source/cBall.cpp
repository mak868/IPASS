#include "cBall.hpp"
/// @author Thomas Theil
/// @date 25-06-2018 15:00
/// @brief cBall
/// @details
/// This class controlles a ball of the game pong
/// 
/// cBall initialize(example)
/// @code
/// cBall ball(x,y);
/// @endcode
/// 

cBall::cBall(int posX, int posY):
    originalX(posX),
    originalY(posY)
{}
/// @brief Reset()
/// @details
/// It will reset the ball to its starting position
///  
/// (example)
/// @code
/// ball.Reset();
/// @endcode
/// 
void cBall::Reset(){
    x = originalX;
    y = originalY;
    direction = 0;
}

/// @brief changeDir()
/// @details
/// changing the directon of the ball
/// 
/// @par Posible directions
///  <b>0</b> stop \n
///  <b>1</b> left \n
///  <b>2</b> upleft \n
///  <b>3</b> downleft \n
///  <b>4</b> right \n
///  <b>5</b> upright \n
///  <b>6</b> downright \n


void cBall::changeDir(int newDir){
    direction = newDir;
}

/// @brief ramdomdir(char tresholdleft, tresholdRight)
/// @details
/// changing to a ramdom direction left or right.
/// 1 a ramdom direction to the left
/// 2 a ramdom direction to the right
///
///@par example
/// @code
/// ball.ramdomdir(char dir);
/// @endcode
/// 

void cBall::ramdomdir(char tresholdLeft, char tresholdRight){
   
    //direction = (rand() % tresholdLeft) + tresholdRight;
    direction = tresholdLeft;
}
/// @brief update()
/// @details
/// updating the position of the ball
///

void cBall::update(){
    switch(direction){
        default:
        case 0: //stop
            break;
        
        case 1: //left
            x--;
            break;
        
        case 4: //right
            x++;
            break;
        
        case 2: //upleft
            x--; y--;
            break;
        
        case 3: //downleft
            x--; y++;
            break;
        
        case 5: //upright
            x++; y--;
            break;
        case 6: //downright
            x++; y++;
            break;
    }
}

/// @brief int getX()
/// @details
/// get the ball it X axis 
///
/// @returns int 

int cBall::getX(){
    return x;
}
/// @brief int getY()
/// @details
/// get the ball it Y axis 
///
/// @returns int 
int cBall::getY(){
    return y;
}
/// @brief int getY()
/// @details
/// get the ball direction for with the ball is traveling in \n
/// see @ref changeDir() for the meaning of the directions.
///
/// @returns int 
int cBall::getDir(){
    return direction;
}

