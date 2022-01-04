#include <iostream>
#include <vector>

using namespace std;
string word1;
string word2;
string output;
int cnt = 0;

bool test()
{
    vector<int> alpha(27, 0);
    for (int i = 0; i < word1.length(); i++)
    {
        alpha[word1[i] - 'a']++;
    }
    for (int i = 0; i < word2.length(); i++)
    {
        alpha[word2[i] - 'a']++;
    }
    for (int i = 0; i < output.length(); i++)
    {
        alpha[output[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] != 0)
            return false;
    }

    return true;
}
void solve(int idx1, int idx2, int idx_out)
{
    if (idx_out >= output.size() || (idx1 >= word1.size() && idx2 >= word2.size()))
    {
        return;
    }

    if (word1[idx1] == word2[idx2])
    {
        solve(idx1 + 1, idx2, idx_out + 1);
        if (cnt > 0)
        {
            cnt = 0;
            solve(idx1, idx2 + 1, idx_out + 1);
        }
    }

    else
    {
        if (word1[idx1] == output[idx_out])
        {
            solve(idx1 + 1, idx2, idx_out + 1);
        }
        else if (word2[idx2] == output[idx_out])
        {
            solve(idx1, idx2 + 1, idx_out + 1);
        }
        else
        {
            cnt++;
        }
    }

    if (cnt > 0)
        return;

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> word1 >> word2 >> output;

        cnt = 0;
        if (test())
        {
            solve(0, 0, 0);
            cout << "Data set " << i + 1 << ": ";
            if (cnt > 0)
                cout << "no\n";
            else
                cout << "yes\n";
        }

        else
        {
            cout << "Data set " << i + 1 << ": ";
            cout << "no\n";
        }
    }

    return 0;
}