#include<iostream>
// #include<map>

using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string s;
		cin>>s;
		// std::map<char,int> dict;
		int arr[26];
		for(int i=0;i<26;i++){
			arr[i]=0;
		}
		int len = s.length();
		for(int i=0;i<len;i++){
			arr[int(s[i])-97]++;
		}
		int max =0;
		int ind = -1;
		for(int i=0;i<26;i++){
			if(max<arr[i]){
				max = arr[i];
				ind = i;
			}
		}
		cout<<char(ind+97)<<endl;
	}
	return 0;
}