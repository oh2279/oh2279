#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        ll num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    ll cmp = 3e9 + 1;

    ll first = 0;
    ll second = 0;
    ll third = 0;

    for (ll i = 0; i < n-2; i++) {
        ll start = i+1;
        ll end = n - 1;
        while (start < end) { // start >= end가 되면 종료
            ll buf = v[start] + v[end] + v[i];

            if (abs(buf) < cmp) {
                first = v[i];
                second = v[start];
                third = v[end];
                cmp = abs(buf);
            }
            if (buf < 0) start++; // 0보다 작으면 음수 한단계 키워줌
            else end--; // 0보다 크면 양수 한단계 줄여줌
        }
    }
    cout << first << ' ' << second << ' '<< third;
    return 0;
}