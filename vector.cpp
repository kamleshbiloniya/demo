#include<bits/stdc++.h>

using namespace std;
string convertto24(string s){
		string result = "";
	  if(s[8]=='P'){
	      result = to_string(12+ (int(s[0])-48)*10 + int(s[1])-48);
	      cout<<result<<endl;
	  }else{
	  		if((int(s[0])-48)*10 + int(s[1])-48 == 12){
	  			result = "00"
	  		}
	  		else{		
		      result = s[0];
		      result += s[1];
	  		}
	  }
	  for(int i=2;i<8;i++){
	      result += s[i];
	  }
	  return result;
}

int main(){
	string in="01:12:12PM";
	string out;
	// cin>>in;
	out = convertto24(in);
	cout<<out<<endl;
}