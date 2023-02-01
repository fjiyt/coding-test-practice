#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;

    for(int i=0; i<T; i++)
    {
        string str;
        cin >> str;

        stack <char> st;
        char tmp = '\0'; //연속인지 비교할 문자(직전에 있는 문자)

        st.push(str[0]);
        for(int j=1; j<str.length(); j++)
        {
            if(tmp == '\0')
            {
                if(!st.empty())
                {
                    tmp = st.top(); //tmp가 비어있는 경우에는 직전의 문자
                    if(tmp == str[j]) //같으면 직전 문자 stack에서 꺼냄
                    {
                        st.pop();
                    }
                    else //다르면 현재 문자 삽입
                    {
                        st.push(str[j]);
                        tmp = '\0'; //비교할 문자 갱신해줄라고 
                    }
                }
                else //스택이 아예 비어있으면 (모든 문자열이 그룹 or 처음) 현재 문자 삽입
                {
                    st.push(str[j]);
                    tmp = '\0';
                }
            }
            else
            {
                if(tmp!=str[j]) //직전 문자와 다를경우 -> 직전 문자가 group이여서 pop 했을수도 있으니깐 tmp 초기화하고 다시 비교해보기
                {
                    tmp = '\0';
                    j--;
                }
            }
        }
        if(st.empty()) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}