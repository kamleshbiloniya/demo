#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
	int val;
	struct Node *next;
}node;
node *arr[1000];
node * findnode(int val){
	node *p = arr[val];
	if(p==NULL)return NULL;
	else{
		node *q = arr[p->val];
		while(q!=NULL && q->val != val){
			q =q->next;
		}
		return q;
	}
}
node *createnode(int val){
	node *p = (node *)malloc(sizeof(node));
	p->val = val;
	p->next = NULL;
	return p;
}
void addnode(int a,int b){
	if(a==b)return;
	node *p = arr[a];
	node *q = createnode(b);
	if(p==NULL){
		arr[a] = q;
	}else{
		while(p->next!=NULL){
			if(p->val == b)return;
			p=p->next;
		}
		p->next = q;
	}
}
int main(int argc, char const *argv[])
{
	int m,n; // m=no of nodes,n=no of edges
	cin>>m>>n;
	for(int i=0;i<m;i++){
		arr[i]=NULL;
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
		if(p==NULL)cout<<i<<" : NULL"<<endl;
		while(p!=NULL){
			// cout<<"loop"<<endl;
			cout<<p->val<<" ";
			p = p->next;
		}
		cout<<endl;
	}

	return 0;
}