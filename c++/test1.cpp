#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    char str[50];
    int left = 0;
    int right = 0;
    
    cin >> str;
    
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i]=='(')
        {
            left ++;
        }
        else right ++;
    }

    if(left == right) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    
    return 0;
}