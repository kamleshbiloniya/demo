#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int maxScore(vector<int> a, int m) {
    int n = a.size();
    sort(a.begin(),a.end());
    int seg = n/m;
    int rem = n%m;
    int sum =0;
    for(int i=0;i<seg;i++){
        for(int j=0;j<m;j++){
            sum = (sum + (i+1)*a[i*m+j]%mod)%mod;
            cout<<(i+1)<<"*"<<a[i*m+j]<<endl;
        }
    }
    if(rem !=0){
        for(int i=seg*m;i<n;i++){
            sum = (sum +( seg*a[i])%mod)%mod;
            cout<<seg<<"*"<<a[i]<<endl;
        }
    }
    return sum;
    
}


int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	std::vector<int> v(n);
	for (int i = 0; i <n; ++i)
	{
		cin>>v[i];
	}
	cout<<maxScore(v,m)<<endl;
	return 0;
}