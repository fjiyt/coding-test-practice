# tie

tie는 tuple이나 pair로 묶인 변수를 _여러 변수_ 에 한꺼번에 담아올 수 있디.

```c++
#include <iostream>
#include <tuple>

using namespace std;

int main()
{
    auto t = make_tuple(1,2,3);
    
    int x = get<0>(t);
    int y = get<1>(t);
    int z = get<2>(t);

    cout << x << " " << y << " " << z << "\n";

    x=y=z=0;
    cout << x << " " << y << " " << z << "\n";

    tie(x,y,z) = t;
    cout << x << " " << y << " " << z << "\n";

    x=y=z=0;
    tie(x,y,ignore) = t;
    cout << x << " " << y << " " << z << "\n";
}
```