#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "TestBase.h"
using namespace std;
//Конструктор по умолчанию
TestBase::TestBase() : head(nullptr) {}
// Деконструктор класса
TestBase::~TestBase() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}
//Конструктор копирования
TestBase::TestBase(const TestBase &other) {
    if (other.head == nullptr) {
        head = nullptr;
        return;
    }
    head = new Node(other.head->person);
    Node *current = head;
    Node *otherCurrent = other.head->next;
    while (otherCurrent != nullptr) {
        current->next = new Node(otherCurrent->person);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}
// Конструктор, принимающий указатель на Node (копирование среза списка)
TestBase::TestBase(Node* node) : head(nullptr) {
    Node* current = node;
    while(current != nullptr) {
        append(current->person);
        current = current->next;
    }
}
void TestBase::append(const PersonTest& data)
{
    Node* new_node = new Node(data);
    if (head == nullptr) {
        head = new_node;
    } else {
        Node* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
}
void TestBase::add(const PersonTest& data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    //проверочка
    if (occurence_check(data.getName()))
    {
        klon_check += 1;
        if (klon_check == 4)
        {
            cout << "Mb Caesar knows what to do with this symbols?" << endl;
            cout << "Bc, Qosgof rcsgb'h ybck. hfm gcashvwbu szgs" << endl;
            cout << "R14" << endl;
        }
        else if (klon_check == 6)
        {
            cout << "Morbi.. Morbius?" << endl;
            cout << "Hello, Neighbour. This is for u: 293716953949747652976955329" << endl;
        }
        else if (klon_check == 8)
        {
            cout << "Are you still here? Take this: 86677 85119 52287 13973 56185 50964 86772 43930 27774 97259 55081 93783 16780 17673 93790" << endl;
            cout << "48647 30935 32894 91805 66357 76604" << endl;
        }
        else if (klon_check == 9)
        {
            cout << "Last cypher was Modulo N" << endl;
        }
        else if (klon_check == 14)
        {
            cout << "Wow! PGab" << endl;
            cout << 13343555 << endl;
            cout << 3465688 << endl;
            cout << 234556 << endl;
            cout << 2343475 << endl;
        }
    }
}
void TestBase::write(const string& name) const {
    bool flag = true;
    Node* current = head;
    while (current != nullptr) {
        if (current->person.getName() == name)
        {
            current->person.write();
            flag = false;
            break;
        }
        current = current->next;
    }
    if (flag) cout << "Person not found!" << endl;
}
TestBase::Node* TestBase::findPerson(const string&name)
{
    Node* current = head;
    bool flag = true;
    while (current != nullptr) {
        if (current->person.getName() == name) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
void TestBase::writeAll() const {
    Node* current = head;
    while (current != nullptr) {
        current->person.write();
        current = current->next;
    }
}
void TestBase::sort() {
    if (head == nullptr || head->next == nullptr) {
        return;  // Список пустой или содержит только один элемент, сортировка не требуется
    }

    Node* middle = head;
    Node* current = head->next;
    while (current != nullptr) {
        current = current->next;
        if (current != nullptr) {
            middle = middle->next;
            current = current->next;
        }
    }

    Node* left = head;
    Node* right = middle->next;
    middle->next = nullptr;

    TestBase leftList(left);
    TestBase rightList(right);

    leftList.sort();
    rightList.sort();

    // Слияние двух отсортированных списков
    Node* merged = nullptr;
    Node** mergeRef = &merged;

    while (leftList.head != nullptr && rightList.head != nullptr) {
        if (leftList.head->person.compare(rightList.head->person) <= 0) {
            *mergeRef = new Node(leftList.head->person);
            leftList.head = leftList.head->next;
        } else {
            *mergeRef = new Node(rightList.head->person);
            rightList.head = rightList.head->next;
        }
        mergeRef = &((*mergeRef)->next);
    }

    // Добавляем оставшиеся элементы, если таковые имеются
    while (leftList.head != nullptr) {
        *mergeRef = new Node(leftList.head->person);
        leftList.head = leftList.head->next;
        mergeRef = &((*mergeRef)->next);
    }

    while (rightList.head != nullptr) {
        *mergeRef = new Node(rightList.head->person);
        rightList.head = rightList.head->next;
        mergeRef = &((*mergeRef)->next);
    }

    // Освобождаем память, занятую исходным списком
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = merged;
}
void TestBase::clear()
{
    Node* current = head;
    Node *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}
void TestBase::addToSorted(const PersonTest& data) {
    Node* newNode = new Node(data);

    if (head == nullptr || head->person.compare(data) > 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->person.compare(data) <= 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

}
ostream& operator<<(ostream& out,const TestBase &testBase) {
    TestBase::Node* current = testBase.head;
    while (current != nullptr) {
        out << current->person.getName() << " " << current->person.getTestnumber() << " ";
        vector<int> results = current->person.getResult();
        for (int i = 0; i < results.size(); i++) {
            out << results[i] << " ";
        }
        out << endl;
        current = current->next;
    }
    return out;
}
istream& operator>> (istream& in,TestBase& testBase) {
    string name;
    int testnumber;
    string line;
    vector<int> results;
    while (getline(in, line)) {
        istringstream iss(line);

        if (iss >> name >> testnumber) {
            int value;
            results.clear();

            while (iss >> value) {
                results.push_back(value);
            }

            const PersonTest new_person(name, testnumber, results);
            testBase.append(new_person);
        }
    }
    return in;
}
void TestBase::finder(char d,const char *name, int testnumber, vector<int> bottom, vector<int> top) {
    Node* current = head;
    switch (d)
    {
        case('w'):
            while (current != nullptr)
            {
                Node* next = current->next;
                if (current->person.check(name, testnumber, bottom, top)) current->person.write();
                current = next;
            }
        case('r'):
            while (current != nullptr)
            {
                Node* next = current->next;
                if (current->person.check(name, testnumber, bottom, top)) {
                    current->person.write();
                    TestBase::remove(current->person);
                }
                current = next;
            }
        default: break;
    }
}
void TestBase::remove(const PersonTest& data)
{
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->person == data) {
            if (previous == nullptr) { // удаляемый элемент - первый в списке
                head = current->next;
            }
            else {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}
void TestBase::getBallList(int testnumber)
{
    Node* current = head;
    bool flag = true;
    while (current != nullptr) {
        if (current->person.getTestnumber() == testnumber) {
            PersonTest::show_vec(current->person.getResult());
            flag = false;
        }
        current = current->next;
    }
    if (flag) cout << "Тест не найден" << endl;
}
bool TestBase::occurence_check(const string& name) {
    for (int i = 0; i < names_dict.size(); i++)
    {
        int error_num = 0;
        for (int j = 0; j < name.size() && j < names_dict[i].size(); j++)
        {
            if (names_dict[i][j] != name[j]) error_num += 1;
        }
        if (error_num <= 3)
        {
            names_dict.erase(names_dict.begin() + i);
            return true;
        }
    }
    return false;
}
