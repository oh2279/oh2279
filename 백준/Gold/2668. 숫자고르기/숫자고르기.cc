#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int arr[101];
bool visited[101],flag;
set<int> ans;

void dfs(int pivot, int num){
    if (visited[num]) { // 다시 돌아왔다면
        if (pivot == num) {
            flag = true;
            ans.insert(num);
        }
        return;
    }
    visited[num] = true;
    dfs(pivot,arr[num]); //
    if (flag) {
        ans.insert(num);
        ans.insert(arr[num]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i=1; i<=n;i++){
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        visited[i] = true;
        dfs(i,arr[i]);
        memset(visited, false, sizeof(visited));
        flag = false;
    }
    cout << ans.size() << '\n';
    for (auto k : ans) {
        cout << k << '\n';
    }
    return 0;
}