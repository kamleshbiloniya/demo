#include<bits/stdc++.h>

using namespace std;


int find(int n,int k){
	if(k>n)return 0;
	if(k==n || 2*k>n || 2*k==n )return 1;
	if(2*k+1 == n )return 2;
	return find(n,2*k)+find(n,2*k+1);
}
int main(int argc, char const *argv[])
{
	int n= 5;
	int k= 1;
	cout<<find(n,k)<<endl;
	return 0;
}