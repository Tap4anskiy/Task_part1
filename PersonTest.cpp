#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "PersonTest.h"
#include "TestBase.h"
using namespace std;

// конструктор по умолчанию
PersonTest::PersonTest() {
    this->name = "";
    this->testnumber = 0;
    this->result = vector<int>();
}
// конструктор с параметрами
PersonTest::PersonTest(const string& name, int testnumber, const vector<int>& result) {
    this->name = name;
    this->testnumber = testnumber;
    this->result = result;
}
// конструктор копирования
PersonTest::PersonTest(const PersonTest &other) {
    name = other.name;
    testnumber = other.testnumber;
    result = other.result;
}
// Деконструктор класса
PersonTest::~PersonTest(){}
string PersonTest::getName() const {
    return name;
}
int PersonTest::getTestnumber() const {
    return testnumber;
}
vector<int> const& PersonTest::getResult()const{
    return result;
}
void PersonTest::show_vec(vector<int>const&vec)
{
    for (int i=0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
void PersonTest::write() {
    cout << *this << endl;
}
bool PersonTest::correct(const char *s, string condition)
{
    if (condition=="int_digit")
    {
        while(*s)
        {
            if((*s < '0' || *s > '9') && *s != ' ') return false;
            s++;
        }
        return true;
    }
    if (condition=="double_digit")
    {
        while(*s)
        {
            if((*s < '0' || *s > '9') && *s != ' ' && *s != '.') return false;
            s++;
        }
        return true;
    }
    else if (condition=="word")
    {
        while(*s)
        {
            if (not(isalpha(*s)) && not(isspace(*s))) return false;
            s++;
        }
        return true;
    }
    else return false;
}
void PersonTest::read()
{
    string s;
    string res;
    bool key1; bool key2; bool key3;
    cin.get();
    cout << "Введите имя: ";
    getline(cin, s);
    key3 = true;
    while (key3)
    {
        char* buffer = new char[s.length() + 1];
        s.copy(buffer, s.length() + 1);
        buffer[s.length()] = '\0';
        if (!correct(buffer,"word"))
        {
            cout << "Ошибка, пожалуйста, введите имя: ";
            cin >> s;
        }
        else key3 = false;
        delete[] buffer;
    }
    name = s;
    cout << "Введите номер теста: ";
    cin >> s;
    key1 = true;
    while (key1)
    {
        char* buffer = new char[s.length() + 1];
        s.copy(buffer, s.length() + 1);
        buffer[s.length()] = '\0';
        if (!correct(buffer,"int_digit"))
        {
            cout << "Ошибка, пожалуйста, введите целое число: ";
            cin >> s;
        }
        else key1 = false;
        delete[] buffer;
    }
    testnumber = stoi(s);
    cin.get();
    cout << "Введите результаты: ";
    getline(cin, s);
    key2 = true;
    while (key2)
    {
        char* buffer = new char[s.length() + 1];
        s.copy(buffer, s.length() + 1);
        buffer[s.length()] = '\0';
        if (!correct(buffer,"int_digit"))
        {
            cout << "Ошибка, пожалуйста, введите целые числа: ";
            getline(cin, s);
        }
        else key2 = false;
        delete[] buffer;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ') res += s[i];
        else {
            result.push_back(stoi(res)); res = "";
        }
    }
    result.push_back(stoi(res));
    res = "";
}
void PersonTest::read(const char *file) {
    ifstream in;
    in.open(file);
    if(in.is_open()) in >> *this;
    else
    {
        cout << "FILE NOT FOUND";
    }
    in.close();
}
int PersonTest::compare(const PersonTest& other) const {
    if (name != other.name) {
        return name.compare(other.name);
    } else if (testnumber != other.testnumber) {
        return testnumber - other.testnumber;
    } else {
        return 0;
    }
}
bool PersonTest::check(const char *name, int testnumber, vector<int> bottom, vector<int> top)
{
    if (name == nullptr && testnumber == -1 && bottom.size() == 0 && top.size() == 0) return false;
    if (name != nullptr)
    {
        if (this->getName() != name) return false;
    }
    if (testnumber != -1)
    {
        if (this->getTestnumber() != testnumber) return false;
    }
    if (bottom.size() != 0)
    {
        if (bottom.size() >= this->getResult().size())
        {
            for (int i=0; i<this->getResult().size();i++)
            {
                if (bottom[i]>this->getResult()[i]) return false;
            }
        }
        else return false;
    }
    if (top.size() != 0)
    {
        if (top.size() >= this->getResult().size())
        {
            for (int i=0; i<this->getResult().size();i++)
            {
                if (top[i]<this->getResult()[i]) return false;
            }
        }
        else return false;
    }
    return true;
}
bool operator==(const PersonTest& that, const PersonTest& other) {
    return that.getName() == other.getName() && that.getTestnumber() == other.getTestnumber() \
    && that.getResult() == other.getResult();
}
void PersonTest::getProperty(vector<double> coefficient)
{
    long double multiply;
    for (int i = 0; i < this->result.size(); i++) {
        if (i > coefficient.size() - 1)
        {
            multiply += result[i];
        }
        else
        {
            multiply += coefficient[i] * result[i];
        }
    }
    cout << "Взвешенная сумма: " << multiply << endl;
}
ostream& operator<<(ostream& out, const PersonTest& person)
{
    out << person.getName() << " " << person.getTestnumber() << " ";
    vector<int>vec = person.getResult();
    for (int i=0; i < vec.size(); i++)
    {
        out << vec[i] << " ";
    }
    return out;
}
istream& operator>>(istream& in,PersonTest &person) {
    string name;
    int testnumber;
    string line;
    vector<int> results;
    getline(in, line);
    istringstream iss(line);
    if (iss >> name >> testnumber) {
        int value;
        results.clear();
        while (iss >> value) {
            results.push_back(value);
        }
    }
    return in;
}

