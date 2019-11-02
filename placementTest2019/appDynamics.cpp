#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	map<int,int> dict;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		if(dict[x])dict[x]++;
		else{
			dict[x] = 1;
		}
	}

	map<int,int>::iterator itr;
	map<int,int>::iterator itr2;
	itr2 = dict.begin();
	itr2--;
	itr = dict.end();
	itr--;
	int ans=0;
	while(itr != itr2 && k>0){
		int current = itr->first;
		int val = itr->second;
		
		cout<<current<<" "<<val <<" "<< k<<" "<< endl;
		if(k >= val){
			ans += current*val;
			k -= val;
			dict[current-1] += val;
			itr--;
			int next = itr->first;
			// dict[next] += val;
			cout<<" running ans "<<ans<<endl;
		}

		else{
			ans += k*current;
			k=0;
		}
	}
	cout<<"ans = "<<ans<<endl;
	return 0;
}

/*
5 19
4 3 6 2 4

*/