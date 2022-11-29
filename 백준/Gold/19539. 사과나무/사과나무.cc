#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,sum,cnt;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n;i++){
        int num;
        cin >> num;
        sum += num;
        cnt += (num/2);
    }

    if(sum%3 ==0){
        if(cnt >= sum/3) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}