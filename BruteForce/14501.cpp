#include <iostream>
#include <vector>

using namespace std;
int N;
int max_cost = 0;
struct working
{
    int day;
    int pay;
}w[16];

void Solve(int day, int pay)
{
    //일을 할 수 있는 경우
    if(day <= N && day+w[day].day <= N+1)
    {
        //일을 한다
        Solve(day+w[day].day, pay+w[day].pay);
        //일을 안한다
        Solve(day+1, pay);
    }
    //일을 할 수 없는 경우
    else{
        if(day < N)
        {
            Solve(day+1, pay);
        }
        if(pay > max_cost) {
            max_cost = pay;
        }
    }
}
int main()
{
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> w[i].day >> w[i].pay;
    }

    Solve(1,0);

    cout << max_cost << "\n";
}