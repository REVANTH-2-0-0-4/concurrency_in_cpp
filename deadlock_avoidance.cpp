include<iostream>
#include<thread>
#include<vector>
#include<mutex>
using namespace std;
int shared_value = 0;
void shared_value_increment(){
    glock.lock();
    int temp = shared_value;
    this_thread::sleep_for(chrono::microseconds(1));
    shared_value = temp + 1;
     // this is one reason  why dead lock can occur  because the lock has not been given to the next thread , so none of the threads make progress which is technically called  as the deadlock 
}
void shared_value_increment2(){
	glock.lock();
	try{
    		int temp = shared_value;
    		this_thread::sleep_for(chrono::microseconds(1));
	    	shared_value = temp + 1;
		throw "Dangerous Exception";
	}
	catch(...){
		cout<<"Handle Exception:"<<endl;
		return;
	}
	glock.unlock();
	// in this case , although u have unlocked , it the program doesnt reach the line where u unlocked it , since return statement is begin executed in the catch block  in that case , what we can  use lock_guard a feature which cpp provides , which automatically returns the lock when goes out of scope 
}
void shared_value_increment3(){        
	lock_guard<mutex> lockGuard(glock);
        try{
                int temp = shared_value;
                this_thread::sleep_for(chrono::microseconds(1));
                shared_value = temp + 1;
                throw "Dangerous Exception";
        }
        catch(...){
                cout<<"Handle Exception:"<<endl;
                return;
        }
        // this runs correctly because of using the lockguard
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
