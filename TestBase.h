#ifndef TESTBASE_H
#define TESTBASE_H

#include "PersonTest.h"
#include <vector>
using namespace std;
class TestBase {
private:
    vector<string> names_dict = {
        "Murilo Benicio", "Giovanna Antonelli", "Vera Fischer", "Reginaldo Faria", "Daniela Escobar",
        "Adriana Lessa", "Neuza Borges", "Jandira Martini", "Marcello Novaes", "Marcos Frota",
        "Beth Goulart", "Cissa Guimaraes", "Victor Fasano","Debora Falabella", "Luciano Szafir",
        "Guilherme Karam", "Myriam Rios", "Nivea Stelmann", "Raul Gazolla", "Thais Fersoza",
        "Sergio Marone", "Juliana Paes", "Thiago Fragoso", "Elizangela", "Carla Diaz",
        "Carolina Macieira", "Perry Salles", "Solange Couto", "Thalma De Freita", "Mara Manzan",
        "Silvio Guindani" };
    int klon_check = 0;
    //Структура узла
    struct Node {
        PersonTest person;
        Node *next;
        Node(const PersonTest &data) : person(data), next(nullptr) {}
    };
    Node *head;
public:
    TestBase(); //Конструктор по умолчанию
    ~TestBase();    //Деструктор
    TestBase(const TestBase &other);  //Конструктор копирования
    TestBase(Node* node);  //Копирование среза списка
    void append(const PersonTest& data);  //Добавление узла в конец
    void add(const PersonTest &data);  //Добавление узла в начало
    void write(const string& name) const;  //Вывод узла
    Node* findPerson(const string &name);  //Поиск узла по имени
    void sort();  //Сортировка
    void addToSorted(const PersonTest& person); //Добавление узла без нарушения сортировки
    void writeAll() const;  //Вывод всех узлов
    void remove(const PersonTest& data);
    void clear();
    void finder(char d, const char *name= nullptr, int testnumber = -1,  vector<int> bottom = vector<int>(), \
            vector<int> top = vector<int>());
    friend ostream& operator<< (ostream& out,const TestBase &testBase); //Перегрузка оператора вывода
    friend istream& operator>> (istream& in,TestBase &testBase);    //Перегрузка оператора ввода
    void getBallList(int testnumber);
    bool occurence_check(const string& name);
};

#endif  // TESTBASE_H
