#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

int t,a,b;
bool visited[10001];

void bfs(){
    queue<pair<int,string>> q;
    q.push({a,""});
    visited[a] = true;

    while(!q.empty()){
        int num = q.front().first;
        string op = q.front().second;
        q.pop();

        if(num == b){
            cout << op << '\n';
            return;
        }

        int D, S, L, R,tmp;
        // D
        D = (num * 2) % 10000; // mod
        if (!visited[D]){
            visited[D] = true;
            q.push({D, op + "D"});
        }

        // S
        S = num -1;
        if(num == 0) S = 9999;
        if (!visited[S]){
            visited[D] = true;
            q.push({S, op + "S"});
        }

        // L
        if(num % 1000 == num){ // 4자리수가 아니라면
            L = num*10;
        }
        else{ // 4자리수라면
            tmp = num / 1000;
            L = (num % 1000) * 10 + tmp;
        }
        if(!visited[L]){
            visited[L]=true;
            q.push({L,op+"L"});
        }
        // R
        tmp = num % 10* 10000; // 맨 마지막 자리를 맨 앞으로
        R = (tmp + num)/10;
        if(!visited[R]){
            visited[R]=true;
            q.push({R,op+"R"});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while(t--){
        cin >> a >> b;
        memset(visited,0,sizeof(visited));
        bfs();
    }
    return 0;
}