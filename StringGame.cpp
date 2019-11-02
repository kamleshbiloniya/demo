#include<bits/stdc++.h>

using namespace std;

string playgame(string s,int k){
	int i=0;
	while (i<s.length()){
		if(s.length()<k)return s;
		int count=1;
		while(count <k && i < s.length()-1){
			if(s[i]==s[i+1]){count++;i++;}
			else{
				count=1;
				i++;
				// break;
			}
		}
		if(count ==k){
			s.erase(i-count+1,count);
			i=0;
		}
		else i++;

	}
	return s;
}

int main(){
	string s;
	int k;
	cin>>k>>s;
	s = playgame(s,k);
	cout<<s<<endl;
}