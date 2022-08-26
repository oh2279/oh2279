#include <bits/stdc++.h>

using namespace std;

vector<int> pos;
vector<int> zero;
vector<int> neg;
int n,sum,num,odd_pos=0,neg_pos=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num>= 1) pos.push_back(num);
        else if (num == 0) zero.push_back(num);
        else neg.push_back(num);
    }
    sort(pos.begin(), pos.end(), greater<>());
    sort(neg.begin(), neg.end(), less<>());

    if(!pos.empty()){
        for (int i = 0; i < pos.size(); i++) {
            if(i==(pos.size()-1)){
                odd_pos = pos[i];
                //cout << "odd_pos : " << odd_pos << endl;
                break;
            }
            if (pos[i + 1] != 1) sum = sum + pos[i] * pos[++i];
            else if (pos[i + 1] == 1) sum = sum + pos[i] + pos[++i];

        }
    }
    if(!neg.empty()){
        for (int i = 0; i < neg.size(); i++) {
            if(i==(neg.size()-1)){
                neg_pos = neg[i];
                break;
            }
            sum = sum + neg[i] * neg[++i];
        }
    }
    if(!zero.empty()){
        neg_pos=0;
    }
    sum = sum + odd_pos + neg_pos;
    cout << sum;
    return 0;
}