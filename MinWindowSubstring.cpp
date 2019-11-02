#include<bits/stdc++.h>

using namespace std;

string minWindow(string s, string t){
	int n = s.length();
	int m = t.length();

	if(n==0 || m==0 || m>n )return "";

	int hash_S[256]={0};
	int hash_T[256]={0};

	for(int i=0;i<m;i++){
		hash_T[t[i]]=1;
	}
	int count =0;
	int start =0;
	int minstart=0;
	int minlen = INT_MAX; 
	for(int i=0;i<n;i++){
		hash_S[s[i]]++;
		if(hash_T[s[i]]!= 0 && hash_T[s[i]]>= hash_S[s[i]])count++;
		if(count == m){
			while(hash_T[s[start]] ==0 || (hash_S[s[start]] > hash_T[s[start]])){
				if(hash_S[s[start]] > hash_T[s[start]])hash_S[s[start]]--;
				start++;
			}
			if(minlen > i-start+1){
				minlen = i - start +1;
				minstart = start;
			}
		}
	}
	return s.substr(minstart,minlen);

}
int main(int argc, char const *argv[])
{
	string S="ADOBECODEBANCABC";
	string T="ABC";
	string ans = minWindow(S,T);
	cout<<ans<<endl;
	return 0;
}