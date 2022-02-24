#include <iostream>
#include <algorithm>

using namespace std;

string origin;
string add;

int main()
{
    cin >> origin;

    int idx = 0;
    while(1)
    {
        string tmp = add;
        reverse(tmp.begin(), tmp.end());
        string update = origin + tmp;

        int size = update.length();
        bool isPalindrome = true;
        for(int i=0; i<size/2; i++)
        {
            if(update[i] != update[size-i-1]) {
                isPalindrome = false;
                break;
            }
        }

        if(isPalindrome) {
            cout << size << "\n";
            break;
        }
        else{
            add.push_back(origin[idx]);
            idx++;
        }
    }
}