#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;
int maxi=-1,cnt;

vector<int> failure(vector<int> pattern){
    int j=0;
    vector<int> fail(pattern.size());
    // pi 배열은 접두사 접미사가 일치하는 최대 길이 구하기
    for(int i = 1; i < pattern.size() ; i++){
        while(j > 0 && pattern[i] != pattern[j]) { // 다르면
            j = fail[j - 1]; // 일치하는 부분까지 인덱스를 앞당김
        }
        if(pattern[i] == pattern[j]) {
            fail[i] = ++j; // 접두 접미사가 일치하는 최대 길이 저장
        }
        else{
            fail[i]=0;
        }
        maxi = max(maxi,fail[i]);
    }
    return fail;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string s;
    cin >> n;

    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >>v[n-1-i];
    }
    vector<int> f = failure(v);
    for(int i=1; i<f.size();i++){
        if (maxi < f[i]) {
            maxi = f[i];
            cnt = 1;
        }
        else if (maxi == f[i]) {
            cnt++;
        }
    }
    if(maxi ==0){
        cout << -1;
    }
    else {
        cout << maxi << ' ' << cnt;
    }
    return 0;
}