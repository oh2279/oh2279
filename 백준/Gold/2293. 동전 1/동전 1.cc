#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;
int n,k;
int arr[110];
int dp[10010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >>k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    dp[0] = 1;	// 아무 동전도 선택하지 않은 경우
    for (int i = 1; i <= n; i++) { //각 동전에 대해
        for (int j = arr[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - arr[i]];
        }
    }

    cout<<dp[k];
    return 0;
}