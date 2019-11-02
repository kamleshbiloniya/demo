#include<bits/stdc++.h>
using namespace std;

int numFountains(vector<int> fountains) {
    int n = fountains.size();
    vector<int> extents(n, 0);

    for (int i = 0; i < n; i++) {
        int left = max(i+1 - fountains[i], 1);
        int right = min(i+1 + fountains[i], n);
        extents[left] = max(extents[left], right);
        cout<<i<<" "<<left<<" "<<right<<endl;
    }

    int num_fountains = 1;
    int right = extents[0], next_right = 0;
    for (int i = 0; i < n; i++) {
        next_right = max(next_right, extents[i]);
        if (i == right) {
            num_fountains++;
            right = next_right;
        }
    }

    return num_fountains;
}

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    int ans = numFountains(v);
    cout<<ans<<endl;
}