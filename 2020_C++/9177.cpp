#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h>

using namespace std;

int solve(string word1, string word2, string output)
{
    int idx1 = 0, idx2 = 0;
    int i = 0;

    int tmp1 = idx1, tmp2 = idx2;
    int tmp_i = i;
    while (i < output.size())
    {
        if (tmp1 >= word1.size() && tmp2 >= word2.size())
        {
            break;
        }

        if (word1[tmp1] == word2[tmp2])
        {
            if ((word1[tmp1] != output[tmp_i]) && (word1[tmp1] != output[tmp_i + 1]))
                return -1;

            tmp1++;
            tmp2++;
            tmp_i++;
        }

        else
        {
            if (word1[tmp1] == output[tmp_i])
            {
                idx1 = ++tmp1;
                tmp2 = idx2;
            }
            else if (word2[tmp2] == output[tmp_i])
            {
                idx2 = ++tmp2;
                tmp1 = idx1;
            }
            else
            {
                return -1;
            }

            i = ++tmp_i;
        }
    }
    return 1;
}
int main()
{
    int num;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        string word1;
        string word2;
        string output;
        cin >> word1 >> word2 >> output;

        int ret = solve(word1, word2, output);
        cout << "Data set " << i + 1 << ": ";
        switch (ret)
        {
        case 1:
            cout << "yes\n";
            break;

        case -1:
            cout << "no\n";
            break;

        default:
            break;
        }
    }

    return 0;
}