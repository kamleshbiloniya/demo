#include<bits/stdc++.h>

using namespace std;

void findGroups(vector<string> user1,vector<string> user2){
	int n = user1.size();
	map<string,string> dict;
	for(int i=0;i<n;i++){
		dict[user1[i]]=user2[i];
	}
	int count = 1;
	for(int i=0;i<n;i++){
		string start = user1[i];
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
	// s[i].substr(32,length_of_username);
	vector<string>usernames1;
	vector<string>usernames2;
	// for(int i=0;i<s.length();I++){
	// 	usernames1.push_back(s[i].substr(32,length_of_username););
	// 	usernames2.push_back(32 + length_of_username+14,length_of_username);
	// }
	usernames1.push_back("a");
	usernames2.push_back("b");
	usernames1.push_back("b");
	usernames2.push_back("a");
	usernames1.push_back("a");
	usernames2.push_back("c");
	usernames1.push_back("c");
	usernames2.push_back("a");
	usernames1.push_back("b");
	usernames2.push_back("c");
	usernames1.push_back("c");
	usernames2.push_back("b");
	usernames1.push_back("d");
	usernames2.push_back("e");
	usernames1.push_back("e");
	usernames2.push_back("d");
	usernames1.push_back("d");
	usernames2.push_back("f");
	usernames1.push_back("f");
	usernames2.push_back("d");
	usernames1.push_back("e");
	usernames2.push_back("f");
	usernames1.push_back("f");
	usernames2.push_back("e");
	findGroups(usernames1,usernames2);

	
	return 0;
}