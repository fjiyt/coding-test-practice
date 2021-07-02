#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int X, Y;
    long long strength;
    cin >> X >> Y >> strength;

    long long player[X], item[Y];
    long long total=0;
    long long max_strength=strength/2; //체력소모, 회복 총 값

    for(int i=0; i<X; i++)
    {
        cin >> player[i];
        if(player[i] > max_strength) return -1;
        total += player[i];
    }

    for(int i=0; i<Y; i++)
    {
        cin >> item[i];
        if(item[i] > max_strength) return -1;
        total -= item[i];
    }

    if(total >= strength) //이길 방법이 없을 경우
    {
        cout << "0\n";
        return 0;
    }
    
    int p=1, q=1;
    total = strength;
    for(int i=0; i<X+Y && (p-1 < X || q-1 < Y); i++)
    {
        total -= player[p-1];

        if(total > 0){
            cout << -p <<"\n";
            p++;
        }
        else{ //아이템 사용
            total = total + player[p-1] + item[q-1];
            cout << q << "\n";
            q++;
        }
    }
    return 0;
}