#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
	int val;
	struct Node *next;
}node;
node *root;
node *arr[100];
int vis[1000];
node * createnode(int val){
	node *p = (node *)malloc(sizeof(node));
	p->val = val;
	p->next = NULL;
}
void addnode(int a , int b){
	node * q = (node *)malloc(sizeof(node));
	if(arr[a]==NULL){
		arr[a]=q;
	}
	else{
		node *p = arr[a];
		while(p->next){
			p = p->next;
		}
		p->next = q;
	}
	return;
}
bool DFS(int i, std::vector<int> val){
	node *p = arr[i];
	while(p){
		if(!vis[p->val]){
			vis[p->val]=1;
			if(val[p->val] > val[i])return 0;
			else{
				DFS(p->val,val);
			}
		}
		p = p->next;
	}
	return 1;

}
int validRoot(int n, std::vector<int> from, std::vector<int> to, std::vector<int> val){
	for(int i=0;i<n-1;i++){
		addnode(from[i],to[i]);
		addnode(to[i],from[i]);
	}
	int ans =0;
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(arr));
		vis[i]=1;
		ans += DFS(i,val);
	}
	return ans;

}

int main(int argc, char const *argv[])
{
	std::vector<int> from;
	std::vector<int> to;
	std::vector<int> val;
	from.push_back(3);
	from.push_back(1);
	from.push_back(2);
	to.push_back(2);
	to.push_back(0);
	to.push_back(0);
	val.push_back(4);
	val.push_back(1);
	val.push_back(4);
	val.push_back(1);

	int ans = validRoot(4,from,to,val);
	cout<<ans<<endl;

	return 0;
}