#include<bits/stdc++.h>

using namespace std;

int find(string s){
	int n = s.length();
	int arr[n];
	int maxlen =0;
	for(int i=0;i<n;i++){
		arr[i]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(s[j]<=s[i] && arr[i] < arr[j]+1){
				arr[i] = arr[j]+1;
				if(maxlen<arr[i])maxlen = arr[i];
			}
		}
	}
	return maxlen;

}
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	int len = find(s);
	cout<<len<<endl;
	return 0;
}