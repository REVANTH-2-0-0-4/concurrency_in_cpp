#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
using namespace std;
int shared_value = 0;
mutex glock;
void shared_value_increment(){
    glock.lock();
    int temp = shared_value;
    this_thread::sleep_for(chrono::microseconds(1));
    shared_value = temp + 1;
    glock.unlock();
}
int main(){
        vector<thread> threads;
        for(int i = 0 ; i < 100 ; i++){
                threads.push_back(thread(shared_value_increment));
        }
        for(int i = 0 ; i < 100 ; i++){
                threads[i].join();
        }
        cout<<" shared value : " <<shared_value<<endl;
}
// what we are essentially doing is that , we are locking the critical section the read , write opeations , so that only one could access the resouce at a time , avoiding the data race  , in this if we forget to return the lock , then the next threads cant make proress , which would lead to a dead lock situation , so we have to always check whethere we are returing the lock to the next person or not , so that the next thread gets the acccess 
