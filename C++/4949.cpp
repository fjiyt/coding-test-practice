#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        string input;
        getline(cin, input);

        if(input == ".") {
            break;
        }

        stack <char> s;
        bool flag = true;
        for(int i=0; i<input.size(); i++)
        {
            if(input[i]=='(' || input[i]=='[') s.push(input[i]);
            if(input[i]==')') {
                if(s.size() == 0) {
                    flag = false;
                    break;
                }
                char left = s.top();
                s.pop();
                if(left=='(') continue;
                else if(left=='[') {
                    flag = false;
                    break;
                }
            }
            else if(input[i]==']') {
                if(s.size() == 0) {
                    flag = false;
                    break;
                }
                char left = s.top();
                s.pop();
                if(left=='[') continue;
                else if(left=='(') {
                    flag = false;
                    break;
                }
            }

            if(input[i]=='.') break;
        }

        if(flag) {
            if(s.size()>0) flag = false;
        }

        if(flag) cout << "yes\n";
        else cout << "no\n";
    }
}