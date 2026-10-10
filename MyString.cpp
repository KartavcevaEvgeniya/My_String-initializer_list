#include "MyString.h"
#include <cstring>
int MyString::count = 0;

// Конструктор за замовчуванням
MyString::MyString()
{
    length = 80;
    str = new char[length + 1];
    str[0] = '\0';
    count++;
}

// Конструктор довільного розміру
MyString::MyString(int size)
{
    length = size;
    str = new char[length + 1];
    str[0] = '\0';
    count++;
}

// Конструктор з рядком
MyString::MyString(const char* text)
{
    length = strlen(text);
    str = new char[length + 1];
    strcpy(str, text);
    count++;
}

// Конструктор копіювання
MyString::MyString(const MyString& obj)
{
    length = obj.length;
    str = new char[length + 1];
    strcpy(str, obj.str);
    count++;
}

MyString::~MyString()
{
    delete[] str;
    count--;
}

void MyString::Input()
{
    char temp[1000];

    cout << "Enter string: ";
    cin.getline(temp, 1000);

    delete[] str;

    length = strlen(temp);
    str = new char[length + 1];
    strcpy(str, temp);
}

void MyString::Output() const
{
    cout << str << endl;
}

// Копіювання рядка
void MyString::MyStrcpy(MyString& obj)
{
    if (this != &obj)
    {
        delete[] str;

        length = obj.length;
        str = new char[length + 1];
        strcpy(str, obj.str);
    }
}

// Пошук підрядка
bool MyString::MyStrStr(const char* text)
{
    return strstr(str, text) != nullptr;
}

int MyString::MyChr(char c)
{
    for (int i = 0; i < length; i++)
    {
        if (str[i] == c)
        {
            return i;
        }
    }
    return -1;
}

int MyString::MyStrLen()
{
    return length;
}

void MyString::MyStrCat(MyString& b)
{
    int newLength = length + b.length;
    char* temp = new char[newLength + 1];
    strcpy(temp, str);
    strcat(temp, b.str);

    delete[] str;

    str = temp;
    length = newLength;
}

void MyString::MyDelChr(char c)
{
    int j = 0;

    for (int i = 0; i < length; i++)
    {
        if (str[i] != c)
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    length = j;
}

int MyString::MyStrCmp(MyString& b)
{
    int result = strcmp(str, b.str);

    if (result < 0)
    {
        return -1;
    }

    if (result > 0)
    {
        return 1;
    }
    return 0;
}

const char* MyString::GetStr() const { return str; }

int MyString::GetLength() const { return length;}

int MyString::GetCount() { return count; }

// operator []
char& MyString::operator[](int index)
{
    return str[index];
}

// operator ()
void MyString::operator()()
{
    Input();
}

// obj + 'A'
MyString MyString::operator+(char c) const
{
    MyString temp(length + 1);
    for (int i = 0; i < length; i++)
    {
        temp.str[i] = str[i];
    }
    temp.str[length] = c;
    temp.str[length + 1] = '\0';

    return temp;
}

// 'A' + obj
MyString operator+(char c, const MyString& obj)
{
    MyString temp(obj.GetLength() + 1);
    temp[0] = c;
    for (int i = 0; i < obj.GetLength(); i++)
    {
        temp[i + 1] = obj.GetStr()[i];
    }
    temp[obj.GetLength() + 1] = '\0';

    return temp;
}

// obj + 10
MyString MyString::operator+(int n) const
{
    if (n < 0)
    {
        n = 0;
    }

    MyString temp(length + n);
    for (int i = 0; i < length; i++)
    {
        temp.str[i] = str[i];
    }
    for (int i = length; i < length + n; i++)
    {
        temp.str[i] = ' ';
    }
    temp.str[length + n] = '\0';

    return temp;
}

// 10 + obj
MyString operator+(int n, const MyString& obj)
{
    return obj + n;
}

// obj++
MyString MyString::operator++(int)
{
    MyString old(*this);
    MyString temp = *this + '*';
    *this = temp;

    return old;
}

// ++obj
MyString& MyString::operator++()
{
    MyString temp = '*' + *this;
    *this = temp;

    return *this;
}

// operator =
MyString& MyString::operator=(const MyString& obj)
{
    if (this != &obj)
    {
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        strcpy(str, obj.str);
    }
    return *this;
}

// operator <<
ostream& operator<<(ostream& out, const MyString& obj)
{
    out << obj.GetStr();
    return out;
}

// operator >>
istream& operator>>(istream& in, MyString& obj)
{
    char temp[1000];
    in.getline(temp, 1000);
    MyString newString(temp);
    obj = newString;

    return in;
}

//initializer_list
MyString::MyString(initializer_list<char> list)
{
    length = static_cast<int>(list.size());
    str = new char[length + 1];

    int i = 0;

    for (char c : list)
    {
        str[i] = c;
        i++;
    }

    str[length] = '\0';
}
MyString::MyString(MyString&& obj) noexcept
{
    str = obj.str;
    length = obj.length;

    obj.str = nullptr;
    obj.length = 0;
}
MyString& MyString::operator=(MyString&& obj) noexcept
{
    if (this != &obj)
    {
        delete[] str;

        str = obj.str;
        length = obj.length;

        obj.str = nullptr;
        obj.length = 0;
    }
    return *this;
}
