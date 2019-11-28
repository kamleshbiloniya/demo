#include<bits/stdc++.h>

using namespace std;
std::vector<int > loadBalancer(int k, std::vector<int > arr, std::vector<int> load){
	int n = arr.size();
	std::vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		v.push_back(make_pair(arr[i],load[i]));
	}
	sort(v.begin(),v.end());
	map<int,pair<int,int>> dict;
	int j=0;
	int maxload =0;
	for(int i=0;i<n;i++){
		int start = v[i].first;
		int end = start + v[i].second-1;
		if(!dict[j].first){
			dict[j] = make_pair(v[i].second,end);
			if(v[i].second>maxload)maxload = v[i].second;
			j++;
			j = j%k;
			continue;
		}
		if(dict[j].second<= start){
			dict[j].first += v[i].second;
			dict[j].second = end;
			if(dict[j].first > maxload)maxload = dict[j].first;
			j++;
			j = j%k;
			continue;
		}
		int tmp = j;
		j++;
		j = j%k;
		while(tmp != j){
			if(dict[j].second<= start){
				dict[j].first += v[i].second;
				dict[j].second = end;
				if(dict[j].first > maxload)maxload = dict[j].first;
				j++;
				j = j%k;
				break;
			}
			j++;
			j = j%k; 
		}
	}
	std::vector<int> ans;
	int count=1;
	cout<<"max load is "<<maxload<<endl;
	for(auto itr = dict.begin();itr!=dict.end();++itr){
		if(itr->second.first == maxload){
			ans.push_back(count);
		}
		count++;
	}
	return ans;

}

int main(int argc, char const *argv[])
{
	int k,n;
	cin>>k>>n;
	std::vector<int> arr;
	std::vector<int> load;
	int tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		arr.push_back(tmp);
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		load.push_back(tmp);
	}
	std::vector<int> ans = loadBalancer(k,arr,load);
	cout<<"ans is "<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}

/*

3
5
1
2
3
4
5
5
6
3
4
4
4




3
7
1
2
12
5
6
30
32
7
15
10
10
10
10
15
10


*/