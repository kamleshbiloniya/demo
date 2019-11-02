#include<bits/stdc++.h>


using namespace std;

void find(int arr[], int k,int len){

	// int len = sizeof(arr)/sizeof(arr[0]);
	// cout<<"eln "<<len<<endl;
	for(int i=0;i<len-2;i++){
		int sum = k -arr[i];
		set<int> s;
		for(int j=i+1;j<len;j++){
			if(s.find(k-arr[i]-arr[j])!=s.end()){
				cout<<arr[i]<<"+"<<arr[j]<<"+"<<k-arr[i]-arr[j]<<"="<<k<<endl;
				return;
			}
			else{
				s.insert(arr[j]);
			}
		}

	}
}
int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	find(arr,k,n);
	return 0;
}