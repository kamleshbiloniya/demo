//19:02
#include<bits/stdc++.h>
using namespace std;

int minswap(string s){
	int n =s.length();
	map<int,int> dict;
	for(int i=0;i<n;i++){
		dict[s[i]]++;
	}
	int odd=0;
	for(auto itr=dict.begin();itr!=dict.end();++itr){
		if(itr->second %2)odd++;
	}
	if(odd>1)return -1;
	int ans=0;
	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-1-i]){
			int cnt1=1;
			int cnt2=1;
			while(i+cnt1<n && s[i+cnt1]!=s[n-1-i])cnt1++;
			while(n-1-i-cnt2>=0 && s[n-1-i-cnt2]!=s[i])cnt2++;
			if(cnt1>cnt2){
				for(int j=n-1-i-cnt2;j<n-i-1;j++){
					char ch = s[j];
					s[j] = s[j+1];
					s[j+1] = ch;
				}
			}
			else{
				for(int j=i+cnt1;j>i;j--){
					char ch = s[j-1];
					s[j-1] = s[j];
					s[j] = ch;
				}
			}
			ans += min(cnt2,cnt1);
		}
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	string s = "asflkj";
	int ans = minswap(s);
	cout<<ans<<endl;
	return 0;
}