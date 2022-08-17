#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <string>
#include <queue>
#include <functional>
#include <complex>
#include <cmath>
#include <unordered_map>
#include <map>
typedef long long ll;
using namespace std;

int n,m;
ll r;
int arr[301][301];
bool visited[301][301];
// 오른쪽 아래쪽 왼쪽 위쪽 순서
int dx[]={0,1,0,-1};
int dy[] ={1,0,-1,0};
deque<int> dq[301];

bool changeDir(int x, int y, int d){
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (nx > n || nx < 1 || ny > m || ny < 1) return true;
    if (visited[nx][ny]) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> r;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=m;j++){
            cin >> arr[i][j];
        }
    }
    int cnt = min(n, m) / 2;
    for (int i = 1; i <= cnt; i++) {
        int x = i, y = i, d = 0;
        while(true) {
            if(visited[x][y]) break;
            visited[x][y] = true;
            dq[i].push_back(arr[x][y]);
            if(changeDir(x,y,d)) d++;
            x= x + dx[d];
            y = y + dy[d];
            if(d==4) break;
        }
    }

    // rolling
    for (int i = 1; i <= cnt; i++) {
        int k = r % dq[i].size(); // 굳이 r만큼 돌릴 필요 x
        while (k--) {
            dq[i].push_back(dq[i].front());
            dq[i].pop_front();
        }
    }
    memset(visited,false,sizeof(visited));
    for (int i = 1; i <= cnt; i++) {
        int x = i, y = i, d = 0,k=0;
        while(true) {
            if(visited[x][y]) break;
            visited[x][y] = true;
            arr[x][y] = dq[i][k++];
            if(changeDir(x,y,d)) d++;
            x= x + dx[d];
            y = y + dy[d];
            if(d==4) break;
        }
    }

    for(int i=1; i<=n;i++){
        for(int j=1; j<=m;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}