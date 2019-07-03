#include "Button.h"

Button::Button(){
             
}
Button::Button(char ch[]){
     int l = strlen(ch);
     for(int i=0;i<l;i++){
          cha[i] = '\0'; 
     }
     strcpy(cha,ch); 
     textWidth = textwidth(cha);                 
}

void Button::setPosition(int xc,int yc,int w,int h){
     x = xc;
     y = yc;
     width = w;
     height = h;
     
     buttonWidth = width;    
     textWidth = buttonWidth-textWidth;   
     textWidth = round(textWidth/2)+2;
                           
}

void Button::setVisible(int i){
     buttonType = i;
     if(buttonType==1){
         setcolor(0);
         line(x,y,x+width,y);
         line(x,y,x,y+height);
         setcolor(15);
         line(x,y+height,x+width,y+height);
         line(x+width,y,x+width,y+height);
         
         setcolor(color);        
         outtextxy(x+textWidth,y+2,cha);

     }else{
         setcolor(15);
         line(x,y,x+width,y);
         line(x,y,x,y+height);
         setcolor(0);
         line(x,y+height,x+width,y+height);
         line(x+width,y,x+width,y+height);
           
         setcolor(color);        
         outtextxy(x+textWidth,y+2,cha);
     }
}

void Button::setVisible(){
     if(buttonType==1){
         setcolor(0);
         line(x,y,x+width,y);
         line(x,y,x,y+height);
         setcolor(15);
         line(x,y+height,x+width,y+height);
         line(x+width,y,x+width,y+height);
         
         setcolor(color);        
         outtextxy(x+textWidth,y+2,cha);

     }else{
         setcolor(15);
         line(x,y,x+width,y);
         line(x,y,x,y+height);
         setcolor(0);
         line(x,y+height,x+width,y+height);
         line(x+width,y,x+width,y+height);
           
         setcolor(color);        
         outtextxy(x+textWidth,y+2,cha);
     }
}

void Button::setType(int t){
     buttonType = t; 
}

void Button::setText(char ch[]){
     int l = strlen(ch);
     for(int i=0;i<l;i++){
          cha[i] = '\0'; 
     }
     strcpy(cha,ch); 
     textWidth = textwidth(cha); 
         
}
void Button::setTextColor(int c){
       color = c;
}
void Button::setFont(int f,int fs,int st){  
     font = f;
     fontSize = fs;
     style = st;  
     settextstyle(font, style, fontSize);      
}
int Button::getX(){
     return x;     
}
int Button::getY(){
     return y;     
}
int Button::getWidth(){
     return width;     
}
int Button::getHeight(){
     return height;     
}

void Button::mouseClick(){
     button = false;
     bool status = checkMouse();
     if(status){
           setVisible(1);
           delay(80);
           setVisible(0); 
           button = true;        
     }
}

bool Button::checkMouse(){
     MouseEven e;
     e.LeftClick();
     if((e.mouseClickX()>=x&&e.mouseClickX()<=x+width)&&(e.mouseClickY()>=y&&e.mouseClickY()<=y+height)){     
         return true;  
     }else {
          return false;         
     }
}
bool Button::getButton(){
     return button;
}
