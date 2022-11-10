#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n,m,ans,cnt;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0; i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
        if(num < 0) cnt++;
    }

    sort(v.begin(), v.end());

    for(int i=0; i<cnt;i+=m){ // 음수
        ans += abs(v[i]) * 2;
    }
    for (int i = n-1; i >= cnt; i-=m) { // 양수
        ans += v[i]*2;
    }
    ans -= max(abs(v[0]),abs(v[n-1]));
    cout << ans ;
    return 0;
}