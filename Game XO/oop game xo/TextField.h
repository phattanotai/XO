#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <math.h>

using namespace std;

class TextField{
      public:
              int x1,y1,textWid,width,height;
              int bkColor,textColor;
      public:
             TextField(int x,int y,int textwidth,int textheight);
             TextField();
             void setTextField(int x,int y,int textwidth,int textheight);
             int getIntText(int textWidth);
             double getDoubleText(int textWidth);
             char* getCharText(int textWidth);      
             int getX();
             int getY();
             int getWidth();
             int getHeight();
             void setButtonColor(int bkcolor,int textcolor);
             void clearText();
};

