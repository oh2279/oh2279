#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<int,int>> v;
vector<ll> sum;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i=0;i<n;i++){
        int pos,people;
        cin >> pos >> people;
        v.push_back({pos, people});
    }
    // 마을 위치 오름차순 정렬
    sort(v.begin(),v.end());

    // 첫번째 마을부터 현재 마을까지의 사람 누적합 저장
    sum.push_back(v[0].second);
    for(int i=1; i<n;i++){
        sum.push_back(sum[i-1] + v[i].second);
    }

    int left = 0;
    int right = n-1;
    int ans = 0x7f7f7f7f;
    while(left<=right){
        int mid = (left+right)/2;
        ll lsum = sum[mid];
        ll rsum = sum[n-1] - sum[mid];

        if(lsum >=rsum){
            right = mid-1;
            ans = min(ans,v[mid].first);
        }
        else{
            left = mid+1;
        }
    }
    cout << ans;
    return 0;
}