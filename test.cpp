#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    map<string, string> mapTest;
    mapTest["Just"] = "yes";
    mapTest["A"] = "no";
    mapTest.insert(pair<string, string>("Test", "maybe"));
    for(auto it = mapTest.begin();it != mapTest.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    multimap<string, string> mapTest2;
    mapTest2.insert(pair<string, string>("Anton", "clever"));
    mapTest2.insert(pair<string, string>("Anton", "handsome"));
    mapTest2.insert(pair<string, string>("Boris", "cunt"));
    for(auto it2 = mapTest2.begin();it2 != mapTest2.end(); ++it2)
    {
        cout << it2->first << " " << it2->second << endl;
    }

    srand(time(NULL));
    int del;
    int add;
    set<int> setTest1;
    for(int i = 0; i < 4; i++)
    {
        setTest1.insert(rand() % 10);
    }
    cout << "Все элементы: ";
    copy(setTest1.begin(), setTest1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "Какой элемент нужно удалить? " << endl;;
    cin >> del;
    setTest1.erase(del);
    cout << "Какой элемент хотите добавить? " << endl;
    cin >> add;
    setTest1.insert(add);
    cout << "Новый список элементов: ";
    copy(setTest1.begin(), setTest1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "Size:" << setTest1.size() << endl;

    return 0;
}