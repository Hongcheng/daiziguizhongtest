#include <iostream>
using namespace std;
int rebinary(int v)
{
	v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
	v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2);
	v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4);
	v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8);
	v = ( v >> 16 ) | ( v << 16);
	return v;
}
void printintbinary(int v)
{
	int n = 32;
	for(int i = 0;i<32;i++)
	{
		cout << int((v&0x80000000)>>31) << " ";
		v <<= 1;
	}
	cout << endl;
}
int main()
{
	int v = 121;
	printintbinary(v);
	int n = rebinary(v);
	printintbinary(n);
	return 0;
}