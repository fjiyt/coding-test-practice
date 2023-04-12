#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
int max_alp = 0, max_cop = 0;

int DP[151][151];

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0; 
    for(int i=0; i<problems.size(); i++)
    {
        max_alp = max(max_alp, problems[i][0]);
        max_cop = max(max_cop, problems[i][1]);
    }
        
    for(int i=0; i<=150; i++)
    {
        for(int j=0; j<=150; j++)
        {
            DP[i][j] = 1e9;
        }
    }
    
    if(max_alp <= alp && max_cop <= cop) return 0;
    if(alp > max_alp) alp = max_alp;
    if(cop > max_cop) cop = max_cop;
    DP[alp][cop] = 0;
    
    for(int i=alp; i<=max_alp; i++)
    {
        for(int j=cop; j<=max_cop; j++)
        {
            if(i < max_alp) DP[i+1][j] = min(DP[i+1][j], DP[i][j]+1);
            if(j < max_cop) DP[i][j+1] = min(DP[i][j+1], DP[i][j]+1);
            
            for(int k=0; k<problems.size(); k++)
            {
                if(problems[k][0] <= i && problems[k][1] <= j)
                {
                    int nalp = i + problems[k][2];
                    int ncop = j + problems[k][3];
                    
                    nalp = min(nalp, max_alp);
                    ncop = min(ncop, max_cop);

                    DP[nalp][ncop] = min(DP[nalp][ncop], DP[i][j] + problems[k][4]);
                }
            }
        }
    }
    
    answer = DP[max_alp][max_cop];
    
    return answer;
}