#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n;
ull tmp;
vector<pair<ull,int>> v;

bool cmp(const pair<ull,int>& v1, const pair<ull,int>& v2){
    // 인수 3을 제일 많이 가지는 수가 맨 앞으로,
    // 만약 동일하다면, 작은 수가 앞으로 와야함.
    // why? 4와 8은 둘다 인수3을 0개 가지는데, 8에서 4를 나누기3과 곱하기 2를 통해 만들 수 없기 때문
    if(v1.second == v2.second) return v1.first < v2.first;
    return v1.second > v2.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n;i++){
        ull num; int cnt=0;
        cin >> num;
        tmp = num;
        while(tmp%3==0){
            tmp /= 3;
            cnt++;
        }
        v.push_back({num,cnt}); // 숫자와 인수3의 개수 저장
    }
    // 키포인트 : 인수 3을 가장 많이 가진 숫자가 맨 앞에 와야한다!
    // 3 9를 보면 3에서 9를 곱하기2와 나누기3 연산만으론 절대 만들 수 없음
    sort(v.begin(),v.end(), cmp);

    for(auto i : v){
        cout << i.first << ' ';
    }

    return 0;
}