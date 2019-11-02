#include<bits/stdc++.h>
#define MAX 50
using namespace std;


void minMaxValues(int arr[],int n,int m){
	int sum =0;
	for (int i = 0; i < (n+m); i++)
	{
		sum += arr[i];
		arr[i] += 50;
	}

	bool dp[n+1][MAX*MAX+1];

	memset(dp,0,sizeof(dp));
	dp[0][0]=1;

	for (int i = 0; i < (n+m); i++)
	{
		for (int k = min(n,i+1); k>=1; k--)
		{
			for (int j = 0; j < MAX*MAX+1; j++)
			{
				if(dp[k-1][j])dp[k][j+arr[i]]=1;	
			}
		}
	}
	int maxp = INT_MIN;
	int minp = INT_MAX;

	for (int i = 0; i < MAX*MAX+1; i++)
	{
		if(dp[n][i]){
			int tmp = i-50*n;
			maxp = max(maxp,tmp*(sum-tmp));
			minp = min(minp,tmp*(sum-tmp));
		}
	}
	cout<<maxp<<" "<<minp<<endl;
}

int main(int argc, char const *argv[])
{
    int n = 2, m = 2; 
    int arr[] = { 1, 2, 3, 4 }; 
    minMaxValues(arr, n, m); 
	return 0;
}