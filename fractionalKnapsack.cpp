#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Node{
	int val;
	int wt;
	float r; //ratio = val/wt;
}node;

bool cmp(node *a,node *b){
	return a->r > b->r;
}

int main(){
	int W = 50;
	int n=3; //size of array
	int wt[] = {10,20,30};
	int val[] = {60,100,120};
	node *arr[n];
	for(int i=0;i<n;i++){
		node *a = (node*)malloc(sizeof(node));
		a->val = val[i];
		a->wt = wt[i];
		a->r = val[i]/wt[i];
		arr[i] =a;


	}
	sort(arr,arr+n,cmp);
	for(int i=0;i<n;i++){
		cout<<arr[i]->r<<endl;
	}
	int j=0;
	float total =0;
	while(j<n && W > arr[j]->wt){
		W -= arr[j]->wt;
		total +=  arr[j]->val;
		j++;
	}
	if(W>0 && j<n){
		total += W*(arr[j]->val)/(1.0*arr[j]->wt);
	}
	cout<<total<<endl;
}