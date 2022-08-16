#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <string>
#include <queue>
#include <functional>
#include <complex>
#include <cmath>
#include <unordered_map>
#include <map>
typedef long long ll;
using namespace std;

int n;
void solve(){
    queue<ll> q;
    vector<ll> v;

    for(int i=0; i<=9;i++){
        q.push(i);
        v.push_back(i);
    }

    while(!q.empty()){
        ll number = q.front();
        q.pop();

        int last = number % 10;
        for(int i=0;i<last;i++){
            q.push(number*10 + i);
            v.push_back(number*10 + i);
        }
    }
    cout << ((n > v.size()) ? -1 : v[n-1]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    solve();
}