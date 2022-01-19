//슬라이딩 윈도우 -> 길이가 K로 고정
#include <iostream>
#include <map>
#include <vector>

using namespace std;
int N, K;
long long bf = 0;
map<int,int> m;
vector <int> v;

int sliding_window()
{
    int start = 0, end = 0;

    while(1)
    {
        //end가 끝까지 되면
        if(end==N)
        {
            while(start < N)
            {
                if(m[v[start]] > 1)
                {
                    m[v[start]]--;
                }
                else if(m[v[start]] == 1)
                {
                    m.erase(v[start]);
                }    
                start++;

                if(m[v[start]] > 1) 
                {
                    bf += m[v[start]] -1;
                }
            }
            break;
        }

        //K개의 숫자가 다 들어왔을때
        if(end-start > K)
        {
            if(m[v[start]] > 1)
                m[v[start]]--;
            else if(m[v[start]]==1)
            {
                m.erase(v[start]);
            }
                
            start++;
        }
        //K개의 숫자가 안들어왔을때
        while(end-start <= K)
        {
            if(m.find(v[end]) != m.end())
            {
                m[v[end]]++;
            }
            else{
                m.insert(make_pair(v[end],1));
            }
            if(end-start == K)
            {
                if(m[v[start]] > 1) bf += m[v[start]] - 1;
            }

            end++;
        }
    }

    return bf;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        v.push_back(str.length());
    }

    cout << sliding_window() << "\n";
}