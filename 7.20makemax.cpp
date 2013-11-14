#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp(const void *a,const void *b)
{
	int m1,m2,ta = *(int *)a,tb = *(int *)b;
	int i = 0;
	while(tb>0)
	{
		ta*=10;
		tb /=10;
	}
	m1 = ta + *(int *)b;
	ta = *(int *)a;
	tb = *(int *)b;
	while(ta>0)
	{
		tb *= 10;
		ta /= 10;
	}
	m2 = tb + *(int *)a;
	return m2-m1;
}
int main()
{
	int data[] = {96,9,95,556,56,55,5,554,54,3,2,1};
	qsort(data,12,sizeof(data[0]),cmp);
	for(int i = 0;i<12;i++)
		cout << data[i]<< " ";
	return 0;
}