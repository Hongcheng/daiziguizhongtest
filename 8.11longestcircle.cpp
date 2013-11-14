#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
}
int longtrigle(int a[],int n)
{
	qsort(a,n,sizeof(a[0]),cmp);
	int i = 0;
	for(i = 0;i<n-2;i++)
	{
		if(a[i]<a[i+1]+a[i+2])
			return a[i]+a[i+1]+a[i+2];
	}
	return 0;
}
int main()
{
	int a[]={10,8,6,4,8,4,9};
	int c = longtrigle(a,7);
	cout << c;
	return 0;
}