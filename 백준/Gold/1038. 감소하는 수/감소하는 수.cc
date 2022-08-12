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
ll arr[1000001];

void solve(){
    queue<ll> q;
    int cnt=10;

    for(int i=1; i<=9;i++){
        q.push(i);
    }

    while(cnt <= n && !q.empty()){
        ll number = q.front();
        q.pop();

        int last = number % 10;
        for(int i=0;i<last;i++){
            q.push(number*10 + i);
            arr[cnt++] = number*10 + i;
        }
    }
    if (cnt >= n && arr[n] != 0) cout << arr[n];
    else cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    if(n <= 10){
        cout << n;
    }
    else solve();
}