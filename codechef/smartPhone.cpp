#include<bits/stdc++.h>

using namespace std;


int main(){
	int n;
	cin>>n;
	long long max=0;
	int ind=0;
	std::vector<long long int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end(),greater<>());
	for(int i=0;i<n;i++){
		if(max<(i+1)*v[i]){
			max = (i+1)*v[i];
			ind = i;
		}
	}
	cout<<max<<endl;

}

// 4
// 30
// 20
// 53
// 14