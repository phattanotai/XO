#include "TextField.h"

TextField::TextField(){

}
TextField::TextField(int x,int y,int w,int h){
     width = round(w*14.5)+5;
     height = h;
     x1 = x;
     y1 = y;
     
}
void TextField::setTextField(int x,int y,int w,int h){
     width = round(w*14.5)+5;
     height = h;
     x1 = x;
     y1 = y;
     
     setcolor(0);
     line(x1,y1,x1+width,y1);
     line(x1,y1,x1,y1+height);
     setcolor(15);
     line(x1,y1+height,x1+width,y1+height);
     line(x1+width,y1,x1+width,y1+height); 
    
}
int TextField::getIntText(int textWidth){
    char *st=new char[textWidth];
    textWid = textWidth;
    char ch;
    for(int i=0;i<textWidth;i++){
       st[i]='\0'; 
    }
    int i=0;
    int c=0,b=0;
    while(ch!=13&&ch!=9){      
        if(kbhit()){
          ch=getch(); 
          if(i<textWidth-1){                 
               if(ch==8){
                   setcolor(bkColor);
                   outtextxy(x1+5,y1+2,st);
                   st[i-1]='\0';
                   setcolor(textColor);
                   outtextxy(x1+5,y1+2,st);
                   c=textwidth(st);
                   i--;
                   if(i<=0){i=0;}       
               }else{
                   st[i]=ch;                      
                   setcolor(textColor);
                   outtextxy(x1+5,y1+2,st);
                   c=textwidth(st);
                   i++; 
               } 
           }else{
              if(ch==8){
                   setcolor(bkColor);
                   outtextxy(x1+5,y1+2,st);
                   st[i-1]='\0';
                   setcolor(1);
                   outtextxy(x1+5,y1+2,st);
                   c=textwidth(st);
                   i--;
                   if(i<=0){i=0;}
              }     
           }       
        }
        setcolor(0);
        line(x1+5+c,y1+2,x1+5+c,y1+height-2);
        delay(100);
        setcolor(bkColor);
        line(x1+5+c,y1+2,x1+5+c,y1+height-2);
        delay(100);           
    }
    ch=0; 
    return atoi(st);        
}
double TextField::getDoubleText(int textWidth){
    char *st1=new char[textWidth];
    textWid = textWidth;
    char ch;
    for(int i=0;i<textWidth;i++){
       st1[i]='\0'; 
    }
    int i=0;
    int c=0,b=0;
    while(ch!=13&&ch!=9){      
        if(kbhit()){
          ch=getch(); 
          if(i<textWidth-1){                 
               if(ch==8){
                   setcolor(bkColor);
                   outtextxy(x1+5,y1+2,st1);
                   st1[i-1]='\0';
                   setcolor(textColor);
                   outtextxy(x1+5,y1+2,st1);
                   c=textwidth(st1);
                   i--;
                   if(i<=0){i=0;}       
               }else{
                   st1[i]=ch;                      
                   setcolor(1);
                   outtextxy(x1+5,y1+2,st1);
                   c=textwidth(st1);
                   i++; 
               } 
           }else{
              if(ch==8){
                   setcolor(bkColor);
                   outtextxy(x1+5,y1+2,st1);
                   st1[i-1]='\0';
                   setcolor(textColor);
                   outtextxy(x1+5,y1+2,st1);
                   c=textwidth(st1);
                   i--;
                   if(i<=0){i=0;}
              }     
           }       
        }
        setcolor(0);
        line(x1+5+c,y1+2,x1+5+c,y1+height-2);
        delay(100);
        setcolor(bkColor);
        line(x1+5+c,y1+2,x1+5+c,y1+height-2);
        delay(100);           
    }
    ch=0; 
    return atof(st1);        
}

char* TextField::getCharText(int textWidth){
    char *st2=new char[textWidth];
    textWid = textWidth;
    char ch;
    for(int i=0;i<textWidth;i++){
       st2[i]='\0'; 
    }
    int i=0;
    int c=0,b=0;
    while(ch!=13&&ch!=9){      
       if(kbhit()){
          ch=getch(); 
          if(i<textWidth-1){                 
               if(ch==8){
                   setcolor(bkColor);
                   outtextxy(x1+5,y1+2,st2);
                   st2[i-1]='\0';
                   setcolor(textColor);
                   outtextxy(x1+5,y1+2,st2);
                   c=textwidth(st2);
                   i--;
                   if(i<=0){i=0;}       
               }else{
                   st2[i]=ch;                      
                   setcolor(textColor);
                   outtextxy(x1+5,y1+2,st2);
                   c=textwidth(st2);
                   i++; 
               } 
           }else{
              if(ch==8){
                   setcolor(bkColor);
                   outtextxy(x1+5,y1+2,st2);
                   st2[i-1]='\0';
                   setcolor(textColor);
                   outtextxy(x1+5,y1+2,st2);
                   c=textwidth(st2);
                   i--;
                   if(i<=0){i=0;}
              }     
           }       
        }
        setcolor(0);
        line(x1+5+c,y1+2,x1+5+c,y1+height-2);
        delay(100);
        setcolor(bkColor);
        line(x1+5+c,y1+2,x1+5+c,y1+height-2);
        delay(100);           
    } 
    ch=0;
    return st2;        
}

int TextField::getX(){
    return x1;
}
int TextField::getY(){
    return y1;
}
int TextField::getWidth(){
    return width;
}
int TextField::getHeight(){
    return height;
}
void TextField::setButtonColor(int bkcolor,int textcolor){
     bkColor = bkcolor;
     textColor = textcolor;
}
void TextField::clearText(){
     setcolor(7);
     int l=0;
     for(int i = 0;i<textWid;i++){
          outtextxy(x1+5+l,y1+2,"W");
          l+=14.5;
     }  
}

