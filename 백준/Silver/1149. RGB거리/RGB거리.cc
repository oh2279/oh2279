#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n;
int dp[1001][3];
int cost[3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    // 모든 경우의 수 다 계산
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[0]; // R => 이전 집이 초록색이나 파란색으로 칠했을 때 그 둘 중 최소비용 + 빨간 집으로 칠하는 비용
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[1]; // G => 이전 집이 빨간색이나 파란색으로 칠했을 때 그 둘 중 최소비용 + 초록 집으로 칠하는 비용
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + cost[2]; // B => 이전 집이 빨간색이나 초록색으로 칠했을 때 그 둘 중 최소비용 + 파란 집으로 칠하는 비용
    }

    int tmp = min(dp[n][0], dp[n][1]);
    cout << min(tmp, dp[n][2]);
}