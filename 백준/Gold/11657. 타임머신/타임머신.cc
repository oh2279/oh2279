#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<pair<int,int>,int>> v;
int n,m,a,b,c;
long long dist[510];

void bellman_ford(){
    dist[1]=0;
    for(int i=1;i<=n-1;i++){
        for(int j=0; j<v.size();j++){
            int start = v[j].first.first;
            int End = v[j].first.second;
            int cost = v[j].second;

            if(dist[start]==987654321) continue;
            if(dist[End] > dist[start]+cost){
                dist[End] = dist[start]+cost;
            }
        }
    }
    for(int i=0; i < v.size(); i++){
        int start = v[i].first.first;
        int End = v[i].first.second;
        int cost = v[i].second;

        if(dist[start]==987654321) continue;
        if(dist[End] > dist[start]+cost){
            cout << -1 <<'\n';
            return;
        }
    }
    for(int i=2;i<=n;i++){
        if(dist[i]==987654321){
            cout << -1 << '\n';
        }
        else{
            cout << dist[i] <<'\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=1; i<=n;i++) dist[i]=987654321;
    for(int i=0; i<m;i++){
        cin >> a >> b >> c;
        v.push_back({{a,b},c});
    }
    bellman_ford();
    return 0;
}