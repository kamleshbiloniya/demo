#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int x,y,n;
		cin>>x>>y>>n;
		int ans =0;
		for(int j=0;j<n;j++){
			int h;
			cin>>h;
			int a = (h-y)/(x-y);
			if(a*(x-y)<h-y)a++;
			ans += a;
		}
		cout<<ans<<endl;
	}
	return 0;
}