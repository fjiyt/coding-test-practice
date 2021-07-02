#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
string answer = "";
int downtable(int k, int num)
{
    int cnt = 0;
    while (1)
    {
        k++;
        if (answer[k] == 'O')
            cnt++;
        if (cnt == num)
            break;
    }

    return k;
}
int uptable(int k, int num)
{
    int cnt = 0;
    while (1)
    {
        k--;
        if (answer[k] == 'O')
            cnt++;
        if (cnt == num)
            break;
    }
    return k;
}

int findInt(string cmd)
{
    int num = 0;
    for (int i = 0; i < cmd.length(); i++)
    {
        if (cmd[i] >= 48 && cmd[i] <= 57)
        {
            num = num * 10 + cmd[i] - 48;
        }
    }

    return num;
}
string solution(int n, int k, vector<string> cmd)
{

    stack<int> z;
    int end = n - 1;

    for (int i = 0; i < n; i++)
    {
        answer.push_back('O');
    }
    vector<int> cmdC;
    for (int i = 0; i < cmd.size(); i++)
    {
        if (!cmd[i].find('C'))
        {
            cmdC.push_back(i);
        }
        else if (!cmd[i].find('Z'))
        {
            cmdC.pop_back();
        }
    }
    vector<int> sorts;
    for (int i = 0; i < n; i++)
    {
        sorts.push_back(i);
    }
    for (int i = 0; i < cmd.size(); i++)
    {
        if (!cmd[i].find('D'))
        {
            int num = findInt(cmd[i]);
            k = downtable(k, num);
        }
        else if (!cmd[i].find('U'))
        {
            int num = findInt(cmd[i]);
            k = uptable(k, num);
        }
        else if (!cmd[i].find('C'))
        {
            if (!cmdC.empty())
            {
                int num = cmdC.front();
                if (num == i)
                    cmdC.erase(cmdC.begin());
            }
            else
            {
                break;
            }
            answer[k] = 'X';
            z.push(k);
            if (k == end)
            {
                k = uptable(k, 1);
                end = k;
            }
            else
            {
                k = downtable(k, 1);
            }
        }
        else if (!cmd[i].find('Z'))
        {
            int tmp = z.top();
            z.pop();
            answer[tmp] = 'O';
            if (tmp > end)
            {
                end = tmp;
            }
        }
    }

    return answer;
}