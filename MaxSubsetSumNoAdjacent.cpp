#include<bits/stdc++.h>

using namespace std;



int main(int argc, char const *argv[])
{
	
	int arr[] = {5, 5, 10, 100, 10, 5};
	int len = sizeof(arr)/sizeof(arr[0]);

	int excl = 0;
	int incl = arr[0];
	for(int i=1;i<len;i++){
		int excl_n = max(incl,excl);
		incl = excl + arr[i];
		excl = excl_n;
	}
	int ans = max(incl,excl);
	cout<<ans<<endl;
	return 0;
}