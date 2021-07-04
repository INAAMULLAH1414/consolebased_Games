#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#define cols 4

void initialize(int*board[][cols]);
void display(int *board[][cols]);
void info(void);
bool chkWin(int *board[][cols],int *winState[][cols]);
using namespace std;
int main()
{
	char ch;
	bool win = false;
	int *board[cols][cols];
	int *temp;
	int X1=cols-1,Y1=cols-1,X2=cols-1,Y2=cols-1;//use for  position in game
	int rand1,rand2,rand3,rand4;
	for(int i=0;i<cols;i++)
	{
		for(int j=0;j<cols;j++)
		{
			 board[i][j] = new int;
		}
	}
	initialize(board);
	display(board);
	info();
	getch();
	for(int i=0;i<50;i++)
	{
		do
		{
			rand1 = (rand() + time(0)) % cols;
			rand2 = (rand() + time(0)) % cols;
			rand3 = (rand() + time(0)) % cols;
			rand4 = (rand() + time(0)) % cols;
		}
		while((rand1==cols-1 && rand2==cols-1) || (rand3==cols-1 && rand4==cols-1));
		*temp = *board[rand1][rand2];
		*board[rand1][rand2] = *board[rand3][rand4];
		*board[rand3][rand4] = *temp;
		display(board);
	}
	*temp = 1;
	int *winState[cols][cols];
	for(int i=0;i<cols;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(!(i==cols-1&&j==cols-1))
			{
				winState[i][j] = new int;
				*winState[i][j] = *temp;
				*temp +=1;
			}
		}
	}
	int count=0;
	while(!win)
	{
		ch = getch();
		X1=X2;
		Y1=Y2;
		switch(ch)
		{
			case 'a':
			case 'A':
			if(!(Y2-1<0))
			Y2--;
				break;
			case 'd':
			case 'D':
			if(!(Y2+1==cols))
			Y2++;
				break;
			case 'w':
			case 'W':
			if(!(X2-1<0))
			X2--;
				break;
			case 's':
			case 'S':
			if(!(X2+1==cols))
			X2++;
				break;
				case '5':
					initialize(board);
					break;
					
			default:
			cout<<"\nwrong input..\n";
		}
		*temp = *board[X1][Y1];
		*board[X1][Y1] = *board[X2][Y2];
		*board[X2][Y2] = *temp;
		display(board);
		count++;
		if(count>10)//minimum move to check for wining
		win = chkWin(board,winState);	
	}
	cout<<"\nYou win.\nMove used = "<<count;
	cout<<"\npress any key to end the game.\n";
	getch();
	for(int i=0;i<cols;i++)
	{
		for(int j=0;j<cols;j++)
		{
			 delete board[i][j];
			 delete winState[i][j];
		}
	}
	delete temp;
	
	return 0;
}
void display(int *board[][cols])
{
	system("cls");
	for(int i=0;i<cols;i++)
	{
		for(int j=0;j<cols;j++)
		{
			 cout<<*board[i][j]<<"\t";
		}
		cout<<endl<<endl;
		
	}
	Sleep(100);
}
void info(void)
{
	cout<<"\nUse w-for up"
	<<"\ns-for down"
	<<"\na-for left"
	<<"\nd-for right"
	<<"\nNote that \"0\" indicate current position in game."
	<<"\nPress any key to start the game.\n";
}
bool chkWin(int *board[][cols],int *winState[][cols])
{
	int count =0;
	for(int i=0;i<cols;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(!(i==cols-1&&j==cols-1))
			{
				if(*board[i][j] == *winState[i][j])
				count++;
			}
		}	
	}
	if(count==15)
	return true;
	else return false;
}
void initialize(int *board[][cols])
{
	int temp=1;
for(int i=0;i<cols;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(!(i==cols-1&&j==cols-1))
			{
				*board[i][j] = temp;
				temp +=1;
			}
			else
			{
				*board[i][j]='\0';
			}
		}
	}
}
