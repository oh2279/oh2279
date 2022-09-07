#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string doc,word;

    getline(cin, doc);
    getline(cin, word);

    int cnt=0;
    for(int i=0; i<doc.size();i++){
        bool flag=true;
        for(int j=0;j<word.length();j++) {
            if(doc[i+j]!=word[j]) {
                flag=false;
                break;
            }
        }
        if(flag) {
            cnt++;
            i+=word.length()-1;
        }
    }
    cout << cnt;
    return 0;
}