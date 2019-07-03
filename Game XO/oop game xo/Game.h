#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <math.h>

#include "Button.h"
#include "Frame.h"
#include "TextField.h"
#include "Label.h"

using namespace std;

class Game:public Frame{
   private:
         int bkcolor;
         int playTurn;
         int score[9];
         int state[9];
         int index;
         
         char *playerName1,*playerName2,*playerName;
                 
         Button sbt1,sbt2;
         Label slb;             
         Button bt1,bt2;         
         TextField tf1,tf2;         
         Label lb1,lb2;
    
    public:     
         bool loop;
         bool status;
         
         Button replay,exit;
              
   public:
         Game();      
         void viewGame();
         int selectGame();
         void input1Name();
         void input2Name();         
         void clearData();         
         void checkGame();
         void mouseClick();
         
   private:
         void draw(int x1,int y1,int i);          
         void text(int i);  
         void gameOver();
         void checkScore(int x,int y,int z);
         int checkMouse();    
};
