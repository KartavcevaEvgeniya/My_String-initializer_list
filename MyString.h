#pragma once
#include <iostream>
using namespace std;
#include <initializer_list>
//#include <utility>

class MyString
{
private:
    char* str;
    int length;
    static int count;

public:
    MyString();
    MyString(int size);
    MyString(const char* text);
    MyString(const MyString& obj);
    //initializer_list
    MyString(initializer_list<char> list);
    MyString(MyString&& obj) noexcept;
    MyString& operator=(MyString&& obj) noexcept;
    //
    ~MyString();

    void Input();
    void Output() const;

    void MyStrcpy(MyString& obj);
    bool MyStrStr(const char* text);
    int MyChr(char c);
    int MyStrLen();
    void MyStrCat(MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(MyString& b);

    const char* GetStr() const;
    int GetLength() const;

    static int GetCount();

    // obj[index]
    char& operator[](int index);

    // obj() - введення з клавіатури
    void operator()();

    // obj + 'A'
    MyString operator+(char c) const;

    // obj + 10
    MyString operator+(int n) const;

    // obj++
    MyString operator++(int);

    // ++obj
    MyString& operator++();

    // obj1 = obj2
    MyString& operator=(const MyString& obj);
};

// 'A' + obj
MyString operator+(char c, const MyString& obj);

// 10 + obj
MyString operator+(int n, const MyString& obj);

// Виведення
ostream& operator<<(ostream& out, const MyString& obj);

// Введення
istream& operator>>(istream& in, MyString& obj);