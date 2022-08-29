#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S, T;
    cin >> S >> T;

    int idx=T.size()-1;
    while(!T.empty()){
        if(S==T){
            cout<< 1;
            return 0;
        }
        if(T[idx]=='A'){
            T.pop_back();
        }
        else if(T[idx]=='B'){
            reverse(T.begin(),T.end());
            //cout << "reverse : " <<T << endl;
            T.erase(0,1);
        }
        //cout << T << endl;
        idx = T.size()-1;
    }
    cout << 0;
    return 0;
}