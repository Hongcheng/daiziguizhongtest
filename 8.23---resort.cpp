#include <iostream>
#include <stdlib.h>
using namespace std;
void resort(int a[],int b[],int n)
{
	int *P = new int[n];
	int p0;
	for(int i = 0;i<n;i++)
		P[a[i]] = i;
	for(int i = 0;i<n;i++)
		if(a[i] == 0)
		{
			p0=i;
			break;
		}
	while(true)
	{
		if(b[p0] == 0)
		{
			for(int i = 0;i<n;i++)
			{
				if(a[i] != b[i])
				{
					bp0 = b[p0];
					
				}
			}
		}
		bp0 = b[p0];
		temp = P[bp0];
		a[p0] = a[temp];
		a[temp] = 0;
		P[bp0] = p0;
		P[0] = temp;
		p0 = temp;
}
int main()
{
	int a = {0,1,2};
	int b = {0,2,1};
	resort(a,b,3);
	return 0;
}