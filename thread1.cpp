#include<iostream> 
#include<thread> 
using namespace std;
void task(int x){
    cout<<"Hello from the created thread !"<<endl;
    cout<<"The argument passed is : "<<x<<endl;
}
// int main(){
//     thread  Mythread(&task,100);
//     cout<<"Hello from the main thread ! "<<endl;
//     return 0;
// }
// the output for this is as below : 
// Hello from the main thread ! Hello from the created thread !
// The argument passed is : 
// terminate called without an active exception
// 100
// this is beause the two threads , were interleaving , and hence the program switched before the print statement executes 
 // before the task function gets completed , the main thread executed the return 0 and terminated the program , to avoid this 
 // we have to specifically tell the main thread to wait until this thread completes the execution 
 
 int main(){
    thread  Mythread(&task,100);
    Mythread.join();
    cout<<"Hello from the main thread ! "<<endl;
    return 0;
}
//output : 
// Hello from the created thread !
// The argument passed is : 100
// Hello from the main thread ! 