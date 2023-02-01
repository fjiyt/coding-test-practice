#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, d, k, c; //접시의 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호
vector<int> v;

void solve()
{
    int start = 0, end = 0;
    int plate = 0;      //먹은 그릇수
    int sushi_kind = 0; //초밥 가짓수
    int max_kind = 0;   //초밥 최대 가짓수

    vector<int> sushi_plate;
    set<int> sushi;

    //공짜로 주는 초밥 종류 삽입
    sushi_plate.push_back(c);
    sushi.insert(c);
    for (start = 0; start < N; start++)
    {
        while (plate < k)
        {
            plate++;
            sushi_plate.push_back(v[end]);
            sushi.insert(v[end]);

            //end 설정
            if (end == N)
            {
                end = 0;
            }
            else
                end++;
        }
        if (plate == k)
        {
            sushi_kind = sushi.size();
            max_kind = max(max_kind, sushi_kind);
            int tmp = count(sushi_plate.begin(), sushi_plate.end(), v[start]);
            if (tmp == 1)
            {
                set<int>::iterator it = sushi.find(v[start]);
                sushi.erase(it);
            }
            plate--;
            sushi_plate.erase(sushi_plate.begin() + 1);
        }
    }

    cout << max_kind << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    solve();

    return 0;
}