#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
// int S[1000000];
// int H[1000000];
typedef struct Node {
	int id;
	int s;
}node;
bool cmp(node *a,node *b){
	return a->s < b->s;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for(int test=0;test<t;test++){
		int n,k;
		cin>>n>>k;
		node *arr[n];
		for(int i=0;i<n;i++){
			int strength;
			cin>>strength;
			node *p = (node *)malloc(sizeof(node));
			p->id = i;
			p->s = strength;
			arr[i]=p;
		}
		sort(arr,arr+n,cmp);
		std::vector<int> ht;
		for(int i=0;i<k;i++){
			int h;
			cin>>h;
			ht.push_back(h);
		}
		sort(ht.begin(),ht.end());
		int max=0;
		int ind=0;
		for(int i=0;i<n;i++){
			cout<<arr[i]->s<<" "; 
		}
		cout<<endl;
		for(int i=0;i<k;i++){
			cout<<ht[i]<<" ";
		}
		cout<<endl;
		for(int i=n-1;i>=0;i--){
			int j=k-1;
			while(j>0 && arr[i]->s < ht[j]){
				j--;
			}
			if(i==n-1){
				max = j;
				ind = arr[i]->id;
			}
			else if(max==j){
				ind = arr[i]->id;
			}
			else if(j<max){
				// cout<<ind<<endl;
				break;
			}
		}
		cout<<ind<<endl;

	}
	return 0;
}