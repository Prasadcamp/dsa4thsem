#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
}*root;

class bst
{
	public:
		bst()
		{
			root=NULL;
		}
		void create(int d);
		void insert(node* p,int d);
		void search(node *p,int key);
		void traverse(node *p);
};
void bst:: create(int d)
{
	cout<<"\n create()...";
	if(root==NULL)
	{
		root= new node();
		root->data=d;
		root->left=root->right=NULL;
	}
}
void bst::insert(node *p,int d)
{
	cout<<"\n insert()...";
	if(root==NULL)
		return create(d);
	else
	{
		node * temp;
		temp->data=d;
		temp->left=temp->right=NULL;
		
		if(temp->data <= p->data)
		{
			if(p->left==NULL)
			{
				p->left=temp;
			}
			else{
				node * temp1=p;
				while(temp1->left != NULL){
					temp1= temp1->left;
				}
				temp1->left= temp;
			}
		}
		else
		{
			if(p->right==NULL)
			{
				p->right=temp;
			}
			else{
				node * temp1=p;
				while(temp1->right!= NULL){
					temp1= temp1->right;
				}
				temp1->right= temp;
			}
		}
	}
}
void bst::search( node *p,int key)
{
	if(p->data==key){
		cout<<"\n\n key is found:";
		return ;
	}
	else{
		node * temp1=p;
		if(key <=p->data){
			while(temp1->data!=key){
			temp1=temp1->left;
			}
			if(temp1->data ==key){
				cout<<"\n key is found ";
				return;
			}
			else{
				cout<<"key is not found\n";
			}
		}
		else{
			while(temp1->data!=key){
			temp1=temp1->right;
			}
			if(temp1->data ==key){
				cout<<"\n key is found ";
				return;
			}
			else{
				cout<<"key is not found\n";
			}
		}
	}
}

void bst::traverse(node *p)
{
	if(p==NULL)
	cout<<"\n no tree is created:";
	else
	{
		traverse(p->left);
		cout<<p->data;
		traverse(p->right);
		cout<<p->right;
	}
}
int main()
{	
	bst b1;
	b1.create(10);
	b1.insert(root,20);
	b1.search(root,10);
	b1.traverse(root);
	return 0;
}











