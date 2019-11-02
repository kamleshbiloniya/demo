//Recursively remove all adjacent duplicates


#include<bits/stdc++.h>

using namespace std;
int erase ( string *S ,int i ){
	// cout<<"hi "<<*S<<endl;
	S->erase(S->begin()+i);
	S->erase(S->begin()+(i-1));

	i--;
	if((*S).size()<2)return 2;

	if(i==0)i++;

	if(S[i] == S[i-1]){
		i = erase(S,i);
	}
	return i;


}

string remove(string s){
	// cout<<"hello"<<endl;
	int len = s.length();
	if(len<2)return s;
	
	int i=1;
	while(i<s.length()){
		if(s[i] == s[i-1]){
			i = erase(&s , i);
		}
		else{
			i++;
		}
		
	}
	return s;

}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		string ans = remove(s);

		cout << ans<<endl;
	}
	return 0;
}