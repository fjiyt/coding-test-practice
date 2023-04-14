// next_permutation 사용하여 표현
// 순열 생성 가능하면 true, 못하면 false 리턴
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> v;
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    if(next_permutation(v.begin(), v.end())) {
        for(int i=0; i<N; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    else cout << "-1\n";
}