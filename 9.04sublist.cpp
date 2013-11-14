#include <iostream>
#include <stdlib.h>
using namespace std;
int longestlist(int a[],int n,int S)
{
	int len = n,sum,i,j;
	i = j = sum = 0;
	while(true)
	{
		if(j >=n || i > j)
			break;
		if(sum<S)
		{
			sum += a[j];
			j++;
			cout << "+";
		}
		else
		{
			len = len>(j-i+1)?(j-i+1):len;
			sum -= a[i];
			i++;
			cout << "-";
		}
		cout << sum << "-" << len << endl;
	}
	return len;
}
int a[]={5,1,3,5,10,7,4,9,2,8};
int main()
{	
	int longest = longestlist(a,10,10);
	cout << longest << endl;
	return 0;
}