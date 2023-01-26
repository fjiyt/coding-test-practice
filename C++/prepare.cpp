#include <iostream>

using namespace std;

void recur_function(int i)
{
    if (i == 5)
        return;
    printf("%d번째 재귀함수에서 %d 번째 재귀함수를 호출합니다.\n", i, i + 1);
    recur_function(i + 1);
    printf("%d번째 재귀함수를 종료합니다\n", i);
}
int main()
{
    recur_function(1);
}