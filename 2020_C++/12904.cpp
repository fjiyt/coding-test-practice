#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;
string input, output;

//모두 뒤에 추가하는 것이기 때문에 뒤를 비교하면 됨

int Solve()
{
    int in_length = input.length();

    while (input != output)
    {
        int out_length = output.length();
        if (in_length == out_length)
            return 0;

        if (output.substr(out_length - 1, 1) == "A")
        {
            output = output.substr(0, out_length - 1);
        }
        else if (output.substr(out_length - 1, 1) == "B")
        {
            output = output.substr(0, out_length - 1);
            reverse(output.begin(), output.end());
        }
    }

    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> input >> output;

    int ret = Solve();
    cout << ret << "\n";
}