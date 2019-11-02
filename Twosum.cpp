#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>dict;
        std::vector<int> ans;
        int len = nums.size();
        for(int i=0;i<len;i++){
        	cout<<"hello"<<endl;
        	if(target - nums[i] >0 && dict[target - nums[i]]>0){
        		cout<<"sir" << i<<endl;
                ans.push_back(i);
        		ans.push_back(dict[target - nums[i]]-1);
        		break;
        	}
        	else{
        		cout<<"no hit "<<nums[i]<<":"<<i<<endl;
        		if(target-nums[i] >=0){
        			dict[target - nums[i]] = i+1;
        		}
        	}
        }
        return ans;

        
    }
};

int main(int argc, char const *argv[])
{

	int n,t;
	cin>>n;
	std::vector<int> v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	cin>>t;
	Solution mysol;
	std::vector<int> ans= mysol.twoSum(v,t);
	for(int i=0;i<2;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}