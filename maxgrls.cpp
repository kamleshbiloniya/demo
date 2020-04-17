#include<iostream>
#include<limits.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
    scanf("%d",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }

    long long x;
    long long ans =  LLONG_MAX;
    // printf("%lld\n",ans);
    for (int i = 0; i < n; ++i)
    {
    	scanf("%lld",&x);
    	if(arr[i]!=0){
    		x = x/arr[i];
    		// printf("%lld\n",x);
    		if(x<ans)ans=x;
    	}	
    }
    printf("%lld\n",ans);
	return 0;
}