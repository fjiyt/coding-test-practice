#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int left_location;
int right_location;

int distance(int num, string hand)
{
    int left_distance = abs(left_location - num) % 3 + abs(left_location - num) / 3;
    int right_distance = abs(right_location - num) % 3 + abs(right_location - num) / 3;

    if (left_distance < right_distance)
        return 0;
    else if (left_distance > right_distance)
        return 1;
    else
    {
        if (hand == "left")
            return 0;
        else if (hand == "right")
            return 1;
    }

    return -1;
}
string solution(vector<int> numbers, string hand)
{
    string answer = "";
    left_location = 10;
    right_location = 12;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            left_location = numbers[i];
            answer.push_back('L');
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            right_location = numbers[i];
            answer.push_back('R');
        }
        else if (numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0)
        {
            if (numbers[i] == 0)
            {
                numbers[i] = 11;
            }
            if (distance(numbers[i], hand) == 0)
            {
                answer.push_back('L');
                left_location = numbers[i];
            }
            else if (distance(numbers[i], hand) == 1)
            {
                answer.push_back('R');
                right_location = numbers[i];
            }
        }
    }

    cout << answer << "\n";
    return answer;
}

int main()
{
    string hand;
    cin >> hand;
    vector<int> numbers;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }

    solution(numbers, hand);
}