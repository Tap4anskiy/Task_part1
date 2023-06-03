#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "PersonTest.h"
#include "TestBase.h"
TestBase test;
void save()
{
    string file_name;
    cin.get();
    cout << "Введите путь к файлу: ";
    getline(cin, file_name);
    ofstream file(file_name);
    if (file.is_open())
    {
        file << test;
        cout << "Список сохранен в файле!" << endl;
    }
    else cout << "Файл не найден!" << endl;
    file.close();
}
void load()
{
    string file_name;
    cin.get();
    cout << "Введите путь к файлу: ";
    getline(cin, file_name);
    ifstream infile(file_name);
    if (infile.is_open())
    {
        infile >> test;
        infile.close();
        cout << "Список загружен:" << endl;
        test.writeAll();
    }
    else cout << "Файл не найден!" << endl;
    infile.close();
}
void sort()
{
    test.sort();
    cout << "Отсортированный список:" << endl;
    test.writeAll();
}
void add()
{
    PersonTest person;
    person.read();
    test.add(person);
    cout << "Вы добавили человека!" << endl;
}
void find(char d) {
    string name; int testnumber;
    vector<int> bottom; vector<int> top;
    string s; string res;
    cout << "Введите условия для проверки, если хотите пропустить условие введите '-1' " << endl;
    cin.get();
    cout << "Введите имя: " << endl;
    cin >> name;
    const char*name1;
    if (name == "-1") name1 = nullptr;
    else  name1 = name.c_str();
    cout << "Введите номер теста: " << endl;
    cin >> testnumber;
    cin.get();
    res = "";
    cout << "Введите вектор нижних ограничений: " << endl;
    getline(cin, s);
    if (s != "-1") {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') res += s[i];
            else {
                bottom.push_back(stoi(res));
                res = "";
            }
        }
        bottom.push_back(stoi(res));
    }
    res = "";
    cout << "Введите вектор верхних ограничений: " << endl;
    getline(cin, s);
    if (s != "-1") {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') res += s[i];
            else {
                top.push_back(stoi(res));
                res = "";
            }
        }
        top.push_back(stoi(res));
    }
    switch (d)
    {
        case('w'): {
            cout << "Следующие люди удовлетворяют условиям:" << endl;
            test.finder('w', name1, testnumber, bottom, top);
            break;
        }
        case('r'): {
            cout << "Следующие люди были удалены:" << endl;
            test.finder('r', name1, testnumber, bottom, top);
            break;
        }
        default: break;
    }
}
void testinfo() {
    int testnumber;
    cout << "Введите номер теста: ";
    cin >> testnumber;
    cout << "Набор результатов для теста " << testnumber << ":" << endl;
    test.getBallList(testnumber);
}
void clear()
{
    test.clear();
    cout << "Список очищен!" << endl;
}
void writeall() {
    cout << "Список всех людей:" << endl;
    test.writeAll();
};
void getproperty()
{
    vector<double> coeff;
    string name; string s; string res;
    cout << "Введите имя человека:" << endl;
    cin >> name;
    if (test.findPerson(name) == nullptr) cout << "Человек не найден" << endl;
    else {
        cin.get();
        cout << "Введите весовые коэффициенты:" << endl;
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') res += s[i];
            else {
                coeff.push_back(stoi(res));
                res = "";
            }
        }
        coeff.push_back(stoi(res));
        test.findPerson(name)->person.getProperty(coeff);
    }
}
void help() {
    cout << "Доступные команды:" << endl;
    cout << "help - вывести на экран список команд" << endl;
    cout << "writeall - вывести на экран всех людей" << endl;
    cout << "clear - очистить список" << endl;
    cout << "load - добавить список из файла" << endl;
    cout << "save - сохранить список в файле" << endl;
    cout << "add - добавить элемент" << endl;
    cout << "sort - отсортировать" << endl;
    cout << "find - вывести на экран элементы, удовлетворяющие условиям" << endl;
    cout << "delete - удалить элементы, удовлетворяющие условиям" << endl;
    cout << "testinfo <номер теста> - выдать для теста список наборов баллов" << endl;
    cout << "property - взвешенная сумма баллов" << endl;
    cout << "exit - завершить работу и выйти" << endl;
}
void puh()
{
    string command;
    while(true)
    {
        cin >> command;
        system("cls");
        if(command == "help") help();
        if(command == "writeall") writeall();
        if(command == "clear") clear();
        if(command == "load") load();
        if(command == "save") save();
        if(command == "add") add();
        if(command == "sort") sort();
        if(command == "find") find('w');
        if(command == "delete") find('r');
        if(command == "testinfo") testinfo();
        if(command == "property") getproperty();
        if(command == "exit") return;
    }

}
int main(int argc, const char * argv[]) {
    help();
    puh();
}
