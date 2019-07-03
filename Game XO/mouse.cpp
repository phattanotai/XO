#include "myinclude.h"

int mode=0; 
int state[9];
bool status=false;
int turn=0;

void check_mouse(int position[]){
         int i=0; 
         if(position[0]>=335&&position[0]<=350+textwidth("1 Play Game")+5&&position[1]>=170&&position[1]<=190){
                button(1,340,170,textwidth("1 Play Game")+10,textheight("1 Play Game")+4);  
                delay(30); 
                button(0,340,170,textwidth("1 Play Game")+10,textheight("1 Play Game")+4);
                put_data(state,&turn,&status);
                clear_data();                                               
                clearviewport();
                view_game();
                setcolor(7);
                text(3);
                setcolor(RED);
                text(5);
                mode=1;
                turn=1; 
                status=true; 
                position[0]=position[1]=0;             
         }        
         if(position[0]>=335&&position[0]<=350+textwidth("2 Play Game")+5&&position[1]>=201&&position[1]<=220){
                button(1,340,200,textwidth("2 Play Game")+10,textheight("2 Play Game")+4);  
                delay(30); 
                button(0,340,200,textwidth("2 Play Game")+10,textheight("2 Play Game")+4);
                put_data(state,&turn,&status);
                clear_data();                                               
                clearviewport();
                view_game();
                setcolor(7);
                text(3);
                setcolor(RED);
                mode=2;
                text(1);
                turn=1; 
                status=true;
                position[0]=position[1]=0;              
         }        
         if(status){
             if(mode==1){
                 if(position[0]>=10&&position[0]<=110&&position[1]>=10&&position[1]<=110&&state[0]==0){
                     i=0;   
                     put_data(state,&turn,&status);                
                     draw(10,10,i); 
                     state[0]=1;
                     position[0]=position[1]=0;
                 }
                 if(position[0]>=110&&position[0]<=210&&position[1]>=10&&position[1]<=110&&state[1]==0){
                     i=1;  
                     put_data(state,&turn,&status);                  
                     draw(110,10,i);
                     state[1]=1; 
                     position[0]=position[1]=0;                                                         
                 }
                 if(position[0]>=210&&position[0]<=310&&position[1]>=10&&position[1]<=110&&state[2]==0){
                     i=2;
                     put_data(state,&turn,&status);
                     draw(210,10,i);
                     state[2]=1;
                     position[0]=position[1]=0;                                                           
                 }
                 if(position[0]>=10&&position[0]<=110&&position[1]>=110&&position[1]<=210&&state[3]==0){
                     i=3;                      
                     put_data(state,&turn,&status);
                     draw(10,110,i); 
                     state[3]=1;
                     position[0]=position[1]=0;                                                                          
                 }
                 if(position[0]>=110&&position[0]<=210&&position[1]>=110&&position[1]<=210&&state[4]==0){
                     i=4;   
                     put_data(state,&turn,&status);
                     draw(110,110,i); 
                     state[4]=1;
                     position[0]=position[1]=0;                                                                               
                 }
                 if(position[0]>=210&&position[0]<=310&&position[1]>=110&&position[1]<=210&&state[5]==0){
                     i=5;
                     put_data(state,&turn,&status);
                     draw(210,110,i); 
                     state[5]=1; 
                     position[0]=position[1]=0;                                                                              
                 }
                 if(position[0]>=10&&position[0]<=110&&position[1]>=210&&position[1]<=310&&state[6]==0){
                     i=6;                     
                     put_data(state,&turn,&status);
                     draw(10,210,i); 
                     state[6]=1;
                     position[0]=position[1]=0;                                                                               
                 }
                 if(position[0]>=110&&position[0]<=210&&position[1]>=210&&position[1]<=310&&state[7]==0){
                     i=7;
                     put_data(state,&turn,&status);
                     draw(110,210,i); 
                     state[7]=1;  
                     position[0]=position[1]=0;                                                                             
                 }
                 if(position[0]>=210&&position[0]<=310&&position[1]>=210&&position[1]<=310&&state[8]==0){
                     i=8;                     
                     put_data(state,&turn,&status);
                     draw(210,210,i);
                     state[8]=1;
                     position[0]=position[1]=0;                                                                               
                 }                       
             }
             else if(mode==2){
                 if(position[0]>=10&&position[0]<=110&&position[1]>=10&&position[1]<=110&&state[0]==0){
                     i=0; 
                     put_data(state,&turn,&status);                  
                     draw(10,10,i); 
                     state[0]=1;
                     position[0]=position[1]=0;
                 }
                 if(position[0]>=110&&position[0]<=210&&position[1]>=10&&position[1]<=110&&state[1]==0){
                     i=1; 
                     put_data(state,&turn,&status);                   
                     draw(110,10,i);
                     state[1]=1; 
                     position[0]=position[1]=0;                                                         
                 }
                 if(position[0]>=210&&position[0]<=310&&position[1]>=10&&position[1]<=110&&state[2]==0){
                     i=2;
                     put_data(state,&turn,&status);
                     draw(210,10,i);
                     state[2]=1; 
                     position[0]=position[1]=0;                                                          
                 }
                 if(position[0]>=10&&position[0]<=110&&position[1]>=110&&position[1]<=210&&state[3]==0){
                     i=3;                    
                     put_data(state,&turn,&status);
                     draw(10,110,i);
                     state[3]=1; 
                     position[0]=position[1]=0;                                                                          
                 }
                 if(position[0]>=110&&position[0]<=210&&position[1]>=110&&position[1]<=210&&state[4]==0){
                     i=4;   
                     put_data(state,&turn,&status);
                     draw(110,110,i); 
                     state[4]=1;
                     position[0]=position[1]=0;                                                                               
                 }
                 if(position[0]>=210&&position[0]<=310&&position[1]>=110&&position[1]<=210&&state[5]==0){
                     i=5;
                     put_data(state,&turn,&status);
                     draw(210,110,i);
                     state[5]=1; 
                     position[0]=position[1]=0;                                                                                
                 }
                 if(position[0]>=10&&position[0]<=110&&position[1]>=210&&position[1]<=310&&state[6]==0){
                     i=6;                    
                     put_data(state,&turn,&status);
                     draw(10,210,i);
                     state[6]=1; 
                     position[0]=position[1]=0;                                                                               
                 }
                 if(position[0]>=110&&position[0]<=210&&position[1]>=210&&position[1]<=310&&state[7]==0){
                     i=7;
                     put_data(state,&turn,&status);
                     draw(110,210,i); 
                     state[7]=1;
                     position[0]=position[1]=0;                                                                               
                 }
                 if(position[0]>=210&&position[0]<=310&&position[1]>=210&&position[1]<=310&&state[8]==0){
                     i=8;                  
                     put_data(state,&turn,&status);
                     draw(210,210,i);
                     state[8]=1; 
                     position[0]=position[1]=0;                                                                               
                 }
             }
          }
}



void get_mouse(int position[]){
     int x,y;
     if(ismouseclick(WM_LBUTTONDOWN)){
          getmouseclick(WM_LBUTTONDOWN,x,y);
          position[0]=x;
          position[1]=y;
     }
}
