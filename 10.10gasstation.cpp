#include <iostream>
#include <stdlib.h>
using namespace std;
int gasstation(int gas[],int cost[],int n)
{
	int tank = 0;
	int start = n;
	int now = 0;
	tank = gas[0] - cost[0];
	while(true)
	{
		if(tank >=0)
		{
			now++;
			tank = tank + gas[now] - cost[now];
			cout << "+";
		}
		else
		{
			start--;
			tank = tank + gas[start] - cost[start];
			cout << "-";
		}
		if(now == start)
			break;
	}
	if(tank >= 0)
		return start;
	else
		return -1;
}
int main()
{
	int gas[]={5,5,5,5};
	int cost[]={6,4,5,4};
	int start = gasstation(gas,cost,4);
	cout << start << endl;
	return 0;
}