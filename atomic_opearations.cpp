#include <iostream>
#include <thread>
#include <atomic>
#include<vector>
#include<jthread>
using namespace std;
atomic<int> shared_value(0);
void increment() {
    shared_value++; // this is an atomic operations 
    // shared_value = shared_value + 1 --> this is a non atomic operation ,
}
int main() {
   vector<jthread> threads;
   for(int i = 0 ; i < 10 ; i++){
    jthreads.push_back(jthread(increment));  
   }
   
    cout << shared_value << endl;
}