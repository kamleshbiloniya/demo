#include<iostream>
using namespace std;

int binarysearch(int low, int high, int arr[],int key){
    // cout<<"searching key "<< key<<endl;
    while(low!=high){
        int mid=(low+high)/2;
        if(key>arr[mid]){
            low=mid+1;
        }
        else if(key<arr[mid]){
            high=mid-1;
        }
        else if (key == arr[mid]){
            return mid;
        }
        else{
            break;
        }
    }


    return -1;
    
}
int main(){
    int N,q;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; i++){
        int entry;
        cin>>entry;
        arr[i]=entry;
    }
    cin>>q;
    int arrq[q];
    for(int i=0; i<q; i++){
        int entry;
        cin>>entry;
        arrq[i]=entry;
    }
    int low=0,high=N-1;
    for(int i=0; i<q; i++){
        cout<<binarysearch(low,high,arr,arrq[i])<<endl;
    }
return 0;
}