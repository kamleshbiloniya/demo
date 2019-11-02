#include<iostream>
#include<vector>
using namespace std;
int gcd(int a , int b){

	if(b==0)return a;
	else return gcd(b,a%b);
}
int phi(int n){
	int count =0;
	for(int i=1;i<n;i++){
		if(gcd(n,i)==1)count++;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	std::vector<int> phiarr;
	phiarr.push_back(0);//phi(0)=0 Or not define 
	phiarr.push_back(1);//phi(1)=1
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int count=0;
		for(int j=1;j<=n;j++){
			if(j==1)cout<<1<<" ";
			else{
				if(j<phiarr.size()){
					cout<<phiarr[j]<<" ";
				}else{
					phiarr.push_back(phi(j));
					cout<<phiarr[j]<<" ";	
				}
				
			}
		} 
		cout<<endl;
	}
	return 0;
}