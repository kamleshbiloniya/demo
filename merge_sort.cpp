#include<iostream>
using namespace std;

int merge(int arr[],int start,int end){
	if(start >= end)return 0;
	int mid = (start + end)/2;

	int cnt1 = merge(arr,start,mid);
	int cnt2 = merge(arr,mid+1,end);
	int tmp1[mid-start+1];
	int tmp2[end-mid];
	int a=0,b=0;
	for(int i=start;i<=mid;i++){
		tmp1[a] = arr[i];
		a++;
	}
	for(int i=mid+1;i<=end;i++){
		tmp2[b]=arr[i];
		b++;
	}
	int i=0,j=0;
	int k =start;
	int count=0;
	while(i<a && j<b){
		if(tmp1[i]<=tmp2[j]){
			arr[k] = tmp1[i];
			i++;
			k++;
		}
		else{
			count++;
			arr[k]=tmp2[j];
			j++;
			k++;
		}
	}
	while(i<a){
		arr[k]=tmp1[i];
		i++;
		k++;
	}
	while(j<b){
		arr[k]= tmp2[j];
		j++;
		k++;
	}
	return count+cnt1+cnt2;
}
int main(int argc, char const *argv[])
{
	int arr[]={2, 1, 3, 1, 2};
	int count = merge(arr,0,4);
	for(int i=0;i<5;i++){
		cout<<arr[i]<<endl;
	}
	cout<<"count :: "<<count<<endl;
	return 0;
}