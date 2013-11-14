#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

node* addsinglelinkedlist(node *list1,node *list2)
{
	node *q1 = list1,*q2 = list2;
	node *ans = NULL,*p = NULL,*q = NULL,*pre = NULL;
	ans = new node();
	p = q = ans;
	// q = new node();
	// ans->next = q;
	while(q1&&q2)
	{
		pre = q;
		q = new node();
		pre->next = q;

		int num = q1->data + q2->data;
		q->data = num % 10;
		if(num > 9)
		{
			p->data = p->data + 1;
			for(p=p->next;p!=q;p=p->next)
			{
				p->data = 0;
			}
		} 
		else if(num < 9)
			p = q;
		// pre = q;
		// q = new node();
		// pre->next = q;
		q1 = q1->next;
		q2 = q2->next;
	}
	if(ans->data == 0)
		ans = ans->next;
	return ans;
}

node* makelist(int d[],int n)
{
	node *head = new node();
	head->data = d[0];
	node *pre = head,*cur = head;
	for(int i=1;i<n;i++)
	{
		cur = new node();
		cur->data = d[i];
		pre->next = cur;
		pre = cur;
	}
	pre->next = NULL;
	return head;
}

int main()
{
	int n = 7;
	int a[] = {8,8,7,8,8,8,9};
	int b[] = {1,1,1,1,1,1,1};
	node *list1 = makelist(a,n);
	node *list2 = makelist(b,n);
	node *ans = addsinglelinkedlist(list1,list2);
	for(; ans; ans = ans->next)
		cout << ans->data << " ";
	cout << endl;
	return 0;	
}