#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    stack <int> st;
    for(int i=numbers.size()-1; i>=0; i--)
    {
        if(i==numbers.size()-1)
        {
            answer.push_back(-1);
            st.push(numbers[i]);
            continue;
        }
        bool flag = false;
        while(!st.empty())
        {
            if(st.top() > numbers[i])
            {
                answer.push_back(st.top());
                st.push(numbers[i]);
                flag = true;
                break;
            }
            else{
                st.pop();
            }
        }
        if(st.empty() && !flag){
            answer.push_back(-1);
            st.push(numbers[i]);
        }
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}