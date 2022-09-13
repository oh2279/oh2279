#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,k;
int coin[101];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >>k;
    for (int i = 1; i <= n; i++)
        cin >> coin[i];

    for(int i=1; i<=k;i++) {
        dp[i] = 987654321;
    }
    dp[0]=0;
    for (int i = 1; i <= k; i++){
        for(int j=1; j<=n;j++){
            if(i < coin[j]) continue;

            int tmp = dp[i-coin[j]] + 1;
            if(tmp < dp[i]) dp[i] = tmp;
        }
    }
    if(dp[k] >= 987654321) dp[k] = -1;
    cout << dp[k];

    return 0;
}