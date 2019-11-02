//https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

#include<bits/stdc++.h>

using namespace std;
string prints(string s){
	int len = s.length();

	int arr[len][len];
	memset(arr,0,sizeof(arr));

	for(int i=0;i<len;i++){
		arr[i][i]=1;
	}
	for(int i=1;i<len;i++){
		if(s[i]==s[i-1]){
			arr[i-1][i]=1;
		}
	}
	int maxlen =0;
	int ind =0;
	for(int l=3; l<=len;l++){
		for(int i=0;i<=len-l;i++){
			int j = i+l-1;
			if(s[i] == s[j] && arr[i+1][j-1]){
				arr[i][j]=1;
				if(l>maxlen){
					maxlen = l;
					ind = i;
				}
			}
		}
	}
	string tmp = s.substr(ind,maxlen);
	return tmp;
} 

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		cout<<prints(s)<<endl;;
	}
	return 0;
} 