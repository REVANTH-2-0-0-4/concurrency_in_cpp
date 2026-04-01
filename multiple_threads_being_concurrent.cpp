#include<iostream>
#include<thread>
#include<vector>
using namespace std;
int main(){
	vector<thread> threads;
	auto lambda = [](int x){
	  cout<<"Hello from the thread!" << this_thread::get_id()<<endl;
	};
	for(int i = 0 ; i < 5 ; i++){
	   threads.push_back(thread(lambda,100));
	}
	for(int i = 0 ; i < 5 ; i++){
	    threads[i].join();
	}
	cout<<" Hello from the main thread !"<<endl;
	cout<<"Main thread id --> " <<this_thread::get_id()<<endl;
	return 0;
}
// the output of the following program : 
// Hello from the thread!Hello from the thread!Hello from the thread!45
// Hello from the thread!6
//
//Hello from the thread!3
//2
 //Hello from the main thread !
//Main thread id --> 1
