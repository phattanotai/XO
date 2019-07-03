#include "MouseEven.h"

void MouseEven::LeftClick(){
     if(ismouseclick(WM_LBUTTONDOWN)){
          getmouseclick(WM_LBUTTONDOWN,x,y);
     }
}
int MouseEven::mouseClickX(){
    return x;
}
int MouseEven:: mouseClickY(){
    return y;
}
