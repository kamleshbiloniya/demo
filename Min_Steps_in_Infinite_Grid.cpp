int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int len = A.size();
    int x = A[0];
    int y = B[0];
    int result=0;
    for(int i=1; i<len; i++){
        int a = A[i]-x;
        int b = B[i]-y;
        result += (abs(a)>abs(b))?abs(a):abs(b);
        x = A[i]; 
        y = B[i];
    }
    return result;
}

