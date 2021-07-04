#include<iostream>
using namespace std;
const int rows = 7;
const int cols = 7;
void display(int[][cols],int);
void initialize(int [][cols],int);
int main()
{
	int rSum,cSum,primaryDiagonalSum=0,secondaryDiagonalSum=0;
	int x=0,y=cols/2,n=1;
	int magicBox[rows][cols];
	initialize(magicBox,rows);
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			magicBox[x][y] = n;
			n++;
			if((n-1)%cols==0)
			{
				x++;
				if(x==rows)
				x=0;	
			}
			else
			{
				x--;
				y++;
				if(x<0)
				x=rows-1;
				else if(x==rows)
				x=0;	
				
				if(y<0)
				y=rows-1;
				else if(y==rows)
				y=0;
			}
		}
	}
	cout<<"\t\tThe magic Box of order "<<cols<<" is..\n\n";
	display(magicBox,rows);
	for(int i=0;i<rows;i++)
	{
		rSum=0;
		cSum=0;
		for(int j=0;j<cols;j++)
		{
			rSum += magicBox[i][j];
			cSum += magicBox[j][i];
			if(i==j)
			primaryDiagonalSum += magicBox[i][j];
		}
		cout<<"\nsum of row "<<i+1<<" = "<<rSum;
		cout<<"\t\tsum of col "<<i+1<<" = "<<cSum;
	}
	int j=cols-1;
	for(int i=0;i<rows;i++)
	{
		secondaryDiagonalSum += magicBox[i][j];
		j--;
	}
	cout<<"\nsum of primary   diagonal = "<<primaryDiagonalSum;
	cout<<"\nsum of secondary diagonal = "<<secondaryDiagonalSum<<endl;
	system("pause");
}

void display(int magicBox[][cols],int rows)
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<magicBox[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void initialize(int magicBox[][cols],int rows)
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			magicBox[i][j] = 0;
		}
	}
}
