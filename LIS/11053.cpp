#include <iostream>
#include <vector>

using namespace std;

vector <int> v;
int arr[1001];
int N;

int LIS()
{
    for(int i=1; i<N; i++)
    {
        if(v.back() < arr[i])
        {
            v.push_back(arr[i]);
        }
        else{
            *(lower_bound(v.begin(), v.end(), arr[i])) = arr[i];
        }
    }

    return v.size();
}
int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    v.push_back(arr[0]);
    cout << LIS() << "\n";

}