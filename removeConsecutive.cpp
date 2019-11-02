#include<bits/stdc++.h>

using namespace std;
string remove(string s){
	int len = s.length();
	list<char> a;
	for(int i=0;i<len;i++){
		a.push_back(s[i]);
	}
	a.unique();
	int n = a.size();
	string ans;
	list<char>::iterator itr;
	for(itr=a.begin();itr!=a.end();++itr){
		ans += *itr;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	s = remove(s);
	cout<<s<<endl;
	return 0;
}