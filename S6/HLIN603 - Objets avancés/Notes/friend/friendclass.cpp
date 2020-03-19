// Source : https://docs.microsoft.com/en-us/cpp/cpp/friend-cpp?view=vs-2019

#include <iostream>

using namespace std;


// #### First example
class B;

class A {
    public:
        int Func1( B& b );
};

class B {
    private:
        int numberB;

    // A::Func1 is a friend function to class B
    // so A::Func1 has access to all members of B
    friend int A::Func1( B& );
};

int A::Func1( B& b ) { return b.numberB; }   // OK

// -------------------------------------
// #### Second example
class C {
    
    friend class D;  // Declare a friend class
    
    private:
        int number;
    
    public:
        C() : number(3){}
        void printMember() { cout << number << endl; }

};

class D {
    public:
        void change( C& _numb, int x ){ _numb.number = x; }
};


int main(){
    C c;
    D d;
    c.printMember();
    d.change( c, 5 );
    c.printMember();
    return 0;
}