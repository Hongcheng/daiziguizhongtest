#include <iostream>
using namespace std;
int data[] = {1,1,0,1,1,0,0};
int main()
{
	int dp[10];
	for(int i=0;i<10;i++)
		dp[i]=-1;
	int temp;
	int i,j;
	for(i = 0;i<6;i++)
	{
		temp = 0;
		for(j = i;j<7;j++)
		{
			if(data[j] == 1)
				temp++;
			else
				temp--;
			if(temp == 0)
				dp[i] = j-i+1;
		}
		cout << dp[i] << " ";
	}
}