#include <iostream>
#include "String.h"
using namespace std;

int main()
{
    String a;

    cout << a.size() << endl;
    
    String b("abc");
    cout << b;
    cout << b.size() << endl;

    String c = b.reverse();
    cout << c << c.size() << endl;

    cout << c[0] << endl;
    c[0] = '4';
    cout << c[0] << endl;
    cout << c[-1] << endl;
    c[-1] = '0';
    cout << c[-1] << endl;

    String d(c);
    cout << (d == c) << endl;
    cout << (b != c) << endl;
    cout << (d != c) << endl;
    cout << (b == c) << endl;


    cout << (a<b) << endl;
    cout << (a<a) << endl;
    cin >> a >> a >> a >> a;
    cout << a << "size of " << a.size() << endl;


    cout << a+b << endl;
    a=a+b;
    a+=b;
    cout << a << endl;
}
