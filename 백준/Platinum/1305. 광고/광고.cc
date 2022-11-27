#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int fail[1000000];

void failure(string str){
    int j=0;
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
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int l;
    string s;
    cin >> l >> s;
    failure(s);

    cout << l-fail[l-1];
    return 0;
}