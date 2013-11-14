#include <iostream>
#include <stdlib.h>
using namespace std;
bool yesorno = true;
void pipei(char *p,int count)
{
	if(*p == '\0')
		return;
	if(count < 0)
	{
		yesorno = false;
		return;
	}
	if(*p == '(')
		pipei(p++,count++);
	else if(*p == ')')
		pipei(p++,count--);
	else
		pipei(p++,count);
}
int main()
{
	char str[]="(abcd(e)";
	int count = 0;
	char *p = &str[0];
	pipei(p,count);
	return 0;
}