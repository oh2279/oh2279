#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

queue<pair<int,int>> q;
int w,h,mirror;
char map[101][101];
int count_for_change_dir[101][101];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<pair<int,int>> v;
pair<int,int> start,End;



void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 범위 안에 들고, 벽이 아닌 경우
            while (nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] != '*') {
                if (count_for_change_dir[nx][ny] == 0) {
                    count_for_change_dir[nx][ny] = count_for_change_dir[x][y] + 1;
                    q.push({nx, ny});
                }
                // 레이저의 특성 : 한 방향으로 쭉 이동
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> w >> h;
    int ccnt=0;
    for(int i=0; i<h ;i++){
        for(int j=0; j<w; j++){
            cin >> map[i][j];
            if(map[i][j]=='C'){
                if(ccnt==0){
                    start.first=i;
                    start.second=j;
                    ccnt++;
                }
                else{
                    End.first=i;
                    End.second=j;
                }
            }
        }
    }
    q.push({start.first,start.second});
    bfs();
    // while문에서 한 방향으로 '처음' 나아갈 때도 거울의 수를 +1 해주었기 때문에 -1
    cout << count_for_change_dir[End.first][End.second] - 1 << endl;
    return 0;
}