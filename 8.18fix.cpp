#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
}
int lesttime(int a[],int n)
{
	int sum = 0,all = 0;
	qsort(a,n,sizeof(a[0]),cmp);
	for(int i = 0;i<n;i++)
		sum += a[i];
	all = sum;
	for(int i = 0;i<n-2;i++)
	{
		cout << all << " ";
		sum -= a[i];
		all +=sum;
	}
	return all;
}
int main()
{
	int a[]={5,8,8,8};
	int all = lesttime(a,4);
	cout << all << endl;
	return 0;
}