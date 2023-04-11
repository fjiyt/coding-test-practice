#include <iostream>
#include <map>

using namespace std;

int main()
{
    map <int,int> m;

    m.insert(pair<int,int> (3,10));
    m.insert(make_pair(5,100));
    m.insert({2,40});
    pair <int,int> p(4,30);
    m.insert(p);

    m[11] = 200;
    m[12] = 200;
    m[13] = 30;

    map <int,int>::iterator iter;
    for(iter = m.begin(); iter!=m.end(); iter++)
    {
        cout << "<" << (*iter).first << "," << (*iter).second << ">" << " ";
    }
    cout << "\n";

    m[13] = 130;

    pair<map<int,int>::iterator, bool> pr;
    pr=m.insert({13,30});
    if(true==pr.second) cout << "저장완료 : " << pr.first->first << ", " << pr.first->second << "\n";
    else cout << "이미있음\n";

    map<string,int,greater<string>> m2;
    m2.insert({"apple", 3});
    m2.insert({"bananan",5});
    map <string, int>::iterator it;
    for(it = m2.begin(); it!=m2.end(); it++)
    {
        cout << "<" << (*it).first << "," << (*it).second << ">" << " ";
    }
    cout << "\n";

    map<string, int, less<string>> m3;
    m3.insert({"apple", 3});
    m3.insert({"bananan",5});
    map <string, int>::iterator it2;
    for(it2 = m3.begin(); it2!=m3.end(); it2++)
    {
        cout << "<" << (*it2).first << "," << (*it2).second << "> ";
    }

    cout << "\n";
}