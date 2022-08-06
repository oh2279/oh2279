#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>
#include<set>

using namespace std;

char arr[6][6];
int dx[4] = { -1,1,0,0};
int dy[4]={0,0,1,-1};
vector<pair<int,int>> e, t;
int n;

bool ch(int x,int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x;
        int ny = y;
        while (nx >= 0 && ny >= 0 && nx < n && ny < n) {
            if (arr[nx][ny] == 'O') break;
            if (arr[nx][ny] == 'S') return false;
            nx += dx[i];
            ny += dy[i];
        }
    }
    return true;
}

void dfs(int cnt,int idx) {
    if (cnt == 3) {
        for (auto x : t) {
            // bfs 탐색
            if (!ch(x.first, x.second)) {
                return;
            }
        }
        cout << "YES\n";
        exit(0);
    }
    // 조합으로 탐색
    for (int i = idx; i < e.size(); i++) {
        arr[e[i].first][e[i].second] = 'O';
        dfs(cnt + 1, i+1);
        arr[e[i].first][e[i].second] = 'X';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'T') {
                t.push_back({ i,j });
            }
            else if (arr[i][j] == 'X') {
                e.push_back({ i,j });
            }
        }
    }
    dfs(0, 0);
    cout << "NO\n";

    return 0;
}