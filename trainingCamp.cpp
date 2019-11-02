#include<iostream>
#include<map>
using namespace std;
int skill(int num){
	int count=0;
	while(num>0){
		count += num%2;
		num /=2;
	}
	return count;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	map<int,int> dict;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		arr[i]=a;
	}
	for(int i=0;i<n;i++){
		int b;
		cin>>b;
		dict[arr[i]]=b;
	}
	map<int,int>::iterator itr;
	int sum=0;
	int last = -1;
	int last_b =-1;
	int flag=1;
	for(itr=dict.begin();itr!=dict.end();++itr){
		if(last==-1){
			last = itr->first;
			last_b = itr->second;
		}
		else{
			int a = itr->first;
			int b = itr->second;
			if(a!=last && flag){
				last = a;
				last_b = b;
			}
			else{
				if(flag){
					sum += last_b;
					flag =0;
				}
				sum += b;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}