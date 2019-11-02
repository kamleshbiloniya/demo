#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    n= s.length();
   long count =0;
   for(int i=0;i<n-1;i++){
       for(int j=i+1;j<n;j++){
           if(s[i]!=s[j]){
                if(j<n-1&&j==i+1&&s[i]==s[j+1])count++;
                break;
           }
           else{
               count++;
           }
       }
   }
    return count+n;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    cout << result << "\n";

    fout.close();

    return 0;
}