#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

int n;
int arr[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);

    int res = 1;
    for (int i = 0; i < n; i++) {
        //cout << arr[i] << ' ' << res << '\n';
        if (arr[i] > res) {
            break;
        }
        res += arr[i];
    }

    //출력
    cout << res;
    return 0;
}