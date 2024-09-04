#include<iostream>
#include <thread>
#include <mutex>


int counter= 0;
std::mutex mtx;

// here the thread wont wait till the other one finish so the counter will be less than 20000
// void Count(){       
//     for(int i=0 ; i<10000 ;i++){
//         if(mtx.try_lock()){
//             ++counter;
//             mtx.unlock();
//         }
//     }
//    std::cout << " mtx.try_lock " <<std::endl;    
// }

// here the thread will wait till the other one finish so counter will be 20000
// void Count(){
//     for(int i=0 ; i<10000 ;i++){
//         mtx.lock();
//         ++counter;
//         mtx.unlock();
        
//     }
//    std::cout << " mtx.lock " <<std::endl;

// }

// //using lock_guard
// void Count(){       
//     std::lock_guard<std::mutex> lock(mtx);
//     for(int i=0 ; i<10000 ;i++){
       
//         ++counter;
//     }
//     std::cout << " lock_guard " <<std::endl;
// }

//using unique_lock
void Count(){       
   // std::unique_lock<std::mutex> lock(mtx);
   std::unique_lock<std::mutex> lock(mtx,std::defer_lock);
   lock.lock();
    for(int i=0 ; i<10000 ;i++){
       
        ++counter;
    }
    std::cout << " unique_lock " <<std::endl;
}

int main(){

    std::thread t1(Count);
    std::thread t2(Count);

    t1.join();
    t2.join();

    std::cout << counter <<std::endl;
    return 0;
}