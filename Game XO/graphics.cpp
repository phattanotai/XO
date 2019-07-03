#include "myinclude.h"

int score[9];
int index=0;
bool *status_p;
int *state_p;
int *turn_p;


void view_game(){
     setcolor(0);
     line(110,10,110,310); 
     line(210,10,210,310);    
     line(10,110,310,110);    
     line(10,210,310,210); 
     
     setcolor(15);
     line(111,10,111,310); 
     line(211,10,211,310);        
     line(10,111,310,111);    
     line(10,211,310,211);
          
     setcolor(0);
     line(310,10,310,310);
     line(10,310,310,310);
     setcolor(15);
     line(10,10,310,10);
     line(10,10,10,310); 
     
     setcolor(15);
     line(320,10,450,10);
     line(320,10,320,310);
     setcolor(0);
     line(320,310,450,310);
     line(450,10,450,310);
     
     setcolor(0);
     outtextxy(345,172,"1 Play Game"); 
     button(0,340,170,textwidth("1 Play Game")+10,textheight("1 Play Game")+4);
     
     outtextxy(345,202,"2 Play Game"); 
     button(0,340,200,textwidth("2 Play Game")+10,textheight("2 Play Game")+4); 

     setcolor(RED);
     text(3); 
}

void check_score(int x,int y,int z){
        setcolor(1);
        if(score[x]==1&&score[y]==1&&score[z]==1){
                    text(7);
                    *status_p=false;                                                                                                 
        }else if(score[x]==2&&score[y]==2&&score[z]==2){
                    text(8);
                    *status_p=false;                                                                             
        }
}
void check_game(){
           check_score(0,1,2);
           check_score(3,4,5);
           check_score(6,7,8);          
           check_score(0,3,6);
           check_score(1,4,7);
           check_score(2,5,8);          
           check_score(2,4,6);
           check_score(0,4,8);         
}

void clear_data(){
     index=0;
     for(int i=0;i<9;i++){
                 state_p[i]=0;
                 score[i]=0; 
     }
}

void game_over(){ 
         if(index>=9){          
            *turn_p=0;
            *status_p=false;
            setcolor(1);
            text(4);
            clear_data();
         }
}


void draw(int x1,int y1,int i){ 
       setcolor(14);   
       if(*turn_p==1){
          int dx1=x1+30,dy1=y1+30,dx2=x1+70,dy2=y1+70; 
          line(dx1,dy1,dx2,dy2);
          line(dx1,dy2,dx2,dy1);
          score[i]=1;
          check_game(); 
          setcolor(7);
          text(1);
          setcolor(RED);
          text(2);
          *turn_p=2;   
      }else if(*turn_p==2){          
          circle(x1+50,y1+50,20);
          score[i]=2;
          check_game();
          setcolor(7);
          text(2);
          setcolor(RED);
          text(1); 
          *turn_p=1;  
      }
      index++;
      game_over();
}


void button(int look,int x,int y,int width,int height){
    if(look==0){
         setcolor(15);
         line(x,y,x+width,y);
         line(x,y,x,y+height);
         setcolor(0);
         line(x,y+height,x+width,y+height);
         line(x+width,y,x+width,y+height);
    }else{
         setcolor(0);
         line(x,y,x+width,y);
         line(x,y,x,y+height);
         setcolor(15);
         line(x,y+height,x+width,y+height);
         line(x+width,y,x+width,y+height);  
    }     
}


void text(int i){
     if(i==1){
          outtextxy(365,80,"ตอนนี้");
          outtextxy(330,100,"เป็นตาของคุณ X เล่น");
     }else if(i==2){
          outtextxy(365,80,"ตอนนี้");
          outtextxy(330,100,"เป็นตาของคุณ O เล่น");
     }else if(i==3){
          outtextxy(335,80,"ยังไม่ได้เริ่มเล่นเกม");
          outtextxy(357,100,"กรุณาคลิก ");
          outtextxy(350,120,"Play Game");
     }else if(i==4){
          outtextxy(120,130,"Game Over");
          outtextxy(130,150,"ไม่มีผู้ชนะ"); 
          outtextxy(120,170,"คลิกเล่นอีกครั้ง");     
     }else if(i==5){
          outtextxy(365,80,"ตอนนี้");
          outtextxy(330,100,"เป็นตาของคุณ เล่น");
     }else if(i==6){
          outtextxy(365,80,"ตอนนี้");
          outtextxy(330,100,"เป็นตาของ คอม เล่น");
     }
     else if(i==7){
          outtextxy(130,150,"X winner");
          outtextxy(120,170,"คลิกเล่นอีกครั้ง");
     }else if(i==8){
          outtextxy(130,150,"o winner");
          outtextxy(120,170,"คลิกเล่นอีกครั้ง");
     }
}

void get_data(int *st,int *tu,bool *stu){
     state_p=st;
     turn_p=tu;
     status_p=stu;
}
void put_data(int *st,int *tu,bool *stu){
     get_data(st,tu,stu);
}
