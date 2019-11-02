#include<iostream>
using namespace std;
typedef struct NODE{
    int val;
    int x;
    struct NODE *next;
    int childs; // # children
    struct NODE *parent;
    
}node;
node * arr[100];
int st[101];
node* createnode(int b) {
  node *newnode = (node *)malloc(sizeof(node));
  newnode->next = NULL;
  newnode->val = b;
  newnode->x = 0;
  newnode->childs =0;
  newnode->parent = NULL;
  return newnode;

}
void addnode(int a,int b) {
  node *newnode = createnode(b);
  // cout<<"("<<a<<","<<b<<")"<<endl;
  if(arr[a]==NULL){
    arr[a] = createnode(a);
    // cout<<"Error: node createnode";
  }
  //else{
    node *tmp = arr[a];
    // tmp->childs +=1;
    while(tmp->next!=NULL){
      // tmp->childs +=1;
      tmp = tmp->next;
    }
    tmp->next = newnode;
    newnode->parent = tmp;
      
 // }
  
}
void add(node * tmp, int b){
  while(tmp!=NULL){
    tmp->x += b;
    tmp = tmp->next;
    add(tmp,b);
  }
}

int main() {
    int n;
    cin>>n;
    for (int i =1 ; i <=n; ++i)
    {
      arr[i]=NULL;
    }
    arr[1]=createnode(1);
    for(int i=0; i<n-1;i++){
        int a,b;
        cin>>a>>b;
        addnode(a,b);
        // addnode(b,a);
    }
   int op;
   cin>>op;
   for (int i = 1; i <=op; ++i)
    {
      string s;
      cin>>s;
      int a,b;
      cin>>a>>b;
      if(s[0]='m'){
        cout<<max(arr[a]->x,arr[b]->x)<<end;
      }
      else{
        node * tmp = arr[a];
        while(tmp!=NULL){
          tmp->x +=b;
          tmp = tmp->next;
          add(a,b);
        }
        
      }
    } 
    
   
    return 0;
}