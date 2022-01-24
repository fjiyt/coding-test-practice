#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int c_arr[200001];
int s_arr[2001];

struct ball{
    int idx;
    int color;
    int size;
    int ret;
};

bool comp1(const ball &a, const ball &b) //idx 기준
{
    return a.idx < b.idx;
}
bool comp2(const ball &a, const ball &b) // size 기준
{
    if (a.size == b.size)
        return a.color < b.color;
    return a.size < b.size;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector <ball> arr(N);

    int color, size;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].color >> arr[i].size;
        arr[i].idx = i;
    }
    //정렬을 해서 앞에 공의 크기를 누적 합
    //size를 기준으로 sort
    sort(arr.begin(), arr.end(), comp2);
    int total = 0;
    for(int i=0; i<N; i++)
    {
        int size = arr[i].size;
        int color = arr[i].color;

        c_arr[color] += size;
        s_arr[size] += size;
        total += size;

        arr[i].ret = total - c_arr[color] - s_arr[size] + size;

        if(i!=0 && arr[i].size == arr[i-1].size && arr[i].color == arr[i-1].color)
        {
            arr[i].ret = arr[i-1].ret;
        }
    }

    //color를 기준으로 sort
    sort(arr.begin(), arr.end(), comp1);

    for(int i=0; i<N; i++)
    {
        cout << arr[i].ret << "\n";
    }

    return 0;
}