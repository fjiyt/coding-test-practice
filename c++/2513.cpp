#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector <pair<int,int> > v;
    int apart, bus_limit, school_location;

    cin >> apart >> bus_limit >> school_location;

    v.push_back(make_pair(school_location,0)); //학교를 0으로 기준
    while(apart--)
    {
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y)); //학교를 기준으로 거리측정 후 vector 삽입
    }
    sort(v.begin(), v.end()); //오름차순 정렬

    int school_index=lower_bound(v.begin(), v.end(), make_pair( school_location, 0 )) - v.begin();
    int v_size = v.size();

    int present = school_index; //현재 위치
    int prev = school_index; //이전 위치
    int left=0, right=v_size-1;
    bool direction = 0; //왼쪽 : 0 , 오른쪽 : 1
    int bus_remain = bus_limit, distance=0;
 
    while(left-1<=school_index && right+1>=school_index)
    {
        //현재 학교 -> 방향 설정
        if(present == school_index){
            bus_remain = bus_limit;

            if(left == school_index && right == school_index) break;
            else if(left == school_index) {direction = 1; continue;}
            else if(right == school_index) {direction = 0; continue;}

            if(abs(v[left].first) > abs(v[right].first)) //왼쪽부터 실행
            {
                direction = 0;
            }
            else //오른쪽부터 실행
            {
                direction = 1;
            }
            
        }
        //현재 학교가 아닐때->다음 장소로 넘어감 (학교여도 됨. 학교면 애들 내려준다고 생각)
        else
        {
            if(v[present].second <= bus_remain) bus_remain -= v[present].second;
            else // 넘치는 경우. 몇명만 태워갈수있음
            {
                if(bus_remain >= 0)
                {
                    v[present].second = v[present].second - bus_remain;
                    prev = present;
                    present = school_index;
                    v_size++;
                    continue;
                }   
            }
        }

        distance += abs(v[present].first - v[prev].first);
        prev = present;
        if(direction == 0) present=left++;
        else present=right--;
    }

    cout << distance << "\n";
    return 0;
}