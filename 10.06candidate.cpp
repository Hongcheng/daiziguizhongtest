#include <iostream>
#include <stdlib.h>
// #include <vector>
using namespace std;
int candidate(int *A,int len)
{
	int B[100]={0};
	int i;
	for(i = 1;i<len-1;i++)
	{
		if(A[i]<A[i-1]&&A[i]<A[i+1])
			B[i] = 1;
	}
	for(i = 0;i<len;i++)
	{
		if(B[i]==1)
		{
			i++;
			B[i] = 2;
			while(B[i]<B[i+1]&&i<len-1)
			{
				B[i]= B[i-1]+1;
				i++;
			}
		}
		else
			i++;
	}
	for(i=len-1;i>=0;i--)
	{
		if(B[i]==1)
		{
			i--;
			while(B[i]<B[i-1]&&i>0)
			{
				B[i] = B[i+1]+1;
				i--;
			}
			B[i] = B[i]>(B[i+1]+1)?B[i]:(B[i+1]+1);
		}
	}
	for(i = 0;i<len;i++)
	{
		cout << B[i] << " ";
	}
	return 0;
}
int main()
{
	int A[]={5,4,3,3,2,6};
	candidate(A,6);
	return 0;
}