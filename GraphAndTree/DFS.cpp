#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
	int val;
	struct Node *next;
}node;

node *arr[100];
int vis[100];
node * createnode(int val){
	node * newnode = ( node *)malloc(sizeof(node));
	newnode->val = val;
	newnode->next = NULL;
	return newnode;
}

void addnode(int a,int b){
	node *p = createnode(b);
	if(arr[a]==NULL){
		arr[a] = p;
	} 
	else{
		node *q = arr[a];
		while(q->next!=NULL){
			q = q->next;
		}
		q->next = p;
	}
	return;
}
node *findnode(int val){
	node *p =arr[val];
	if(p){
		node *q = arr[p->val];
		while(q->val != val){
			q = q->next;
		}
		return q;
	}
	else{
		return p;
	}
}
void DFS(node *root){
	node *p = arr[root->val];
	while(p){
		if(!vis[p->val]){
			vis[p->val]=1;
			cout<<"Visting "<<p->val<<endl;
			DFS(p);
		}
		p = p->next;
	}
}
int main(int argc, char const *argv[])
{
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		arr[i] = NULL;
		// linklist[i]=NULL;
		vis[i]=0;
	}
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		addnode(a,b);
		addnode(b,a);
	}
	for(int i=0;i<m;i++){
		node *p = arr[i];
		cout<<i<<" : ";
		if(p==NULL){
			cout<<" NULL";
		}else{
			while(p!=NULL){
				cout<<p->val<<" ";
				p = p->next;
			}
		}
		cout<<endl;
	}
	node *p = findnode(0);
	cout<<"root = "<<0<<endl;
	vis[p->val] = 1;
	if(p)DFS(p);
	return 0;
}