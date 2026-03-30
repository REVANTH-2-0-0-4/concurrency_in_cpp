#include<iostream> 
#include<thread>
#include<vector>
using namespace std;
int main(){
    auto lambda = [](int x){
        cout<<"Hello from the  thread "<< this_thread::get_id()<<endl;
        cout<<"The argument passed is : "<<x<<endl;
    };
    vector<thread> threads;
    for(int i = 0 ; i < 10 ; i++){
    	threads.push_back(thread(lambda,100));
	threads[i].join();
    }
    cout<<"Hello,from the main thread"<<endl;
    cout<<"The main thread id "<<this_thread::get_id()<<endl;
    return 0;
    	// the output of this program : 
    	// Hello from the  thread 2
    	// The argument passed is : 100
    	// Hello from the  thread 3
    	// The argument passed is : 100
    	// Hello from the  thread 4
    	// The argument passed is : 100
    	// Hello from the  thread 5
    	// The argument passed is : 100
    	// Hello from the  thread 6
    	//The argument passed is : 100
    	// Hello from the  thread 7
    	// The argument passed is : 100
    	// Hello from the  thread 8
    	// The argument passed is : 100
    	// Hello from the  thread 9
    	// The argument passed is : 100
    	// Hello from the  thread 10
    	// The argument passed is : 100
    	// Hello from the  thread 11
     	// The argument passed is : 100
	//Hello,from the main thread
	//The main thread id 1
	// this is more of a sequential program , to get the maximum benefit of concurrency , we need to change out code to the following 
	// for(int i = 0 ; i < 10 ; i++){
        //threads.push_back(thread(lambda,100));
	//}
	//for(int i = 0 ; i < 10 ; i++){
      		//  threads[i].join();
	// }
	// now all the ten threads , execute concurrently , while the main thread stops till all the threads gets executed 
	// in the first case , it can also happen that , all the threads have the same id , because the second thread is begin created after the first thread  terminates , the os can actually assign the same id , in some cases , based on the os!
}
