#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
bool P[100][100];
void isPalin(char *str)
{
	int n = strlen(str);
	int i,j,L;
	for(i=0;i<n;i++)
	{
		P[i][i] = true;
	}
	for(L=2;L<=n;L++)
	{
		for(i = 0;i<n-L+1;i++)
		{
			j = i+L-1;
			if(L == 2)
				P[i][j] = (str[i]==str[j]);
			else
				P[i][j] = (str[i]==str[j])&&P[i+1][j-1];
		}
	}
	return;
}
int main()
{
	char a[] = "ababbbabbababa";
	isPalin(a);
	
	return 0;
}