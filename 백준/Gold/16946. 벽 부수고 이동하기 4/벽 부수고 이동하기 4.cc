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

int n,m,group_cnt;
int map[1001][1001];
int ans[1001][1001];
bool visited[1001][1001];
int group[1001][1001];

vector<int> v;
int dx[] = { 0,1,0,-1};
int dy[] = {1,0,-1,0};

void bfs(int a, int b){
    queue<pair<int,int>> q;
    q.push({a,b});
    visited[a][b]=true;
    group[a][b] = group_cnt;
    int cnt = 1;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 1 || visited[nx][ny]) continue;

            if (map[nx][ny] == 0) {
                group[nx][ny]=group_cnt;
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    v.push_back(cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n;i++){
        string s;
        cin >> s;
        for(int j=0; j<s.size();j++){
            map[i][j] = s[j]-'0';
        }
    }
    for(int i=0; i<n;i++){
        for(int j=0; j <m; j++){
            if(map[i][j]==0 && visited[i][j]==false){
                bfs(i,j);
                group_cnt++;
            }
        }
    }
    for(int i=0; i<n;i++) {
        for (int j = 0; j < m; j++) {
            if(map[i][j]==1){
                set<int> s;
                for(int k=0; k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx>=0 && ny>=0 && nx < n && ny < m){
                        if(map[nx][ny]==0){
                            if(s.find(group[nx][ny]) == s.end()){
                                s.insert(group[nx][ny]);
                                ans[i][j] += v[group[nx][ny]];
                            }
                        }
                    }
                }
                ans[i][j] += 1;
                ans[i][j] %= 10;
            }
        }
    }
    for(int i=0; i<n;i++){
        for(int j=0; j <m; j++){
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}