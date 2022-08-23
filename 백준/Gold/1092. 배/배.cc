#include <bits/stdc++.h>

using namespace std;

int n,m,ans;
vector<int> crane;
vector<int> box;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        int c;
        cin >> c;
        crane.push_back(c);
    }

    cin >> m;
    for(int i=0; i<m;i++){
        int b;
        cin >> b;
        box.push_back(b);
    }
    sort(crane.begin(),crane.end(),greater<>());
    sort(box.begin(),box.end(),greater<>());

    if(box[0] > crane[0]){
        cout << -1;
        return 0;
    }

    while(!box.empty()){
        ans++;
        for(int i=0; i<crane.size();i++){
            for(int j=0; j<box.size();j++){
                if(crane[i] >= box[j]){
                    box.erase(box.begin()+j);
                    break;
                }
            }
        }
    }
    cout<< ans;
}