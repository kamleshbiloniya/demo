#include<bits/stdc++.h>
#define Bigno pow(10,9)+7
using namespace std;

int substrings(string s) {
    int n = s.length();
    int ans;
    for(int i=0;i<n;i++){
        int tmp = s[i]-'0';
        ans += tmp;
        ans = ans % Bigno;
        for (int j=0;j<n;j++){
            tmp += tmp*10 +(s[j]-'0');
            ans += tmp;
            ans = ans%Bigno;

        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
	string s="123";
	int ans = substrings(s);
	cout<<ans<<endl;
	return 0;
}