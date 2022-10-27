#include<bits/stdc++.h>
using namespace std;

int n,r,c;
int dp[501][501];
int matrix[501][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i=1; i<=n;i++){
        cin >> r >> c;
        matrix[i][0]=r;
        matrix[i][1]=c;
    }
    for (int i = 1; i < n; i++)// 구간의 크기 = 곱하는 행렬의 수
    {
        for (int j = 1; i + j <= n; j++) // 시작점
        {
            dp[j][i + j] = 987654321; // 초기화
            for (int k = j; k <= i + j; k++) // k는 기준점
            {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i+j][1]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}