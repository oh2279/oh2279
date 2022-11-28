#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> failure(string str){
    int j=0;
    int siz = str.length();
    vector<int> fail(str.length());
    // pi 배열은 접두사 접미사가 일치하는 최대 길이 구하기
    for(int i = 1; i < siz; i++){
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
    return fail;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    while(true){
        cin >> s;
        if(s==".") break;
        vector<int> f = failure(s);

        if(s.size()%(s.size()-f[s.size()-1]))
            cout << 1<<'\n';
        else
            cout << s.size() / (s.size() - f[s.size() - 1]) << '\n';
    }

    return 0;
}