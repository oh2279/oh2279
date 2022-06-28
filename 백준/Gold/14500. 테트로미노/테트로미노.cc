#include <iostream>
#include <vector>
using namespace std;

int n,m,ans;
int map[501][501];
int visited[501][501];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void dfs(int r, int c, int depth, int sum) {
    if (depth == 3) {
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = r + dx[i];
        int ny = c + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
        if (visited[nx][ny])continue;
        visited[nx][ny] = true;
        dfs(nx, ny, depth + 1, sum + map[nx][ny]);
        visited[nx][ny] = false;
    }
}

void shape1(int r, int c)
{
    int sum = 0;
    sum = map[r][c] + map[r][c + 1] + map[r][c + 2] + map[r - 1][c + 1];
    ans = max(ans, sum);
}

void shape2(int r, int c)
{
    int sum = 0;
    sum = map[r][c] + map[r][c + 1] + map[r][c + 2] + map[r + 1][c + 1];
    ans = max(ans, sum);
}

void shape3(int r, int c)
{
    int sum = 0;
    sum = map[r][c] + map[r + 1][c] + map[r + 2][c] + map[r + 1][c + 1];
    ans = max(ans, sum);
}

void shape4(int r, int c)
{
    int sum = 0;
    sum = map[r][c] + map[r - 1][c + 1] + map[r][c + 1] + map[r + 1][c + 1];
    ans = max(ans, sum);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            dfs(i, j, 0, map[i][j]); // ㅜ 모양을 제외한 나머지는 dfs로 가능
            visited[i][j] = false;
            if (i - 1 >= 0 && j + 2 < m) shape1(i, j); // ㅗ
            if (j + 2 < m && i + 1 < n) shape2(i, j); // ㅜ
            if (i + 2 < n && j + 1 < m) shape3(i, j); //ㅏ
            if (i + 1 < n && i - 1 >= 0 && j + 1 < m) shape4(i, j); // ㅓ
        }
    }
    cout << ans;
    return 0;
}
