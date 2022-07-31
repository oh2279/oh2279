#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

priority_queue<int,vector<int>,greater<>> pq;
int n,ans,tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i=0; i<n;i++){
        int card;
        cin >> card;
        pq.push(card);
    }

    while(!pq.empty()){
        int first = pq.top();
        pq.pop();

        if(pq.empty()) break;

        int second = pq.top();
        pq.pop();

        tmp = first+second;
        ans += tmp;
        pq.push(tmp);
    }
    cout << ans;
    return 0;
}