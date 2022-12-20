#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> v;
vector<int> prime;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    v.resize(n + 1, true);
    // 에라토스테네스의 체
    for(int i=2; i*i<=n ;i++){
        if(!v[i]) continue;
        for(int j=i*i; j<=n;j+=i){
            v[j]=false;
        }
    }
    // 체를 거른 것들을 저장
    for(int i=2; i<=n; i++){
        if(v[i]) prime.push_back(i);
    }

    int left = 0, right = 0;// 투포인터
    int ans = 0; // 경우의 수
    int sum = 0;
    while (true) {
        if (sum >= n) {
            sum -= prime[left++];
        } else if (right == prime.size()) {
            break;
        } else {
            sum += prime[right++];
        }
        if (sum == n) ans++;
    }
    cout << ans;
    return 0;
}