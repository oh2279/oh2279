#include <iostream>
#include <algorithm>
#include <deque>
#include<string>
using namespace std;


int T, N;
string func,arr;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        deque<int> dq;
        string s = "";
        bool rvs = false, error = false;
        cin >> func >> N >> arr;
        for (int j = 0; j < arr.length(); j++) {
            if (isdigit(arr[j])) {
                s += arr[j];
            }
            else {
                if (!s.empty()) {
                    dq.push_back(stoi(s));
                    s = "";
                }
            }
        }

        for (auto k : func) {
            if (k == 'R') {
                if (rvs) {
                    rvs = false;
                }
                else {
                    rvs = true;
                }
            }
            else {
                if (dq.empty()) {
                    cout << "error\n";
                    error = true;
                    break;
                }
                if (rvs)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }
        if(!error)
            cout << '[';
        if (!dq.empty() && rvs) {

            for (auto o = dq.rbegin(); o != dq.rend(); o++) {
                if (o == dq.rend() - 1)
                    cout << *o;
                else
                    cout << *o << ',';
            }
        }
        else if (!rvs && !dq.empty()) {
            for (auto o = dq.begin(); o != dq.end(); o++) {
                if (o == dq.end() - 1)
                    cout << *o;
                else
                    cout << *o << ',';
            }
        }
        if (!error)
            cout <<"]\n";
    }
    return 0;
}
