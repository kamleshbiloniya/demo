#include<iostream>

using namespace std;
int j=0;
void convert(int arr[],int BST[],int start,int end){
	if(start>end)return;
	int mid = (start+end)/2;
	BST[j]=arr[mid];
	j++;
	convert(arr,BST,start,mid-1);
	convert(arr,BST,mid+1,end);
}
int main(){

	int t;
	cin>>t;
	for(int j=0;j<t;j++){
		int n;
		cin>>n;
		int BST[n];
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		convert(arr,BST,0,n-1);
		for(int i=0;i<n;i++){
			cout<<BST[i]<<endl;
		}
		
	}
}