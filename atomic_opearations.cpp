#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

using namespace std;

atomic<int> shared_value(0);

void increment() {
    shared_value++; // this is an atomic operations 
    // shared_value = shared_value + 1 --> this is a non atomic operation
    // similarly shared_value+=4; is an atomic operator += , &= , |= , -= , all these are atomic operations 
}

int main() {
    vector<jthread> threads;

    for(int i = 0 ; i < 10 ; i++){
        threads.push_back(jthread(increment));  
    }
   
    cout << shared_value << endl;
}

 // this atomic , can also work with the custom data types , given that, they are trivially copyable ( no non primitives or the custom constrcutors);
 // atomic operations are hardware level privilages ,that we are getting , it happens only when the operation is single step ( that is when the data is trivially copyable)