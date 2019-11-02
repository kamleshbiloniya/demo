#include<iostream>


using namespace std;


int main(int argc, char const *argv[])
{
	int W = 50;
	int n=3; //size of array
	int wt[] = {10,20,30};
	int val[] = {60,100,120};
	
	int K[n+1][W+1];

	for(int i=0;i<=n;i++){
		for(int w = 0;w<=W;w++){
			if(w==0||i==0)K[i][w]=0;

			else if(w >= wt[i-1]){
				K[i][w]=max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
			}else{
				K[i][w]=K[i-1][w];
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int w = 0;w<=W;w++){
			cout<<K[i][w]<<" ";
		}
		cout<<endl;
	}
	cout<<K[n][W]<<endl;
	return 0;
}