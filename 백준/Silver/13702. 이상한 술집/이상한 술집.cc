#include <iostream>
using namespace std;
long long n, k, a[10000], r, l, mid, big, cnt, ans;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (big < a[i]) {
            big = a[i];
        }
    }
    l = 1;
    r = big;
    while (l <= r) {
        cnt = 0;
        mid = (l + r) / 2;
        for (int i = 0; i < n; i++) {
            cnt += a[i] / mid;
        }
        if (cnt >= k) {
            if (ans < mid) {
                ans = mid;
            }
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}