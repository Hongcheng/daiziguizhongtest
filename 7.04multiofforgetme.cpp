#include <iostream>
using namespace std;
int *noselfmulti(int d[],int n)
{
	int *B = new int[n],i,C;
	B[0] = d[0];
	for(i = 1;i<n-1;i++)
	{
		B[i] = B[i-1]*d[i];
	}
	B[n-1] = B[n-2];
	C = d[n-1];
	for(i = n-2;i > 0;i--)
	{
		B[i] = B[i-1]*C;
		C = C*d[i];
	}
	B[0] = C;
	return B;
}
int main()
{
	int d[] = {2,1,2,1,2,1,2};
	int *re = noselfmulti(d,7);
	for(int i = 0;i<7;i++)
		cout << re[i] << " ";
	return 0;
}