#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
bool isInterleaved(char *a,char *b,char *c)
{
	int M=strlen(a),N=strlen(b);
	bool IL[M+1][N+1];
	memset(IL,0,sizeof(IL));
	if((M+N)!=strlen(c))
		return false;
	for(int i=0;i<=M;i++)
	{
		for(int j=0;j<=N;j++)
		{
			if(i==0&&j==0)
				IL[i][j] = true;
			else if(i==0&&b[j-1]==c[j-1])
				IL[i][j] = IL[i][j-1];
			else if(j==0&&a[i-1]==c[i-1])
				IL[i][j] = IL[i-1][j];
		}
	}
}
int main()
{
	char str[] = "12 34";
	int len = strlen(str);
	cout << len << endl;
	return 0;
}