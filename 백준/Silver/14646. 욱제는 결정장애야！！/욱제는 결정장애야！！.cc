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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, temp, cnt = 0, ans = 0;
    int arr[100000] = { 0, };
    cin >> n;
    for (int i = 0; i < 2*n; i++) { // 돌림판 돌리기
        cin >> temp;
        arr[temp - 1]++;
        cnt++;// 스티커 갯수
        if (arr[temp - 1] == 2) {  // 두번 다 뽑힌 경우
            cnt -= 2;
        }
        if (cnt > ans) { // 스티커의 개수가 최대인 경우
            ans = cnt;
        }
    }
    cout << ans;
}