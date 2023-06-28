#include <iostream>

using namespace std;

int M;
bool arr[21];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M;
    while(M--)
    {
        string command;
        int num;

        cin >> command;

        if(command=="add")
        {
            cin >> num;
            arr[num] = true;
        }
        else if(command=="remove")
        {
            cin >> num;
            if(arr[num]) arr[num] = false;
        }
        else if(command=="check")
        {            
            cin >> num;

            if(arr[num]) cout << "1\n";
            else cout << "0\n";
        }
        else if(command=="toggle")
        {
            cin >> num;

            if(arr[num]) arr[num] = false;
            else arr[num] = true;
        }
        else if(command=="all")
        {
            for(int i=1; i<=20; i++)
            {
                arr[i] = true;
            }
        }
        else if(command=="empty")
        {
            for(int i=1; i<=20; i++)
            {
                arr[i] = false;
            }
        }
    }
}