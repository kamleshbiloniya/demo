#include<bits/stdc++.h>

using namespace std;
void insertionSort(int arr[],int start,int end){
	if(start>=end)return;
	for(int i=start+1;i<=end;i++){
		int j=i;
		int tmp = arr[i];
		while(j>start && arr[j-1]>arr[i]){
			arr[j] = arr[j-1];
			j--;
		}
		arr[j]=tmp;
	}
	return;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	insertionSort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}