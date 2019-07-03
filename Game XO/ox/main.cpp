#include  <iostream>
#include  <conio.h>
#include  <stdlib.h>
#include  <time.h>
using namespace std;
int mat[3][3];

/*ฟังก์ชันสำหรับแสดงตารางออกมาครับ*/
void printmat(){
	system("cls");
	cout<<"Player is X ";
	cout<<endl;
	cout<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<"\t\t\t";
		for(int j=0;j<3;j++)
		{		
			if(mat[i][j]==0)
				cout<<"[:]";
			else if(mat[i][j]==1)
				cout<<"[X]";
			else if(mat[i][j]==4)
				cout<<"[O]";
		}
		cout<<endl;
	}
	cout<<endl;
}

/*ฟังก์ชันสำหรับเคลียร์ค่าตารางให้แต่ละช่องกลายเป็น 0*/
void reset(){
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			mat[i][j]=0;	
		}
	}
}

/*ฟังก์ชันสำหรับกำหนดตำแหน่งที่ PLAYER หรือ COM เลือกครับ*/
int set(int x,int y,int player){
	if(x==-1)
	{
		cout<<"You can't select this poisition !!";
	}
	else
	{
		if(mat[x][y]==0)
		{
			if(player%2==0)
				mat[x][y]=1;
			else
				mat[x][y]=4;
			return 1;
		}
		else
		{
			cout<<"You can't select this poisition !!";
		}
	}
	cout<<endl;
	return 0;
}

/*ฟังก์ชันสำหรับหาผู้ชนะ จะคืนค่า 1 หรือ 2 กลับ เพื่อบอกว่า PLAYER หรือ COM เป็นฝ่ายชนะ และค่า 0 หากยังไม่มีผู้ชนะ*/
int checkwinner(){
	int sum=0,i,j;

	/*ตรวจสอบในแนวนอน*/
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			sum=sum+mat[i][j];
		}
		if(sum==3)
			return 1;
		else if(sum==12)
			return 2;
		sum=0;
	}
	
	/*ตรวจสอบในแนวตั้ง*/
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			sum=sum+mat[j][i];
		}
		if(sum==3)
			return 1;
		else if(sum==12)
			return 2;
		sum=0;
	}

	/*ตรวจสอบในแนวแทยงจากซ้ายมาขวา*/
	for(i=0;i<3;i++)
	{
		sum=sum+mat[i][i];
	}
	if(sum==3)
		return 1;
	else if(sum==12)
		return 2;
	sum=0;
	
	/*ตรวจสอบในแนวแทยงจากขวามาซ้าย*/
	sum=mat[0][2]+mat[1][1]+mat[2][0];
	if(sum==3)
		return 1;
	else if(sum==12)
		return 2;
	sum=0;

	return 0;   // ถ้าไม่มีผู้ชนะ ให้รีเทิร์น 0 กลับไป
}

int main(){
	char poi,newgame;
	int end=0,x=-1,y=-1,turn=0;
	int ok=0;

	do{
		system("cls");
		srand(time(NULL));
		end=0;
		turn=0;

		cout<<"\t\tKeys for select poisition";
		cout<<endl;
		cout<<endl;
		cout<<"\t\t\t[Q][W][E]";
		cout<<endl;
		cout<<"\t\t\t[A][S][D]";
		cout<<endl;
		cout<<"\t\t\t[Z][X][C]";
		cout<<endl;
		cout<<endl;
		cout<<"Click any key to continue";
		
		getch();
		reset();
		while(end==0 && turn<9)	// ทำซ้ำไปเรื่อยๆ ในขณะที่ยังไม่มีผู้ชนะ และจำนวน turn < 9
		{    
			printmat();
			if(turn%2==0)  // Player
			{
				cout<<"Enter Poisition : ";
				do
				{	
					poi=getch();
					if(poi=='q' || poi=='Q')
					{
						x=0;
						y=0;
					}
					else if(poi=='w' || poi=='W')
					{
						x=0;
						y=1;
					}
					else if(poi=='e'|| poi=='E')
					{
						x=0;
						y=2;
					}
					else if(poi=='a'|| poi=='A')
					{
						x=1;
						y=0;
					}
					else if(poi=='s'|| poi=='S')
					{
						x=1;
						y=1;
					}
					else if(poi=='d'|| poi=='D')
					{
						x=1;
						y=2;
					}
					else if(poi=='z'|| poi=='Z')
					{
						x=2;
						y=0;
					}
					else if(poi=='x'|| poi=='X')
					{
						x=2;
						y=1;
					}
					else if(poi=='c'|| poi=='C')
					{
						x=2;
						y=2;
					}
					else
					{
						x=-1;
						y=-1;
					}
				}while(mat[x][y]!=0 || x ==-1);
			}
			else	// Computer's Turn
			{
				cout<<"COM's turn, Please wait... \n";
				do
				{
					if(turn<9)
					{
						ok=0;
						x=rand()%3;	// ให้ COM แรนดอมตำแหน่งของช่อง
						y=rand()%3;
						if(mat[x][y]==0)
							ok=1;
					}
				}while(ok==0&&turn<9);
			}

			if(set(x,y,turn)==1);	// ถ้าสามารถเลือกตำแหน่งดังกล่าวได้
			{
				end=checkwinner(); 	// ตรวจสอบหาผู้ชนะ
				turn++;  	// เพิ่มค่า turn ในแต่ละรอบ
			}


		}
		printmat();
		if(end==1)
		{	
			cout<<"^^ You Win !! ";
		}
		else if(end==2)
		{
			cout<<"T T You Lost !! ";
		}
		else
		{
			if(turn==9)
			{
				cout<<"Ahhhh Draw ";
			}
		}
		cout<<endl;
		cout<<endl;
		getch();

		cout<<"New Game (Y)?: ";	// ถามผู้เล่นว่าต้องการเล่นอีกหรือไม่ ?
		cin>>newgame;

	}while (newgame=='Y' || newgame=='y');
	return 0;
}
