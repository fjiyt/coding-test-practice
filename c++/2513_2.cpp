#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int apart, bus_limit, school_location;

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector < pair<int,int> > v;

    cin >> apart >> bus_limit >> school_location;

    v.push_back(make_pair(school_location,0));
    while(apart--)
    {
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y)); 
    }
    sort(v.begin(), v.end()); //오름차순 정렬

    long long school_index=lower_bound(v.begin(), v.end(), make_pair( school_location, 0 )) - v.begin();

    int present = school_index;
    int prev = school_index;
    int distance = 0;
    int bus_remain = bus_limit;

    for(long long i=0; i <= school_index; i++)
    {
        prev = present;
        present = i;
        distance += abs(v[present].first - v[prev].first); //이동거리
        if((bus_remain - v[present].second <= 0) && (i != school_index))
        {
            v[present].second -= bus_remain;
            distance += abs(v[school_index].first - v[present].first); // 학교에 태운 학생을 내려놓고 와야됨
            bus_remain = bus_limit;
            i--; //아직 아파트에 타야될 학생 있음
        }
        else{
            bus_remain -= v[present].second;
        }
    }

    bus_remain=bus_limit;
    for(long long i=v.size()-1; i >= school_index; i--)
    {
        //cout << distance << "\n";
        prev = present;
        present = i;

        distance += abs(v[present].first - v[prev].first); //이동거리
        if((bus_remain - v[present].second <= 0) && (i != school_index))
        {
            v[present].second -= bus_remain;
            distance += abs(v[school_index].first - v[present].first); // 학교에 태운 학생을 내려놓고 와야됨
            i++; //아직 아파트에 타야될 학생 있음
        }
        else{
            bus_remain -= v[present].second;
        }
    }

    cout << distance << "\n";
    return 0;
}