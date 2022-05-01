#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000001];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    long long left = 1LL;
    long long right = 1000000000001LL;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    while (left + 1 < right){
        long long mid = (left + right) / 2;
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += mid / arr[i];
        }
        if (cnt >= m) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    cout << right;
    return 0;

}
