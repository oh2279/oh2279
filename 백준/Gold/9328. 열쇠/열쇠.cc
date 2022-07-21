#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>

using namespace std;

int t,h,w;
char map[101][101];
string key;
bool keys[26];
bool visited[101][101];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int checkAlpha(char C){
    if(C<='Z' && C>='A') return 1;
    else if(C<='z' && C>='a') return 2;
    else return 0;
}

void bfs( queue<pair<int,int>> q , queue<pair<int,int>> door[26]){
    int cnt=0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(map[x][y]=='$')
            cnt++;

        for(int i=0; i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >=0 && nx < h && ny >=0 && ny < w && map[nx][ny]!='*' && !visited[nx][ny]){
                if(checkAlpha(map[nx][ny]) == 1){ // 대문자
                    if(!keys[map[nx][ny]-65]){ // 키가 없다면
                        door[map[nx][ny]-65].push({nx,ny});
                        continue;
                    }
                }
                else if(checkAlpha(map[nx][ny]) == 2) { // 소문자 == 키 습득
                    keys[map[nx][ny] - 97] = true;

                    // 키를 주웠는데 해당 키에 대응되는 잠긴 문이 있다면
                    if(!door[map[nx][ny]-97].empty()) {
                        while (!door[map[nx][ny] - 97].empty()) {
                            int rx = door[map[nx][ny] - 97].front().first;
                            int ry = door[map[nx][ny] - 97].front().second;
                            door[map[nx][ny] - 97].pop();
                            q.push({rx, ry}); // 빈칸으로 바꿔줌 = 해당 위치를 큐에 삽입
                            visited[rx][ry]=true;
                        }
                    }
                }
                // 빈칸, $, 키, 키가 있는 문의 경우는 방문
                q.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while(t--){
        cin >> h >> w;
        queue<pair<int,int>> q;
        queue<pair<int,int>> door[26];
        memset(visited,false,sizeof(visited));
        memset(keys,false,sizeof(keys));

        for(int i=0; i<h;i++){
            for(int j=0; j<w; j++){
                cin >> map[i][j];
                if(i==0 || i == h-1 || j==0 || j==w-1) {
                    if (checkAlpha(map[i][j]) == 1){ // 대문자 == 문
                        if (!(keys[map[i][j] - 65])){ // 키가 없다면
                            door[map[i][j] - 65].push({i, j});
                            continue;
                        }

                    }
                    else if (map[i][j] == '*') continue;
                    else if (checkAlpha(map[i][j]) == 2) { // 소문자 == 키
                        keys[map[i][j]-97] = true;
                    }
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        cin >> key;
        if(key != "0"){
            for(char i : key) {
                keys[i - 97] = true;
                if (keys[i - 97] && !door[i - 97].empty()) {
                    while (!door[i - 97].empty()) {
                        int x = door[i - 97].front().first;
                        int y = door[i - 97].front().second;
                        door[i - 97].pop();
                        q.push({x, y});
                        visited[x][y] = true;
                    }
                }
            }
        }
        bfs(q,door);
    }
    return 0;
}