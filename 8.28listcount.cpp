#include <iostream>
#include <stdlib.h>
using namespace std;
void repetitions(int a[],int n)
{
	int i = 0;
	int element,frequency;
	for(i = 0;i<n;i++)
		a[a[i]%n] += n;
	for(i = 0;i<n;i++)
	{
		frequency = a[i]/n;
		element = i;
		cout << "element:" << element << ",frequency:" << frequency << endl;
	}
}
int a[]={2,4,6,3,6,4,6,7,3,6};
int main()
{
	repetitions(a,10);
	return 0;
}