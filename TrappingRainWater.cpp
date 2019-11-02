#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int arr[] = {3,0,0,2,0,4};
	int len = 6;
	int left[len];
	int right[len];
	left[0] = arr[0];
	for(int i=1;i<len;i++){
		left[i] = max(arr[i],left[i-1]);
	}
	right[len-1] = arr [ len-1];
	for(int i=len-2;i>=0;i--){
		right[i] = max(arr[i],right[i+1]);
	}
	int water =0;
	for(int i=0;i<len;i++){
		water += (min(left[i],right[i])-arr[i]);
	}
	cout<<water<<endl;
	return 0;
}