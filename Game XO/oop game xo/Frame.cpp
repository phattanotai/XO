#include "Frame.h"

Frame::Frame(int w,int h,char ch[]){ 
      width = w;
      height = h;
      strcpy(title,ch);       
}
Frame::Frame(int w,int h){
      width = w;
      height = h;
}
Frame::Frame(char ch[]){
      int l = strlen(ch);
      strcpy(title,ch); 
}
Frame::Frame(){

}

void Frame::setSize(int w,int h){
      width = w;
      height = h;
}
void Frame::setTitle(char ch[]){
      int l = strlen(ch);
      strcpy(title,ch); 
}
void Frame::setVisible(bool st){
      status = st;
      if(status){         
           initwindow(width,height,title);           
      }      
}
bool Frame::getStatus(){
     return status;     
}
void Frame::setBkColor(int c){
      color = c;
      setbkcolor(color);  
      clearviewport();                  
}
