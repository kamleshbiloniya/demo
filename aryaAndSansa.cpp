#include<iostream>
#include<cmath>
#include<math.h>
#define MAX pow(10,9)+7
using namespace std;
double playGame(int A,int S,double prob,int p,int r){
	if(A<S*p){
		return prob;
	}
	if(A+S == r){
		return prob+1;
	}
	return playGame(A+1,S,prob,p,r)+playGame(A,S+1,prob,p,r);
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	for(int i=0;i<t;i++){
		int r,p;
		cin>>r>>p;
		double ans = playGame(p,0,0,p,r);
		ans = fmod(ans,MAX);
		cout<<ans<<endl;
	}
	return 0;
}