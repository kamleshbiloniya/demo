vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(),A.end());
    int len = A.size();
    if(len%2==0){
        for(int i=0; i<len; i+=2){
            int x = A[i];
            A[i]=A[i+1];
            A[i+1] = x;
        }
    }
    else{
        for(int i=0; i<len-1; i+=2){
            int x = A[i];
            A[i]=A[i+1];
            A[i+1] = x;
        }
    }
    return A;
}
