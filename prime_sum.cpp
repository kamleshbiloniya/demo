//Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number



bool Isprime(int a){
    if(a==2)return true;
    for(int i=2; i<=sqrt(a); i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
vector<int> Solution::primesum(int A) {
    vector <int> B;
    for(int i=2; i<A; i++){
        if(Isprime(i)){
            if(Isprime(A-i)){
               B.push_back(i);
               B.push_back(A-i);
               return B;
            }
        }
    }
}
