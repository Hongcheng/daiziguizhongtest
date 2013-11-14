#include <iostream>
#include <map>
using namespace std;
int num[]={15, 7, 12, 11, 14, 13, 9, 11,8};
void longestint(int num[],int n)
{
	map<int,int>mapint;//use the map int-int
	int max = 0;
	int start = 0;
	int i,m;
	for(i = 0;i<n;i++)
	{
		if(mapint[num[i]] == 0)//when this number=0,means there has no this number before,make it 1
		{
			mapint[num[i]] = 1;
		}
		if(mapint[num[i]+1] != 0)//if the next number != 0,means this number can link to the next one,make it next+1
		{
			mapint[num[i]] = mapint[num[i]+1]+1;
		}
		m = num[i] - 1;
		while(mapint[m] != 0)//now if the number before it was not 0,make the before one add 1 in this number
		{
			mapint[m] = mapint[m+1] + 1;
			m--;
		}
	}
	for(i= 0;i<mapint.size();i++)//find the max number,means from this number, the next max number was linked
	{
		if(mapint[i] > max)
		{
			max = mapint[i];
			start = i;
		}
	}
	for(i = start;i<start+max;i++)
		cout << i << " ";
	cout << endl;
	// for(i = 0;i < mapint.size();i++)
	// 	cout << i << ":" << mapint[i] << endl;
}
int main()
{
	longestint(num,9);
	return 0;
}