#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	long long int ans=0;
	std::vector<long long int> v(n);
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end(),greater<>());
	long long max = v[0];
	for(int i=0;i<n;i++){
		v[i]=max-v[i];
	}
	for(int i=0;i<n;i++){
		ans += (v[i]*i - sum);
		sum += v[i];
	}
	cout<<ans<<endl;
	return 0;
}