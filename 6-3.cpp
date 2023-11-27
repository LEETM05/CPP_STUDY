// #include <iostream>

// using namespace std;

// class Parent {
//     public:
//     Parent() {cout << "Parent 생성자 호출\n";}
//     virtual ~Parent() {cout << "Parent 소멸자 호출\n";}
// };

// class Child : public Parent {
//     public:
//     Child() : Parent() {cout << "Child 생성자 호출\n";}
//     ~Child() { cout << "Child 소멸자 호출\n";}
// };

// int main() {
//     cout << "--- 평범한 Child 만들었을 때 --- \n";
//     {Child c;}
//     cout << "--- Parent 포인터로 Child 가리켰을 때 ---\n";
//     {Parent*p = new Child();
//         delete p;
//     }
// }

#include <iostream>

using namespace std;

class A {
   public:
    virtual void show() { cout << "Parent!\n"; }
};

class B : public A {
   public:
    void show() override { cout << "Child!\n"; }
};

void test(A& a) {a.show();}

int main() {
    A a;
    B b;
    test(a);
    test(b);
    return 0;
}