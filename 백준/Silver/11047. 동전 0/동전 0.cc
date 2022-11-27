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

    int n,k, coin = 0;

    cin >> n >> k;

    vector<int> vec(n);
    for(int i=0; i<n;i++){
        cin >> vec[i];
    }
    sort(vec.begin(),vec.end(),greater<>());
    for(int i=0; i<n;i++){
        if(vec[i] < k){
            coin += k / vec[i];
            k = k % vec[i];
        }

        else if(vec[i] == k){
            coin += 1;
            break;
        }
    }
    cout << coin;
    return 0;
}