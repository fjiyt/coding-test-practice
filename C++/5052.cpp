#include <iostream>
#include <algorithm>
#include <string> 
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++)
    {
        int n;
        cin >> n;

        vector <string> s_arr; //전화번호 문자열 저장
        for(int j=0; j<n; j++)
        {
            string tmp;
            cin >> tmp;
            s_arr.push_back(tmp);
        }

        sort(s_arr.begin(), s_arr.end()); //전화번호 정렬(사전식)
        /* 
        911
        91125426
        913
        */

        int cnt = 0;
        for(int i=0; i<n-1; i++)
        {
            /* 앞 번호가 더 길이가 짧으면 
            -> 앞의 길이를 기준으로 뒷 번호를 자름 
            -> 같으면 NO / 전부 다르면 YES */
            if(s_arr[i].length() < s_arr[i+1].length() && s_arr[i] == s_arr[i+1].substr(0,s_arr[i].size())) cnt++;
        }

        if(cnt > 0) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}