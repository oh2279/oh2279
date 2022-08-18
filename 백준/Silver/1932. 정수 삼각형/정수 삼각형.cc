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

int n,num;
vector<int> v[510];
int dp[510][510];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=i;j++){
            cin >> num;
            v[i].push_back(num);
        }
    }
    dp[1][0] = v[1][0];
    dp[1][1] = 0;

    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][0] +v[i][0];
        for(int j=1; j<v[i].size();j++){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + v[i][j];
        }
    }
    int ans=-1;
    for(int i=0; i<v[n].size();i++){
        ans = max(ans,dp[n][i]);
        //cout << dp[n][i] << ' ';
    }
    cout << ans;
}