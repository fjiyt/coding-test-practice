#include <iostream>
#include <vector>

using namespace std;

int T;
vector <string> v;
int isPalindrome(int left, int right, string str, int remove)
{
    while(left < right)
    {
        if(str[left] == str[right])
        {
            left++;
            right--;
        }
        else{
            if(remove==0)
            {
                if(isPalindrome(left+1, right, str, 1)==0 || isPalindrome(left, right-1, str, 1)==0)
                {
                    return 1;
                }
                return 2;
            }
            else{
                return 2;
            }
        }
    }
    return 0;
}
void solve()
{
    for(int i=0; i<T; i++)
    {
        int left = 0;
        int right = v[i].length()-1;
        cout << isPalindrome(left, right, v[i], 0) << "\n";
    }
}
int main()
{
    cin >> T;
    for(int i=0; i<T; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    solve();
}