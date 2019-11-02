//122221



int Solution::isPalindrome(int A) {
    string B = to_string(A);
    int len = B.length();
    for(int i=0 ; i<= len/2; i++){
        if(B.at(i)!=B.at(len-1-i))return false;
    }
    return true;
}
