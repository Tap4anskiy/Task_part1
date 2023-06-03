#ifndef PERSONTEST_H
#define PERSONTEST_H

#include <string>
#include <vector>
using namespace std;
class PersonTest {
    //Атрибуты класса PersonTest
private:
    string name;
    int testnumber;
    vector<int> result;


    //Методы класса PersonTest
public:
    PersonTest();   //Конструктор по умолчанию
    ~PersonTest();  //Деструктор
    PersonTest(const string& name, int testnumber, const vector<int>& result);  //Конструктор с параметрами объекта
    PersonTest(const PersonTest& other);    //Конструктор копирования
    string getName() const; //Возврат атрибута name объекта
    int getTestnumber() const;  //Возврат атрибута testnumber объекта
    vector<int> const& getResult() const;   //Возврат вектор result объекта
    static void show_vec(vector<int> const&vec);   //Вывод вектора на экран
    void write();  //Вывод информации об объекте
    bool correct(const char *s, string condition); //Проверка правильности ввода
    void read();  //Чтение с клавиатуры
    void read(const char *file);    //Чтение с файла
    int compare(const PersonTest& other) const; //Сравнение двух объектов
    void getProperty(vector<double> coefficients);
    bool check(const char *name= nullptr, int testnumber = -1,  vector<int> bottom = vector<int>(), \
            vector<int> top = vector<int>());   //Проверка информации об объекте
    friend bool operator==(const PersonTest& that, const PersonTest& other);
    friend ostream& operator<< (ostream& out,const PersonTest &person); //Перегрузка оператора вывода
    friend istream& operator>> (istream& in,PersonTest &person);    //Перегрузка оператора ввода
};


#endif  // PERSONTEST_H
