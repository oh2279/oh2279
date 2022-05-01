#include<iostream>
#include<math.h>
using namespace std;

int n, m;
int num[1001];
int arr[1001];

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
        arr[i] = arr[i - 1] + abs(num[i] - num[i - 1]);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << arr[b - 1] - arr[a - 1] << '\n';
     
    }
}
