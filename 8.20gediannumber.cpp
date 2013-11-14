#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
}
void larger(int *a,int *b)
{
	if(*a >= *b)
		return;
	else
	{
		int temp = *b;
		*b = *a;
		*a = temp;
		return;
	}
}
int main()
{
	int x1,y1,x2,y2;
	x1 = 0;
	y1 = 0;
	x2 = 2;
	y2 = 10;
	// cin >> x1 >> y1 >> x2 >> y2;
	larger(&x1,&x2);
	larger(&y1,&y2);
	int a = x1 - x2;
	int b = y1 - y2;
	larger(&a,&b);
	int temp;
	while(b != 0)
	{
		temp = a%b;
		a = b;
		b = temp;
		larger(&a,&b);
	}
	cout << a-1 << endl;
	return 0;
}