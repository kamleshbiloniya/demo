#include<bits/stdc++.h>

using namespace std;

bool isVowel(char c){
	return c=='a' || c == 'e' || c=='i' || c=='o' || c=='u';
}

std::vector<int> Vowel(std::vector<string> v, std::vector<string> u){
	int n= v.size();
	int m= u.size();
	std::vector<int> ans;
	int arr[n+1];
	arr[0]=0;
	for (int i = 0; i < n; ++i)
	{
		if(v[i][0]==v[i][v[i].length()-1] && isVowel(v[i][0]))arr[i+1]=1;
		else arr[i+1]=0;
	}

	for (int i = 1; i <= n; ++i)
	{
		arr[i] += arr[i-1];
	}
	for (int i = 0; i < m; ++i)
	{
		int l = int(u[i][0]-'0');
		int r = int(u[i][2]-'0');
		// cout<<l<<" "<<r<<endl;
		ans.push_back(arr[r]-arr[l-1]);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	std::vector<string> v(n);
	std::vector<string> u(m);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>u[i];
	}
	std::vector<int> ans = Vowel(v,u);
	int len = ans.size();
	for (int i = 0; i < len; ++i)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}

/*
5 3
aba bcb ece aa e
1-3 2-5 2-2

*/