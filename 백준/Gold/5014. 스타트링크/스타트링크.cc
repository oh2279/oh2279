#include <bits/stdc++.h>

using namespace std;

int f,s,g,u,d;
int visited[1000001];
int dx[2];

void bfs(){
    queue<int> q;
    q.push(s);
    visited[s]=1;

    while(!q.empty()){
        int x = q.front();
        q.pop();


        if(x == g){
            cout << visited[g]-1;
            return;
        }
        for(int i=0; i<2; i++){
            int nx = x + dx[i];

            if(nx > 0 && nx <= f){
                if(visited[nx]==0){
                    q.push(nx);
                    visited[nx] = visited[x] + 1;
                }
            }

        }
    }
    cout << "use the stairs";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> f >> s >> g >> u >> d;
    dx[0]=u;
    dx[1]=-d;

    if(s == g){
        cout << 0;
    }
    else bfs();
    return 0;
}