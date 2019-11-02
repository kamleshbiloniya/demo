#include <bits/stdc++.h>
// #include<algorithm>

using namespace std;

typedef struct Job{
	int deadline;
	int profit;
}job;
bool comparison(job *a , job *b){
	return a->profit < b->profit;
}
int main(int argc, char const *argv[])
{
	job *arr[5];
	for(int i=4;i>=0;i--){
		job *a = (job *)malloc(sizeof(job));
		a->deadline = 5 - i;
		a->profit = 4-i;
		arr[4-i] = a;
	}
	for(int i=0;i<5;i++){
		cout<<arr[i]->profit<<" ";
	}
	cout<<endl;

	sort(arr,arr+5,comparison);
	for(int i=0;i<5;i++){
		cout<<arr[i]->profit<<" ";
	}
	cout<<endl;

	return 0;
}