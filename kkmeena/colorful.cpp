#include <bits/stdc++.h> 
using namespace std;


int main(int argc, char const *argv[])
{
	long m,n,k,t;
	cin>>n>>m>>k>>t;
	std::vector<int> v;
	for(long i=0;i<k;i++){
		long x,y;
		cin>>x>>y;
		x--;
		y--;
		v.push_back(x*m+y);
	}
	// for(int i=0;i<v.size();i++){
	// 	cout<<v[i]<<" ";
	// }
	// cout<<endl;
	sort(v.begin(),v.end());
	// for(int i=0;i<v.size();i++){
	// 	cout<<v[i]<<" ";
	// }
	cout<<endl;
	for(long i=0;i<t;i++){
		long x,y;
		cin>>x>>y;
		x--;
		y--;
		long val = x*m+y;
		long waste = 0;
		while(val>v[waste]){
			waste++;
			if(waste == v.size()){
				cout << "Waste" << endl;
				continue;
			}
		}
		if(val==v[waste]){
			cout << "Waste" << endl;
			continue;
		}
		val = val-waste;
		val = val%3;
		switch(val){
		case 0:
			cout  << "Carrots" << endl;
			break;
		case 1:
			cout << "Kiwis" << endl;
			break;
		case 2:
			cout << "Grapes" << endl;
			break;
		default:
			cout << "error" << endl ;
			break;
		}
	}
	return 0;
}