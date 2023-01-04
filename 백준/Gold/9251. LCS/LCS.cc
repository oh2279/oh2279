#include <iostream>
#include<string>
#include <algorithm>
using namespace std;


int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int a = s1.length();
    int b = s2.length();

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{   
                dp[i][j] = max(dp[i][j - 1],dp[i-1][j]);
            }
        }
    }

    cout << dp[a][b];

    return 0;
}