#include <iostream>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <string>
#include <cctype>
#include<math.h>


using namespace std;
void DFS(int u);
int findAugmentingPath(int u);
int findBlossom(int s);
void updateMatching(int s , int e);
typedef struct Node{
  int val;                  //mode number
  struct Node *next;
}node;
node * findpointer(int node_val);
node *arr[100];
int count=0;
int vis[100];
int edge[100];
int parent[100];
int papa[100];
int Bnode[100];
int present[100];
int total=0;
node* createNode(int a){
  node *newnode=(node*)malloc(sizeof(node));
  newnode->val=a;
  newnode->next=NULL;
  // newnode->parent=NULL;
  return newnode;
}
void addNode(int i,int val){
  node *newnode=createNode(val);
  if(arr[i]==NULL){
    arr[i]=newnode;
  }
  else{
    node *ptr=arr[i];
    while(ptr->next!=NULL){
      ptr=ptr->next;
    }
    ptr->next=newnode;
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  // int S[n];
  if(m==0){
  	cout<<"0"<<endl;
  	return 0;
  }
  for(int i=1;i<=n;i++){
    edge[i]=0;                       //there is no node in S initially
    vis[i]=0;                     //mark all node unvisited
    parent[i]=0;
    present[i]=1;
  }
  for(int i=0;i<m;i++){         //store the input into adjasency list
    int a,b;
    cin>>a>>b;
    addNode(a,b);
    addNode(b,a);
  }

  if(n==1){
  	cout<<0<<endl; // only one vertex => zero matching 
  	return 0;
  }
  
  ///////////// print the graph //////////////////
 // for(int i=1;i<=n;i++){
 //    std::cout <<"index " <<i<<'=';
 //    if(arr[i]==NULL){
 //      std::cout << "NO edge from this vertex" << '\n';
 //    }
 //    else{
 //      node *p=arr[i];
 //      while(p->next!=NULL){
 //        std::cout << p->val<<" ";
 //        p=p->next;
 //      }
 //      std::cout << p->val<<" ";
 //      std::cout << '\n';
 //    }
 //  }
for(int i=1; i<=n; i++){
	DFS(i);
}
 

  if(total==n/2){
  	 cout<<total<<endl;
  	 for (int i = 1; i <=n; ++i)
	  {
	  	if(edge[i] && edge[edge[i]]){
	  		cout<<i<<" "<<edge[i]<<endl;
	  		edge[i]=0;
	  		edge[edge[i]]=0;
	  	}
	  	// vis[i]=0;
	  	// parent[i]=0;
	  }
	  return 0;
  }
  // vis[5]=0;
  // findAugmentingPath(5);
  // int tmp =8;

	// while(tmp!=NULL){ // find pointer of v
	// 	if(tmp->val==6)break;
	// 	tmp=tmp->next;
	// }
	// cout<<" tmp val "<<tmp<<endl;
	// while(tmp){
	// 	cout<<" current val is = "<< tmp<<endl;
	// 	tmp=parent[tmp];
	// }
  for (int i = 1; i <= n; ++i)
  {
  	vis[i]=0;
  	parent[i]=0;
  }

// findBlossom(1);
// for (int i = 1; i <=n; ++i)
// {
// 	if (present[i])
// 	{
// 		cout<<i<<" ";
// 	}
// }
// for (int i = 1; i <=n; ++i)
// {
// 	cout<<i<<"=="<<edge[i]<<endl;
// 	vis[i]=0;
// }
// cout<<endl;
// cout<<"7 "<<findAugmentingPath(7)<<endl;

for (int i = 1; i <=n; ++i)
{
	if(edge[i]==0){
		// cout<<"calling for "<<i<<endl;
		for (int j = 1; j <=n; ++j)
		{
			papa[j]=0;
			vis[j]=0;
		}
		int e = findAugmentingPath(i);
		// cout<<"e = "<<e<<endl;
		if(e)updateMatching(i,e);
		// for (int i = 1; i <=n; ++i)
		// {
		// 	cout<<i<<"=="<<edge[i]<<endl;
		// 	vis[i]=0;
		// }
		// cout<<endl;
	}

}

cout<<total<<endl;
for (int i =1; i <=n; ++i)
{
	if(edge[i] && edge[edge[i]]){
  		cout<<i<<" "<<edge[i]<<endl;
  		edge[i]=0;
  		edge[edge[i]]=0;
  	}
}

  return 0;
}

void DFS(int u){
	if(vis[u]==0){
		// cout<<" vertex->"<<u<<endl;
		vis[u]=1;
		node * start = arr[u];
		while(start != NULL){
			// arr[start->val]->parent = arr[u];
			if(edge[u]==0 && edge[start->val]==0){ // if both vertex is not matched yet 
				// cout<<"edge "<<edge[u]<<"<-->"<<edge[start->val]<<endl;
				edge[u]=start->val;
				edge[start->val]=u;
				total++;
				// cout<<"edge "<<edge[u]<<"<-->"<<edge[start->val]<<endl;
			}
			DFS(start->val);
			start = start->next;
		}

	}
	else return;
}


int findAugmentingPath(int u){
	if(vis[u]==0){
		vis[u]=1;
		node *ptr = findpointer(u);
		node *childs = arr[u];
		// cout<<" heri bol "<< u <<endl;
		while(childs!=NULL){
			// cout<< " hii "<<endl;
			if(edge[childs->val]!=0 && childs->val != papa[u] && vis[childs->val]==0){
				papa[childs->val]=u;
				papa[edge[childs->val]]=childs->val;
				vis[childs->val]=1;
				// cout<<" jms "<<childs->val<<endl;	
				int i =findAugmentingPath(edge[childs->val]);
				if(i && i!=u)return i;
			}
			else if(edge[childs->val]==0 && childs->val != papa[u] && vis[childs->val]==0){
				papa[childs->val]=u;
				// cout<< " jsr "<<childs->val<<endl;
				return childs->val;
			}
			else{
				// return 0;
			}
			childs = childs->next;
		}
	}
	else return 0;
	return 0;
}



node * findpointer(int node_val){
	if(arr[node_val]==NULL)return NULL;
	node * tmp = arr[arr[node_val]->val];
	while(tmp!=NULL){ // find pointer of u
		if(tmp->val==node_val)return tmp;
		tmp=tmp->next;
	}
	return NULL;
}

int findBlossom(int s){
	if(vis[s]==0){
		cout<<" call for "<<s<<endl;
		vis[s]=1;
		node * ptr = arr[s];
		while(ptr!=NULL){
			if(vis[ptr->val]==0){
				parent[ptr->val]=s;
				findBlossom(ptr->val);
			}
			else if(present[ptr->val] && ptr->val != parent[s]){
				// cout<<"cycle found"<<endl;
				cout<<ptr->val<<" "<<s<<" ";
				int x=parent[s];
				present[s]=0;
				int len=2;
				while(x!=ptr->val && x && present[x]){
					cout<<x<<" ";
					present[x]=0;
					x =parent[x];
					len++;
				}
				parent[ptr->val]=s; //create cyccle 
				present[ptr->val]=0; // hide node
				cout<<endl;
				if(len%2)
				cout<<" odd cycle "<<endl;
				return ptr->val;
			}
			ptr=ptr->next;
		}
	}
	else return 0;
	return 0;
}

void updateMatching(int s , int e){
	while(s!=papa[e]){
		edge[e]=papa[e];
		edge[papa[e]]=e;
		e=papa[papa[e]];
		// cout<<"loop s ="<<s<<"  e = "<<e<<endl;
	}
	edge[e]=s;
	edge[s]=e;
	total++;
	return;
}
















//test case1
// 6 9
// 1 2
// 1 3
// 2 3
// 2 4
// 2 5
// 3 5
// 4 5
// 4 6
// 5 6
// index 1=2 3 
// index 2=1 3 4 5 
// index 3=1 2 5 
// index 4=2 5 6 
// index 5=2 3 4 6 
// index 6=4 5 


//test case 2

// 8 9
// 1 2
// 2 3
// 3 4
// 4 5
// 5 1
// 4 6
// 6 7
// 7 8
// 8 6

//test case 3
// 10 10
// 1 2
// 2 3
// 3 4
// 4 5
// 5 1
// 1 6
// 2 7
// 3 8
// 4 9
// 5 10

//test case 4
// 8 6
// 1 2
// 2 3
// 2 4
// 5 6
// 6 7
// 4 3


//test caes5
// 20 8
// 9 13
// 12 14
// 12 19
// 12 20
// 13 18
// 13 20
// 17 20
// 18 20
// test case 6
// 10 10
// 1 4
// 1 6
// 1 8
// 4 10
// 4 3
// 3 7
// 4 6
// 6 2
// 2 5
// 5 9
// ans:5
//test case 7
// 20 20
// 2 6
// 2 8
// 3 13
// 3 15
// 3 16
// 3 17
// 6 11
// 6 12
// 6 13
// 6 15
// 6 18
// 8 11
// 9 13
// 11 14
// 11 16
// 11 18
// 12 14
// 12 19
// 13 18
// 15 16

//test case 8
// 10 10
// 1 4
// 1 6
// 1 8
// 4 10
// 4 3
// 3 7
// 4 6
// 6 2
// 2 5
// 5 9
//test case 9
// 10 13
// 10 9
// 10 2
// 10 1
// 9 6
// 9 5
// 8 7
// 8 2
// 8 1
// 7 4
// 7 3
// 6 5
// 6 3
// 4 3
//test case 10
// 10 13
// 1 2
// 1 9
// 1 10
// 2 5
// 2 6
// 3 4
// 3 9
// 3 10
// 4 7
// 4 8
// 5 6
// 5 8
// 7 8