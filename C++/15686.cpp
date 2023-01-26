#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

#define INF 99999999

vector<

    pair<int, int>

    >
    house;
vector<
    pair<int, int>

    >
    chicken;
int arr[52][52] = {
    0,
};
bool pickChicken[13] = {
    false,
};
int totalDistance;
int M; //최대 치킨 개수

void findMinDistance(int index, int pickNum)
{
    if (pickNum == M)
    {
        int tmpDistance = 0;
        for (int i = 0; i < house.size(); i++)
        {
            int houseDistance = INF;
            for (int j = 0; j < chicken.size(); j++)
            {
                if (pickChicken[j])
                {
                    int tmp = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                    houseDistance = min(houseDistance, tmp);
                }
            }

            tmpDistance += houseDistance;
        }

        totalDistance = min(totalDistance, tmpDistance);
        return;
    }

    if (index == chicken.size())
    {
        return;
    }

    pickChicken[index] = true;
    findMinDistance(index + 1, pickNum + 1);
    pickChicken[index] = false;
    findMinDistance(index + 1, pickNum);

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                house.push_back(make_pair(i, j));
            }
            else if (arr[i][j] == 2)
            {
                chicken.push_back(make_pair(i, j));
            }
        }
    }

    totalDistance = INF;
    findMinDistance(0, 0);

    cout << totalDistance << "\n";
    return 0;
}