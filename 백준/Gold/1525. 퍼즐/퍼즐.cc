#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

string s,ans="123456780";
set<string> visited;

int bfs(){
    queue<pair<string,int>> q;
    q.push({s,0});
    visited.insert(s);

    while(!q.empty()){
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == ans){
            return cnt;
        }

        // 0의 위치를 기준
        // 문자열 -> 행렬 좌표값으로 변환
        int zero = cur.find('0');
        int x = zero/3;
        int y = zero%3;

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >=3 || ny < 0 || ny >=3) continue;

            string next = cur;
            // 행렬 좌표값을 문자열 값으로 변환
            swap(next[x*3+y],next[nx*3+ny]);

            if(visited.find(next)==visited.end()){ // end값이 나오는 건 찾지못했다는 뜻
                visited.insert(next);
                q.push({next,cnt+1});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i=0; i<3; i++){
        for(int j=0; j<3;j++){
            int tmp;
            cin >> tmp;
            char c = tmp + '0';
            s += c;
        }
    }
    cout << bfs();
}