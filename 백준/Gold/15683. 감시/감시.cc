#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n,m,ans=65;
int arr[8][8];

vector<pair<int,int>> cctv;
int dx[4] = {0, -1, 0, 1}; //0 == right, 1 == up, 2 == left, 3 == down
int dy[4] = {1, 0, -1, 0};

void check(int x, int y, int dir) {
    dir %= 4; // 감시 방향으로 전진
    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
        if(arr[nx][ny]==6) break;
        if (arr[nx][ny] !=0) continue;
        arr[nx][ny] = '#';
    }
    //return;
}
// num번째 CCTV를 회전
void bruteForce(int num) {
    if (num == cctv.size()) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0) tmp++;
            }
        }
        ans = min(tmp, ans);
        return;
    }
    int x = cctv[num].first;
    int y = cctv[num].second;
    // 중간 정보 저장
    int store[8][8];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            store[i][j] = arr[i][j];
        }
    }
    for (int dir = 0; dir < 4; dir++) { // 0 == right, 1 == up, 2 == left, 3 == down
        //dir 1 증가하면 90도 회전
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                store[i][j] = arr[i][j]; // 중간 정보 저장
            }
        }
        if (arr[x][y] == 1) {
            check(x, y, dir); // right
        } else if (arr[x][y] == 2) {
            check(x, y, dir); // right
            check(x, y, dir + 2); // left

        } else if (arr[x][y] == 3) {
            check(x, y, dir); // right
            check(x, y, dir + 1); // up
        } else if (arr[x][y] == 4) {
            check(x, y, dir); // right
            check(x, y, dir + 1); // up
            check(x, y, dir + 2); // left

        } else if (arr[x][y] == 5) {
            check(x, y, dir); // right
            check(x, y, dir + 1); // up
            check(x, y, dir + 2); // left
            check(x, y, dir + 3); // down
        }
        bruteForce(num + 1);

        // return 받았으면 = CCTV를 한번씩 확인 했으면
        // 다시 중간 정보를 불러와서 방향 돌려보면서 확인
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = store[i][j];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0; i<n;i++){
        for (int j=0;j<m;j++) {
            cin >> arr[i][j];
            if (arr[i][j] >= 1 && arr[i][j] <= 5) {
                cctv.push_back({ i, j });
            }
        }
    }
    bruteForce(0);
    cout << ans;
    return 0;
}