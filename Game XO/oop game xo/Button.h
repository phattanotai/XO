#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include "MouseEven.h"

using namespace std;

class Button{     
      private:
              int x,y,width,height;
              int buttonType;
              int color;
              char cha[];
              int font,fontSize,style;
              int textWidth;
              int buttonWidth;
              bool button;
      public:
              Button(char ch[]);
              Button();
              
              void setPosition(int x,int y,int width,int height);
              void setText(char ch[]);
              void mouseClick();
              void setType(int t);
              void setTextColor(int c);
              void setFont(int font,int fontSize,int style);
              void setVisible();
              void setVisible(int i);
              
              
              bool getButton();
              
              int getX();
              int getY();
              int getWidth();
              int getHeight();
              
      private:
              bool checkMouse();
         
};
