#include <iostream>
#include <stdlib.h>
using namespace std;
int position(int a[],int n,int b)
{
	int i = 0;
	while(a[i]!=b)
	{
		if(a[i]>b)
			i = i+a[i]-b;
		else
			i = i+b-a[i];
		if(i >= n)
			return -1;
	}
	return i;
}
int a[]={8,7,6,5,6,7,8,9,10,9};
int main()
{
	int p = position(a,10,5);
	cout << p << endl;
}