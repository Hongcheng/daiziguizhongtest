#include <iostream>
#include <stdlib.h>
using namespace std;
int ftmn(int a[],int n)
{
	int i = n-1;
	while(i>=0)
	{
		if(a[i] == n)
			i--;
		else if(a[i]<n&&a[i] == a[a[i]])
		{
			i--;
		}
		else
		{
			int temp = a[a[i]];
			a[a[i]] = a[i];
			a[i] = temp;
			i--;
		}
	}
	i = 1;
	while(i<n)
	{
		if(a[i] != i)
			return i;
		else
			i++;
	}
	if(a[0]==n)
		return n+1;
	else
		return n;
}
int main()
{
	int a[]={3,4,-1,1,6,10,8,9,4,7,2,5};
	int re = ftmn(a,12);
	cout << re << endl;
	return 0;
}