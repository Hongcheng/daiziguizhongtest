#include <iostream>
using namespace std;
int a[]={4,10,15,23,26};
int b[]={0,9,12,20};
int c[]={5,18,22,30};
struct sortedlist
{
	int d[100];
	int len;
};
// void minrange(sortedlist *d,int num)
// {
// 	int *
// }
void minrange(int a[],int b[],int c[],int n1,int n2,int n3,int *min,int *max)
{
	int i,j,k,tmin,tmax,range = 99999;
	i = j = k = 0;
	while(true)
	{
		if(a[i]<b[j] && b[j]<c[k])
		{
			tmin = a[i];i++;
			tmax = c[k];
		}
		else if(a[i]<c[k] && c[k]<b[j])
		{
			tmin = a[i];i++;
			tmax = b[j];
		}
		else if(b[j]<a[i] && a[i]<c[k])
		{
			tmin = b[j];j++;
			tmax = c[k];
		}
		else if(b[j]<c[k] && c[k]<a[i])
		{
			tmin = b[j];j++;
			tmax = a[i];
		}
		else if(c[k]<a[i] && a[i]<b[j])
		{
			tmin = c[k];k++;
			tmax = b[j];
		}
		else
		{
			tmin = c[k];k++;
			tmax = a[i];
		}

		if(tmax-tmin < range)
		{
			*min = tmin;
			*max = tmax;
			range = tmax - tmin;
		}
		if(i >= n1 || j >= n2 || k >= n3)
			break;
	}
}
int main()
{
	int min,max;
	minrange(a,b,c,5,4,4,&min,&max);
	cout << min << '-' << max << endl;
}