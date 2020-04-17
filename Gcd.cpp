#include <iostream>
// #include <bits/stdc++.h>
// #define pb push_back
using namespace std;
int main() 
{
    int t;
    cin>>t;
    int n;
    for(int test=0;test<t;test++)
    {
	    scanf("%d",&n);
	    if(n==1)
	    {
	        // cout<<"1\n";
	        // cout<<"1"<<" "<<"1\n";
	        printf("1\n1 1\n");
	    }
	    else
	    {
		    // vector<vector<int>>ans;
		    // vector<int> copy;
		    // copy.pb(1);
		    int ans=n/2;
		    // cout<<ans<<endl;
		    printf("%d\n",ans);
		    int pages= (n>2)?3:2;
		    // cout<<pages<<" 1 ";
		    printf("%d 1 ",pages);
		    for(int i=2;i<=n;i+=2)
		    {
		        // copy.pb(i);
		        
		        if((i+1)<=n)
		        {
		            // copy.pb(i+1);
		            // if(i!=2)cout<<"2 "<<i<<" "<<i+1<<endl;
		            // else cout<<i<<" "<<i+1<<endl;
		            if(i!=2)printf("2 %d %d\n",i,i+1);
		            else printf("%d %d\n",i,i+1);
		        }
		        else{
		        	// cout<<"1 "<<i<<endl;
		        	printf("1 %d\n",i);
		        }
		        // ans.push_back(copy);
		        // copy.clear();

		    }
		    // cout<<ans.size()<<"\n";
		    // for(int i=0;i<ans.size();i++)
		    // {
		    //     cout<<ans[i].size()<<" ";
		    //     for(int j=0;j<ans[i].size();j++)
		    //     cout<<ans[i][j]<<" ";
		    //     cout<<"\n";
		    // }
	    }   
    }
	return 0;
}

