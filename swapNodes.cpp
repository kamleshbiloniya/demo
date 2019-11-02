#include<iostream>

using namespace std;

typedef struct Node{
	int val;
	struct Node *right;
	struct Node *left;
	struct Node *parent;
}node;
node * root;
node *createNode(int val){
	node * newnode = (node *)malloc(sizeof(node));
	newnode->val = val;
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->parent=NULL;
	return newnode;
}
node * searchNode(node *p , int val){
	if(p->val==val)return p;
	if(p->left!=NULL){
		return searchNode(p->left,val);
	}
	if(p->right!=NULL){
		return searchNode(p->right,val);
	}
	return NULL;

}
void addnode(int val,int a,int b){
	if(a ==-1 && b==-1)return;
	if(val==1){
		root = createNode(val);
	}
	else{
		node *p = searchNode(root,val);
		if(a!=-1){
			node *l = createNode(a);
			l->parent = p;
			p->left = l;
		}
		if(b!=-1){
			node *r = createNode(b);
			r->parent = p;
			p->right = r;
		}
	}
	return;

}
void inOrder(node *p){
	if(p->left != NULL){
		inOrder(p->left);
	}
	cout<<p->val<<" ";
	if(p->right!=NULL){
		inOrder(p->right);
	}
}
void swapnode(node *root,int h, int k){
	if(k==1){
		node * p = root->left;
		root->left = root->right;
		root->right = p;
		if(root->left!=NULL){
			swapnode(root->left,h,h);
		}
		if(root->right!=NULL){
			swapnode(root->right,h,h);
		}

	}
	else{
		if(root->left!=NULL){
			swapnode(root->left,h,k-1);
		}
		if(root->right!=NULL){
			swapnode(root->right,h,k-1);
		}	
	}
	
	return;

}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b;
		addnode(i,a,b);
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int k;
		cin>>k;
		swapnode(root,k,k);
		inOrder(root);
		cout<<endl;
	}
	return 0;
}