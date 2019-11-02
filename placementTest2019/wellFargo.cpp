//1:07 AM
#include<bits/stdc++.h>

using namespace std;
int gcd(int a,int b){
	if(a<b){
		int c = a;
		a = b;
		b =c;
	}
	if(b==0)return a;
	return gcd(b,a%b);
}
int vis[100]={0};
bool BFS(int arr[][100],std::vector<int> dst,std::vector<int>src,int i,int j,int g){
	cout<<i<<" "<<j<<endl;
	int flag =0;
	int m = dst.size();
	for (int k = 0; k < m; ++k)
	{
		if(arr[i][dst[k]]>g && vis[dst[k]]==0){
			if(j==dst[k])return true;
			else {
				vis[dst[k]]=1;
				flag = flag + BFS(arr,src,dst,dst[k],j,g);
			}
		}
	}
	return flag;

	return 0;
}
std::vector<int> find(std::vector<int> src,std::vector<int> dst,int n,int g){
	int m = src.size();
	int arr[100][100];
	std::vector<int> ans;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			arr[i][j] = gcd(i,j);
		}
	}
	for(int i=0;i<m;i++){
		if(arr[src[i]][dst[i]]>g){
			ans.push_back(1);
		}
		else{
			int flag =0;
			vis[src[i]]=1;
			flag = BFS(arr,dst,src,src[i],dst[i],g);
			ans.push_back(flag);
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	std::vector<int >src;
	std::vector<int> dst;
	src.push_back(3);
	src.push_back(35);
	dst.push_back(7);
	dst.push_back(15);
	int g  = 2;
	std::vector<int> v = find(src,dst,35,2);
	for (int i = 0; i < 2; ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}