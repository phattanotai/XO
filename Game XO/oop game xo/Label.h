#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <math.h>

using namespace std;

class  Label{
       private:
               int x,y;
               int color; 
               int font,fontSize,style;     
               char cha[]; 
                    
       public:
              Label();
              Label(char ch[]);
              Label(int x,int y);
              Label(int x,int y,char ch[]);
              void setText(char ch[]);
              void setPosition(int x,int y);
              void setTextColor(int color);
              void setFont(int font,int fontSize,int style);
              void setVisible(bool visiton);
                   
};
