#include "pongManger.hpp"
/// @author Thomas Theil
/// @date 25-06-2018 21:30
/// @brief pongManger(hwlib::glcd_oled  & oled, cBall & ball, cPaddel & player1, cPaddel & player2, piezo & sound). 
/// @details
/// The pong game class \n
/// The class wil controle the pong game
/// 
/// @pre 
/// hwlib a must to run this
/// @endpre
///
/// pongManger(exampel)
/// @code
/// cBall ball(64,32);
/// cPaddel player1(1,0,controler1);
/// cPaddel player2(127,0,controler1);
/// 
/// pongManger pong(oled,ball,player1,player2,buzzer);
/// while(1){
///     pong.Update();
///     pong.Draw();
///
/// }
/// @endcode
/// 
pongManger::pongManger(hwlib::glcd_oled  & oled, cBall & ball, cPaddel & player1, cPaddel & player2, piezo & sound):
    display(oled),
    ball(ball),
    player1(player1),
    player2(player2),
    sound(sound)
{
        ball.Reset();
        player1.Reset();
        player2.Reset();
        ball.ramdomdir();
}

/// @brief score()
/// @details
/// this will reset the game
/// 

void pongManger::score(){
        ball.Reset();
        player1.Reset();
        player2.Reset();    
}

/// @brief Draw()
/// @details
/// Will draw to the conected oled screen
/// 
void pongManger::Draw(){
    display.clear();
    
    int ballx = ball.getX();
    int bally = ball.getY();
  
    int player1x = player1.getX();
    int player1y = player1.getY();
 
    int player2x = player2.getX();
    int player2y = player2.getY();
    
    int padelSize1 = player1.paddelSize();
    int padelSize2 = player2.paddelSize();
 
    for(int i =0; i < heightLevel; i++){
        for(int j =0; j < widthLevel; j++){
          
            if(ballx == j && bally == i){
                display.write( hwlib::location(j, i), hwlib::black );
            }
            else if(player1x == j && (player1y <= i && (player1y+padelSize1) >= i)){
                    display.write( hwlib::location(j, i), hwlib::black );
            }
            else if(player2x == j && (player2y <= i && (player2y+padelSize2) >= i)){
                display.write( hwlib::location(j, i), hwlib::black );
            } 
        }
        
    }
}
/// @brief Update()
/// @details
/// Update's the position of all the objects. \n
/// It wil also run a @ref collision() 
void pongManger::Update(){
        player1.update();
        player2.update();
        ball.update();
        this->collision();
}
/// @brief collision()
/// @details
/// This function will check if there hase been any colission with the object. \n
/// when a collision is detected a sound wil play out of the piezo speaker \n
/// \n
/// if the bal reaches one side the game wil end and a sound will play\n
/// the game will restart on its own

void  pongManger::collision(){
    int ballx = ball.getX();
    int bally = ball.getY();
  
    int player1x = player1.getX();
    int player1y = player1.getY();
 
    int player2x = player2.getX();
    int player2y = player2.getY();
    
    int padelSize1 = player1.paddelSize();
    int padelSize2 = player2.paddelSize();   
    
    //colision player1
    for(int i=0; i < padelSize1; i++){
        if(ballx == player1x+1){  
            if(bally == (player1y + i)){
                ball.ramdomdir(5); 
                sound.tone('b',100);
            }
        }
    }

    //colision player2
    for(int i=0; i < padelSize2; i++){
        if(ballx == player2x-1){  
            if(bally == (player2y + i)){
                ball.ramdomdir(6,3); //needs to be ramdom
                sound.tone('d',100);
            }
        }
    }
    
    // bottom wall
    if(bally >= heightLevel-1){
        int newDir = (ball.getDir() == 6 ? 5:2);
        ball.changeDir(newDir);
        sound.tone('g',100);
    }
        
     // top wall
    if(bally <= 5){
        int newDir = (ball.getDir() == 5 ? 6:3);
        ball.changeDir(newDir);
        sound.tone('C',100);
    }
           
     // right wall
    if(ballx >= widthLevel){
        //score player2
        int  notes[4]  = {'C','b','d','a'};
        int  lenght[4] = {100,150,200,500};
        sound.song(notes, lenght, 4);
        this->score();
    }
    // left wall
    if(ballx <= 0){
        //score player2
        int  notes[4]  = {'f','f','g','c'};
        int  lenght[4] = {100,150,200,500};
        sound.song(notes, lenght, 4);
        this->score();
    }
    
}