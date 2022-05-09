#include<iostream>
#include <algorithm>
#include<queue>
#include<vector>
using namespace std;

int t, n, m, k;
int map[51][51];
int visited[51][51];
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
}

void dfs(int y, int x){
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;

        if (map[ny][nx] == 1 && visited[ny][nx] == 0) { // 이동한 곳에 인접한 배추가 있으면
            dfs(ny, nx);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> m >> n >> k; // m이 열, n이 행
        reset();

        while (k--) {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1 && visited[i][j] == 0) { // 배추가 있고 방문하지 않았으면
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}