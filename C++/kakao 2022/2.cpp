#include <string>
#include <vector>

using namespace std;
int rest;
string ans;

void trans(int n, int k)
{
    if (n)
    {
        trans(n / k, k);
        rest = n % k;
        ans += (rest + '0');
    }
}

bool isPrime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int solution(int n, int k)
{
    int answer = 0;

    trans(n, k);

    int tmp = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == '0')
        {
            if (tmp)
            {
                if (isPrime(tmp))
                {
                    answer++;
                }
            }
            tmp = 0;
        }
        else
        {
            tmp *= 10;
            tmp += ans[i] - '0';
        }
    }

    if (tmp)
    {
        if (isPrime(tmp))
        {
            answer++;
        }
    }

    return answer;
}