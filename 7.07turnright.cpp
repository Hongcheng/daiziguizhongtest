#include <stdio.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
node * singlelistturnleft(struct node *head,int k)
{
	int len = 1;
	node *p = head;
	while(p->next != NULL)
	{
		len++;
		p = p->next;
	}
	p->next = head;
	k = k%len;
	while(k>0)
	{
		p = p->next;
		k--;
	}
	head = p->next;
	p->next = NULL;
	return head;
}
node * singlelistturnright(struct node *head,int k)
{
	int len = 1;
	node *p = head;
	while(p->next != NULL)
	{
		len++;
		p = p->next;
	}
	p->next = head;
	k = len - k%len;
	while(k>0)
	{
		p = p->next;
		k--;
	}
	head = p->next;
	p->next = NULL;
	return head;
}
void arrayturnleft(int d[],int len,int k)
{
	int left = len,tmp,l,r,i;
	k = k%len;
	if(k == 0)
		return;
	l = r = 0;
	for(;r<k;r++)
	{}
	for(;r<len;r++,l++)
	{
		tmp = d[l];
		d[l] = d[r];
		d[r] = tmp;
	}
	if(len%k != 0)
		arrayturnleft(&d[l],k,k-len%k);//if didn;t do it integer,the last k need do it again
}
int main()
{
	node n[6],*nn;
	for(int i=0;i<5;i++)
	{
		n[i].data = i;
		n[i].next = &n[i+1];
	}
	n[5].data = 5;
	n[5].next = NULL;
	nn = singlelistturnleft(n,3);
	while(nn != NULL)
	{
		printf("%d\n", nn->data);
		nn = nn->next;
	}
/////////////////////////////////////////////////////////////
	// int d[10]={1,2,3,4,5,6,7,8,9,10};
	// arrayturnleft(d,10,13);
	// for(int i=0;i<10;i++)
	// 	printf("%d\n", d[i]);
	return 0;
}