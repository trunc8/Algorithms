// Run as "g++ -std=c++11 -pthread"

// cpp program to demonstrate multithreading
// using three different callables
#include <iostream>
#include <thread>
using namespace std;

// A dummy function
void foo(int P1){
    for(int i=0; i<P1; i++){
        cout << "1.Thread using function"
        " pointer as callable\n";
    }
}

// A callable object
class thread_obj {
public:
    void operator() (int P2){
        for(int i=0; i<P2; i++){
            cout << "2.Thread using function"
            " object as callable\n";
        }
    }
};

int main(){
    cout << "Threads 1, 2 and 3 "
    "operating independently\n";

    thread th1(foo, 3); //function pointer as callable
    thread th2(thread_obj(), 3); //function object as callable

    auto f = [](int P3){
        for(int i=0; i<P3; i++){
            cout << "3.Thread using lambda"
            " expression as callable\n";
        }
    };

    thread th3(f, 3); //lambda expression as callable

    // Wait for threads to finish
    th1.join();

    th2.join();

    th3.join();

    return 0;
}
