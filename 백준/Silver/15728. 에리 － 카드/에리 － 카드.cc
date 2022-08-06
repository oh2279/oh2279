#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int N,K;
    vector<int> share_cards;
    vector<int> team_cards;
    cin>>N>>K;
    for(int i = 0; i<N;i++)
    {
        int card;
        cin>>card;
        share_cards.push_back(card);
    } 
    for(int i = 0; i<N;i++)
    {
        int card;
        cin>>card;
        team_cards.push_back(card);
    } 

    long int max= -100000000;
    int max_team_card_index= 0;
    for(int k = 0; k < K+1; k++)
    {
        max= -100000000;
        for(int i = 0; i< N; i++)
        {
            for(int j = 0; j<N-k;j++)
            {
                
                if(max < share_cards[i] * team_cards[j])
                {
                    max = share_cards[i] * team_cards[j];
                    max_team_card_index = j;
                }
            }
        }
        if(k < K)
            team_cards.erase(team_cards.begin() + max_team_card_index);
        
    }

    cout<<max;

}
