#include  <iostream>
#include  <conio.h>
#include  <stdlib.h>
#include  <time.h>
using namespace std;
int mat[3][3];

/*�ѧ��ѹ����Ѻ�ʴ����ҧ�͡�Ҥ�Ѻ*/
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

/*�ѧ��ѹ����Ѻ�������ҵ��ҧ������Ъ�ͧ������ 0*/
void reset(){
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			mat[i][j]=0;	
		}
	}
}

/*�ѧ��ѹ����Ѻ��˹����˹觷�� PLAYER ���� COM ���͡��Ѻ*/
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

/*�ѧ��ѹ����Ѻ�Ҽ�骹� �Ф׹��� 1 ���� 2 ��Ѻ ���ͺ͡��� PLAYER ���� COM �繽��ª�� ��Ф�� 0 �ҡ�ѧ����ռ�骹�*/
int checkwinner(){
	int sum=0,i,j;

	/*��Ǩ�ͺ��ǹ͹*/
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
	
	/*��Ǩ�ͺ��ǵ��*/
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

	/*��Ǩ�ͺ����§�ҡ�����Ң��*/
	for(i=0;i<3;i++)
	{
		sum=sum+mat[i][i];
	}
	if(sum==3)
		return 1;
	else if(sum==12)
		return 2;
	sum=0;
	
	/*��Ǩ�ͺ����§�ҡ����ҫ���*/
	sum=mat[0][2]+mat[1][1]+mat[2][0];
	if(sum==3)
		return 1;
	else if(sum==12)
		return 2;
	sum=0;

	return 0;   // �������ռ�骹� ��������� 0 ��Ѻ�
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
		while(end==0 && turn<9)	// �ӫ���������� 㹢�з���ѧ����ռ�骹� ��Шӹǹ turn < 9
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
						x=rand()%3;	// ��� COM �ù������˹觢ͧ��ͧ
						y=rand()%3;
						if(mat[x][y]==0)
							ok=1;
					}
				}while(ok==0&&turn<9);
			}

			if(set(x,y,turn)==1);	// �������ö���͡���˹觴ѧ�������
			{
				end=checkwinner(); 	// ��Ǩ�ͺ�Ҽ�骹�
				turn++;  	// ������� turn ������ͺ
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

		cout<<"New Game (Y)?: ";	// �����������ҵ�ͧ�������ա������� ?
		cin>>newgame;

	}while (newgame=='Y' || newgame=='y');
	return 0;
}
