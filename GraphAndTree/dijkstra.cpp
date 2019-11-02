#include<bits/stdc++.h>
using namespace std;
#define INF 9999999
typedef struct Node{
	int val;
	int w;
	struct Node *next;
}node;

node *arr[100];
int vis[100];
int mindis[100];
std::vector<int> visited;
node * createnode(int val, int w){
	node * newnode = ( node *)malloc(sizeof(node));
	newnode->val = val;
	newnode->w = w;
	newnode->next = NULL;
	return newnode;
}

void addnode(int a,int b,int w){
	node *p = createnode(b,w);
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
void Dijkstra(){
	int minw =INT_MAX;
	int ind =0;
	int flag=0;
	for(int i=0;i<visited.size();i++){
		node *p = arr[visited[i]];
		while(p){
			if(!vis[p->val]){
				if(mindis[visited[i]]+p->w < minw){
					minw = p->w+mindis[visited[i]];
					ind = p->val;
					flag=1;
				}
			}
			p = p->next;
		}
	}
	if(flag){
		vis[ind]=1;
		visited.push_back(ind);
		mindis[ind]=minw;
		Dijkstra();
	}
	else return;
}

int main(int argc, char const *argv[])
{
	int m,n;
	cin>>m>>n; // m = no of nodes , n=no of edges
	for(int i=0;i<m;i++){
		arr[i] = NULL;
		vis[i]=0;
		mindis[i]=INF;
	}
	for(int i=0;i<n;i++){
		int a,b,w;
		cin>>a>>b>>w;
		addnode(a,b,w);
		addnode(b,a,w);
	}
	for(int i=0;i<m;i++){
		node *p = arr[i];
		cout<<i<<" : ";
		if(p==NULL){
			cout<<" NULL";
		}else{
			while(p!=NULL){
				cout<< "("<<p->val<<" "<<p->w<<")"<<" ";
				p = p->next;
			}
		}
		cout<<endl;
	}
	node *p = findnode(0);
	cout<<"root = "<<0<<endl;
	vis[p->val] = 1;
	visited.push_back(p->val);
	mindis[p->val]=0;
	Dijkstra();
	for(int i=0;i<visited.size();i++){
		cout<<i<<" :"<<mindis[i]<<endl;
	}
	return 0;
}
 /*

9 14
0 1 4
1 2 8
2 3 7
3 4 9
4 5 10
5 6 2
6 7 1
7 0 8
1 7 11
7 8 7
6 8 6
2 8 2
2 5 4
3 5 14

*/