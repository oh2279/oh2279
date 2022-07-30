#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i=0; i<n;i++){
        int p;
        cin >> p;
        v.push_back(p);
    }

    sort(v.begin(),v.end());

    int sum=0;

    for(int i=0; i<v.size();i++){
        for(int j=0; j<=i;j++){
            sum += v[j];
        }
    }
    cout << sum;
}