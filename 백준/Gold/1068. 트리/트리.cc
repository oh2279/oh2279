#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,del,root,ans;
vector<int> tree[51];

int dfs(int node) {
    if (node == del) return -1;
    if (tree[node].empty()) { // 자식이 없으면 left
        ans++;
        return 0 ;
    }
    for (int i = 0; i < tree[node].size(); i++) {
        int tmp = dfs(tree[node][i]); // dfs 탐색
        if (tmp == -1 && tree[node].size() == 1) // 자식 노드가 삭제될 노드이고 자식이 하나라면 부모가 leaf가 된다.
            ans++;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == -1)
            root = i;
        else
            tree[num].push_back(i);
    }
    cin >> del;
    dfs(root);

    cout << ans;
    return 0;
}