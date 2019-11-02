#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int cnt = 50;
	float total = 0;
	float sqsum=0;
	std::vector<float> v;
	for(int i=0;i<cnt;i++){
		float tmp;
		cin>>tmp;
		v.push_back(tmp);
		total += tmp;
		// sqsum += tmp*tmp;
	}
	float mean = total/50.0;
	for (int i = 0; i < cnt; ++i)
	{
		sqsum += (v[i]-mean)*(v[i]-mean);
	}
	
	float var = sqsum/49;
	float sd = sqrt(var);
	cout<< "total is ="<<total<<endl;
	cout<<" mean is "<< mean<<endl;
	cout<<"sqsum is "<<sqsum<<endl;
	cout<<" var is "<<var<<endl;
	cout<<"sd is "<<sd<<endl;

	return 0;
}