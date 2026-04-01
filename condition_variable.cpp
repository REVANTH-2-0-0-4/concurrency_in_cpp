#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
#include<condition_variable>
using namespace std;

mutex glock;
condition_variable gconditionvariable;

int main(){
         
    int result = 0;
    bool notified = false;

    //reporting thread 
    // must wait on work  , done by the working thread 
    thread reporter([&]{
        unique_lock<mutex> lock(glock);
        if(!notified){
            gconditionvariable.wait(lock);
        }
        cout<<"Reporter  , result is : "<<result<<endl;
    });

    // worker thread 
    thread worker([&]{
        {
            unique_lock<mutex> lock(glock);  
            // unique lock , is also a general purpose lock , but has more power  , it is required when we are using the conidition variable 
            result = 42 + 1 + 7;
            // our work is done
            notified = true;
        }

        this_thread::sleep_for(chrono :: seconds(5));
        cout<<"Work Complete"<<endl;

        // wake up a thread that is waiting for some condition to be true 
        gconditionvariable.notify_one();

    });

    reporter.join();
    worker.join();

    return 0;
}

// condition variable is a special feature provided by the cpp , which is used to avoid the overhead associated with the all the threads other than the one which is accessing the crirical section 
// continously asking whether it got a lock or not  , insted of the threads continously checking for lock which burns cycles , what happens is the condition variable notifies the next thread , when the current thread , finishes its execution 
