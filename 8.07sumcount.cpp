#include <iostream>
#include <string.h>
using namespace std;
int sumcount(int a[],int n,int m)
{
	int **dp = new int* [n];
	dp[0] = new int[m*n];
	for(int i = 0;i<m;i++)
		dp[i] = dp[i-1]+m;
	memset(dp,0,sizeof(int)*m*n);
	dp[0][0] = 1;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			dp[i+1][dp[i][j]+a[i]] += dp[i][j];
		}
	}
	int dpm = 0;
	dpm = dp[n-1][m - a[n-1]];
	return dpm;
}
int main()
{
	int a[5]={5,5,10,2,3};
	cout << "1234";
	int b=0;
	// b = sumcount(a,5,15);
	cout << b;
	return 0;
}