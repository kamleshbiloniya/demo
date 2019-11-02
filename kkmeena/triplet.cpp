#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<map>
using namespace std;
using std::cout;

int countTrip(std::vector<int> kk){
  int n = kk.size();
  sort(kk.begin(),kk.end(),greater<int>());
  int i=0;
  int j;
  int count=0;
  while(i<=n-3){
    int sum = kk[i];
    map<int,int>dict;
    for(j=i+1;j<n;j++){
      if(dict[kk[j]]>0){
        count++;
        break;
      }
      else{
        dict[sum-kk[j]] = j;
      }
    }
    dict.clear();
    i++;

  }
  return count>0?count:-1;
}



int main(){
	int t;
	cin >> t;
	for (int j = 0; j <t; ++j)
  {
	    int n;
	    cin >> n;
	    vector<int> kk(n);
	    for(int i=0;i<n;i++) {
	        cin >> kk[i];
      }
      int ans = countTrip(kk);
      cout<<ans<<endl;
  }

	return 0;
}
