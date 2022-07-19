#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i=0; i<arr1.size();i++){
        int len = arr1[i].size();
        vector<int> v;
        for(int j=0; j<len;j++){
            v.push_back(arr1[i][j] + arr2[i][j]);   
        }
        answer.push_back(v);
    }
    return answer;
}