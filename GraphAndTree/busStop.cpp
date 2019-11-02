#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int c[n];
	int total =0;
	map<pair<int,int>,int> dict;
	for(int i=0;i<n;i++){
		cin>>c[i];
		dict[make_pair(i,(i+1)%n)]=c[i];
		dict[make_pair((i+1)%n,i)]=c[i];
		total += c[i];
		cout<<i <<" : "<<(i+1)%n<<endl;
	}
	int arr[n][n];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		int j=i+1;
		int d=0;
		arr[i][i]=0;
		while(j!=i){
			if(dict[make_pair(j,(j+1)%n)])
			d += dict[make_pair(j,(j+1)%n)];
			else d += dict[make_pair((j+1)%n,j)];
			arr[i][j] = min(total-d , d);
			// cout<<i<<" "<<j<<" "<<arr[i][j] << " "<<dict[make_pair(j,(j+1)%n)] <<endl;
			j = (j+1)%n;
		}
	}
	for(int i=0;i<n;i++){
		for (int j = 0; j<n; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}