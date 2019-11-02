#include<iostream>
using namespace std;
typedef struct Node{
  int val;
  int wt;
  struct Node *next;
}node;
node *arr[100];
node* createnode(int b,int w) {
  node *newnode = (node *)malloc(sizeof(node));
  newnode->next = NULL;
  newnode->val = b;
  newnode->wt = w;
  return newnode;

}
void addnode(int a,int b, int w) {
  node *newnode = createnode(b,w);
  if(arr[a]==NULL){
    arr[a] = newnode;
  }
  else{
    node *tmp = arr[a];
    while(tmp->next!=NULL){
      tmp = tmp->next;
    }
    tmp->next = newnode;
  }
}
int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b,w;
    cin>>a>>b>>w;
    addnode(a,b,w);
  }
  for(int i=0;i<n;i++){
    node *tmp = arr[i];
    while(tmp->next!=NULL){
      cout<<tmp->val<< " "<<tmp->wt<<endl;
      tmp = tmp->next;
    }
  }
  return 0;
}
