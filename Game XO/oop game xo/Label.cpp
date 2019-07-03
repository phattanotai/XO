#include "Label.h"

Label::Label(){
        
}
Label::Label(char ch[]){
       strcpy(cha,ch); 
}
Label::Label(int lx,int ly){
        x = lx;
        y = ly;

}
Label::Label(int lx,int ly,char ch[]){
        x = lx;
        y = ly;
      
        strcpy(cha,ch);
         
}
void Label::setText(char ch[]){
        strcpy(cha,ch);
}
void Label::setPosition(int lx,int ly){
        x = lx;
        y = ly;

}

void Label::setFont(int f,int fs,int st){  
         font = f;
         fontSize = fs;
         style = st;  
         settextstyle(font, style, fontSize);
}
void Label::setVisible(bool visition){
      if(visition){           
            int xc=x+5;
            int yc=y+2;              
            outtextxy(xc,yc,cha); 
      }
}
void Label::setTextColor(int c){
      setcolor(c); 
       
}
