# Longest Increasing Subsequence (가장 긴 증가하는 부분 수열)
- 이진탐색 이용
  - c++ : lower_bound()

~~~c++
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
~~~