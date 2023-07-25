#include <iostream>

using namespace std;

struct A {
    A() { cout << "a ctor" << endl; };
    virtual void f() { cout << "a" << endl; }
};

struct B : A {
    B() { cout << "b ctor" << endl; f(); };
    virtual void f() { cout << "b" << endl; }
};

struct C : B {
    C() { cout << "c ctor" << endl; };
    virtual void f() { cout << "c" << endl; }
};

int main() {
    C c;
    cout << "--" << endl;
    B *b = new C();
    b->f();
    cout << "--" << endl;
}