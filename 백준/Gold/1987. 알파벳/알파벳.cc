#include<iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int r,c,ans;
string str;
char map[21][21];
vector<char> v;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int alpha[26];

void dfs(int x,int y,int depth) {
    ans = max(depth, ans);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
            if (!alpha[map[nx][ny]-65]){
                // 현재 위치의 알파벳을 방문한 알파벳으로 저장
                alpha[map[nx][ny]-65]++;

                // 해당 정보들을 가지고 dfs 탐색 시작
                dfs(nx, ny, depth+1);

                // 상단의 재귀함수가 끝났다면, 인접한 다른 경로도 확인해야하므로
                // 현재 위치의 알파벳을 방문하지 않은 알파벳으로 변경
                alpha[map[nx][ny]-65]--;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;

    for(int i=0; i<r;i++){
        cin >> str;
        for(int j=0; j<str.size();j++){
            map[i][j] = str[j];
        }
    }
    alpha[map[0][0]-65]++;
    dfs(0,0,1);

    cout << ans;

    return 0;
}
