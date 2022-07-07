#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n,ans=987654321;
int dp[1001][3];
int cost[1001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    // n-1번째까지의 경우의 수 다 계산
    for (int i = 1; i <= n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    // 1번집의 색을 하나씩 고정하면서 dp
    for(int k=0; k <= 2; k++){
        // 하나를 선택하고 나머지값은 엄청 큰 값을 줘서 선택 안하도록함
        for(int i=0; i <= 2; i++){
            if(i == k) dp[1][k]=cost[1][k];
            else dp[1][i]= 987654321;
        }
        // dp점화식
        for(int i=2;i<=n;i++){
            dp[i][0] = min(dp[i-1][1],dp[i-1][2])+cost[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2])+cost[i][1];
            dp[i][2] = min(dp[i-1][1],dp[i-1][0])+cost[i][2];
        }
        //
        for(int i=0; i <= 2; i++){
            if(i == k) continue;
            ans = min(ans, dp[n][i]);
        }
    }

    cout << ans;
    return 0;
}