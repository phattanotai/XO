#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <math.h>

using namespace std;

class MouseEven{
   private:          
          int x,y;         
   public:
          void LeftClick();
          void RightClick();
          
          int mouseClickX();
          int mouseClickY();
                  
};

