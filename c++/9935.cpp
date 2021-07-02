#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> st;
stack<char> temp;
string in;
string fire;

int find_explo()
{
    int end = fire.size()-1;
    int now = end; 
    int cnt = 0;
    
    while(!st.empty())
    {
        char t = st.top();
        st.pop();

        if(t == fire[now])
        {
            if(now == 0) now = end;
            else now--;

            cnt ++;
        }
        else
        {
            temp.push(t);
        }
    }
    if(now == end && cnt == 0) // 이제 폭발물이 없는경우
    {
        return 1;
    }

    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> in;
    cin >> fire;

    for(long unsigned int i=0; i<in.size(); i++)
    {
        st.push(in[i]);
    }

    while(1)
    {
        int ret = find_explo();
        
        if(ret==1)
        {
            if(temp.size()==0)
            {
                cout << "FRULA";
            }
            while(!temp.empty()){
                cout << temp.top();
                temp.pop();
            }
            cout << endl;
            return 0;
        }

        else if(ret==0)
        {
            while(!temp.empty()){
                char t = temp.top();
                temp.pop();
                st.push(t);
            }
        }
    }
    return 0;
}