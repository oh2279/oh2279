#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int V,E,start,u,v,w;
vector<pair<int,int>> graph[20001]; // 그래프
int table[20001]; // 최단거리 테이블

void dijk(int start){
    table[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start}); //  가중치, 인덱스

    while(!pq.empty()) {
        int idx = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (table[idx] != cost) continue;

        for (int i = 0; i < graph[idx].size(); i++) {
            int next = graph[idx][i].first; // 인덱스
            int weight = graph[idx][i].second; // 가중치

            if (table[next] > table[idx] + weight) { // 원래 값보다 해당 인덱스의 노드를 거쳐갔을 때 작아지면 초기화
                table[next] = table[idx] + weight; // 테이블에 새로운 가중치 입력
                pq.push({table[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E >> start;

    while(E--){
        cin >> u >> v >> w;
        graph[u].emplace_back(v,w); // first는 도착지, second는 가중치
    }

    fill(table,table+20001,987654321); // 테이블 초기화

    dijk(start);

    for(int i=1; i<=V;i++){
        if(table[i]==987654321){
            cout << "INF\n";
        }
        else {
            cout << table[i] << '\n';
        }
    }

    return 0;
}
