#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin>>t;
 std::vector<int> v;
while(t!=0){
	v.push_back(t%10);
	t/10;
}
int len =v.size();
cout<<len<<endl;

  return 0;
}