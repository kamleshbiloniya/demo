#include<iostream>


using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for(int x=0;x<t;x++){
		int n;
		string s;
		cin>>n>>s;
		int i=0,j=1;
		int arr[n];
		arr[0]=1;
		while(j<n){
			if(s[j]>=s[j-1]){
				arr[j] = arr[j-1] + j-i+1;
				j++;
			}	
			else{
				arr[j] = arr[j-1]+ 1;
				i=j;
				j++;
			}
		}
		cout<<arr[n-1]<<endl;
	}
	return 0;
}