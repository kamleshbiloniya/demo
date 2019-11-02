//Problem : Give a string find number of substrings containing at least one each vowels (a,e,i,o,u); 
// Eg : aeioua --> subsring {aeiou,aeioua,eioua} as =3;
//Eg2: aeiouexaaeuiouaauzaio --> 
/*
{aeioue
aeiou
aaeuio
aaeuiou
aaeuioua
aaeuiouaa
aaeuiouaau } */
//https://www.geeksforgeeks.org/find-substrings-contain-vowels/
#include<bits/stdc++.h>

using namespace std;
bool isvowel(char c){
	return (c=='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void find (string s){

	int len = s.length();
	int start =0;
	set<char> dict;
	for(int i=0;i<len;i++){
		if(isvowel(s[i])){
			dict.insert(s[i]);
			if(dict.size()==5){
				cout<<s.substr(start,i-(start-1))<<endl;
			}
		}
		else{
			start = i+1;
			dict.clear();
		}
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		find(s);
	}
	return 0;
}