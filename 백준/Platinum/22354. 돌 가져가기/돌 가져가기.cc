#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll n,ans=0;
string s;
vector<ll> score;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;

    for(ll i=0; i<n;i++){
        ll num;
        cin>> num;
        score.push_back(num);
    }

    ll cmp;
    for(ll i=0; i<n;i++){
        cmp = score[i];
        if(s[i]==s[i+1]) {
            cmp = max(cmp, score[i + 1]);
            ll j=i+1;
            for ( ; j < n; j++) {
                if (s[j] == s[j + 1])
                    cmp = max(cmp, score[j+1]);
                else break;
            }
            i = j;
        }
        v.push_back(cmp);
    }
    //for(auto k :v) cout << k;
    v[0] = 0;
    v[v.size()-1]=0;
    sort(v.begin(),v.end(),greater<>());
    //for(auto k :v) cout << k;

    ll siz;

    if(v.size() < 3){
        cout << 0; return 0;
    }
    else{
        siz = (v.size()-3) / 2 + 1;
    }
    for(ll i=0; i<siz;i++){
        ans += v[i];
    }
    cout << ans;
    return 0;
}