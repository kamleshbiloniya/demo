#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int test;
	scanf("%d",&test);
	for(int t=0;t<test;t++){
		int n;
		scanf("%d",&n);
		std::vector<long long int> A(n);
		std::vector<long long int> B(n);
		for (int i = 0; i <n; ++i)
		{
			scanf("%lld",&A[i]);
		}
		for (int i = 0; i <n; ++i)
		{
			scanf("%lld",&B[i]);
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		int i=0,j=0;
		int count=0;
		while(i<n && j<n){
			if(A[i]>B[j]){
				count++;
				i++;
				j++;
			}
			else{
				i++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}