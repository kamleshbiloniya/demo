#include<bits/stdc++.h>
#include<stdlib.h> 


using namespace std;
typedef struct BOX
{
	int h,w,d;
}Box;

bool cmp(Box a,Box b){
	return a.w*a.d > b.w*b.d;
}
int maxHight(Box arr[],int n){

	Box a[3*n];
	int index = 0;
	for(int i=0;i<n;i++){
		a[index].h = arr[i].h;
		a[index].w = max(arr[i].d,arr[i].w);
		a[index].d = min(arr[i].d,arr[i].w);
		index++;
	}
	for(int i=0;i<n;i++){
		a[index].h = arr[i].w;
		a[index].w = max(arr[i].d,arr[i].h);
		a[index].d = min(arr[i].d,arr[i].h);
		index++;
	}
	for(int i=0;i<n;i++){
		a[index].h = arr[i].d;
		a[index].w = max(arr[i].h,arr[i].w);
		a[index].d = min(arr[i].h,arr[i].w);
		index++;
	}
	n = 3*n;
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i].h<<" "<<a[i].w<<" "<<a[i].d<<endl;
	}

	int mh[n];
	for(int i=0;i<n;i++){
		mh[i] = a[i].h;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i].w < a[j].w && a[i].d < a[j].d && mh[i] < mh[j]+a[i].h)mh[i] = mh[j]+a[i].h;
		}
	}
	int max =-1;
	for(int i=0;i<n;i++){
		if(mh[i]>max)max = mh[i];
	}
	return max;
}

int main(int argc, char const *argv[])
{
	Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};

	int answer = maxHight(arr,4);
	cout<<answer<<endl;
	return 0;
}