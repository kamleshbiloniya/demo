#include<iostream>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <string>
#include <cctype>
#include<math.h>
using namespace std;
int a[1000];
int item[100];
int count=0;
typedef struct Node{
  int val;
  struct Node *next;
}node;
node * arr[1000];
node *createNode(int a){
  node *newnode = (node*)malloc(sizeof(node));
  newnode->val = a;
  return newnode;
}
void addNode(int x ,int y) {
  node * newnode = createNode(y);
  if(arr[x]==NULL){
    arr[x]=newnode;
  }
  else{
    node *ptr = arr[x];
    while(ptr->next !=NULL){
      ptr = ptr->next;
    }
    ptr->next=newnode;
  }
}

// int BSF(int x){
//   std::vector<int> v;
//   node *ptr = arr[x];
//   while(ptr!=NULL){
//     v.push_back(ptr->val);
//     ptr = ptr->next;
//   }
// }

int main (){
  int n,m,k,s;
  cin>>n>>m>>k>>s;
  for (int i=1; i<=n; i++){
    cin>>a[i];
  }
  for(int i=1;i<=k;i++){
    item[i]=0;
  }

for(int j=0; j<m; j++){
  int a,b;
  cin>>a>>b;
  addNode(a,b);
  addNode(b,a);
}
for(int i=1; i<=n; i++){
 node *ptr = arr[i];
 cout<<i<<" -->";
 while (ptr!=NULL){
   cout<<ptr->val<<" ";
   ptr = ptr->next;
 }
 std::cout  << '\n';
}
// for(int i=0; i<n; i++){
//   if(s>1){
//     count = 0;
//     cout<<BSF(i)<<" ";
//   }
//   else{
//     cout<<1<<" ";
//   }
// }
  return 0;
}
