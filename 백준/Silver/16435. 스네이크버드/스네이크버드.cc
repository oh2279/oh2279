#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, l,h;
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        cin >> h;
        v.push_back(h);
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < n; i++) {
        if (v[i] <= l) {
            l++;
       }
    }
    cout << l;
    return 0;
}
