#include <iostream>
#include <vector>
#include<cctype>
#include<string>
using namespace std;

int space;
int alpha[26];
vector<char> ans;

int main() {
    string str;
    getline(cin, str);

    cin >> space;
    for (int i = 0; i < 26; i++) {
        cin >> alpha[i];
    }
    ans.push_back(tolower(str[0])); // 제목 저장
    for(int i=1; i<str.size();i++){
        if(isalpha(str[i]) && str[i-1]==' '){
            ans.push_back(tolower(str[i]));
        }
    }

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == str[i+1]) continue; // 다음과 같으면 패스

        if (str[i] == ' ') { // 공백이면
            if (space <= 0) { // 남은 횟수가 0이하면
                cout << -1; // 불가능
                return 0;
            }
            else { // 0보다 크면
                space--; // 하나 감소
            }
        }
        else { // 알파벳일 경우
            if (isupper(str[i])) { // 대문자면
                str[i] = str[i] + 32; // 소문자로 바꿔서 저장
            }
            int tmp = str[i] - 97; // 인덱스로 변환 a = 97이니까 -97

            if (alpha[tmp] <= 0) { // 0 이하면
                cout << -1; // 불가능
                return 0;
            } else {
                alpha[tmp]--; // 0보다 크면 사용가능한 횟수 하나 감소
            }
        }
    }

    // 제목 출력 및 검사
    for(int i=0; i<ans.size();i++){
        if(alpha[ans[i]-97] >=1) {
            cout << char(toupper(ans[i]));
            alpha[ans[i]-97]--;
        }
        else{
            cout << -1;
            return 0;
        }
    }
}