#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void transtr(string str,string re)
{
	// cout << re <<endl;
	if(str[0] == '\0')
	{
		// re+='\0';
		cout << re << endl;
		return;
	}
	else if(str[0] == '1')
	{
		transtr(&str[1],re+'a');
		int num = 10 + str[1]-48;
		// cout << num << endl;
		transtr(&str[2],re+char(num+96));
	}
	else if(str[0] == '2'&&str[1]<'7')
	{
		transtr(&str[1],re+'b');
		int num = 20 +str[1]-48;
		// cout << num << endl;
		transtr(&str[2],re+char(num+96));
	}
	else
	{
		int num = str[0]-48;
		// cout << num << endl;
		transtr(&str[1],re+char(num+96));
	}
	return;
}

int main()
{
	string a = "12259";
	// int num;
	// num = (a[0]-48)*10 + a[1]-48;
	// cout <<  num << endl;
	string b="";
	transtr(a,b);
	return 0;
}