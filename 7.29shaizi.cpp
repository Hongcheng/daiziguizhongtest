#include <iostream>
using namespace std;
int shaizinew(int m,int n,int x)//when there are n shaizi,and every shaizi has m sizes,the state we kan get x point
{
	if(n == 1)
		if(x>=1&&x<=m)
			return 1;
		else
			return 0;
	else
	{
		int state = 0;
		for(int i = 1;i<=m;i++)
			state+=shaizinew(m,n-1,x-i);
		return state;
	}
}
int main()
{
	int m=6,n=2;
	int state=1;
	for(int i = 0;i<n;i++)
		state *= m;
	cout << state << endl;
	return 0;
}