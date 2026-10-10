#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
    MyString a("Hello");
    cout << "a = " << a << endl;
    cout << "Length = " << a.MyStrLen() << endl;
    
    cout << "Index of 'l' = "<< a.MyChr('l') << endl;
    cout << "Find \"ell\" = " << a.MyStrStr("ell") << endl;

    MyString copy;
    copy.MyStrcpy(a);
    cout << "Copy = "<< copy << endl;
    
    MyString b(" World");

    MyString cat(a);

    cat.MyStrCat(b);

    cout << "Concat = " << cat << endl;

    MyString del("Hello");
    del.MyDelChr('l');
    cout << "Delete l = " << del << endl;

    MyString s1("Apple");
    MyString s2("Banana");

    cout << "Compare = " << s1.MyStrCmp(s2) << endl;
    cout << "a[1] = " << a[1] << endl;

    // obj + 'A'
    MyString r1 = a + '!';
    cout << "a + '!' = " << r1 << endl;

    // 'A' + obj
    MyString r2 = 'A' + a;
    cout << "'A' + a = " << r2 << endl;

    // obj + 10
    MyString r3 = a + 10;
    cout << "a + 10 = \"" << r3 << "\"" << endl;
    cout << "Length = " << r3.MyStrLen() << endl;

    // 10 + obj
    MyString r4 = 10 + a;
    cout << "10 + a = \"" << r4 << "\"" << endl;

    // obj++
    a++;
    cout << "a++ = " << a << endl;

    // ++obj
    ++a;
    cout << "++a = " << a << endl;

    // operator =
    MyString x("One");
    MyString y("Two");
    x = y;
    cout << "x = y: " << x << endl;

    // operator ()
    MyString keyboard;

    cout << "Enter string for operator():\n";
    keyboard();
    cout << "Result: " << keyboard << endl;

    MyString input;
    cout << "Enter string for operator >>:\n";
    cin >> input;
    cout << "You entered: ";
    cout << "Objects: " << MyString::GetCount() << endl;
    
    //initializer_list
    MyString a2{'H', 'e', 'l', 'l', 'o'};

    cout << "Original: ";
    a.Output();

    MyString b2(move(a));

    cout << "Move constructor: ";
    b.Output();

    MyString c("World");

    c = move(b);

    cout << "Move assignment: ";
    c.Output();

    return 0;
}