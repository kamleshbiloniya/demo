//Given 2 non negative integers m and n, find gcd(m, n)
int Solution::gcd(int A, int B) {
    while(B!=0){
        int t=B;
        B = A %B;
        A = t;
    }
    return A;
}
