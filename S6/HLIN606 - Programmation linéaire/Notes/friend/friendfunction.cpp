// Source : https://docs.microsoft.com/en-us/cpp/cpp/friend-cpp?view=vs-2019

#include <iostream>

using namespace std;

class Point {
    
    private:
        int number;
    
    protected:
        int number2;

    public:
        Point( void ) : number(0), number2(3) {}
        void PrintPrivate( void ){
            cout << "number : " << number << endl; 
            cout << "number2 : " << number2 << endl; 
        }

    // If friend is removed ChangePrivate could'nt read number & number2
    friend void ChangePrivate( Point & );

};

void ChangePrivate ( Point &i ) { i.number++; i.number2++; }

int main(){
    Point sPoint;
    cout << "### Start" << endl;
    sPoint.PrintPrivate();
    ChangePrivate(sPoint);
    cout << "\n### Increment" << endl;
    sPoint.PrintPrivate();

    return 0;
}