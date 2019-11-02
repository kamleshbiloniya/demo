#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	priority_queue<int,vector<int>,greater<int>> pq; //Min heap
	priority_queue<int> pq; // Max heap
	pq.push(20);
	pq.push(10);
	pq.push(50);
	pq.push(5);

	while(!pq.empty()){
		cout<<pq.top()<<endl;
		pq.pop();
	}
	return 0;
}