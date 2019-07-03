#include <iostream>
#include <conio.h> 
#include <stdio.h.>
#include <graphics.h>
#include <cstdlib>

using namespace std;

// graphics.cpp
void view_game();
void check_score(int x,int y,int z);
void check_game();
void clear_data();
void game_over();
void draw(int x1,int y1,int i);
void button(int look,int x1,int y1,int x2,int y2);
void text(int i);
void get_data(int *st,int *tu,bool *stu);
void put_data(int *st,int *tu,bool *stu);


//mouse.cpp
void check_mouse(int position[]);
void get_mouse(int position[]);


