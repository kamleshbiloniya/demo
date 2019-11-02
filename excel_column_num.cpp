//Given a column title as appears in an Excel sheet, return its corresponding column number.
int Solution::titleToNumber(string A) {
    int len = A.length();
    int sum = 0;
    for(int i=0; i<len; i++){
        // cout << int(A.at(i))<<endl;
        sum +=  (int(A.at(i)) - 64)*pow(26,len-1-i);
    }
    return sum;
}
