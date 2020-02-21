#include <iostream>

using namespace std;

class Point {
    
    private:
        int number;
        
    public:
        Point( void ) : number(0) {}
        void PrintPrivate( void ){cout << number << endl; }

    // If friend is removed ChangePrivate could'nt read number 
    friend void ChangePrivate( Point & );

};

void ChangePrivate ( Point &i ) { i.number++; }

int main(){
    Point sPoint;
    sPoint.PrintPrivate();
    ChangePrivate(sPoint);
    sPoint.PrintPrivate();

    return 0;
}