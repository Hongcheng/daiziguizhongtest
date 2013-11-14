#include <stdio.h>
using namespace std;

struct bst_node
{
	int key;
	bst_node *left;
	bst_node *right;
};
void bst_morris_inorder_middle(struct  bst_node *root)
{
	struct bst_node *p = root,*tmp;
	while(p)
	{
		if(p->left == NULL)//if has no left node,output and turn to the right node
		{
			printf("%d\n", p->key);
			p = p->right;
		}
		else//has the left node
		{
			tmp = p->left;
			while(tmp->right!=NULL && tmp->right!=p)//turn to the left node's rightest node
				tmp = tmp->right;
			if(tmp->right == NULL)//if the rightest node's right is NULL,make it point to p.And turn to p's left
				//In this way,when p's left scan over,it can turn back to p
			{
				tmp->right = p;
				p = p->left;
			}
			else//it mines the rightest node's right is point to p,it mines p's left have been scan then come back to p
			{	//so we should output p and make the rightest node to be NULL,and turn to p's right,say goodbye to the left tree
				printf("%d\n", p->key);
				tmp->right = NULL;
				p = p->right;
			}
		}
	}
}
void bst_morris_inorder_first(struct  bst_node *root)
{
	struct  bst_node *p = root,*tmp;
	while(p)
	{
		printf("%d\n", p->key);
		if(p->left == NULL)
			p = p->right;
		else
		{
			tmp = p->left;
			while(tmp->right!=NULL&tmp->right!=p)
				tmp=tmp->right;
			if(tmp->right == NULL)
			{
				tmp->right = p->right;
				p = p->left;
			}
			else
			{
				tmp->right == NULL;
				p = p->right;
			}
		}
	}
}
//if want to use morris tree to do the last scan,the noleaf node should point to the right tree
//so,is that possible??????????????????

// void bst_morris_inorder_last(struct  bst_node *root)
// {
// 	struct  bst_node *p = root,*tmp;
// 	while(p)
// 	{
// 		if(p->left == NULL)
// 		{
// 			tmp = p->right;
// 			while(tmp->right!=NULL&&tmp->right!=p)
// 				tmp = tmp->right;
// 			p = 
// 		}
// 	}
// }
int main()
{
	bst_node t[9];
	for(int i=0;i<9;i++)
	{
		t[i].key = i;
		t[i].left = NULL;
		t[i].right = NULL;
	}
	t[0].left = &t[1];
	t[0].right = &t[2];
	t[1].left = &t[3];
	t[1].right = &t[4];
	t[2].right = &t[5];
	t[4].left = &t[6];
	t[4].right = &t[7];
	t[5].left = &t[8];
	bst_morris_inorder_middle(t);
	return 0;
}