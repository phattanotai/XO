#include "KeyboardEven.h"

void KeyboardEven::keyDown(){
     if(kbhit()){
         ch = getch(); 
     }
}
char KeyboardEven::getkeyDown(){
     return ch;
}
