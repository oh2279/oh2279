#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

string s;
int ans = -1;

int max_failure(string str){
    int j=0;
    vector<int> fail(str.size());
    // pi 배열은 접두사 접미사가 일치하는 최대 길이 구하기
    for(int i = 1; i < str.size() ; i++){
        while(j > 0 && str[i] != str[j]) { // 다르면
            j = fail[j - 1]; // 일치하는 부분까지 인덱스를 앞당김
        }
        if(str[i] == str[j]) {
            fail[i] = ++j; // 접두 접미사가 일치하는 최대 길이 저장
        }
        else{
            fail[i]=0;
        }
        ans = max(ans,fail[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 과제 해석 : 문자열을 잘라보면서 그때마다의 실패함수의 최댓값을 가지고,
    // 매번 최댓값 비교를 통해 마지막에 남는 값이 바로, 두 번 이상 나오면서 가장 긴 부분문자열의 길이이다.
    // (두번 이상 나온다 == (접두사==접미사))

    cin >> s;

    for(int i=0; i<s.size()-1;i++){
        int maxi = max_failure(s.substr(i));
        if(maxi >= ans){
            ans = maxi;
        }
    }
    cout << ans;
    return 0;
}