#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;
vector<int> oper;
vector<int> num;

long long solution(string expression)
{
    long long answer = 0;
    int number = 0;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '+' || expression[i] == '*' || expression[i] == '-')
        {
            oper.push_back(atoi(expression[i]));
            number = 0;
        }
        else
        {
        }
    }
    return answer;
}