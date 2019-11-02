#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    int l = s1.length();
   int arr[l+1][l+1];
   for(int i=0;i<=l;i++){
    arr[i][0]=0;
   }
   for(int i=0;i<=l;i++){
    arr[0][i]=0;
   }
    for(int i=1;i<=l;i++){
        for(int j=1;j<=l;j++){
            if(i==0||j==0)arr[i][j]=0;
            if(s1[i-1]==s2[j-1]){
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else{
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    return arr[l][l];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    cout << result << "\n";

    fout.close();

    return 0;
}
