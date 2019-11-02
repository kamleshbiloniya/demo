#include<bits/stdc++.h>

using namespace std;

int remove(std::vector<int> a,int k){
	int len = a.size();
	map<int,std::vector<int>>dict;
	for(int i=1;i<len;i++){

		dict[a[i]-a[i-1]].push_back(i-1);
	}
	map<int,std::vector<int>>::iterator start,endx;
	endx = dict.end();
	start = dict.begin();
	endx--;
	start--;
	int i=0;
	int j=len-1;

	while(i<j && endx != start){
		std::vector<int> v = endx->second;
		int m = v.size();
		// cout<<endx->first<<" v size "<<m<<endl;
		for(int x =0;x<m;x++){
			int indx = v[x];
			// cout<<indx<<endl;
			if(indx<i || indx > j)continue;
			if(indx-i+1 <= j - indx){
				if(k>= indx -i+1){
					k -= indx-i+1;
					i = indx+1;
				}
				else return endx->first;
			} 
			else{
				if(k>= j- indx){
					k -= j - indx;
					j = indx;
				}
				else return endx->first;
			}
			cout<<i<<" "<<j<<endl;
		}
		endx--;
	}
	return 0;

}


int alternative(std::vector<int> a , int k){
	int len = a.size();
	int arr[len-1];
	for(int i=1;i<len;i++){
		arr[i-1]= a[i]-a[i-1];
	}
	int n = len - k -1;
	if(n==1){
		int min = arr[0];
		for (int i = 0; i < len-1; ++i)
		{
			if(min>arr[i])min = arr[i];
		}
		return min;
	}
	int max=INT_MIN;
	int min = INT_MAX;
	int f= (arr[0]>arr[1])?0:1;
	int s = (f==0)?1:0;
	int i;
	for(i=2;i<n;i++){
		if(arr[i]>arr[f]){
			s = f;
			f = i;
		}
		else if(arr[i]>arr[s]){
			s = i;
		}
	} 
	min = arr[f];
	cout<<"n = "<<n <<" "<<s<<" "<<f<<endl;
	cout<<min<<endl;
	while(i<len-1){
		if(i-f+1<=n && i-s+1<=n){
			if(arr[i]>arr[f]){
				s = f;
				f = i;
			}
			else if(arr[i]>arr[s]){
				s = i;
			}
			
		}
		else if(i-f+1>n && i-s+1<=n){
			if(arr[i]>arr[s]){
				f = i;
			}
			else{
				f=s;
				s =i;
			}
		}
		else {
			if(arr[i]>arr[f]){
				s = f;
				f = i;
			}
			else{
				s =i;
			}
		}
		if(min > arr[f])min = arr[f];
		i++;
		cout<<arr[f]<<endl;
	}
	return min;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans = alternative(a,k);
	cout<<ans<<endl;
}