// Source : https://docs.microsoft.com/en-us/cpp/cpp/friend-cpp?view=vs-2019

#include <iostream>

using namespace std;

class B;

class A {
    public:
        int Func1( B& b );

    private:
        int Func2( B& b );
};

class B {
    private:
        int numberB;

    // A::Func1 is a friend function to class B
    // so A::Func1 has access to all members of B
    friend int A::Func1( B& );
};

int A::Func1( B& b ) { return b.numberB; }   // OK
int A::Func2( B& b ) { return b.numberB; }   // C2248

int main(){
    return 0;
}