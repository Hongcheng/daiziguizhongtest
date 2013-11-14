#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <map>
using namespace std;
bool isAllExist(map<char,int> mapchar)
{
	map<char,int>::iterator l_it;
	l_it = mapchar.begin();
	while(l_it != mapchar.end())
	{
		if(mapchar[(*l_it).first] == 0)
		{	
			return false;
		}
		else
			++l_it;
	}
	return true;
}
void shortestsubstr(const string l,const string ct,int *begin,int *end)
{
	int pbegin = 0,pend = 0;
	int nAbstractBegin = 0,nAbstractEnd = 0;
	int nTargeLength = l.length()+1;
	int N= l.length();
	map<char , int> mapchar;
	for(int i=0;i<ct.length();i++)
	{
		mapchar[ct[i]] = 0;
	}
	while(true)
	{
		while(!isAllExist(mapchar)&&pend < N)
		{
			map<char ,int >::iterator l_it;; 
   			l_it=mapchar.find(l[pend]);
   			if(l_it!=mapchar.end())
				mapchar[l[pend]]++;//if there are no such char in the table,won't add this in map
			pend++;
		}
		while(isAllExist(mapchar))
		{
			if(pend-pbegin < nTargeLength)
			{
				nTargeLength = pend-pbegin;
				nAbstractBegin = pbegin;
				nAbstractEnd = pend;
			}
			mapchar[l[pbegin]]--;
			// cout << l[pbegin] << "|";
			pbegin++;
		}
		if(pend>=N)
			break;
	}
	*begin = nAbstractBegin;
	*end = nAbstractEnd;
	return;
	// memcpy(sss,&l[pbegin],sizeof(l[pbegin]),nTargeLength);
	// return sss;
}
int main()
{
	string longstr = "aaaaaaaaaacbebbbbbdddddddcccccc";
	string chartable = "abcd";
	int b,e;
	shortestsubstr(longstr,chartable,&b,&e);
	cout << b << " " << e << endl;
	return 0;
}