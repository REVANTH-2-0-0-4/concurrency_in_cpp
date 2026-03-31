#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
using namespace std;
int shared_value = 0;
void shared_value_increment(){
    int temp = shared_value;
    this_thread::sleep_for(chrono::microseconds(1));
    shared_value = temp + 1;
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
