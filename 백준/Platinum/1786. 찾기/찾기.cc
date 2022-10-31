#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string t,p;
vector<int> ans;
int pi[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getline(cin ,t);
    getline(cin, p);

    int j=0;
    // pi 배열은 접두사 접미사가 최대로 겹칠 때의
    for(int i = 1; i<p.size() ; i++){ // 접두사 접미사가 일치하는 최대 길이 구하기
        while(j > 0 && p[i] !=  p[j]) { // 다르면
            j = pi[j - 1]; // 일치할 때 까지 인덱스를 앞당김
        }
        if(p[i] == p[j])
            pi[i] = ++j; // 접두 접미사가 일치하는 최대 길이 저장
    }

    int m = p.size();
    j=0;
    for(int i = 0; i<t.size() ; i++){
        while(j > 0 && t[i] !=  p[j]) { // 다르면
            j = pi[j - 1];
        }
        if(t[i] == p[j]){
            if(j==m-1){ // 패턴 찾음
                ans.push_back(i-m+2); // 위치 저장
                j = pi[j];
            }else{
                j++;
            }
        }
    }

    cout << ans.size() << '\n';
    for(auto k : ans) cout << k << ' ';
    return 0;
}