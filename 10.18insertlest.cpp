#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int insertlest(char str[],int n)
{
	int table[n][n],f,l,gap;
	memset(table,0,sizeof(table));
	for(gap = 1;gap<n;gap++)
	{
		for(f=0,l=gap;l<n;f++,l++)
		{
			table[f][l] = (str[l]==str[f])?table[f+1][l-1]:(min(table[f][l-1],table[f+1][l])+1);
		}
	}

	return table[0][n-1];
}
int main()
{
	char str[] = "acbb";
	int lest = insertlest(str,4);
	cout << lest << endl;
	return 0;
}