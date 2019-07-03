#include "Game.h"

Game::Game(){
     setSize(460,320); 
     setTitle(" Game");
     setVisible(true);
     bkcolor = 7;
     
     clearData();        
}

void Game::viewGame(){
     
     setbkcolor(bkcolor); 
     clearviewport();
     
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
     
     
}

void Game::input1Name(){
     setbkcolor(bkcolor); 
     clearviewport();
     
     lb1.setPosition(100,150);   
     lb1.setText("ชื่อผู้เล่น:");   
     lb1.setTextColor(1);
     lb1.setVisible(true);
        
     tf1.setTextField(160,150,10,20); 
     tf1.setButtonColor(7,0);
     playerName = tf1.getCharText(10);
             
}
void Game::input2Name(){
     setbkcolor(bkcolor); 
     clearviewport();
     
     lb1.setPosition(95,120);   
     lb1.setText("ชื่อผู้เล่น 1");   
     lb1.setTextColor(1);
     lb1.setVisible(true);
     
     lb2.setPosition(95,170);
     lb2.setText("ชื่อผู้เล่น 2");
     lb2.setTextColor(1); 
     lb2.setVisible(true);
     
     tf1.setButtonColor(7,0);
     tf2.setButtonColor(7,0);
     tf1.setTextField(160,120,10,20); 
     tf2.setTextField(160,170,10,20); 
     
     playerName1 = tf1.getCharText(6);
     playerName2 = tf2.getCharText(6);   
}

int Game::selectGame(){
     setbkcolor(7); 
     clearviewport();
     
     slb.setText("กรุณาเลือก");
     slb.setPosition(195,100);
     slb.setTextColor(1);
     slb.setVisible(true);
     
     sbt1.setText("เล่น 1 คน");
     sbt2.setText("เล่น 2 คน");
  
     sbt1.setPosition(180,150,100,20);
     sbt2.setPosition(180,200,100,20); 
     sbt1.setTextColor(1);
     sbt2.setTextColor(1); 
     sbt1.setVisible();
     sbt2.setVisible();

     while(true){     
         sbt1.mouseClick();
         sbt2.mouseClick();
         if(sbt1.getButton()){
               return 1;
               break;          
         }else if(sbt2.getButton()){
               return 2;
               break;
         }
     }
}

void Game::checkScore(int x,int y,int z){
        setcolor(1);
        if(score[x]==1&&score[y]==1&&score[z]==1){
               text(7); 
               clearData();                                                                                               
        }else if(score[x]==2&&score[y]==2&&score[z]==2){
               text(8);
               clearData();                                                                                       
        }
}
void Game::checkGame(){
           checkScore(0,1,2);
           checkScore(3,4,5);
           checkScore(6,7,8);          
           checkScore(0,3,6);
           checkScore(1,4,7);
           checkScore(2,5,8);          
           checkScore(2,4,6);
           checkScore(0,4,8);         
}

void Game::clearData(){
       index=0;
       playTurn=1; 
       status = false;
       for(int i=0;i<9;i++){
            score[i]=0;
            state[i]=0;   
       }
}
void Game::gameOver(){
        if(index>=9){             
            setcolor(1);
            text(4);
            clearData();          
         }
}

void Game::draw(int x1,int y1,int i){ 
       setcolor(14);   
       if(playTurn==1){
          int dx1=x1+30,dy1=y1+30,dx2=x1+70,dy2=y1+70; 
          line(dx1,dy1,dx2,dy2);
          line(dx1,dy2,dx2,dy1);
          score[i]=1;
          checkGame(); 
          setcolor(7);
          text(1);
          setcolor(RED);
          text(2);
          playTurn=2;   
      }else if(playTurn==2){          
          circle(x1+50,y1+50,20);
          score[i]=2;
          checkGame();
          setcolor(7);
          text(2);
          setcolor(RED);
          text(1); 
          playTurn=1;  
      }
      index++;
      gameOver();
}


void Game::mouseClick(){
         int i = checkMouse();       
         if(i==0){
               draw(10,10,0); 
         }else if(i==1){
               draw(110,10,1);
         }else if(i==2){
               draw(210,10,2);
         }else if(i==3){
               draw(10,110,3);
         }else if(i==4){
               draw(110,110,4);
         }else if(i==5){
               draw(210,110,5);
         }else if(i==6){
               draw(10,210,6);
         }else if(i==7){
               draw(110,210,7);
         }else if(i==8){
               draw(210,210,8);
         }
  
}

int Game::checkMouse(){   
     MouseEven e;
     e.LeftClick();       
     if((e.mouseClickX()>=10&&e.mouseClickX()<=110)&&(e.mouseClickY()>=10&&e.mouseClickY()<=110)&&(state[0]==0)){
           state[0]=1;                                                                                                        
           return 0;                                                                                        
     }
     else if((e.mouseClickX()>=110&&e.mouseClickX()<=210)&&(e.mouseClickY()>=10&&e.mouseClickY()<=110)&&state[1]==0){  
           state[1]=1;   
           return 1; 
     }
     else if((e.mouseClickX()>=210&&e.mouseClickX()<=310)&&(e.mouseClickY()>=10&&e.mouseClickY()<=110)&&state[2]==0){ 
           state[2]=1;    
           return 2; 
     }
     else if((e.mouseClickX()>=10&&e.mouseClickX()<=110)&&(e.mouseClickY()>=110&&e.mouseClickY()<=210)&&state[3]==0){ 
           state[3]=1;   
           return 3; 
     }
     else if((e.mouseClickX()>=110&&e.mouseClickX()<=210)&&(e.mouseClickY()>=110&&e.mouseClickY()<=210)&&state[4]==0){ 
           state[4]=1;    
           return 4; 
     }
     else if((e.mouseClickX()>=210&&e.mouseClickX()<=310)&&(e.mouseClickY()>=110&&e.mouseClickY()<=210)&&state[5]==0){
           state[5]=1;     
           return 5; 
     }
     else if((e.mouseClickX()>=10&&e.mouseClickX()<=110)&&(e.mouseClickY()>=210&&e.mouseClickY()<=310)&&state[6]==0){ 
           state[6]=1;    
           return 6; 
     }
     else if((e.mouseClickX()>=110&&e.mouseClickX()<=210)&&(e.mouseClickY()>=210&&e.mouseClickY()<=310)&&state[7]==0){ 
           state[7]=1;    
           return 7; 
     }
     else if((e.mouseClickX()>=210&&e.mouseClickX()<=310)&&(e.mouseClickY()>=210&&e.mouseClickY()<=310)&&state[8]==0){
           state[8]=1;     
           return 8; 
     }
     
}
void Game::text(int i){
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
          int width = textwidth(playerName1);
          width = 310 - width;
          width = round(width/2);
          outtextxy(width+8,130,playerName1);
              
          outtextxy(150,150,"ชนะ");          
          outtextxy(120,170,"คลิกเล่นอีกครั้ง");
     }else if(i==8){           
          int width = textwidth(playerName2);
          width = 310 - width;
          width = round(width/2);
          outtextxy(width+8,130,playerName2);
              
          outtextxy(150,150,"ชนะ");          
          outtextxy(120,170,"คลิกเล่นอีกครั้ง");
     }
}
