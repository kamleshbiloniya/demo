int Solution::longestSubsequenceLength(const vector<int> &A) {
    int len = A.size();
    vector<int> B;
    vector<int> C;
    for(int i=0; i<len; i++){
        B.push_back(1);
        C.push_back(1);
    }
    for(int j=0; j<len; j++){
        for(int i=0; i<j; i++){
            if(A[j]>A[i]){
                if(B[j]<=B[i]){
                    B[j]=B[i]+1;
                }
            }
        }
    }
    for(int j=len-1; j>=0; j--){
        for(int i=len-1; j<i; i--){
            if(A[j]>A[i]){
                if(C[j]<=C[i]){
                    C[j]=C[i]+1;
                }
            }
        }
    }
    int max =0;
    for(int i=0; i<len; i++){
       if(max<B[i]+C[i]-1)max=B[i]+C[i]-1;
    }
    return max;
}
