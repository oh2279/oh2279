#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

int arr[100001];
int n,m;

void binarySearch(int tmp) {
    int start = 0;
    int end = n - 1;
    int mid;

    while (end >= start) {
        mid = (start + end) / 2;
        if (arr[mid] == tmp) {
            cout << 1 << "\n";
            return;
        } else if (arr[mid] > tmp) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    cout << 0 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    cin >> m;

    sort(arr, arr + n);
    for(int i=0; i<m;i++){
        int tmp;
        cin >> tmp;
        binarySearch(tmp);
    }
    return 0;
}