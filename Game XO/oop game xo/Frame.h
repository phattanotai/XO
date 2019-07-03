#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <math.h>

using namespace std;

class Frame{
      protected:
             int width,height;
             int color; 
             char title[];
             bool status;
                            
      public:
             Frame(int w,int h,char ch[]);
             Frame(int w,int h);
             Frame(char ch[]);
             Frame();
             
             void setSize(int w,int h);
             void setTitle(char ch[]);
             void setBkColor(int c);
             void setVisible(bool st);
             
             bool getStatus();
      
};
