#include<iostream>
using namespace std;


struct node
{
	string data;
	int childcount=0;
	node* children[10];
	
	node(string value){
		data=value;
		childcount=0;
		for(int i=0;i<n;i++)
		{
			children[i]=nullptr;
		}
	}
};
void addchild(node* parent,const string& childdata){
	if(parent->children <10){
	   parent->children[parent->childcount]=new node[childdata);
	   parent->childcount++;
	}
	else
	{
		cout<<"Maximum size reached for children\n"<<parent->data<<endl;
	}
}

void printtree(node* root, int level=0){
	if (!root) return;
	for(int i=0;i<level;++i){
	
		  
