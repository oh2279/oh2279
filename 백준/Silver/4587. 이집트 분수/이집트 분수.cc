#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) {
    ll buf,res;
    if(x<y){
        buf = x;
        x = y;
        y = buf;
    }
    while(y!=0){
        res = x%y;
        x = y;
        y = res;
    }
    return x;
}
bool cmp(ll p, ll q, ll m){
    if((p * m - (1*q) >= 1)){
        return true;
    }
    return false;
}
void egyptianFraction(ll p, ll q) {
    vector<ll> v;
    int cnt = 1000000;
    ll m=2;

    while(cnt--) {
        if (cmp(p,q,m)) { // 단위 분수로 빼기
            ll bunmo = q * m;
            ll bunza = (p * m) - (1 * q);
            ll tmp = gcd(bunza, bunmo);
            v.push_back(m);
            if(bunmo/tmp >= 1000000){
                v.pop_back();
            }
            else if (bunza / tmp == 1 && bunmo / tmp < 1000000) { // 단위분수를 뺀 결과가 단위분수이고, 분모가 백만보다 작다면
                v.push_back(bunmo/tmp);
                break;
            }
            else if(bunza/tmp != 1){ // 단위 분수를 뺀 결과가 단위분수가 아니라면
                p = bunza/tmp; q = bunmo/tmp;
                m--;
            }
        }
        m++;
    }
    for(int i=0; i<v.size();i++){
        cout << v[i]<< ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll p, q;
    while(true) {
        cin >> p >> q;
        if (p == 0 && q == 0) break;
        egyptianFraction(p, q);
    }
    return 0;
}