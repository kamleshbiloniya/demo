//13:01
#include<bits/stdc++.h>


using namespace std;


int main(int argc, char const *argv[])
{
	int mat[4][4] = {{0,1,1,0},{1,0,0,1},{1,0,0,0},{0,1,0,0}};


	int vis[4]={0};
	int n =4;
	queue<int> q;

	q.push(0);
	vis[0]=1;
	int level =0;
	while(!q.empty()){
		int next = q.front();
		q.pop();
		cout<<next<<endl;
		for(int i=0;i<n;i++){
			if(mat[next][i] && !vis[i]){
				vis[i]=1;
				q.push(i);
			}
		}
	}

	return 0;
}