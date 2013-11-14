#include <iostream>
#include <string.h>
using namespace std;
int rect[4][6]={
	{1,1,0,0,1,0},
	{0,1,1,1,1,1},
	{1,1,1,1,1,0},
	{0,0,1,1,0,0}
};
int nrect[4][6];
int largestarea(int x,int y)
{
	memcpy(nrect,rect,sizeof(int)*x*y);
	int largest=0;
	int *stack = new int[y];
	for(int i=1;i<x;i++)
		for(int j=0;j<y;j++)
		{
			if(nrect[i-1][j] != 0&&nrect[i][j]!= 0)
				nrect[i][j] = nrect[i-1][j]+1;
		}
	for(int i = 0;i<x;i++)
	{
		stack[0] = nrect[i,0];
		int k = 0,highest = stack[0];
		for(int j= 1;j<y;j++)
		{
			if(nrect[i][j]>stack[k])
			{
				k+=1;
				stack[k] = nrect[i][j];
			}
			else if(nrect[i][j]==stack[k])
			{
				k+=1;
				stack[k] = nrect[i][j];
			}
			else
			{
				while(k>0&&stack[k]>nrect[i][j])
				{
					k--;
				}
			}
		}
	}
}
int main()
{
	// for(int i = 0;i<4;i++)
	// {	for(int j=0;j<6;j++)
	// 		cout <<nrect[i][j]<<" ";
	// 	cout << endl;
	// }
	return 0;
}