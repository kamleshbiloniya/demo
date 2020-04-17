#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
	int n,h;
	cin>>n>>h;
	int pos=0;
	int boxpicked=0;
	std::vector<int> stak(n);
	for(int i=0;i<n;i++){
		cin>>stak[i];
	}
	int cmd;
	cin>>cmd;
	while(cmd){
		if(cmd==1){
			if(pos>0)pos--;
		}
		else if(cmd==2){
			if(pos<n-1)pos++;
		}
		else if(cmd==3){
			if(stak[pos]>0 && boxpicked==0){
				stak[pos]--;
				boxpicked++;
			}
		}
		else{
			if(stak[pos]<h && boxpicked==1){
				stak[pos]++;
				boxpicked=0;
			}
		}
		cin>>cmd;
	}
	for(int i=0;i<n;i++){
		cout<<stak[i];
		if(i!=n-1)cout<<" ";
		else cout<<endl;
	}
	return 0;
}

// 7 4
// 3 1 2 1 4 0 1
// 3 2 2 2 2 4 1 3 1 4 0