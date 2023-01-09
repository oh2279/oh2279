#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v;
int bigg = -1;
double avg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n;i++){
        int num;
        cin >> num;
        bigg = max(num,bigg);
        v.push_back(num);
    }
    for (int i=0; i<n;i++){
       avg += (v[i]/(bigg*1.0)) * 100;
    }
    cout << avg / (n*1.0);
    return 0;
}