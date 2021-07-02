#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string input, find;
    getline(cin,input);
    getline(cin, find);

    int cnt = 0; // 동일한 문자열 개수
    for(int i=0; i<input.length(); i++)
    {
        int tmp = i; //탐색 시작부분 저장
        for(int j=0; j<find.length(); j++)
        {
            if(i < input.length() && input[i] == find[j])
            {
                if(j==find.length()-1) //find와 같은 문자열이 있는 경우
                {
                    cnt++; 
                    break;
                }
                i++;
            }
            else 
            {
                i=tmp; //탐색 시작부분 + 1 부터 다시 시작
                break;
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}