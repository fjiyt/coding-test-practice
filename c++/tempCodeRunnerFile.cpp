#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h>

using namespace std;

int solve(string word1, string word2, string output)
{
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < output.size(); i++)
    {
        int tmp1 = idx1, tmp2 = idx2;
        int tmp_i = i;
        while (1)
        {
            if (word1[tmp1] == word2[tmp2])
            {
                if (tmp_i >= output.size() || tmp1 >= word1.size() || tmp2 >= word2.size())
                    break;
                if (word1[tmp1] != output[tmp_i])
                    return -1;

                tmp1++;
                tmp2++;
                tmp_i++;
            }

            else
            {
                if (word1[tmp1] == output[tmp_i])
                {
                    idx1 = tmp1;
                }
                else if (word2[tmp2] == output[tmp_i])
                {
                    idx2 = tmp2;
                }
                i = tmp_i;
                break;
            }
        }
        if ((idx1 < word1.size()) && (word1[idx1] == output[i]))
        {
            idx1++;
        }
        else if ((idx2 < word2.size()) && (word2[idx2] == output[i]))
        {
            idx2++;
        }
        else
        {
            return -1;
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