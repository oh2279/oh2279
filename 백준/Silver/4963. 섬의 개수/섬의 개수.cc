#include<iostream>

using namespace std;

int w,h,cnt;
int map[51][51];
bool visited[51][51];
int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


void dfs(int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= h || nx >= w)
            continue;

        if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
            visited[ny][nx] = 1;
            dfs(ny, nx);
        }
    }
}

void reset() {
    cnt = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        cin >> w >> h; // w가 열, h가 행
        reset();
        if (w == 0 && h == 0) {
            break;
        }
        else {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    cin >> map[i][j];
                }
            }
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (map[i][j] ==1 && visited[i][j] ==false) {
                        visited[i][j] = true;
                        dfs(i, j);
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
    
    return 0;
}