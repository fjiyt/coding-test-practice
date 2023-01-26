#include <iostream>
#include <cstring>
#include <stdbool.h>
#include <algorithm>

#define MAX 52

using namespace std;

bool asc[26]={false,}; 
string word[MAX];
int N, K;
int max_word=0;

void init()
{
    asc['a'-'a']=1;
    asc['c'-'a']=1;
    asc['n'-'a']=1;
    asc['t'-'a']=1;
    asc['i'-'a']=1;
}
void count_word()
{
    int i,j;
    int cnt=0;
    for(i=0; i<N; i++)
    {
        bool read = true;
        for(j=0; j<word[i].length(); j++)
        {
            if(!asc[word[i][j]-'a']) 
            {
                read = false;
                break;
            }
        }
        if(read==true) cnt++;
    }

    max_word = max(max_word,cnt);
    return ;
}
void dfs(int num, int cnt)
{
    if(cnt==K)
    {
        //읽을 수 있는 단어 측정
        count_word();
        return;
    }
    for(int i=4; i<word[num].length()-4; i++)
    {
        if(!asc[word[num][i]-'a'] && cnt < K)
        {
            asc[word[num][i] - 'a']=true;
            cnt++;
            dfs(num+1, cnt);
        }
    }
    return;
}
int main(void)
{
    cin >> N >> K;

    for(int i=0; i<N; i++)
    {
        cin >> word[i];
    }

    if(K<5 || K>26)
    {
        cout << "0\n";
        return 0;
    }

    else if (K==26)
    {
        cout << N << "\n";
        return 0;
    }


    K=K-5;
    init(); //초기 설정
    dfs(0,0);

    cout << max_word << "\n";
    return 0;
}