#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "book";
    cout << s << " : " << s.size() << "\n";
    cout << s << " : " << s.length() << "\n";
    s="";
    cout << s << " : " << s.size() << "\n";

    //c에는 string 에 없는 타입이기 때문에 c-style로 변환해줘야함
    printf("%s\n", s.c_str());

    string str2 = "e";
    str2.insert(0, "H");
    str2.insert(2, "o");
    // 작은 따옴표를 써야됨
    str2.insert(2,2,'l').append(" ");
    cout << str2 << "\n";

    string world = "Half the World Away";
    // push_back에는 char, append에는 string
    str2.insert(6, world, 9, 5).push_back('!');
    str2.append("!");
    cout << str2 << "\n";

    string str = "10";
    int number = stoi(str);
    int number2 = stoi("10");
    cout << number << " " << number2 << "\n";

    int n1 = 1;
    int n2 = 2;
    string s1 = to_string(n1);
    string s2 = to_string(n2);
    cout << s1 + ' ' + s2 << "\n";

    return 0;
}