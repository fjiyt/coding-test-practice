// 최대힙, 최소힙
#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue <int> max_heap;
priority_queue <int, vector<int>, greater<int>> min_heap;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int i=0; i<N; i++)
    {
        int num;
        cin >> num;
        if(max_heap.size() <= min_heap.size())
        {
            max_heap.push(num);
        }
        else min_heap.push(num);

        if(!max_heap.empty() && !min_heap.empty())
        {
            if(max_heap.top() > min_heap.top())
            {
                int max_num = max_heap.top();
                int min_num = min_heap.top();
                max_heap.pop();
                min_heap.pop();
                max_heap.push(min_num);
                min_heap.push(max_num);
            }
        }

        cout << max_heap.top() << "\n";
    }
}