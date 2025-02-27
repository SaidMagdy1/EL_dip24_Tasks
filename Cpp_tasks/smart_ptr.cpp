#include <iostream>
#include <memory>
#include <vector>

int main(){
//unique_pointer
    std::unique_ptr<int>p = std::make_unique<int>(100);
    std::unique_ptr<int>p2 = std::make_unique<int>(10);
    //p=p2; //Error unique cant be assigned
    p = std::move(p2);
    std::vector<std::unique_ptr<int>>vec;
    //vec.push_back(p); //Error unique cant be copied

    std::cout <<"the value is : "<< *p<<std::endl;
    std::cout <<"the Raw ptr is : "<< p.get()<<std::endl;

//shared_pointer
    std::shared_ptr<int>sp=std::make_shared<int>(100);
    std::shared_ptr<int>sp2=std::make_shared<int>(10);
    //sp = std::move(sp2);
    sp = sp2 ; // it works cuz it is a shared

    std::cout <<"the value is : "<< *sp<<std::endl;
    std::cout <<"the Count is : "<< sp.use_count()<<std::endl;
    sp2.reset();
    std::cout <<"the Count is : "<< sp.use_count()<<std::endl;
    std::cout <<"the Count is : "<< sp2.use_count()<<std::endl;  //sp2 released so its 0



    return 0;
}