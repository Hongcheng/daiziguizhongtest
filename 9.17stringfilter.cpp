#include <iostream>
#include <stdlib.h>
using namespace std;
#define ONE 1
#define TWO 2
void stringFilter(char *str)
{
	int state = ONE;
	int j = 0;
	for(int i=0;str[i]!='\0';i++)
	{
		if(state == ONE&&str[i]!='a'&&str[i]!='b')
		{
			str[j] = str[i];
			j++;
		}
		if(state == TWO&&str[i]!='c')
		{
			str[j] = 'a';
			j++;
			if(str[i]!='a'&&str[i]!='b')
			{
				str[j] = str[i];
				j++;
			}
		}
		if(j>1&&str[j-2]=='a'&&str[j-1]=='c')
			j = j-2;
		state = (str[i]=='a')?TWO:ONE;
	}
	if(state == TWO)
	{
		str[j] = 'a';
		j++;
	}
	str[j] = '\0';
}
int main()
{
	char a[]="abcdeicdfegbacb";
	stringFilter(a);
	cout << a << endl;
	return 0;
}