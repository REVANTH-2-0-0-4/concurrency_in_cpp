#include<iostream> 
#include<thread>
using namespace std;
int main(){
    auto lambda = [](int x){
        cout<<"Hello from the created thread !"<<endl;
        cout<<"The argument passed is : "<<x<<endl;
    };
    thread Mythread(lambda,100);
    Mythread.join();
    cout<<"Hello,from the main thread"<<endl;
    return 0;
}