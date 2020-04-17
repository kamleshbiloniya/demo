#include<bits/stdc++.h>

using namespace std;
int counter=0;
int best=0;
void seat( std::vector<int> v,int i){
	if(i>9)return;
	if(i==9)counter ++;

	if(v[i]==0){
		v[i]=1;
		if(i==9){best+=1;return;}
		seat(v,i+1);
	}
	else{
		for (int j = 0; j < 10; ++j)
		{
			if(v[j]==0){
				v[j]=1;
				seat(v,i+1);
				v[j]=0;
			}
		}
	}
	
	return;
}

int main(int argc, char const *argv[])
{
	std::vector<int> v(10);
	
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			v[j]=0;
		}
		v[i]=1;
		seat(v,1);
	}
	cout<<counter<<" "<<best<<endl; // prob=best/counter
	return 0;
}