#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
}
int brothernum(int n)
{
	int nn = n;
	int nn1 = n;
	int temp = nn%10;
	nn /= 10;
	int i = 1;
	int j = 1;
	while(true)
	{
		if(nn%10 > temp)
		{
			temp = nn%10;
			nn /= 10;
			i++;
		}
		else
			break;
	}
	temp = nn%10;
	while(true)
	{
		if(nn1%10 > temp)
			break;
		else
		{
			nn1 /= 10;
			j++;
		}
	}
	cout << i << j << endl;
	int *lastt = new int[i];
	nn1 = n;
	for(int k = 0;k<i;k++)
	{
		lastt[k] = nn1%10;
		nn1/=10;
	}
	nn = (nn/10)*10+lastt[j-1];
	cout << nn << endl;
	lastt[j-1] = temp;
	qsort(lastt,i,sizeof(lastt[0]),cmp);
	while(i>0)
	{
		nn = nn*10 + lastt[i-1];
		i--;
	}
	cout << nn << endl;
	return 0;
}
int main()
{
	brothernum(34722641);
	return 0;
}