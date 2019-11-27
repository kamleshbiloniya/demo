#include<bits/stdc++.h>

using namespace std;
bool isvowel(char c){
	return c=='a' || c=='e' || c=='i' || c =='o' ||c=='u' || c=='A' || c=='E' || c=='I' ||c =='O'||c=='U';
}
bool areTwin(string s1,string s2){
	int con1=0,con2=0;
	int l1 = s1.length();
	int l2 = s2.length();
	set<char> S1;
	set<char> S2;
	for(int i=0;i<l1;i++){
		if(!isvowel(s1[i])){
			con1++;
			S1.insert(s1[i]);
		}
	}
	for(int i=0;i<l2;i++){
		if(!isvowel(s2[i])){
			con2++;
			S2.insert(s2[i]);
		}
	}
	if(S1.size()!=S2.size() || con1 != con2)return false;
	int m = S1.size();
	auto itr = S2.begin();
	for(auto it=S1.begin();it!=S1.end() && itr != S2.end();++it){
		if(*it != *itr)return false;
		++itr;
	}
	return true;
}

void findTwinSet(vector<string> v){ // v = vector of input strings
	set<string> S;
	int n = v.size();
	map<string,string> dict;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(areTwin(v[i],v[j])){
				dict[v[i]] = v[j];
				break;
			}
		}
	}
	int count = 1;
	for(int i=0;i<n;i++){
		string start = v[i];
		int flag =1;
		while(dict[start].length()){
			if(flag){
				flag=0;
				cout<<"Set "<<count<<" :" << start <<" ";
				count ++;
			}
			cout<<dict[start]<<" ";
			string tmp = dict[start];
			dict.erase(start);
			start = tmp;
		}
		if(flag)cout<<endl;
	}
}
int main()
{
	string s1="BDC";
	string s2="BCD";
	// bool ans = areTwin(s1,s2);
	vector<string> input;
	input.push_back("BCC");
	input.push_back("CCB");
	input.push_back("CBC");
	input.push_back("AROC");
	input.push_back("ECOR");
	input.push_back("IOCR");
	findTwinSet(input);
	// cout<<ans<<endl;
	return 0;
}