#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[200001] = {
    0,
};
queue<pair<
    int, int> >
    section;

int best_min = 0; //최소거리 중 최댓값
int N, C;

int section_check(int s_index, int e_index, int best_min)
{
    int start = arr[s_index];
    int end = arr[e_index];
    int num = (end - start) / 2;
    while (num > best_min)
    {
        for (int i = s_index; i <= e_index; i++)
        {
            if (arr[i] == num)
                return num;
        }
        num--;
    }
    return 0;
}
int main()
{
    cin >> N >> C;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    sort(arr, arr + C);
    int mid = 0; // 중간값

    section.push(make_pair(0, C - 1)); //인덱스 값으로 넣기

    //와이파이 모두 설치할때까지
    while ((C - 2) > 0)
    {
        int num = section.size();
        while (num--) //모든 구간 탐색
        {
            int s_i = section.front().first;
            int e_i = section.front().second;
            section.pop();

            int start = arr[s_i];
            int end = arr[e_i];

            mid = (end - start) / 2;
            if (mid > best_min) //더 먼 최소거리가 있는지 확인
            {
                int min = section_check(s_i, e_i, best_min);
                if (min > best_min)
                {
                    best_min = min;
                }
            }
        }
    }
}