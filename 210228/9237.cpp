#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int max_num = 0;
vector <int> tree;

bool compare(int i, int j)
{
    return i > j;
}
int main()
{
    cin >> N;
    int num;
    for(int i=0; i<N; i++)
    {
       cin >> num;
       tree.push_back(num);
    }

    sort(tree.begin(), tree.end(), compare);
    
    for(int i=0; i<N; i++)
    {
        tree[i] = tree[i] + i + 1;
        if(max_num < tree[i]) max_num = tree[i];
    }

    cout << max_num + 1 << "\n";
}