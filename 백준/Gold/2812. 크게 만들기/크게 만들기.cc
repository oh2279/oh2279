#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <string>
#include <queue>
#include <functional>
#include <complex>
#include <cmath>
#include <unordered_map>
#include <map>
typedef long long ll;
using namespace std;

int n,k;
string s;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k >> s;
    for(int i = 0; i<s.size(); i++){
        int num = s[i]-'0';
        while(k && !dq.empty() && num > dq.back()) {
            dq.pop_back();
            k--;
        }
        dq.push_back(num);
    }

    for(int i=0; i<dq.size()-k;i++){
        cout << dq[i];
    }
}
