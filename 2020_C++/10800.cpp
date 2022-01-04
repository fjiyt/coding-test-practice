#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int> > v;
queue<pair<int, int> > que; //들어온 순서대로 담음

bool comp1(const pair<int, int> &a, const pair<int, int> &b) //color 기준
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
bool comp2(const pair<int, int> &a, const pair<int, int> &b) // size 기준
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    int N;
    cin >> N;
    int arr[N + 2][2002];

    int color, size;

    for (int i = 0; i < N; i++)
    {
        cin >> color >> size;
        v.push_back(make_pair(color, size));
        que.push(make_pair(color, size));
    }
    //정렬을 해서 앞에 공의 크기를 누적 합
    //size를 기준으로 sort
    sort(v.begin(), v.end(), comp2);
    int sum = 0;
    int tmp = 0; // 같은 숫자 있을경우 저장
    int pre_color = 0, pre_size = 0;

    for (int i = 0; i < v.size(); i++)
    {
        color = v[i].first;
        size = v[i].second;
        if (pre_size == size)
        {
            sum -= size;
            tmp += size;
        }
        else
        {
            sum += tmp;
            tmp = 0;
        }
        arr[color][size] = sum;
        sum += size;
        pre_size = size;

        cout << color << " " << size << " " << arr[color][size] << "\n";
    }

    cout << "\n\n";
    //color를 기준으로 sort
    sort(v.begin(), v.end(), comp1);
    sum = 0;
    tmp = 0;
    pre_color = 0;
    pre_size = 0;
    for (int i = 0; i < v.size(); i++)
    {
        color = v[i].first;
        size = v[i].second;
        if (pre_color == color)
        {
            if (pre_size == size)
            {
                sum -= size;
                tmp += size;
            }
            else
            {
                sum += tmp;
                tmp = 0;
            }
            arr[color][size] -= sum;
            sum += size;
        }
        else
        {
            sum = size;
            tmp = 0;
        }
        pre_color = color;
        pre_size = size;

        cout << color << " " << size << " " << arr[color][size] << "\n";
    }

    while (!que.empty())
    {
        color = que.front().first;
        size = que.front().second;
        cout << arr[color][size] << "\n";
        que.pop();
    }

    return 0;
}