#include <iostream>
#include <vector>
#include <cstring>
#include <stdbool.h>
#include <string.h>

using namespace std;
struct gaemeHouse
{
};

bool isExist(int index, string in)
{
    if (v[index].empty())
    {
        return false;
    }
    for (int i = 0; i < v[index].size(); i++)
    {
        if (!in.compare(v[index][i])) //같으면
        {
            return true;
        }
    }
}
int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        for (int j = 1; j <= K; j++)
        {
            string in;
            cin >> in;
            if (!isExist(j, in))
            {
            }
        }
    }
}