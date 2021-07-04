#include<iostream>
#include<fstream>
#include<windows.h>
#define cols 20
int generationCount=1;
using namespace std;
void initialize(char A[][cols]);
void LoadMatrix(char A[][cols]);
int countNeighbors(char A[][cols], int r, int c);
void makeNextGeneration(char A[][cols]);
void display(char A[][cols]); 

int main()
{
	char A[cols][cols];
	initialize(A);
	LoadMatrix(A);
	display(A);
	while(1)
	{
		makeNextGeneration(A);
		display(A);	
	}	
}

void initialize(char A[][cols])
{
	for(int i=0;i<cols;i++)
	{
		for(int j=0;j<cols;j++)
		A[i][j] = '\0';
	}
}

void LoadMatrix(char A[][cols])
{
	ifstream read;
	read.open("c://life.txt");
	int row,colomn;
	char ch;
	do
	{
		read>>row;
		read>>ch;
		read>>colomn;
		A[row][colomn] = 'X';
	}
	while(!read.eof());
	read.close();
}

int countNeighbors(char A[][cols], int r, int c)
{
	int count;
	
	/* As in below condition, the main_cell also count as neighbor 
	so we initialize count with -1 ,so it remain correct */
	if(A[r][c]=='X')
	count=-1;
	else count = 0;
	
	for(int i=r-1;i<=r+1;i++)
	{
		for(int j=c-1;j<=c+1;j++)
		{
			if(A[i][j]=='X')
			count++;
		}
		
	}
	return count;
}

void makeNextGeneration(char A[][cols])
{
	int neighbor;
	char B[cols][cols];
	initialize(B);
	int mm=0;
	for(int i=0;i<cols;i++)
	{
		for(int j=0;j<cols;j++)
		{
			neighbor = countNeighbors(A,i,j);
			if(neighbor==0||neighbor==1)
			B[i][j] = '\0';
			else if(neighbor==2)
				{
				 if(A[i][j]=='X')
				 B[i][j] = 'X';
				}
			else if(neighbor==3)
			B[i][j] = 'X';
			else if(neighbor>=4)
			B[i][j] = '\0';
		}
	}
	for(int i=0;i<cols;i++)
			{
				for(int j=0;j<cols;j++)
				{
					A[i][j]=B[i][j];
				}
			}
	
}

void display(char A[][cols])
{
	
	system("cls");
	cout<<"\nGeneration no : "<<generationCount++<<endl<<endl;
	for(int i=0;i<cols;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	Sleep(1000);
}
