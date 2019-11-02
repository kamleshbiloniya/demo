#include<bits/stdc++.h>


using namespace std;

typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
	
}node;
// node *root = NULL;
node *createnode(int val){
	node *newnode = (node *)malloc(sizeof(node));
	newnode->val = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void addnode(node *tree, int val){
	if(tree==NULL){
		cout<<"addnode "<<val<<endl;
		tree = createnode(val);
		return;
	}
	if(val<tree->val){
		if(tree->left == NULL)tree->left =createnode(val);
		else addnode(tree->left,val);
	}
	else{
		if(tree->right == NULL)tree->right = createnode(val);
		else addnode(tree->right,val);
	}
	return;
}
void Inorder(node *root){
	if (root==NULL)return;
	if(root->left != NULL) Inorder(root->left);
	cout<<root->val<<endl;
	if(root->right != NULL) Inorder(root->right);
}

void ClosestElement(node *root,int k){
	
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	node* p =NULL;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(!p)p = createnode(a);
		else addnode(p,a);
	}
	Inorder(p);
	return 0;
}