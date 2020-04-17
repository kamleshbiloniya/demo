#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	for (int i = 1; i <=5; ++i)
	{
		v.pb(i);
		v.pb(i);
	}
	multiset<pair<int,int>> s;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = i+1; j < 10; ++j)
		{
				pair<int,int> p= make_pair(v[i],v[j]);
				s.insert(p);
		}
	}
	multiset<pair<int,int>>::iterator itr;
	int count =0;
	for(itr= s.begin();itr!= s.end();++itr){
		if(abs((*itr).first - (*itr).second)<2)count++;
		cout<<(*itr).first<<" "<<(*itr).second<<endl;
	}
	cout<<s.size()<<" "<<count<<endl;
	return 0;
}