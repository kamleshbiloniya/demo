#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int ind[]={0,1,2,1,2};
	int id[] = {0,1,2,3,4};
	priority_queue<pair<int,int>,std::vector<pair<int,int>>,greater<pair<int,int>>>	 pq;
	for (int i = 4; i >=0; i--)
	{
		pq.push(make_pair(ind[i],id[i]));
	}
	for (int i = 0; i < 5; ++i)
	{
		/* code */
		cout<<pq.top().first<<" "<<pq.top().second<<endl;
		pq.pop();

	}
	return 0;
}