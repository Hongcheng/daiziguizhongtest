#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int cmp(const void *a,const void *b)
{
	return *(char *)a - *(char *)b;
}
bool sortsubstr(char *a,char *b,int al,int bl)
{
	char c[bl+1];
	c[bl]='\0';
	qsort(b,bl,sizeof(b[0]),cmp);
	// cout << 'b' << b << endl;
	for(int i=0;i<al-bl+1;i++)
	{
		memcpy(c,&a[i],bl);
		qsort(c,bl,sizeof(c[0]),cmp);
		cout << "c:" << c << endl;
		cout << "b:" << b << endl;
		bool btem = true;
		for(int j=0;j<bl;j++)
		{
			if(b[j] != c[j])
			{
				btem = false;
				break;
			}
		}
		if(btem)
			return true;
	}
	return false;
}
int main()
{
	char a[]="acabdef";
	char b[]="ba";
	// qsort(b,2,sizeof(b[0]),cmp);
	// cout << b << endl;
	bool re = sortsubstr(a,b,6,2);
	cout << re << endl;
	return 0;
}