#include <iostream>
using namespace std;

float deathisland(int N,int x,int y,int step)
{
	if(x<0||x>=N||y<0||y>=N)
		return 1;
	else if(step<=0)
		return 0;
	else
	{
		float rate = 0.0;
		rate += 0.25*deathisland(N,x-1,y,step-1);
		rate += 0.25*deathisland(N,x+1,y,step-1);
		rate += 0.25*deathisland(N,x,y-1,step-1);
		rate += 0.25*deathisland(N,x,y+1,step-1);
		return rate;
	}
}

int main()
{
	float deathrate;
	int x,y,N,step;
	N = 10,x=1,y=1,step =2;
	deathrate = deathisland(N,x,y,step);
	cout << deathrate << endl;
	return 0;
}