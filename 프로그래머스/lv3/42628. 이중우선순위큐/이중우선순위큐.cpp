#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;

    for(int i=0; i<operations.size();i++){
        string s = operations[i].substr(0,1);
        int n = stoi(operations[i].substr(2));
        if(s== "I"){
            answer.push_back(n);
            sort(answer.begin(), answer.end(), greater<>());
        }
        else if(s=="D"){
            if(answer.size()!=0){
                if(n==1){
                    answer.erase(answer.begin());
                }
                else if(n==-1){
                    answer.pop_back();
                }
            }
        }
    }
    if(answer.empty()){
        v.push_back(0);
        v.push_back(0);
    }
    else{
        sort(answer.begin(), answer.end(), greater<>());
        int maxi = answer.front();
        int mini = answer.back();
        v.push_back(maxi);
        v.push_back(mini);
    }
    return v;
}