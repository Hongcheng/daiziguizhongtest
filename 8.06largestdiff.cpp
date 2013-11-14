#include <iostream>
using namespace std;
void largestdiff(int a[],int n,int *oi,int *oj)
{
	int *b = new int[n];
	int min = a[0];
	int max = 0;
	*oi = 0;
	b[0] = 0;
	for(int i = 1;i<n;i++)
	{
		if(a[i]<min)
		{
			b[i] = i;
			min = a[i];
		}
		else
			b[i] = b[i-1];
	}
	for(int i = 1;i<n;i++)
	{
		if((a[i] - a[b[i]]) > max)
		{
			max = a[i] - a[b[i]];
			*oi = b[i];
			*oj = i;
		}
	}
}
int main()
{
	int a[] = {2,3,1,4,5};
	int i,j;
	largestdiff(a,5,&i,&j);
	cout << i << " " << j;
	return 0;
}