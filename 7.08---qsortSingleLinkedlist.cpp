#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
node* makelist(int d[],int n)
{
	node *head = new node();
	head->data = 0;
	node *pre = head,*cur = head;
	for(int i=0;i<n;i++)
	{
		cur = new node();
		cur->data = d[i];
		pre->next = cur;
		pre = cur;
	}
	pre->next = NULL;
	return head;
}

struct node *partition(struct node *head, struct node *end,
                      struct node **newHead, struct node **newEnd)
{
   struct node *pivot = end;
   struct node *prev = NULL, *cur = head, *tail = pivot;

   while(cur != pivot)
   {
       if(cur->data < pivot->data)
       {
          if((*newHead) == NULL)
               (*newHead) = cur;
           prev = cur;  
           cur = cur->next;
       }
       else
       {
           if(prev)
               prev->next = cur->next;
           struct node *tmp = cur->next;
           cur->next = NULL;
           tail->next = cur;
           tail = cur;
           cur = tmp;
       }
   }
   if((*newHead) == NULL)
       (*newHead) = pivot;
   (*newEnd) = tail;
  return pivot;
}
struct node *quickSortRecur(struct node *head, struct node *end)
{
   if(!head || head == end)
       return head;
   node *newHead = NULL, *newEnd = NULL;
  struct node *pivot = partition(head, end, &newHead, &newEnd);
   if(newHead != pivot)
   {
      struct node *tmp = newHead;
       while(tmp->next != pivot)
           tmp = tmp->next;
       tmp->next = NULL;
       newHead = quickSortRecur(newHead, tmp);
       tmp = getTail(newHead);
       tmp->next =  pivot;
   }
   pivot->next = quickSortRecur(pivot->next, newEnd);
   returnn ewHead;
}
void quickSort(struct node **headRef)
{
   (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
   return;
}


int main()
{
	int d[]={2,5,8,4,7,9,3,1};
	node *head = makelist(d,8),*end;
	node *pre;
	end = head;
	while(end->next != NULL)
		end = end->next;
	pre = head->next;
	quickSort(&head);
	while(pre != NULL)
	{
		cout << pre->data << " ";
		pre = pre->next;
	}

	return 0;
}