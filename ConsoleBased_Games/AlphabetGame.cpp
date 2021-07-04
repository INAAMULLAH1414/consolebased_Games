#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#define cols 20
using namespace std;
void display(char[][cols],int);
void searchAndNull(char board[][cols],int,char);
void setRandCell(char[][cols],int);
void initial(char[][cols],int row);
bool checkWin(char[][cols],int);
bool checkLoss(char[][cols],int);
main()
{
	char ch;
	bool end = true;
	int row=20;
	char board[row][cols];
	initial(board,row);
	for(int i=0;i<6;i++)
	{
		setRandCell(board,row);
	}
	display(board,row);
	int start=time(0),current,count=1;
	while(end)
	{
		current=time(0);
		if(kbhit())
		{
			ch=getch();
			searchAndNull(board,row,ch);
			display(board,row);
			end = checkWin(board,row);
			if(!end)
			{
				system("cls");
				cout<<"You win";
			}
			
			
		}
		else if(current-start==3*count)
		{
			count++;
			setRandCell(board,row);
			end = checkLoss(board,row);
			display(board,row);
			if(!end)
			{
				system("cls");
				cout<<"You loss.";
			}
			
		}

	}
		

}
void initial(char board[][cols],int row)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<cols;j++)
		{
		board[i][j] = '\0';	
		}
		
	}
}

void setRandCell(char board[][cols],int row)
{
	char ch;
	int randRow,randCol;
	do
	{
		randRow=(rand()+time(0)) % 20;
		randCol=(rand()+time(0)) % 20;		
	}
	while(board[randRow][randCol]!='\0');
	ch = (rand()+time(0)) % 26 + 97;
	board[randRow][randCol] = ch;
}


void display(char board[][cols],int row)
{
	system("cls");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}
void searchAndNull(char board[][cols],int row,char key)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(key==board[i][j])
			board[i][j] = '\0';
		}
	}
}
bool checkWin(char board[][cols],int row)
{
	int count=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(board[i][j]=='\0')
			count++;
		}
	}
	if(count==row*cols)
	return false;
	else return true;
}
bool checkLoss(char board[][cols],int row)
{
	int count=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(board[i][j]!='\0')
			count++;
		}
	}
	if(count==20)
	return false;
	else return true;
}
