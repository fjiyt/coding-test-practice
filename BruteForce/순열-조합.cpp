#include <iostream>
#include <vector>

#define n 4
#define r 3

using namespace std;

int arr[n] = {1,2,3,4};
int pArr[r];
int cArr[r];
bool isVisited[n];

void printArray(int p[])
{
    for(int i=0; i<r; i++)
    {
        cout << p[i] << " ";
    }
    cout << "\n";
}
// 중복 허용 안되는 순열 -> isVisited사용, 재귀, dfs
void permutation(int cnt)
{
    if(cnt==r){
        printArray(pArr);
        return;
    }
    
    for(int i=0; i<n; i++)
    {
        if(isVisited[i]) continue;
        isVisited[i] = true;
        pArr[cnt] = arr[i];
        permutation(cnt+1);
        isVisited[i] = false;
    }
}
// 중복 순열 -> isVisited x, dfs
void repeated_permutation(int cnt)
{
    if(cnt==r)
    {
        printArray(pArr);
        return;
    }

    for(int i=0; i<n; i++)
    {
        pArr[cnt] = arr[i];
        repeated_permutation(cnt+1);
    }
}
// 조합 -> bfs
void combination(int depth, int start)
{
    if(depth==r)
    {
        printArray(cArr);
        return;
    }
    for(int i=start; i<n; i++)
    {
        cArr[depth] = arr[i];
        combination(depth+1, i+1);
    }
}
int getCombination(int N, int R)
{
    if(N==R || R==0)
    {
        return 1;
    }
    
    return getCombination(N-1, R-1) + getCombination(N-1,R);
}
int main()
{
    cout << "permutation\n";
    permutation(0);
    for(int i=0; i<r; i++)
    {
        pArr[i] = 0;
    }
    cout << "repeated_permutation\n";
    repeated_permutation(0);

    cout << "combination\n";
    combination(0,0);

    cout << "조합 경우의수\n";
    int tmp_n = n, tmp_r = r;
    cout << getCombination(tmp_n, tmp_r) << "\n";    
}