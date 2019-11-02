#include<bits/stdc++.h>

void swap(int *a , int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp; 
}

using namespace std;
int partition(int arr[],int left,int right){
	// cout<<left<<" "<<right<<endl;
	int pivot = arr[left];
	int l = left;
	int r = right;
	while(l<=right && r>= left){
		// cout<<"loop1";
		while(arr[l]< pivot && 	l< right){
			l++;
		}
		while(arr[r]> pivot && r > left){
			r--;
		}
		if(l>=r)return r;
		else{
			swap(&arr[l],&arr[r]);
			l++;
			r--;
		}
	}
	// return r;
}

void quicksort(int arr[], int left, int  right){
	if(left>=right)return;
	else{
		int p = partition(arr,left,right);
		for(int i=left;i<p;i++){
			// cout<<"partition 1 :"<<arr[i]<< " ";
		}
		// cout<<endl;
		for(int i=p;i<=right;i++){
			// cout<<" partition 2 :"<<arr[i] << " ";
		}
		// cout<<endl;
		quicksort(arr,left,p);
		quicksort(arr,p+1,right);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	quicksort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}