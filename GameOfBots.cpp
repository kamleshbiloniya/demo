#include<iostream>

using namespace std;
bool fun(string s1,string s2,int i,int j){
	int count =0;
	while(s2[j]=='#' && j<s2.length()){
		j++;
		count++;
	}
	int cnt=0;
	while(s1[i]=='#' && i<s1.length()){
		i++;
		cnt++;
	}
	if(i==s1.length() && j==s2.length())return 1;
	else if(s1[i]!=s2[j]){
		return 0;
	}
	else if(s1[i]=='A' && count > cnt){
		return 0;
	}
	else if(s1[i]=='B' && count < cnt){
	    return 0;
	}
	else{
		if(i==s1.length() && j<s2.length())return 0;
		else if(i < s1.length() && j==s2.length())return 0;
		else if(i<s1.length() && j<s2.length()){
			return fun(s1,s2,i+1,j+1);
		}
		else{
			return 1;
		}
	}
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for(int test=0;test<t;test++){
		string s1,s2;
		cin>>s1>>s2;
		int l1= s1.length();
		int l2 = s2.length();
		if(l1!=l2){
			cout<<"No"<<endl;
		}
		else{
			int i=0;
			int j=0;
			bool ans = fun(s1,s2,i,j);
			if(ans)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}