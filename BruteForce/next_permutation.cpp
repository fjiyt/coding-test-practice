#include <iostream>
#include <algorithm>
#include <vector>

#define n 6
#define r 3

using namespace std;

int main()
{
    vector <int> arr;
    for(int i=0; i<6; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
        
    cout << "nPn\n";
    do{
        for(int i=0; i<n; i++)
        {
            cout << arr[i] << " ";
        }cout << "\n";
    }while(next_permutation(arr.begin(), arr.end()));

    // begin() + r 부분부터 뒤집어서 다음에 바로 앞부분이 큰수가 오도록함
    cout << "nPr\n";
    do{
        for(int i=0; i<r; i++)
        {
            cout << arr[i] << " ";
        }cout << "\n";
        reverse(arr.begin()+r, arr.end());
    } while(next_permutation(arr.begin(), arr.end()));
    // 순서 상관없으니, 각 원소를 0,1로 두어서 순열을 구함
    // 1은 포함, 1의 개수는 포함하고 싶은 원소개수
    cout << "nCr\n";
    vector <int> v{0,1,1,1};
    do{
        for(int i=0; i<n; i++)
        {
            if(v[i]==1)
            {
                cout << arr[i] << " ";
            }
        }
        cout << "\n";

    }while(next_permutation(v.begin(), v.end()));
}