#include "header.h"
int main (){  
   Game game;   
   if(game.getStatus()){
      while(true){
          int mode = game.selectGame();
          delay(100);
          game.loop = true;
          if(mode==1){
               game.input1Name(); 
               game.viewGame();              
               game.replay.setText("เล่นใหม่");
               game.replay.setPosition(340,250,100,20);
               game.replay.setTextColor(1);
               
               game.exit.setText("กลับหน้าแรก");
               game.exit.setPosition(340,280,100,20);
               game.exit.setTextColor(1);
               
               while(game.loop){
                    game.replay.setVisible();
                    game.exit.setVisible(); 
                    game.replay.mouseClick();
                    if(game.replay.getButton()){
                          game.clearData();
                          game.status = true;           
                          game.viewGame();                    
                    }
                   game.exit.mouseClick();
                   if(game.exit.getButton()){
                          game.clearData();
                          game.status = true;           
                          game.viewGame();
                          game.loop = false; 
                   }    
               } 
          }else if(mode==2){
               game.input2Name(); 
               game.viewGame();  
               
               game.replay.setText("เล่นใหม่");
               game.replay.setPosition(340,250,100,20);
               game.replay.setTextColor(1);
               
               game.exit.setText("กลับหน้าแรก");
               game.exit.setPosition(340,280,100,20);
               game.exit.setTextColor(1);
               
               while(game.loop){
                   game.replay.setVisible();
                   game.exit.setVisible();           

                   if(game.status){
                       game.mouseClick();                   
                   }
                       
                   game.replay.mouseClick();
                   if(game.replay.getButton()){
                      game.clearData();
                      game.status = true;           
                      game.viewGame();
                                         
                   }
                   game.exit.mouseClick();
                   if(game.exit.getButton()){
                      game.clearData();
                      game.status = true;           
                      game.viewGame();
                      game.loop = false;  
                   } 
                   
                    
               } 
                  
          }
   }
} 
   
  getch();
}
