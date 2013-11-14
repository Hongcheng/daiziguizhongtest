#include <iostream>
#include <stdlib.h>
using namespace std;
struct tree
{
	int parentnum;
	int height;
};
int node[]={1,2,4,2,5,6,-1};
int treeheight(int node[],int n)
{
	tree *tr = new tree[n];
	int i;
	for(i =0;i<n;i++)
	{
		tr[i].parentnum = node[i];
		tr[i].height = 1;
	}
	for(i = 0;i<n;i++)
	{
		int j = tr[i].parentnum;
		while(j != -1)
		{
			if(tr[j].height != 1)
			{
				tr[i].height += tr[j].height;
				break;
			}
			tr[i].height++;
			j = tr[j].parentnum;
		}
	}
	for(i = 0;i<n;i++)
		cout << tr[i].height;
	return 0;
}
int main()
{
	treeheight(node,7);
	return 0;
}