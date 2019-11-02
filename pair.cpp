#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	pair<int,string> p;
	p.first = 1;
	p.second ="kamlesh";
	// cout<<p.first<<" "<<p.second<<endl;
	std::vector<pair<int,string>> v;
	v.push_back(p);
	p.first =5;
	p.second="nisha";
	v.push_back(p);
	p.first = 3;
	p.second ="mohan";
	v.push_back(p);
	sort(v.begin(),v.end(),greater<pair<int,string>>());
	pair<int , string> x = make_pair(2,"sonu");
	v.push_back(x);
	int len = v.size();
	// for (int i = 0; i < len; ++i)
	// {
	// 	cout<<v[i].first<<" "<<v[i].second<<endl;
	// }

	///////////////////////////         map       /////////////////////////



	map<pair<int,string>,int> dict;

	for(int i=0;i<len;i++){
		dict[v[i]]=i;
	}
	map<pair<int,string>,int>::iterator itr;
	for( itr=dict.begin();itr!=dict.end();++itr){
		cout<<itr->first.first<<" "<<itr->first.second<<" "<<itr->second<<endl;
	}
	return 0;
}