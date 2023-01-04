#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[1001][1001];
string a, b;

void find(int i, int j){
    if (dp[i][j] == 0) return; // LCS 값이 없을 땐 출력하지 않기

    if (a[i-1] == b[j-1]){ // 이전의 문자가 같다면, 해당 인덱스로 재귀호출하기
        find(i-1, j-1);
        cout << a[i-1]; // a[i-1] 혹은 b[i-1] 둘 중 하나 출력하기
    } else dp[i-1][j] > dp[i][j-1] ? find(i-1, j) : find(i, j-1);
    // a, b중에서 LCS가 더 큰 값으로 재귀함수 호출하기
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;

    int a_size = a.length();
    int b_size = b.length();

    for (int i = 1; i <= a_size; i++)
        for (int j = 1; j <= b_size; j++){
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    cout << dp[a_size][b_size] << '\n';

    // a_size, b_size위치부터 거꾸로 문자를 찾아가기.
    find(a_size, b_size);
}