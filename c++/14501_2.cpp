#include <iostream>

using namespace std;
struct calendar
{
    int day;
    int pay;
} c[16];

int N;
int max_price = 0;

void Solve(int day, int cost)
{
    //일을 할 수 있는 경우
    if (day <= N && day + c[day].day <= N + 1)
    {
        //일을 하는 경우
        Solve(day + c[day].day, cost + c[day].pay);
        //일을 안 하는 경우
        Solve(day + 1, cost);
    }
    else
    {
        //일을 할 수 없는 경우
        if (day < N)
            Solve(day + 1, cost);
        if (cost > max_price)
            max_price = cost;
    }
}
int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> c[i].day >> c[i].pay;
    }

    Solve(1, 0);

    cout << max_price << "\n";

    return 0;
}