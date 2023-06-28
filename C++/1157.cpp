// 전체 알파벳 개수  -> 26
// A >= 97, a >= 65
#include <iostream>
#include <cstring>

using namespace std;
int a[26];
int main()
{
    string str;
    cin >> str;

    int max_num=0;
    int max_idx = 0;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] >= 97)
        {
            str[i] = toupper(str[i]);
        }
        int idx = str[i] - 65;
        a[idx]++;
        
        if(max_num < a[idx])
        {
            max_num = a[idx];
            max_idx = idx; 
        }
    }
    
    for(int i=0; i<26; i++)
    {
        if(max_num==a[i] && max_idx != i)
        {
            cout << "?\n";
            return 0;
        }
    }

    cout << (char)(max_idx + 65) << "\n";
}