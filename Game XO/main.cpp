#include "myinclude.h"

int main (){  
   initwindow(460,320,"Game XO"); 
   setbkcolor(7); 
   clearviewport(); 
   int position[2];      
   view_game(); 
   while(true){       
         get_mouse(position);           
         check_mouse(position);
   }  
   getch(); 
   return 0;
}



