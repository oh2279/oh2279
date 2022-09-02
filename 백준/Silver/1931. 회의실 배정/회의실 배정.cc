#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> v;

bool comp(pair<int,int>first, pair<int,int> second){
    if(first.second == second.second){
        return first.first < second.first;
    }
    return first.second < second.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,s,e;
    cin >> n;

    for(int i=0; i<n;i++){
        cin >> s >> e;
        v.push_back({s,e});
    }
    sort(v.begin(),v.end(),comp);

    int end = v[0].second;
    int cnt=1;

    for(int i=1; i<n;i++){
        //cout << v[i].first << ' ' << v[i].second << endl;
        if(end <= v[i].first){
            cnt++;
            end = v[i].second;
        }
    }
    cout << cnt;
    return 0;
}