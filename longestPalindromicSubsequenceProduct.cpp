
#include <iostream>
#include<string>
#include<vector>
using namespace std;

int longestPalindromicSubsequenceProduct(string x){
int n = x.size();
vector<vector<int>> dp(n,vector<int>(n,0));
for(int i=0;i<n;i++){
    dp[i][i] = 1;
}
for(int k=1;k<n;k++){
for(int i=0;i<n-k;i++){
        int j = i + k;

            if(x[i]==x[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            } else{
                dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
            }
            cout<<"("<<i<<","<<j<<") "<<dp[i][j]<<endl;
   }
}
int maxProd = 0;
for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
        maxProd = max(maxProd,dp[i][j]*dp[j+1][n-1]);
      }
   }
return maxProd;
}

int main(int argc, char const *argv[])
{
	string s= "ababb";
	int ans = longestPalindromicSubsequenceProduct(s);
	cout<<ans<<endl;
	return 0;
}