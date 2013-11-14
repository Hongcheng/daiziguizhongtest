#include <iostream>
using namespace std;

int magicindex(int d[],int n)
{
	int first = 0,mid = n/2,last = n-1;
	int lmid;
	while(true)
	{
		lmid = mid;
		if(d[mid]>mid)
		{
			last = mid;
			mid = (first+last)/2;
		}
		else if(d[mid] < mid)
		{
			first = mid;
			mid = (first+last)/2;
		}
		else
			return mid;
		if(lmid == mid)
			return -1;
	}
}
int d[]={-10,2,3,4,4,10,12};

int magicindex2(int d[],int n,int start)//start is so important,without it,we should lost the right index,and make the index to be the sublist's
{
	int first = 0,mid = n/2,last = n-1;
	int left,right,index1,index2;
	if(d[mid] != mid+start)
	{
		left = (mid-1)<d[mid]?(mid-1):d[mid];
		right = (mid+1)>d[mid]?(mid+1):d[mid];
		cout << left << " " << right << endl;
		if(left>=0)
		{
			index1 = magicindex2(d,left+1,start);
			if(index1 != -1)
				return index1;
		}
		if(right<n)
		{
			index2 = magicindex2(&d[right],last-right+1,right);
			if(index2 != -1)
				return index2;
		}
		return -1;
	}
	else
		return mid+start;
}

int main()
{
	int mi;
	mi = magicindex2(d,7,0);
	cout << mi << endl;
	return 0;
}