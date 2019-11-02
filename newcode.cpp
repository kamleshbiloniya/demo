#include<iostream>
using namespace std;
typedef struct NODE{
    int val;
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
      tmp->childs +=1;
      tmp = tmp->next;
    }
    tmp->next = newnode;
    newnode->parent = tmp;
      
 // }
  
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
    for(int i=1; i<=n; i++){
        int s;
        cin>>s;
        st[i] = s;
    }
    // for (int i = 1; i <=n; ++i)
    // {
    //   node * tmp = arr[i];
    //   tmp = tmp->next;
    //   while(tmp!=NULL){
    //     cout<<i<<"-->"<<tmp->val<<" ";
    //     tmp = tmp->next;
    //   }
    //   cout<<endl;
    // }
    for(int i=1;i<=n;i++){
      node * tmp = arr[i];
      if(tmp==NULL){
        cout<<"1 ";
        continue;
      }
      int ps = st[tmp->val];
      int count=1;
      while(tmp!=NULL){
          if(ps>=st[tmp->val]){
            count +=tmp->childs;
          }
          tmp= tmp->next;
          // cout<<"fuck"<<endl;
      }
      cout<<count<<" ";
    }
    cout<<endl;
    
    return 0;
}