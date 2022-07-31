#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

vector<pair<int,int>> v;
priority_queue< int, vector<int>, greater<int> > pq;
int n,s,t;

/*bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first <= b.first){
        return true;
    }
    return false;
}*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s >> t;
        v.push_back({s,t});
    }
    sort(v.begin(),v.end());

    pq.push(v[0].second);

    // 필요한 강의실 탐색
    for(int i=1; i<n; i++){
        // top 의 종료 시간보다 i 번째 수업이 늦게 시작한다면, 같은 강의실에서 진행 가능
        if (pq.top() <= v[i].first){
            // 기존의 top 은 제거
            pq.pop();
        }
        pq.push(v[i].second);
    }
    cout<< pq.size();

    return 0;
}