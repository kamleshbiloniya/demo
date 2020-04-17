#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	int count=0;
	std::vector<int> v(n);
	for (int i = 0; i <n; ++i)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(abs(v[i]-v[j])>=k){
				count+= n-j;
				break;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
// 3 1 
// 3 1 3