#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;
int n,x,y,v;
pair<double,int> arr[100001];

bool compare(const pair<double,int> &a, const pair<double,int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int px =0;
    int py = 0;
    cin >> n;
    for(int i=0; i<n;i++){
        cin >> x >> y >> v;
        int dx = abs(x - px);
        int dy = abs(y -py);
        double dist = sqrt(pow(dx,2) + pow(dy,2));

        double sec = dist / double(v);
        arr[i] = {sec,i+1};
    }
    sort(arr, arr+n,compare);
    for(int i=0; i<n ;i++){
        cout << arr[i].second << '\n';
    }
    return 0;
}