#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

int n,ans;
string s;
int alpha[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i=0; i<n;i++){
        cin >> s;
        int siz = s.size()-1;
        for(int j=0; j<s.size();j++){
            alpha[s[j]-65] += int(pow(10,siz));
            siz--;
        }
    }
    sort(alpha,alpha+26,greater<>());

    int idx=0;
    for(int i=9; i>=0;i--){
        ans += alpha[idx] * i;
        idx++;
    }
    cout << ans;
    return 0;
}