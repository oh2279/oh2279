#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >>  n;

    for (ll i = 0; i < n; i++) {
        ll num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());

    ll start = 0;
    ll end = n - 1;
    ll cmp = 2000000000;

    pair<ll,ll> p;

    while(start<end){ // start >= end가 되면 종료
        ll tmp = v[start] + v[end];
        if(abs(tmp) < cmp) {
            p.first = v[start];
            p.second = v[end];
            cmp = abs(tmp);
            if(tmp == 0) break;
        }
        else if(tmp < 0) start++; // 0보다 작으면 음수 한단계 키워줌
        else end--; // 0보다 크면 양수 한단계 줄여줌
    }
    cout << p.first << ' ' << p.second;

    return 0;
}