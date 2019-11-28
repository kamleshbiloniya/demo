#include<bits/stdc++.h>

using namespace std;
typedef struct Node{
	int val;
	int level;
	struct Node *left;
	struct Node *right;

}node;

node * build(std::vector<int> In,std::vector<int>post,int pstart,int pend,int Instart,int Inend,int level){
	if(pstart>pend || Instart > Inend)return NULL;

	node * root = (node *)malloc(sizeof(node));
	root->val = post[pend];
	root->level = level;
	int i=0;
	int count =0;
	for(i=Instart;i<=Inend;i++){
		if(In[i]==post[pend])break;
		count++;
	}
	root->left = build(In,post,pstart,pstart+count-1,Instart,i-1,level+1);
	root->right = build(In,post,pstart+count,pend-1,i+1,Inend,level+1);
	return root;

}
void travel(node *root){
	if(root==NULL)return;
	travel(root->left);
	travel(root->right);
	cout<<root->val<<endl;
	return;
}

void BuildTree(std::vector<int> In, std::vector<int> post){
	int n = In.size();
	node * root = build(In,post,0,n-1,0,n-1,0);
	// travel(root);
	int l2=3;
	int l1=1;
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node *p = q.front();
		q.pop();
		if(p->left){
			q.push(p->left);
		}
		if(p->right){
			q.push(p->right);
		}
		if(p->level > l2)break;
		if(p->level >=l1)cout<<p->val<<" ";
	}
	cout<<endl;

}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	std::vector<int> In;
	std::vector<int> post;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		In.push_back(tmp);
	}
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		post.push_back(tmp);
	}
	BuildTree(In,post);
	return 0;
}

/*

8
4 8 2 5 1 6 3 7
8 4 5 2 6 7 3 1




*/