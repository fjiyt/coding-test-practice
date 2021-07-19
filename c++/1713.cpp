#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct s
{
    int student;
    int time;
    int recommend;
};
int student_vote[101] = {
    -1,
};

int picture_cnt = 0; //걸려있는 사진 수

int main()
{
    int N;
    cin >> N;

    int picture;
    cin >> picture;

    s frame[N];

    for (int i = 0; i < 101; i++)
    {
        student_vote[i] = -1;
    }
    for (int i = 0; i < picture; i++)
    {
        int student_num;
        cin >> student_num;

        if (student_vote[student_num] == -1) //사진이 안걸려있는 경우
        {
            int tmp;
            if (picture_cnt < N)
            {
                tmp = picture_cnt;
                picture_cnt++;
            }
            else
            {
                //삭제할 사진 찾기
                int min_recommend = 1001;
                int remove_index = 0;
                for (int j = 0; j < N; j++)
                {
                    if (min_recommend == frame[j].recommend)
                    {
                        //더 오래된 사진 삭제
                        if (frame[remove_index].time > frame[j].time)
                        {
                            remove_index = j;
                        }
                    }
                    else if (min_recommend > frame[j].recommend)
                    {
                        min_recommend = frame[j].recommend;
                        remove_index = j;
                    }
                }
                //새로운 사진 추가
                tmp = remove_index;
                student_vote[frame[tmp].student] = -1;
            }
            student_vote[student_num] = tmp;
            frame[tmp].student = student_num;
            frame[tmp].time = i;
            frame[tmp].recommend = 1;
        }

        else
        {
            int tmp = student_vote[student_num];
            frame[tmp].recommend++;
        }
    }

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < N; i++)
    {
        if (frame[i].recommend != 0)
        {
            pq.push(frame[i].student);
        }
    }

    while (!pq.empty())
    {
        int num = pq.top();
        pq.pop();
        cout << num << " ";
    }

    cout << "\n";

    return 0;
}