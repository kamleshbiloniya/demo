#include<bits/stdc++.h>

using namespace std;
int find(string s , int n){
	cout<<s<<endl;
	int count =0;
	for(int i=0;i<n;i++){
		if(s[i]=='a'){
			for(int j=0;j<n;j++){
				if(s[j]=='b'){
					int ind = (((j+1)*(j+1))/(i+1)) -1;
					if(ind >=0 && ind < n && (ind +1)*(i+1) == (j+1)*(j+1) && s[ind]=='c'){
						// cout<<i+1<<" "<<j+1<<" "<<ind+1<<endl;
						count++;
					}
				}
			}
		}
	}
	return count;
}

string reverse(string s , int n){
	string tmp;
	n--;
	while(n>=0){
		tmp += s[n];
		n--;
	}
	return tmp;
}

int main(int argc, char const *argv[])
{
	int n;
	string s;
	cin>>n;
	cin>>s;
	int  x = find(s,n);
	// cout<<reverse(s,n)<<endl;
	cout<<x<<endl;

	return 0;
}	