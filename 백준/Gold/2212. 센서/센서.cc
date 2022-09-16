#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,k,ans;
vector<int> v,dist;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n-1;i++){
        int d = v[i+1] - v[i];
        dist.push_back(d);
    }
    sort(dist.begin(),dist.end());

    for(int i=0; i<n-k;i++){
        ans += dist[i];
    }
    cout << ans;

    return 0;
}